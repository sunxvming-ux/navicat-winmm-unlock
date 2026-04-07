#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <psapi.h>
#include "hooks.h"

#pragma comment(lib, "psapi.lib")

// Handle to the real winmm.dll
HMODULE g_hReal = NULL;

// Typedefs for original functions
typedef BOOL (WINAPI *PlaySoundW_t)(LPCWSTR, HMODULE, DWORD);
typedef BOOL (WINAPI *PlaySoundA_t)(LPCSTR, HMODULE, DWORD);

static PlaySoundW_t fp_PlaySoundW = NULL;
static PlaySoundA_t fp_PlaySoundA = NULL;

// Function prototypes for original winmm functions
static void load_original_functions(void);

// Find pattern in memory
static LPVOID find_pattern(LPBYTE start, SIZE_T size, const BYTE *pattern, const CHAR *mask);

// Patch Navicat memory
static BOOL patch_navicat(void);

// Get original DLL path and load it
static void load_original_dll(void) {
    char sysPath[MAX_PATH];
    char dllPath[MAX_PATH];

    if (GetSystemDirectoryA(sysPath, MAX_PATH)) {
        snprintf(dllPath, MAX_PATH, "%s\\winmm.dll", sysPath);
        g_hReal = LoadLibraryA(dllPath);
    }

    if (!g_hReal) {
        // Fallback to current directory
        g_hReal = LoadLibraryA("winmm_orig.dll");
    }

    if (g_hReal) {
        load_original_functions();
    }
}

static void load_original_functions(void) {
    if (!g_hReal) return;

    fp_PlaySoundW = (PlaySoundW_t)GetProcAddress(g_hReal, "PlaySoundW");
    fp_PlaySoundA = (PlaySoundA_t)GetProcAddress(g_hReal, "PlaySoundA");
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

// Patch Navicat - the main unlock logic
static BOOL patch_navicat(void) {
    HMODULE hNavicat = GetModuleHandle(NULL);
    if (!hNavicat) return FALSE;

    // Get module information
    MODULEINFO modInfo;
    if (!GetModuleInformation(GetCurrentProcess(), hNavicat, &modInfo, sizeof(modInfo))) {
        return FALSE;
    }

    LPBYTE baseAddr = (LPBYTE)modInfo.lpBaseOfDll;
    SIZE_T size = modInfo.SizeOfImage;

    // Pattern 1: Navicat 16+ trial check patch
    // This pattern targets the license validation check
    BYTE pattern1[] = {0x48, 0x89, 0x5C, 0x24, 0x08, 0x57, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0xF9};
    CHAR mask1[] = "xxxxxxxxxxxxx";

    LPVOID addr1 = find_pattern(baseAddr, size, pattern1, mask1);
    if (addr1) {
        // Found pattern, apply patch
        DWORD oldProtect;
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3}; // mov eax, 1; ret

        if (VirtualProtect(addr1, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr1, patch, sizeof(patch));
            VirtualProtect(addr1, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr1, sizeof(patch));
        }
    }

    // Pattern 2: License key validation bypass
    BYTE pattern2[] = {0x48, 0x8B, 0xC4, 0x48, 0x89, 0x58, 0x08, 0x48, 0x89, 0x68, 0x10};
    CHAR mask2[] = "xxxxxxxxxxx";

    LPVOID addr2 = find_pattern(baseAddr, size, pattern2, mask2);
    if (addr2) {
        DWORD oldProtect;
        // Patch to always return success
        BYTE patch[] = {0x31, 0xC0, 0x48, 0xFF, 0xC0, 0xC3}; // xor eax, eax; inc rax; ret

        if (VirtualProtect(addr2, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr2, patch, sizeof(patch));
            VirtualProtect(addr2, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr2, sizeof(patch));
        }
    }

    // Pattern 3: Premium feature unlock
    BYTE pattern3[] = {0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x48, 0x8B, 0xD9, 0xE8};
    CHAR mask3[] = "xxxxxxxxxx";

    LPVOID addr3 = find_pattern(baseAddr, size, pattern3, mask3);
    if (addr3) {
        DWORD oldProtect;
        BYTE patch[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3};

        if (VirtualProtect(addr3, sizeof(patch), PAGE_EXECUTE_READWRITE, &oldProtect)) {
            memcpy(addr3, patch, sizeof(patch));
            VirtualProtect(addr3, sizeof(patch), oldProtect, &oldProtect);
            FlushInstructionCache(GetCurrentProcess(), addr3, sizeof(patch));
        }
    }

    return TRUE;
}

// Thread function for patching Navicat
DWORD WINAPI NavicatPatchThread(LPVOID lpParam) {
    (void)lpParam;

    // Wait for Navicat to fully initialize
    Sleep(100);

    // Apply patches
    patch_navicat();

    return 0;
}

void hooks_init(void) {
    // Load original winmm.dll
    load_original_dll();

    // Check if we're running in navicat.exe
    char exePath[MAX_PATH];
    char exeName[MAX_PATH];

    if (GetModuleFileNameA(NULL, exePath, MAX_PATH)) {
        // Extract filename from path
        char* filename = strrchr(exePath, '\\');
        if (filename) {
            strcpy(exeName, filename + 1);
        } else {
            strcpy(exeName, exePath);
        }

        // Check if it's navicat.exe (case insensitive)
        if (_stricmp(exeName, "navicat.exe") == 0) {
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

// ImageBase for GetModuleFileNameW
extern IMAGE_DOS_HEADER __ImageBase;
