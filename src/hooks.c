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

// Get original DLL path and load it
static void load_original_dll(void) {
    char sysPath[MAX_PATH];
    char dllPath[MAX_PATH];

    if (GetSystemDirectoryA(sysPath, MAX_PATH)) {
        snprintf(dllPath, MAX_PATH, "%s\\winmm.dll", sysPath);
        g_hReal = LoadLibraryA(dllPath);
    }

    if (!g_hReal) {
        g_hReal = LoadLibraryA("winmm_orig.dll");
    }

    if (g_hReal) {
        fp_PlaySoundW = (PlaySoundW_t)GetProcAddress(g_hReal, "PlaySoundW");
        fp_PlaySoundA = (PlaySoundA_t)GetProcAddress(g_hReal, "PlaySoundA");
    }
}

// Find pattern in memory
static LPVOID find_pattern(LPBYTE start, SIZE_T size, const BYTE *pattern, const CHAR *mask) {
    SIZE_T patternLen = strlen(mask);

    for (SIZE_T i = 0; i <= size - patternLen; i++) {
        BOOL found = TRUE;
        for (SIZE_T j = 0; j < patternLen; j++) {
            if (mask[j] == 'x' && start[i + j] != pattern[j]) {
                found = FALSE;
                break;
            }
        }
        if (found) {
            return start + i;
        }
    }
    return NULL;
}

// Patch for Navicat 17
static BOOL patch_navicat17(void) {
    HMODULE hNavicat = GetModuleHandle(NULL);
    if (!hNavicat) return FALSE;

    MODULEINFO modInfo;
    if (!GetModuleInformation(GetCurrentProcess(), hNavicat, &modInfo, sizeof(modInfo))) {
        return FALSE;
    }

    LPBYTE baseAddr = (LPBYTE)modInfo.lpBaseOfDll;
    SIZE_T size = modInfo.SizeOfImage;
    BOOL patched = FALSE;

    // Navicat 17 Pattern 1: License check function
    // 48 89 5C 24 08 57 48 83 EC 20 48 8B F9 80 79 08 00
    BYTE pattern1[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0xF9};
    CHAR mask1[] = "xxxxxxxxxxxxx";

    LPVOID addr1 = find_pattern(baseAddr, size, pattern1, mask1);
    if (addr1) {
        DWORD oldProtect;
        // xor eax, eax; inc eax; ret (return TRUE)
        BYTE patch[] = {0x31, 0xC0, 0x48, 0xFF, 0xC0, 0xC3};
        if (VirtualProtect(addr1, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr1, patch, sizeof(patch));
            VirtualProtect(addr1, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr1, sizeof(patch));
            patched = TRUE;
        }
    }

    // Navicat 17 Pattern 2: Trial check bypass
    // 40 53 48 83 EC 20 80 79 08 00 48 8B D9
    BYTE pattern2[] = {0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x80, 0x79, 0x08, 0x00};
    CHAR mask2[] = "xxxxxxxxxx";

    LPVOID addr2 = find_pattern(baseAddr, size, pattern2, mask2);
    if (addr2) {
        DWORD oldProtect;
        // mov eax, 1; ret
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3};
        if (VirtualProtect(addr2, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr2, patch, sizeof(patch));
            VirtualProtect(addr2, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr2, sizeof(patch));
            patched = TRUE;
        }
    }

    // Navicat 17 Pattern 3: IsPremium check
    // 48 89 5C 24 08 57 48 83 EC 20 48 8B 59 10 48 8B F9
    BYTE pattern3[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0x59, 0x10};
    CHAR mask3[] = "xxxxxxxxxxxxxx";

    LPVOID addr3 = find_pattern(baseAddr, size, pattern3, mask3);
    if (addr3) {
        DWORD oldProtect;
        // mov eax, 1; ret
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3};
        if (VirtualProtect(addr3, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr3, patch, sizeof(patch));
            VirtualProtect(addr3, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr3, sizeof(patch));
            patched = TRUE;
        }
    }

    return patched;
}

// Simple log function for debugging
static void log_message(const char* msg) {
    FILE* f = fopen("C:\\temp\\navicat_patch.log", "a");
    if (f) {
        fprintf(f, "%s\n", msg);
        fclose(f);
    }
}

// Thread function for patching Navicat
DWORD WINAPI NavicatPatchThread(LPVOID lpParam) {
    (void)lpParam;

    log_message("Patch thread started");

    // Wait for Navicat to fully initialize
    Sleep(500);

    // Apply patches for Navicat 17
    if (patch_navicat17()) {
        log_message("Patches applied successfully");
    } else {
        log_message("Failed to apply patches");
    }

    return 0;
}

void hooks_init(void) {
    // Load original winmm.dll
    load_original_dll();

    // Load all forwarded function pointers
    load_all_original_functions();

    // Check if we're running in navicat.exe
    wchar_t exePath[MAX_PATH];
    wchar_t exeName[MAX_PATH];

    if (GetModuleFileNameW(NULL, exePath, MAX_PATH)) {
        // Extract filename from path
        wchar_t* filename = wcsrchr(exePath, L'\\');
        if (filename) {
            wcscpy_s(exeName, MAX_PATH, filename + 1);
        } else {
            wcscpy_s(exeName, MAX_PATH, exePath);
        }

        // Check if it's navicat.exe (case insensitive)
        if (_wcsicmp(exeName, L"navicat.exe") == 0) {
            // Create thread to patch Navicat
            HANDLE hThread = CreateThread(NULL, 0, NavicatPatchThread, NULL, 0, NULL);
            if (hThread) {
                CloseHandle(hThread);
            }
        }
    }
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
