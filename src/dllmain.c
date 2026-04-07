#include <windows.h>
#include <stdio.h>
#include "hooks.h"

// Original DLL handle
HMODULE g_hReal = NULL;

// Simple log function
static void log_dllmain(const char* msg) {
    FILE* f = NULL;
    const char* paths[] = {
        "C:\\temp\\navicat_patch.log",
        "C:\\Windows\\Temp\\navicat_patch.log",
        "navicat_patch.log"
    };

    for (int i = 0; i < 3; i++) {
        f = fopen(paths[i], "a");
        if (f) {
            fprintf(f, "[DLLMAIN] %s\n", msg);
            fclose(f);
            return;
        }
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            log_dllmain("=== DLL_PROCESS_ATTACH ===");
            log_dllmain("DisableThreadLibraryCalls...");
            DisableThreadLibraryCalls(hinstDLL);
            log_dllmain("Calling hooks_init...");
            hooks_init();
            log_dllmain("DLL_PROCESS_ATTACH complete");
            break;
        case DLL_PROCESS_DETACH:
            log_dllmain("=== DLL_PROCESS_DETACH ===");
            if (g_hReal) {
                FreeLibrary(g_hReal);
                g_hReal = NULL;
            }
            break;
    }
    return TRUE;
}
