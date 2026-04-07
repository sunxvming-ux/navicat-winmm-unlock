#include <windows.h>
#include "hooks.h"

// Original DLL handle
HMODULE g_hReal = NULL;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hinstDLL);
            hooks_init();
            break;
        case DLL_PROCESS_DETACH:
            if (g_hReal) {
                FreeLibrary(g_hReal);
                g_hReal = NULL;
            }
            break;
    }
    return TRUE;
}
