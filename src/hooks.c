#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <psapi.h>
#include "hooks.h"

#pragma comment(lib, "psapi.lib")

// Global handle to original winmm.dll - defined in dllmain.c
extern HMODULE g_hReal;

// Typedefs for original functions
typedef BOOL (WINAPI *PlaySoundW_t)(LPCWSTR, HMODULE, DWORD);
typedef BOOL (WINAPI *PlaySoundA_t)(LPCSTR, HMODULE, DWORD);

static PlaySoundW_t fp_PlaySoundW = NULL;
static PlaySoundA_t fp_PlaySoundA = NULL;

// Forward declaration
void load_all_original_functions(void);

// Simple log function for debugging - multiple locations
static void log_message(const char* msg) {
    FILE* f = NULL;
    // Try multiple locations for the log file
    const char* paths[] = {
        "C:\\temp\\navicat_patch.log",
        "C:\\Windows\\Temp\\navicat_patch.log",
        "navicat_patch.log"  // Current directory
    };

    for (int i = 0; i < 3; i++) {
        f = fopen(paths[i], "a");
        if (f) {
            fprintf(f, "[%lu] %s\n", GetCurrentProcessId(), msg);
            fclose(f);
            return;
        }
    }
}

static void log_hex(const char* prefix, DWORD value) {
    char buf[256];
    snprintf(buf, sizeof(buf), "%s: 0x%08X (%lu)", prefix, value, value);
    log_message(buf);
}

// Get original DLL path and load it
static void load_original_dll(void) {
    char sysPath[MAX_PATH];
    char dllPath[MAX_PATH];

    log_message("load_original_dll() starting...");

    if (GetSystemDirectoryA(sysPath, MAX_PATH)) {
        snprintf(dllPath, MAX_PATH, "%s\\winmm.dll", sysPath);
        log_message(dllPath);
        g_hReal = LoadLibraryA(dllPath);
        if (g_hReal) {
            log_message("Loaded system winmm.dll successfully");
        } else {
            log_hex("Failed to load system winmm.dll, error", GetLastError());
        }
    }

    if (!g_hReal) {
        log_message("Trying winmm_orig.dll...");
        g_hReal = LoadLibraryA("winmm_orig.dll");
        if (g_hReal) {
            log_message("Loaded winmm_orig.dll");
        }
    }

    if (g_hReal) {
        fp_PlaySoundW = (PlaySoundW_t)GetProcAddress(g_hReal, "PlaySoundW");
        fp_PlaySoundA = (PlaySoundA_t)GetProcAddress(g_hReal, "PlaySoundA");
        log_hex("fp_PlaySoundW", (DWORD)(DWORD_PTR)fp_PlaySoundW);
        log_hex("fp_PlaySoundA", (DWORD)(DWORD_PTR)fp_PlaySoundA);
    } else {
        log_message("ERROR: Could not load original winmm.dll!");
    }
}

// Find pattern in memory
static LPVOID find_pattern(LPBYTE start, SIZE_T size, const BYTE *pattern, const CHAR *mask, const char* patternName) {
    SIZE_T patternLen = strlen(mask);
    char buf[256];

    snprintf(buf, sizeof(buf), "Searching for pattern: %s (len=%zu, search range=%zu)", patternName, patternLen, size);
    log_message(buf);

    for (SIZE_T i = 0; i <= size - patternLen; i++) {
        BOOL found = TRUE;
        for (SIZE_T j = 0; j < patternLen; j++) {
            if (mask[j] == 'x' && start[i + j] != pattern[j]) {
                found = FALSE;
                break;
            }
        }
        if (found) {
            snprintf(buf, sizeof(buf), "Pattern '%s' found at offset 0x%zX (addr: %p)", patternName, i, start + i);
            log_message(buf);
            return start + i;
        }
    }

    snprintf(buf, sizeof(buf), "Pattern '%s' NOT found", patternName);
    log_message(buf);
    return NULL;
}

// Patch for Navicat 17
static BOOL patch_navicat17(void) {
    HMODULE hNavicat = GetModuleHandle(NULL);
    log_hex("GetModuleHandle(NULL)", (DWORD)(DWORD_PTR)hNavicat);

    if (!hNavicat) {
        log_message("ERROR: GetModuleHandle(NULL) failed");
        return FALSE;
    }

    MODULEINFO modInfo;
    if (!GetModuleInformation(GetCurrentProcess(), hNavicat, &modInfo, sizeof(modInfo))) {
        log_hex("GetModuleInformation failed, error", GetLastError());
        return FALSE;
    }

    log_hex("Module base", (DWORD)(DWORD_PTR)modInfo.lpBaseOfDll);
    log_hex("Module size", (DWORD)modInfo.SizeOfImage);

    LPBYTE baseAddr = (LPBYTE)modInfo.lpBaseOfDll;
    SIZE_T size = modInfo.SizeOfImage;
    BOOL patched = FALSE;

    // Navicat 17 Pattern 1: License check function
    // 48 89 5C 24 08 57 48 83 EC 20 48 8B F9 80 79 08 00
    BYTE pattern1[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0xF9};
    CHAR mask1[] = "xxxxxxxxxxxxx";

    LPVOID addr1 = find_pattern(baseAddr, size, pattern1, mask1, "LicenseCheck_v1");
    if (addr1) {
        DWORD oldProtect;
        // xor eax, eax; inc eax; ret (return TRUE)
        BYTE patch[] = {0x31, 0xC0, 0x48, 0xFF, 0xC0, 0xC3};
        if (VirtualProtect(addr1, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr1, patch, sizeof(patch));
            VirtualProtect(addr1, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr1, sizeof(patch));
            log_message("Pattern 1 patched successfully!");
            patched = TRUE;
        } else {
            log_hex("VirtualProtect failed for pattern 1, error", GetLastError());
        }
    }

    // Navicat 17 Pattern 2: Trial check bypass
    // 40 53 48 83 EC 20 80 79 08 00 48 8B D9
    BYTE pattern2[] = {0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x80, 0x79, 0x08, 0x00};
    CHAR mask2[] = "xxxxxxxxxx";

    LPVOID addr2 = find_pattern(baseAddr, size, pattern2, mask2, "TrialCheck");
    if (addr2) {
        DWORD oldProtect;
        // mov eax, 1; ret
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3};
        if (VirtualProtect(addr2, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr2, patch, sizeof(patch));
            VirtualProtect(addr2, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr2, sizeof(patch));
            log_message("Pattern 2 patched successfully!");
            patched = TRUE;
        } else {
            log_hex("VirtualProtect failed for pattern 2, error", GetLastError());
        }
    }

    // Navicat 17 Pattern 3: IsPremium check
    // 48 89 5C 24 08 57 48 83 EC 20 48 8B 59 10 48 8B F9
    BYTE pattern3[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0x59, 0x10};
    CHAR mask3[] = "xxxxxxxxxxxxxx";

    LPVOID addr3 = find_pattern(baseAddr, size, pattern3, mask3, "IsPremium");
    if (addr3) {
        DWORD oldProtect;
        // mov eax, 1; ret
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3};
        if (VirtualProtect(addr3, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr3, patch, sizeof(patch));
            VirtualProtect(addr3, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr3, sizeof(patch));
            log_message("Pattern 3 patched successfully!");
            patched = TRUE;
        } else {
            log_hex("VirtualProtect failed for pattern 3, error", GetLastError());
        }
    }

    // Additional patterns based on IDA analysis of original winmm.dll
    // Pattern 4: Alternative license check signature found in IDA
    // 48 89 5C 24 08 57 48 83 EC 20 49 8B F8 48 8B D9
    BYTE pattern4[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x49, 0x8B, 0xF8};
    CHAR mask4[] = "xxxxxxxxxxxxx";

    LPVOID addr4 = find_pattern(baseAddr, size, pattern4, mask4, "LicenseCheck_Alt");
    if (addr4) {
        DWORD oldProtect;
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3};
        if (VirtualProtect(addr4, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr4, patch, sizeof(patch));
            VirtualProtect(addr4, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr4, sizeof(patch));
            log_message("Pattern 4 patched successfully!");
            patched = TRUE;
        }
    }

    if (!patched) {
        log_message("WARNING: No patterns were found or patched!");
    }

    return patched;
}

// Thread function for patching Navicat
DWORD WINAPI NavicatPatchThread(LPVOID lpParam) {
    DWORD threadId = GetCurrentThreadId();
    char buf[256];
    snprintf(buf, sizeof(buf), "Patch thread started (ID: %lu, param: %p)", threadId, lpParam);
    log_message(buf);

    // Wait for Navicat to fully initialize
    log_message("Waiting 500ms for Navicat to initialize...");
    Sleep(500);

    // Apply patches for Navicat 17
    log_message("Calling patch_navicat17()...");
    if (patch_navicat17()) {
        log_message("Patches applied successfully!");
    } else {
        log_message("Failed to apply any patches");
    }

    log_message("Patch thread exiting");
    return 0;
}

void hooks_init(void) {
    log_message("=== hooks_init() starting ===");

    // Load original winmm.dll
    log_message("Loading original DLL...");
    load_original_dll();

    // Load all forwarded function pointers
    log_message("Loading forwarded functions...");
    load_all_original_functions();

    // Check if we're running in navicat.exe
    wchar_t exePath[MAX_PATH];
    wchar_t exeName[MAX_PATH];

    log_message("Checking executable name...");
    if (GetModuleFileNameW(NULL, exePath, MAX_PATH)) {
        // Extract filename from path
        wchar_t* filename = wcsrchr(exePath, L'\\');
        if (filename) {
            wcscpy_s(exeName, MAX_PATH, filename + 1);
        } else {
            wcscpy_s(exeName, MAX_PATH, exePath);
        }

        // Convert to char for logging
        char exeNameA[MAX_PATH];
        WideCharToMultiByte(CP_ACP, 0, exeName, -1, exeNameA, MAX_PATH, NULL, NULL);
        char buf[512];
        snprintf(buf, sizeof(buf), "Running in: %s", exeNameA);
        log_message(buf);

        // Check if it's navicat.exe (case insensitive)
        if (_wcsicmp(exeName, L"navicat.exe") == 0) {
            log_message("Detected navicat.exe - creating patch thread");
            // Create thread to patch Navicat
            HANDLE hThread = CreateThread(NULL, 0, NavicatPatchThread, NULL, 0, NULL);
            if (hThread) {
                log_message("Patch thread created successfully");
                CloseHandle(hThread);
            } else {
                log_hex("Failed to create patch thread, error", GetLastError());
            }
        } else {
            snprintf(buf, sizeof(buf), "Not navicat.exe, skipping patches (exeName=%s)", exeNameA);
            log_message(buf);
        }
    } else {
        log_hex("GetModuleFileNameW failed, error", GetLastError());
    }

    log_message("=== hooks_init() complete ===");
}

// Hooked PlaySoundW function
BOOL WINAPI PlaySoundW_hook(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound) {
    if (fp_PlaySoundW) {
        return fp_PlaySoundW(pszSound, hmod, fdwSound);
    }
    return FALSE;
}

// Hooked PlaySoundA function
BOOL WINAPI PlaySoundA_hook(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound) {
    if (fp_PlaySoundA) {
        return fp_PlaySoundA(pszSound, hmod, fdwSound);
    }
    return FALSE;
}

// Hooked PlaySound (forward to PlaySoundW)
BOOL WINAPI PlaySoundW_hook(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);
