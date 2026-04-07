#pragma once
#include <windows.h>

// Global handle to original winmm.dll
extern HMODULE g_hReal;

// Initialize hooks and load original DLL
void hooks_init(void);

// Thread function for Navicat patching
DWORD WINAPI NavicatPatchThread(LPVOID lpParam);

// Hooked PlaySound functions
BOOL WINAPI PlaySoundW_hook(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);
BOOL WINAPI PlaySoundA_hook(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
