// Auto-generated forward.c - DO NOT EDIT
#include <windows.h>
#include "hooks.h"

// Function pointer storage
typedef struct { const char* name; FARPROC* ptr; } FuncEntry;

static FARPROC fp_winmm_2 = NULL;
static FARPROC fp_mciExecute = NULL;
static FARPROC fp_CloseDriver = NULL;
static FARPROC fp_DefDriverProc = NULL;
static FARPROC fp_DriverCallback = NULL;
static FARPROC fp_DrvGetModuleHandle = NULL;
static FARPROC fp_GetDriverModuleHandle = NULL;
static FARPROC fp_OpenDriver = NULL;
static FARPROC fp_SendDriverMessage = NULL;
static FARPROC fp_WOWAppExit = NULL;
static FARPROC fp_auxGetDevCapsA = NULL;
static FARPROC fp_auxGetDevCapsW = NULL;
static FARPROC fp_auxGetNumDevs = NULL;
static FARPROC fp_auxGetVolume = NULL;
static FARPROC fp_auxOutMessage = NULL;
static FARPROC fp_auxSetVolume = NULL;
static FARPROC fp_joyConfigChanged = NULL;
static FARPROC fp_joyGetDevCapsA = NULL;
static FARPROC fp_joyGetDevCapsW = NULL;
static FARPROC fp_joyGetNumDevs = NULL;
static FARPROC fp_joyGetPos = NULL;
static FARPROC fp_joyGetPosEx = NULL;
static FARPROC fp_joyGetThreshold = NULL;
static FARPROC fp_joyReleaseCapture = NULL;
static FARPROC fp_joySetCapture = NULL;
static FARPROC fp_joySetThreshold = NULL;
static FARPROC fp_mciDriverNotify = NULL;
static FARPROC fp_mciDriverYield = NULL;
static FARPROC fp_mciFreeCommandResource = NULL;
static FARPROC fp_mciGetCreatorTask = NULL;
static FARPROC fp_mciGetDeviceIDA = NULL;
static FARPROC fp_mciGetDeviceIDFromElementIDA = NULL;
static FARPROC fp_mciGetDeviceIDFromElementIDW = NULL;
static FARPROC fp_mciGetDeviceIDW = NULL;
static FARPROC fp_mciGetDriverData = NULL;
static FARPROC fp_mciGetErrorStringA = NULL;
static FARPROC fp_mciGetErrorStringW = NULL;
static FARPROC fp_mciGetYieldProc = NULL;
static FARPROC fp_mciLoadCommandResource = NULL;
static FARPROC fp_mciSendCommandA = NULL;
static FARPROC fp_mciSendCommandW = NULL;
static FARPROC fp_mciSendStringA = NULL;
static FARPROC fp_mciSendStringW = NULL;
static FARPROC fp_mciSetDriverData = NULL;
static FARPROC fp_mciSetYieldProc = NULL;
static FARPROC fp_midiConnect = NULL;
static FARPROC fp_midiDisconnect = NULL;
static FARPROC fp_midiInAddBuffer = NULL;
static FARPROC fp_midiInClose = NULL;
static FARPROC fp_midiInGetDevCapsA = NULL;
static FARPROC fp_midiInGetDevCapsW = NULL;
static FARPROC fp_midiInGetErrorTextA = NULL;
static FARPROC fp_midiInGetErrorTextW = NULL;
static FARPROC fp_midiInGetID = NULL;
static FARPROC fp_midiInGetNumDevs = NULL;
static FARPROC fp_midiInMessage = NULL;
static FARPROC fp_midiInOpen = NULL;
static FARPROC fp_midiInPrepareHeader = NULL;
static FARPROC fp_midiInReset = NULL;
static FARPROC fp_midiInStart = NULL;
static FARPROC fp_midiInStop = NULL;
static FARPROC fp_midiInUnprepareHeader = NULL;
static FARPROC fp_midiOutCacheDrumPatches = NULL;
static FARPROC fp_midiOutCachePatches = NULL;
static FARPROC fp_midiOutClose = NULL;
static FARPROC fp_midiOutGetDevCapsA = NULL;
static FARPROC fp_midiOutGetDevCapsW = NULL;
static FARPROC fp_midiOutGetErrorTextA = NULL;
static FARPROC fp_midiOutGetErrorTextW = NULL;
static FARPROC fp_midiOutGetID = NULL;
static FARPROC fp_midiOutGetNumDevs = NULL;
static FARPROC fp_midiOutGetVolume = NULL;
static FARPROC fp_midiOutLongMsg = NULL;
static FARPROC fp_midiOutMessage = NULL;
static FARPROC fp_midiOutOpen = NULL;
static FARPROC fp_midiOutPrepareHeader = NULL;
static FARPROC fp_midiOutReset = NULL;
static FARPROC fp_midiOutSetVolume = NULL;
static FARPROC fp_midiOutShortMsg = NULL;
static FARPROC fp_midiOutUnprepareHeader = NULL;
static FARPROC fp_midiStreamClose = NULL;
static FARPROC fp_midiStreamOpen = NULL;
static FARPROC fp_midiStreamOut = NULL;
static FARPROC fp_midiStreamPause = NULL;
static FARPROC fp_midiStreamPosition = NULL;
static FARPROC fp_midiStreamProperty = NULL;
static FARPROC fp_midiStreamRestart = NULL;
static FARPROC fp_midiStreamStop = NULL;
static FARPROC fp_mixerClose = NULL;
static FARPROC fp_mixerGetControlDetailsA = NULL;
static FARPROC fp_mixerGetControlDetailsW = NULL;
static FARPROC fp_mixerGetDevCapsA = NULL;
static FARPROC fp_mixerGetDevCapsW = NULL;
static FARPROC fp_mixerGetID = NULL;
static FARPROC fp_mixerGetLineControlsA = NULL;
static FARPROC fp_mixerGetLineControlsW = NULL;
static FARPROC fp_mixerGetLineInfoA = NULL;
static FARPROC fp_mixerGetLineInfoW = NULL;
static FARPROC fp_mixerGetNumDevs = NULL;
static FARPROC fp_mixerMessage = NULL;
static FARPROC fp_mixerOpen = NULL;
static FARPROC fp_mixerSetControlDetails = NULL;
static FARPROC fp_mmDrvInstall = NULL;
static FARPROC fp_mmGetCurrentTask = NULL;
static FARPROC fp_mmTaskBlock = NULL;
static FARPROC fp_mmTaskCreate = NULL;
static FARPROC fp_mmTaskSignal = NULL;
static FARPROC fp_mmTaskYield = NULL;
static FARPROC fp_mmioAdvance = NULL;
static FARPROC fp_mmioAscend = NULL;
static FARPROC fp_mmioClose = NULL;
static FARPROC fp_mmioCreateChunk = NULL;
static FARPROC fp_mmioDescend = NULL;
static FARPROC fp_mmioFlush = NULL;
static FARPROC fp_mmioGetInfo = NULL;
static FARPROC fp_mmioInstallIOProcA = NULL;
static FARPROC fp_mmioInstallIOProcW = NULL;
static FARPROC fp_mmioOpenA = NULL;
static FARPROC fp_mmioOpenW = NULL;
static FARPROC fp_mmioRead = NULL;
static FARPROC fp_mmioRenameA = NULL;
static FARPROC fp_mmioRenameW = NULL;
static FARPROC fp_mmioSeek = NULL;
static FARPROC fp_mmioSendMessage = NULL;
static FARPROC fp_mmioSetBuffer = NULL;
static FARPROC fp_mmioSetInfo = NULL;
static FARPROC fp_mmioStringToFOURCCA = NULL;
static FARPROC fp_mmioStringToFOURCCW = NULL;
static FARPROC fp_mmioWrite = NULL;
static FARPROC fp_mmsystemGetVersion = NULL;
static FARPROC fp_sndPlaySoundA = NULL;
static FARPROC fp_sndPlaySoundW = NULL;
static FARPROC fp_timeBeginPeriod = NULL;
static FARPROC fp_timeEndPeriod = NULL;
static FARPROC fp_timeGetDevCaps = NULL;
static FARPROC fp_timeGetSystemTime = NULL;
static FARPROC fp_timeGetTime = NULL;
static FARPROC fp_timeKillEvent = NULL;
static FARPROC fp_timeSetEvent = NULL;
static FARPROC fp_waveInAddBuffer = NULL;
static FARPROC fp_waveInClose = NULL;
static FARPROC fp_waveInGetDevCapsA = NULL;
static FARPROC fp_waveInGetDevCapsW = NULL;
static FARPROC fp_waveInGetErrorTextA = NULL;
static FARPROC fp_waveInGetErrorTextW = NULL;
static FARPROC fp_waveInGetID = NULL;
static FARPROC fp_waveInGetNumDevs = NULL;
static FARPROC fp_waveInGetPosition = NULL;
static FARPROC fp_waveInMessage = NULL;
static FARPROC fp_waveInOpen = NULL;
static FARPROC fp_waveInPrepareHeader = NULL;
static FARPROC fp_waveInReset = NULL;
static FARPROC fp_waveInStart = NULL;
static FARPROC fp_waveInStop = NULL;
static FARPROC fp_waveInUnprepareHeader = NULL;
static FARPROC fp_waveOutBreakLoop = NULL;
static FARPROC fp_waveOutClose = NULL;
static FARPROC fp_waveOutGetDevCapsA = NULL;
static FARPROC fp_waveOutGetDevCapsW = NULL;
static FARPROC fp_waveOutGetErrorTextA = NULL;
static FARPROC fp_waveOutGetErrorTextW = NULL;
static FARPROC fp_waveOutGetID = NULL;
static FARPROC fp_waveOutGetNumDevs = NULL;
static FARPROC fp_waveOutGetPitch = NULL;
static FARPROC fp_waveOutGetPlaybackRate = NULL;
static FARPROC fp_waveOutGetPosition = NULL;
static FARPROC fp_waveOutGetVolume = NULL;
static FARPROC fp_waveOutMessage = NULL;
static FARPROC fp_waveOutOpen = NULL;
static FARPROC fp_waveOutPause = NULL;
static FARPROC fp_waveOutPrepareHeader = NULL;
static FARPROC fp_waveOutReset = NULL;
static FARPROC fp_waveOutRestart = NULL;
static FARPROC fp_waveOutSetPitch = NULL;
static FARPROC fp_waveOutSetPlaybackRate = NULL;
static FARPROC fp_waveOutSetVolume = NULL;
static FARPROC fp_waveOutUnprepareHeader = NULL;
static FARPROC fp_waveOutWrite = NULL;

// Get original function pointer
FARPROC GetOriginalProc(const char* name) {
    if (!g_hReal) return NULL;
    return GetProcAddress(g_hReal, name);
}

// Load all original function pointers
void load_all_original_functions(void) {
    if (!g_hReal) return;
    fp_winmm_2 = GetProcAddress(g_hReal, "winmm_2");
    fp_mciExecute = GetProcAddress(g_hReal, "mciExecute");
    fp_CloseDriver = GetProcAddress(g_hReal, "CloseDriver");
    fp_DefDriverProc = GetProcAddress(g_hReal, "DefDriverProc");
    fp_DriverCallback = GetProcAddress(g_hReal, "DriverCallback");
    fp_DrvGetModuleHandle = GetProcAddress(g_hReal, "DrvGetModuleHandle");
    fp_GetDriverModuleHandle = GetProcAddress(g_hReal, "GetDriverModuleHandle");
    fp_OpenDriver = GetProcAddress(g_hReal, "OpenDriver");
    fp_SendDriverMessage = GetProcAddress(g_hReal, "SendDriverMessage");
    fp_WOWAppExit = GetProcAddress(g_hReal, "WOWAppExit");
    fp_auxGetDevCapsA = GetProcAddress(g_hReal, "auxGetDevCapsA");
    fp_auxGetDevCapsW = GetProcAddress(g_hReal, "auxGetDevCapsW");
    fp_auxGetNumDevs = GetProcAddress(g_hReal, "auxGetNumDevs");
    fp_auxGetVolume = GetProcAddress(g_hReal, "auxGetVolume");
    fp_auxOutMessage = GetProcAddress(g_hReal, "auxOutMessage");
    fp_auxSetVolume = GetProcAddress(g_hReal, "auxSetVolume");
    fp_joyConfigChanged = GetProcAddress(g_hReal, "joyConfigChanged");
    fp_joyGetDevCapsA = GetProcAddress(g_hReal, "joyGetDevCapsA");
    fp_joyGetDevCapsW = GetProcAddress(g_hReal, "joyGetDevCapsW");
    fp_joyGetNumDevs = GetProcAddress(g_hReal, "joyGetNumDevs");
    fp_joyGetPos = GetProcAddress(g_hReal, "joyGetPos");
    fp_joyGetPosEx = GetProcAddress(g_hReal, "joyGetPosEx");
    fp_joyGetThreshold = GetProcAddress(g_hReal, "joyGetThreshold");
    fp_joyReleaseCapture = GetProcAddress(g_hReal, "joyReleaseCapture");
    fp_joySetCapture = GetProcAddress(g_hReal, "joySetCapture");
    fp_joySetThreshold = GetProcAddress(g_hReal, "joySetThreshold");
    fp_mciDriverNotify = GetProcAddress(g_hReal, "mciDriverNotify");
    fp_mciDriverYield = GetProcAddress(g_hReal, "mciDriverYield");
    fp_mciFreeCommandResource = GetProcAddress(g_hReal, "mciFreeCommandResource");
    fp_mciGetCreatorTask = GetProcAddress(g_hReal, "mciGetCreatorTask");
    fp_mciGetDeviceIDA = GetProcAddress(g_hReal, "mciGetDeviceIDA");
    fp_mciGetDeviceIDFromElementIDA = GetProcAddress(g_hReal, "mciGetDeviceIDFromElementIDA");
    fp_mciGetDeviceIDFromElementIDW = GetProcAddress(g_hReal, "mciGetDeviceIDFromElementIDW");
    fp_mciGetDeviceIDW = GetProcAddress(g_hReal, "mciGetDeviceIDW");
    fp_mciGetDriverData = GetProcAddress(g_hReal, "mciGetDriverData");
    fp_mciGetErrorStringA = GetProcAddress(g_hReal, "mciGetErrorStringA");
    fp_mciGetErrorStringW = GetProcAddress(g_hReal, "mciGetErrorStringW");
    fp_mciGetYieldProc = GetProcAddress(g_hReal, "mciGetYieldProc");
    fp_mciLoadCommandResource = GetProcAddress(g_hReal, "mciLoadCommandResource");
    fp_mciSendCommandA = GetProcAddress(g_hReal, "mciSendCommandA");
    fp_mciSendCommandW = GetProcAddress(g_hReal, "mciSendCommandW");
    fp_mciSendStringA = GetProcAddress(g_hReal, "mciSendStringA");
    fp_mciSendStringW = GetProcAddress(g_hReal, "mciSendStringW");
    fp_mciSetDriverData = GetProcAddress(g_hReal, "mciSetDriverData");
    fp_mciSetYieldProc = GetProcAddress(g_hReal, "mciSetYieldProc");
    fp_midiConnect = GetProcAddress(g_hReal, "midiConnect");
    fp_midiDisconnect = GetProcAddress(g_hReal, "midiDisconnect");
    fp_midiInAddBuffer = GetProcAddress(g_hReal, "midiInAddBuffer");
    fp_midiInClose = GetProcAddress(g_hReal, "midiInClose");
    fp_midiInGetDevCapsA = GetProcAddress(g_hReal, "midiInGetDevCapsA");
    fp_midiInGetDevCapsW = GetProcAddress(g_hReal, "midiInGetDevCapsW");
    fp_midiInGetErrorTextA = GetProcAddress(g_hReal, "midiInGetErrorTextA");
    fp_midiInGetErrorTextW = GetProcAddress(g_hReal, "midiInGetErrorTextW");
    fp_midiInGetID = GetProcAddress(g_hReal, "midiInGetID");
    fp_midiInGetNumDevs = GetProcAddress(g_hReal, "midiInGetNumDevs");
    fp_midiInMessage = GetProcAddress(g_hReal, "midiInMessage");
    fp_midiInOpen = GetProcAddress(g_hReal, "midiInOpen");
    fp_midiInPrepareHeader = GetProcAddress(g_hReal, "midiInPrepareHeader");
    fp_midiInReset = GetProcAddress(g_hReal, "midiInReset");
    fp_midiInStart = GetProcAddress(g_hReal, "midiInStart");
    fp_midiInStop = GetProcAddress(g_hReal, "midiInStop");
    fp_midiInUnprepareHeader = GetProcAddress(g_hReal, "midiInUnprepareHeader");
    fp_midiOutCacheDrumPatches = GetProcAddress(g_hReal, "midiOutCacheDrumPatches");
    fp_midiOutCachePatches = GetProcAddress(g_hReal, "midiOutCachePatches");
    fp_midiOutClose = GetProcAddress(g_hReal, "midiOutClose");
    fp_midiOutGetDevCapsA = GetProcAddress(g_hReal, "midiOutGetDevCapsA");
    fp_midiOutGetDevCapsW = GetProcAddress(g_hReal, "midiOutGetDevCapsW");
    fp_midiOutGetErrorTextA = GetProcAddress(g_hReal, "midiOutGetErrorTextA");
    fp_midiOutGetErrorTextW = GetProcAddress(g_hReal, "midiOutGetErrorTextW");
    fp_midiOutGetID = GetProcAddress(g_hReal, "midiOutGetID");
    fp_midiOutGetNumDevs = GetProcAddress(g_hReal, "midiOutGetNumDevs");
    fp_midiOutGetVolume = GetProcAddress(g_hReal, "midiOutGetVolume");
    fp_midiOutLongMsg = GetProcAddress(g_hReal, "midiOutLongMsg");
    fp_midiOutMessage = GetProcAddress(g_hReal, "midiOutMessage");
    fp_midiOutOpen = GetProcAddress(g_hReal, "midiOutOpen");
    fp_midiOutPrepareHeader = GetProcAddress(g_hReal, "midiOutPrepareHeader");
    fp_midiOutReset = GetProcAddress(g_hReal, "midiOutReset");
    fp_midiOutSetVolume = GetProcAddress(g_hReal, "midiOutSetVolume");
    fp_midiOutShortMsg = GetProcAddress(g_hReal, "midiOutShortMsg");
    fp_midiOutUnprepareHeader = GetProcAddress(g_hReal, "midiOutUnprepareHeader");
    fp_midiStreamClose = GetProcAddress(g_hReal, "midiStreamClose");
    fp_midiStreamOpen = GetProcAddress(g_hReal, "midiStreamOpen");
    fp_midiStreamOut = GetProcAddress(g_hReal, "midiStreamOut");
    fp_midiStreamPause = GetProcAddress(g_hReal, "midiStreamPause");
    fp_midiStreamPosition = GetProcAddress(g_hReal, "midiStreamPosition");
    fp_midiStreamProperty = GetProcAddress(g_hReal, "midiStreamProperty");
    fp_midiStreamRestart = GetProcAddress(g_hReal, "midiStreamRestart");
    fp_midiStreamStop = GetProcAddress(g_hReal, "midiStreamStop");
    fp_mixerClose = GetProcAddress(g_hReal, "mixerClose");
    fp_mixerGetControlDetailsA = GetProcAddress(g_hReal, "mixerGetControlDetailsA");
    fp_mixerGetControlDetailsW = GetProcAddress(g_hReal, "mixerGetControlDetailsW");
    fp_mixerGetDevCapsA = GetProcAddress(g_hReal, "mixerGetDevCapsA");
    fp_mixerGetDevCapsW = GetProcAddress(g_hReal, "mixerGetDevCapsW");
    fp_mixerGetID = GetProcAddress(g_hReal, "mixerGetID");
    fp_mixerGetLineControlsA = GetProcAddress(g_hReal, "mixerGetLineControlsA");
    fp_mixerGetLineControlsW = GetProcAddress(g_hReal, "mixerGetLineControlsW");
    fp_mixerGetLineInfoA = GetProcAddress(g_hReal, "mixerGetLineInfoA");
    fp_mixerGetLineInfoW = GetProcAddress(g_hReal, "mixerGetLineInfoW");
    fp_mixerGetNumDevs = GetProcAddress(g_hReal, "mixerGetNumDevs");
    fp_mixerMessage = GetProcAddress(g_hReal, "mixerMessage");
    fp_mixerOpen = GetProcAddress(g_hReal, "mixerOpen");
    fp_mixerSetControlDetails = GetProcAddress(g_hReal, "mixerSetControlDetails");
    fp_mmDrvInstall = GetProcAddress(g_hReal, "mmDrvInstall");
    fp_mmGetCurrentTask = GetProcAddress(g_hReal, "mmGetCurrentTask");
    fp_mmTaskBlock = GetProcAddress(g_hReal, "mmTaskBlock");
    fp_mmTaskCreate = GetProcAddress(g_hReal, "mmTaskCreate");
    fp_mmTaskSignal = GetProcAddress(g_hReal, "mmTaskSignal");
    fp_mmTaskYield = GetProcAddress(g_hReal, "mmTaskYield");
    fp_mmioAdvance = GetProcAddress(g_hReal, "mmioAdvance");
    fp_mmioAscend = GetProcAddress(g_hReal, "mmioAscend");
    fp_mmioClose = GetProcAddress(g_hReal, "mmioClose");
    fp_mmioCreateChunk = GetProcAddress(g_hReal, "mmioCreateChunk");
    fp_mmioDescend = GetProcAddress(g_hReal, "mmioDescend");
    fp_mmioFlush = GetProcAddress(g_hReal, "mmioFlush");
    fp_mmioGetInfo = GetProcAddress(g_hReal, "mmioGetInfo");
    fp_mmioInstallIOProcA = GetProcAddress(g_hReal, "mmioInstallIOProcA");
    fp_mmioInstallIOProcW = GetProcAddress(g_hReal, "mmioInstallIOProcW");
    fp_mmioOpenA = GetProcAddress(g_hReal, "mmioOpenA");
    fp_mmioOpenW = GetProcAddress(g_hReal, "mmioOpenW");
    fp_mmioRead = GetProcAddress(g_hReal, "mmioRead");
    fp_mmioRenameA = GetProcAddress(g_hReal, "mmioRenameA");
    fp_mmioRenameW = GetProcAddress(g_hReal, "mmioRenameW");
    fp_mmioSeek = GetProcAddress(g_hReal, "mmioSeek");
    fp_mmioSendMessage = GetProcAddress(g_hReal, "mmioSendMessage");
    fp_mmioSetBuffer = GetProcAddress(g_hReal, "mmioSetBuffer");
    fp_mmioSetInfo = GetProcAddress(g_hReal, "mmioSetInfo");
    fp_mmioStringToFOURCCA = GetProcAddress(g_hReal, "mmioStringToFOURCCA");
    fp_mmioStringToFOURCCW = GetProcAddress(g_hReal, "mmioStringToFOURCCW");
    fp_mmioWrite = GetProcAddress(g_hReal, "mmioWrite");
    fp_mmsystemGetVersion = GetProcAddress(g_hReal, "mmsystemGetVersion");
    fp_sndPlaySoundA = GetProcAddress(g_hReal, "sndPlaySoundA");
    fp_sndPlaySoundW = GetProcAddress(g_hReal, "sndPlaySoundW");
    fp_timeBeginPeriod = GetProcAddress(g_hReal, "timeBeginPeriod");
    fp_timeEndPeriod = GetProcAddress(g_hReal, "timeEndPeriod");
    fp_timeGetDevCaps = GetProcAddress(g_hReal, "timeGetDevCaps");
    fp_timeGetSystemTime = GetProcAddress(g_hReal, "timeGetSystemTime");
    fp_timeGetTime = GetProcAddress(g_hReal, "timeGetTime");
    fp_timeKillEvent = GetProcAddress(g_hReal, "timeKillEvent");
    fp_timeSetEvent = GetProcAddress(g_hReal, "timeSetEvent");
    fp_waveInAddBuffer = GetProcAddress(g_hReal, "waveInAddBuffer");
    fp_waveInClose = GetProcAddress(g_hReal, "waveInClose");
    fp_waveInGetDevCapsA = GetProcAddress(g_hReal, "waveInGetDevCapsA");
    fp_waveInGetDevCapsW = GetProcAddress(g_hReal, "waveInGetDevCapsW");
    fp_waveInGetErrorTextA = GetProcAddress(g_hReal, "waveInGetErrorTextA");
    fp_waveInGetErrorTextW = GetProcAddress(g_hReal, "waveInGetErrorTextW");
    fp_waveInGetID = GetProcAddress(g_hReal, "waveInGetID");
    fp_waveInGetNumDevs = GetProcAddress(g_hReal, "waveInGetNumDevs");
    fp_waveInGetPosition = GetProcAddress(g_hReal, "waveInGetPosition");
    fp_waveInMessage = GetProcAddress(g_hReal, "waveInMessage");
    fp_waveInOpen = GetProcAddress(g_hReal, "waveInOpen");
    fp_waveInPrepareHeader = GetProcAddress(g_hReal, "waveInPrepareHeader");
    fp_waveInReset = GetProcAddress(g_hReal, "waveInReset");
    fp_waveInStart = GetProcAddress(g_hReal, "waveInStart");
    fp_waveInStop = GetProcAddress(g_hReal, "waveInStop");
    fp_waveInUnprepareHeader = GetProcAddress(g_hReal, "waveInUnprepareHeader");
    fp_waveOutBreakLoop = GetProcAddress(g_hReal, "waveOutBreakLoop");
    fp_waveOutClose = GetProcAddress(g_hReal, "waveOutClose");
    fp_waveOutGetDevCapsA = GetProcAddress(g_hReal, "waveOutGetDevCapsA");
    fp_waveOutGetDevCapsW = GetProcAddress(g_hReal, "waveOutGetDevCapsW");
    fp_waveOutGetErrorTextA = GetProcAddress(g_hReal, "waveOutGetErrorTextA");
    fp_waveOutGetErrorTextW = GetProcAddress(g_hReal, "waveOutGetErrorTextW");
    fp_waveOutGetID = GetProcAddress(g_hReal, "waveOutGetID");
    fp_waveOutGetNumDevs = GetProcAddress(g_hReal, "waveOutGetNumDevs");
    fp_waveOutGetPitch = GetProcAddress(g_hReal, "waveOutGetPitch");
    fp_waveOutGetPlaybackRate = GetProcAddress(g_hReal, "waveOutGetPlaybackRate");
    fp_waveOutGetPosition = GetProcAddress(g_hReal, "waveOutGetPosition");
    fp_waveOutGetVolume = GetProcAddress(g_hReal, "waveOutGetVolume");
    fp_waveOutMessage = GetProcAddress(g_hReal, "waveOutMessage");
    fp_waveOutOpen = GetProcAddress(g_hReal, "waveOutOpen");
    fp_waveOutPause = GetProcAddress(g_hReal, "waveOutPause");
    fp_waveOutPrepareHeader = GetProcAddress(g_hReal, "waveOutPrepareHeader");
    fp_waveOutReset = GetProcAddress(g_hReal, "waveOutReset");
    fp_waveOutRestart = GetProcAddress(g_hReal, "waveOutRestart");
    fp_waveOutSetPitch = GetProcAddress(g_hReal, "waveOutSetPitch");
    fp_waveOutSetPlaybackRate = GetProcAddress(g_hReal, "waveOutSetPlaybackRate");
    fp_waveOutSetVolume = GetProcAddress(g_hReal, "waveOutSetVolume");
    fp_waveOutUnprepareHeader = GetProcAddress(g_hReal, "waveOutUnprepareHeader");
    fp_waveOutWrite = GetProcAddress(g_hReal, "waveOutWrite");
}

// Forward winmm_2
__declspec(dllexport) void __stdcall winmm_2() {
    if (fp_winmm_2) {
        ((void (__stdcall*)())fp_winmm_2)();
    }
}

// Forward mciExecute
__declspec(dllexport) void __stdcall mciExecute() {
    if (fp_mciExecute) {
        ((void (__stdcall*)())fp_mciExecute)();
    }
}

// Forward CloseDriver
__declspec(dllexport) void __stdcall CloseDriver() {
    if (fp_CloseDriver) {
        ((void (__stdcall*)())fp_CloseDriver)();
    }
}

// Forward DefDriverProc
__declspec(dllexport) void __stdcall DefDriverProc() {
    if (fp_DefDriverProc) {
        ((void (__stdcall*)())fp_DefDriverProc)();
    }
}

// Forward DriverCallback
__declspec(dllexport) void __stdcall DriverCallback() {
    if (fp_DriverCallback) {
        ((void (__stdcall*)())fp_DriverCallback)();
    }
}

// Forward DrvGetModuleHandle
__declspec(dllexport) void __stdcall DrvGetModuleHandle() {
    if (fp_DrvGetModuleHandle) {
        ((void (__stdcall*)())fp_DrvGetModuleHandle)();
    }
}

// Forward GetDriverModuleHandle
__declspec(dllexport) void __stdcall GetDriverModuleHandle() {
    if (fp_GetDriverModuleHandle) {
        ((void (__stdcall*)())fp_GetDriverModuleHandle)();
    }
}

// Forward OpenDriver
__declspec(dllexport) void __stdcall OpenDriver() {
    if (fp_OpenDriver) {
        ((void (__stdcall*)())fp_OpenDriver)();
    }
}

// Forward SendDriverMessage
__declspec(dllexport) void __stdcall SendDriverMessage() {
    if (fp_SendDriverMessage) {
        ((void (__stdcall*)())fp_SendDriverMessage)();
    }
}

// Forward WOWAppExit
__declspec(dllexport) void __stdcall WOWAppExit() {
    if (fp_WOWAppExit) {
        ((void (__stdcall*)())fp_WOWAppExit)();
    }
}

// Forward auxGetDevCapsA
__declspec(dllexport) void __stdcall auxGetDevCapsA() {
    if (fp_auxGetDevCapsA) {
        ((void (__stdcall*)())fp_auxGetDevCapsA)();
    }
}

// Forward auxGetDevCapsW
__declspec(dllexport) void __stdcall auxGetDevCapsW() {
    if (fp_auxGetDevCapsW) {
        ((void (__stdcall*)())fp_auxGetDevCapsW)();
    }
}

// Forward auxGetNumDevs
__declspec(dllexport) void __stdcall auxGetNumDevs() {
    if (fp_auxGetNumDevs) {
        ((void (__stdcall*)())fp_auxGetNumDevs)();
    }
}

// Forward auxGetVolume
__declspec(dllexport) void __stdcall auxGetVolume() {
    if (fp_auxGetVolume) {
        ((void (__stdcall*)())fp_auxGetVolume)();
    }
}

// Forward auxOutMessage
__declspec(dllexport) void __stdcall auxOutMessage() {
    if (fp_auxOutMessage) {
        ((void (__stdcall*)())fp_auxOutMessage)();
    }
}

// Forward auxSetVolume
__declspec(dllexport) void __stdcall auxSetVolume() {
    if (fp_auxSetVolume) {
        ((void (__stdcall*)())fp_auxSetVolume)();
    }
}

// Forward joyConfigChanged
__declspec(dllexport) void __stdcall joyConfigChanged() {
    if (fp_joyConfigChanged) {
        ((void (__stdcall*)())fp_joyConfigChanged)();
    }
}

// Forward joyGetDevCapsA
__declspec(dllexport) void __stdcall joyGetDevCapsA() {
    if (fp_joyGetDevCapsA) {
        ((void (__stdcall*)())fp_joyGetDevCapsA)();
    }
}

// Forward joyGetDevCapsW
__declspec(dllexport) void __stdcall joyGetDevCapsW() {
    if (fp_joyGetDevCapsW) {
        ((void (__stdcall*)())fp_joyGetDevCapsW)();
    }
}

// Forward joyGetNumDevs
__declspec(dllexport) void __stdcall joyGetNumDevs() {
    if (fp_joyGetNumDevs) {
        ((void (__stdcall*)())fp_joyGetNumDevs)();
    }
}

// Forward joyGetPos
__declspec(dllexport) void __stdcall joyGetPos() {
    if (fp_joyGetPos) {
        ((void (__stdcall*)())fp_joyGetPos)();
    }
}

// Forward joyGetPosEx
__declspec(dllexport) void __stdcall joyGetPosEx() {
    if (fp_joyGetPosEx) {
        ((void (__stdcall*)())fp_joyGetPosEx)();
    }
}

// Forward joyGetThreshold
__declspec(dllexport) void __stdcall joyGetThreshold() {
    if (fp_joyGetThreshold) {
        ((void (__stdcall*)())fp_joyGetThreshold)();
    }
}

// Forward joyReleaseCapture
__declspec(dllexport) void __stdcall joyReleaseCapture() {
    if (fp_joyReleaseCapture) {
        ((void (__stdcall*)())fp_joyReleaseCapture)();
    }
}

// Forward joySetCapture
__declspec(dllexport) void __stdcall joySetCapture() {
    if (fp_joySetCapture) {
        ((void (__stdcall*)())fp_joySetCapture)();
    }
}

// Forward joySetThreshold
__declspec(dllexport) void __stdcall joySetThreshold() {
    if (fp_joySetThreshold) {
        ((void (__stdcall*)())fp_joySetThreshold)();
    }
}

// Forward mciDriverNotify
__declspec(dllexport) void __stdcall mciDriverNotify() {
    if (fp_mciDriverNotify) {
        ((void (__stdcall*)())fp_mciDriverNotify)();
    }
}

// Forward mciDriverYield
__declspec(dllexport) void __stdcall mciDriverYield() {
    if (fp_mciDriverYield) {
        ((void (__stdcall*)())fp_mciDriverYield)();
    }
}

// Forward mciFreeCommandResource
__declspec(dllexport) void __stdcall mciFreeCommandResource() {
    if (fp_mciFreeCommandResource) {
        ((void (__stdcall*)())fp_mciFreeCommandResource)();
    }
}

// Forward mciGetCreatorTask
__declspec(dllexport) void __stdcall mciGetCreatorTask() {
    if (fp_mciGetCreatorTask) {
        ((void (__stdcall*)())fp_mciGetCreatorTask)();
    }
}

// Forward mciGetDeviceIDA
__declspec(dllexport) void __stdcall mciGetDeviceIDA() {
    if (fp_mciGetDeviceIDA) {
        ((void (__stdcall*)())fp_mciGetDeviceIDA)();
    }
}

// Forward mciGetDeviceIDFromElementIDA
__declspec(dllexport) void __stdcall mciGetDeviceIDFromElementIDA() {
    if (fp_mciGetDeviceIDFromElementIDA) {
        ((void (__stdcall*)())fp_mciGetDeviceIDFromElementIDA)();
    }
}

// Forward mciGetDeviceIDFromElementIDW
__declspec(dllexport) void __stdcall mciGetDeviceIDFromElementIDW() {
    if (fp_mciGetDeviceIDFromElementIDW) {
        ((void (__stdcall*)())fp_mciGetDeviceIDFromElementIDW)();
    }
}

// Forward mciGetDeviceIDW
__declspec(dllexport) void __stdcall mciGetDeviceIDW() {
    if (fp_mciGetDeviceIDW) {
        ((void (__stdcall*)())fp_mciGetDeviceIDW)();
    }
}

// Forward mciGetDriverData
__declspec(dllexport) void __stdcall mciGetDriverData() {
    if (fp_mciGetDriverData) {
        ((void (__stdcall*)())fp_mciGetDriverData)();
    }
}

// Forward mciGetErrorStringA
__declspec(dllexport) void __stdcall mciGetErrorStringA() {
    if (fp_mciGetErrorStringA) {
        ((void (__stdcall*)())fp_mciGetErrorStringA)();
    }
}

// Forward mciGetErrorStringW
__declspec(dllexport) void __stdcall mciGetErrorStringW() {
    if (fp_mciGetErrorStringW) {
        ((void (__stdcall*)())fp_mciGetErrorStringW)();
    }
}

// Forward mciGetYieldProc
__declspec(dllexport) void __stdcall mciGetYieldProc() {
    if (fp_mciGetYieldProc) {
        ((void (__stdcall*)())fp_mciGetYieldProc)();
    }
}

// Forward mciLoadCommandResource
__declspec(dllexport) void __stdcall mciLoadCommandResource() {
    if (fp_mciLoadCommandResource) {
        ((void (__stdcall*)())fp_mciLoadCommandResource)();
    }
}

// Forward mciSendCommandA
__declspec(dllexport) void __stdcall mciSendCommandA() {
    if (fp_mciSendCommandA) {
        ((void (__stdcall*)())fp_mciSendCommandA)();
    }
}

// Forward mciSendCommandW
__declspec(dllexport) void __stdcall mciSendCommandW() {
    if (fp_mciSendCommandW) {
        ((void (__stdcall*)())fp_mciSendCommandW)();
    }
}

// Forward mciSendStringA
__declspec(dllexport) void __stdcall mciSendStringA() {
    if (fp_mciSendStringA) {
        ((void (__stdcall*)())fp_mciSendStringA)();
    }
}

// Forward mciSendStringW
__declspec(dllexport) void __stdcall mciSendStringW() {
    if (fp_mciSendStringW) {
        ((void (__stdcall*)())fp_mciSendStringW)();
    }
}

// Forward mciSetDriverData
__declspec(dllexport) void __stdcall mciSetDriverData() {
    if (fp_mciSetDriverData) {
        ((void (__stdcall*)())fp_mciSetDriverData)();
    }
}

// Forward mciSetYieldProc
__declspec(dllexport) void __stdcall mciSetYieldProc() {
    if (fp_mciSetYieldProc) {
        ((void (__stdcall*)())fp_mciSetYieldProc)();
    }
}

// Forward midiConnect
__declspec(dllexport) void __stdcall midiConnect() {
    if (fp_midiConnect) {
        ((void (__stdcall*)())fp_midiConnect)();
    }
}

// Forward midiDisconnect
__declspec(dllexport) void __stdcall midiDisconnect() {
    if (fp_midiDisconnect) {
        ((void (__stdcall*)())fp_midiDisconnect)();
    }
}

// Forward midiInAddBuffer
__declspec(dllexport) void __stdcall midiInAddBuffer() {
    if (fp_midiInAddBuffer) {
        ((void (__stdcall*)())fp_midiInAddBuffer)();
    }
}

// Forward midiInClose
__declspec(dllexport) void __stdcall midiInClose() {
    if (fp_midiInClose) {
        ((void (__stdcall*)())fp_midiInClose)();
    }
}

// Forward midiInGetDevCapsA
__declspec(dllexport) void __stdcall midiInGetDevCapsA() {
    if (fp_midiInGetDevCapsA) {
        ((void (__stdcall*)())fp_midiInGetDevCapsA)();
    }
}

// Forward midiInGetDevCapsW
__declspec(dllexport) void __stdcall midiInGetDevCapsW() {
    if (fp_midiInGetDevCapsW) {
        ((void (__stdcall*)())fp_midiInGetDevCapsW)();
    }
}

// Forward midiInGetErrorTextA
__declspec(dllexport) void __stdcall midiInGetErrorTextA() {
    if (fp_midiInGetErrorTextA) {
        ((void (__stdcall*)())fp_midiInGetErrorTextA)();
    }
}

// Forward midiInGetErrorTextW
__declspec(dllexport) void __stdcall midiInGetErrorTextW() {
    if (fp_midiInGetErrorTextW) {
        ((void (__stdcall*)())fp_midiInGetErrorTextW)();
    }
}

// Forward midiInGetID
__declspec(dllexport) void __stdcall midiInGetID() {
    if (fp_midiInGetID) {
        ((void (__stdcall*)())fp_midiInGetID)();
    }
}

// Forward midiInGetNumDevs
__declspec(dllexport) void __stdcall midiInGetNumDevs() {
    if (fp_midiInGetNumDevs) {
        ((void (__stdcall*)())fp_midiInGetNumDevs)();
    }
}

// Forward midiInMessage
__declspec(dllexport) void __stdcall midiInMessage() {
    if (fp_midiInMessage) {
        ((void (__stdcall*)())fp_midiInMessage)();
    }
}

// Forward midiInOpen
__declspec(dllexport) void __stdcall midiInOpen() {
    if (fp_midiInOpen) {
        ((void (__stdcall*)())fp_midiInOpen)();
    }
}

// Forward midiInPrepareHeader
__declspec(dllexport) void __stdcall midiInPrepareHeader() {
    if (fp_midiInPrepareHeader) {
        ((void (__stdcall*)())fp_midiInPrepareHeader)();
    }
}

// Forward midiInReset
__declspec(dllexport) void __stdcall midiInReset() {
    if (fp_midiInReset) {
        ((void (__stdcall*)())fp_midiInReset)();
    }
}

// Forward midiInStart
__declspec(dllexport) void __stdcall midiInStart() {
    if (fp_midiInStart) {
        ((void (__stdcall*)())fp_midiInStart)();
    }
}

// Forward midiInStop
__declspec(dllexport) void __stdcall midiInStop() {
    if (fp_midiInStop) {
        ((void (__stdcall*)())fp_midiInStop)();
    }
}

// Forward midiInUnprepareHeader
__declspec(dllexport) void __stdcall midiInUnprepareHeader() {
    if (fp_midiInUnprepareHeader) {
        ((void (__stdcall*)())fp_midiInUnprepareHeader)();
    }
}

// Forward midiOutCacheDrumPatches
__declspec(dllexport) void __stdcall midiOutCacheDrumPatches() {
    if (fp_midiOutCacheDrumPatches) {
        ((void (__stdcall*)())fp_midiOutCacheDrumPatches)();
    }
}

// Forward midiOutCachePatches
__declspec(dllexport) void __stdcall midiOutCachePatches() {
    if (fp_midiOutCachePatches) {
        ((void (__stdcall*)())fp_midiOutCachePatches)();
    }
}

// Forward midiOutClose
__declspec(dllexport) void __stdcall midiOutClose() {
    if (fp_midiOutClose) {
        ((void (__stdcall*)())fp_midiOutClose)();
    }
}

// Forward midiOutGetDevCapsA
__declspec(dllexport) void __stdcall midiOutGetDevCapsA() {
    if (fp_midiOutGetDevCapsA) {
        ((void (__stdcall*)())fp_midiOutGetDevCapsA)();
    }
}

// Forward midiOutGetDevCapsW
__declspec(dllexport) void __stdcall midiOutGetDevCapsW() {
    if (fp_midiOutGetDevCapsW) {
        ((void (__stdcall*)())fp_midiOutGetDevCapsW)();
    }
}

// Forward midiOutGetErrorTextA
__declspec(dllexport) void __stdcall midiOutGetErrorTextA() {
    if (fp_midiOutGetErrorTextA) {
        ((void (__stdcall*)())fp_midiOutGetErrorTextA)();
    }
}

// Forward midiOutGetErrorTextW
__declspec(dllexport) void __stdcall midiOutGetErrorTextW() {
    if (fp_midiOutGetErrorTextW) {
        ((void (__stdcall*)())fp_midiOutGetErrorTextW)();
    }
}

// Forward midiOutGetID
__declspec(dllexport) void __stdcall midiOutGetID() {
    if (fp_midiOutGetID) {
        ((void (__stdcall*)())fp_midiOutGetID)();
    }
}

// Forward midiOutGetNumDevs
__declspec(dllexport) void __stdcall midiOutGetNumDevs() {
    if (fp_midiOutGetNumDevs) {
        ((void (__stdcall*)())fp_midiOutGetNumDevs)();
    }
}

// Forward midiOutGetVolume
__declspec(dllexport) void __stdcall midiOutGetVolume() {
    if (fp_midiOutGetVolume) {
        ((void (__stdcall*)())fp_midiOutGetVolume)();
    }
}

// Forward midiOutLongMsg
__declspec(dllexport) void __stdcall midiOutLongMsg() {
    if (fp_midiOutLongMsg) {
        ((void (__stdcall*)())fp_midiOutLongMsg)();
    }
}

// Forward midiOutMessage
__declspec(dllexport) void __stdcall midiOutMessage() {
    if (fp_midiOutMessage) {
        ((void (__stdcall*)())fp_midiOutMessage)();
    }
}

// Forward midiOutOpen
__declspec(dllexport) void __stdcall midiOutOpen() {
    if (fp_midiOutOpen) {
        ((void (__stdcall*)())fp_midiOutOpen)();
    }
}

// Forward midiOutPrepareHeader
__declspec(dllexport) void __stdcall midiOutPrepareHeader() {
    if (fp_midiOutPrepareHeader) {
        ((void (__stdcall*)())fp_midiOutPrepareHeader)();
    }
}

// Forward midiOutReset
__declspec(dllexport) void __stdcall midiOutReset() {
    if (fp_midiOutReset) {
        ((void (__stdcall*)())fp_midiOutReset)();
    }
}

// Forward midiOutSetVolume
__declspec(dllexport) void __stdcall midiOutSetVolume() {
    if (fp_midiOutSetVolume) {
        ((void (__stdcall*)())fp_midiOutSetVolume)();
    }
}

// Forward midiOutShortMsg
__declspec(dllexport) void __stdcall midiOutShortMsg() {
    if (fp_midiOutShortMsg) {
        ((void (__stdcall*)())fp_midiOutShortMsg)();
    }
}

// Forward midiOutUnprepareHeader
__declspec(dllexport) void __stdcall midiOutUnprepareHeader() {
    if (fp_midiOutUnprepareHeader) {
        ((void (__stdcall*)())fp_midiOutUnprepareHeader)();
    }
}

// Forward midiStreamClose
__declspec(dllexport) void __stdcall midiStreamClose() {
    if (fp_midiStreamClose) {
        ((void (__stdcall*)())fp_midiStreamClose)();
    }
}

// Forward midiStreamOpen
__declspec(dllexport) void __stdcall midiStreamOpen() {
    if (fp_midiStreamOpen) {
        ((void (__stdcall*)())fp_midiStreamOpen)();
    }
}

// Forward midiStreamOut
__declspec(dllexport) void __stdcall midiStreamOut() {
    if (fp_midiStreamOut) {
        ((void (__stdcall*)())fp_midiStreamOut)();
    }
}

// Forward midiStreamPause
__declspec(dllexport) void __stdcall midiStreamPause() {
    if (fp_midiStreamPause) {
        ((void (__stdcall*)())fp_midiStreamPause)();
    }
}

// Forward midiStreamPosition
__declspec(dllexport) void __stdcall midiStreamPosition() {
    if (fp_midiStreamPosition) {
        ((void (__stdcall*)())fp_midiStreamPosition)();
    }
}

// Forward midiStreamProperty
__declspec(dllexport) void __stdcall midiStreamProperty() {
    if (fp_midiStreamProperty) {
        ((void (__stdcall*)())fp_midiStreamProperty)();
    }
}

// Forward midiStreamRestart
__declspec(dllexport) void __stdcall midiStreamRestart() {
    if (fp_midiStreamRestart) {
        ((void (__stdcall*)())fp_midiStreamRestart)();
    }
}

// Forward midiStreamStop
__declspec(dllexport) void __stdcall midiStreamStop() {
    if (fp_midiStreamStop) {
        ((void (__stdcall*)())fp_midiStreamStop)();
    }
}

// Forward mixerClose
__declspec(dllexport) void __stdcall mixerClose() {
    if (fp_mixerClose) {
        ((void (__stdcall*)())fp_mixerClose)();
    }
}

// Forward mixerGetControlDetailsA
__declspec(dllexport) void __stdcall mixerGetControlDetailsA() {
    if (fp_mixerGetControlDetailsA) {
        ((void (__stdcall*)())fp_mixerGetControlDetailsA)();
    }
}

// Forward mixerGetControlDetailsW
__declspec(dllexport) void __stdcall mixerGetControlDetailsW() {
    if (fp_mixerGetControlDetailsW) {
        ((void (__stdcall*)())fp_mixerGetControlDetailsW)();
    }
}

// Forward mixerGetDevCapsA
__declspec(dllexport) void __stdcall mixerGetDevCapsA() {
    if (fp_mixerGetDevCapsA) {
        ((void (__stdcall*)())fp_mixerGetDevCapsA)();
    }
}

// Forward mixerGetDevCapsW
__declspec(dllexport) void __stdcall mixerGetDevCapsW() {
    if (fp_mixerGetDevCapsW) {
        ((void (__stdcall*)())fp_mixerGetDevCapsW)();
    }
}

// Forward mixerGetID
__declspec(dllexport) void __stdcall mixerGetID() {
    if (fp_mixerGetID) {
        ((void (__stdcall*)())fp_mixerGetID)();
    }
}

// Forward mixerGetLineControlsA
__declspec(dllexport) void __stdcall mixerGetLineControlsA() {
    if (fp_mixerGetLineControlsA) {
        ((void (__stdcall*)())fp_mixerGetLineControlsA)();
    }
}

// Forward mixerGetLineControlsW
__declspec(dllexport) void __stdcall mixerGetLineControlsW() {
    if (fp_mixerGetLineControlsW) {
        ((void (__stdcall*)())fp_mixerGetLineControlsW)();
    }
}

// Forward mixerGetLineInfoA
__declspec(dllexport) void __stdcall mixerGetLineInfoA() {
    if (fp_mixerGetLineInfoA) {
        ((void (__stdcall*)())fp_mixerGetLineInfoA)();
    }
}

// Forward mixerGetLineInfoW
__declspec(dllexport) void __stdcall mixerGetLineInfoW() {
    if (fp_mixerGetLineInfoW) {
        ((void (__stdcall*)())fp_mixerGetLineInfoW)();
    }
}

// Forward mixerGetNumDevs
__declspec(dllexport) void __stdcall mixerGetNumDevs() {
    if (fp_mixerGetNumDevs) {
        ((void (__stdcall*)())fp_mixerGetNumDevs)();
    }
}

// Forward mixerMessage
__declspec(dllexport) void __stdcall mixerMessage() {
    if (fp_mixerMessage) {
        ((void (__stdcall*)())fp_mixerMessage)();
    }
}

// Forward mixerOpen
__declspec(dllexport) void __stdcall mixerOpen() {
    if (fp_mixerOpen) {
        ((void (__stdcall*)())fp_mixerOpen)();
    }
}

// Forward mixerSetControlDetails
__declspec(dllexport) void __stdcall mixerSetControlDetails() {
    if (fp_mixerSetControlDetails) {
        ((void (__stdcall*)())fp_mixerSetControlDetails)();
    }
}

// Forward mmDrvInstall
__declspec(dllexport) void __stdcall mmDrvInstall() {
    if (fp_mmDrvInstall) {
        ((void (__stdcall*)())fp_mmDrvInstall)();
    }
}

// Forward mmGetCurrentTask
__declspec(dllexport) void __stdcall mmGetCurrentTask() {
    if (fp_mmGetCurrentTask) {
        ((void (__stdcall*)())fp_mmGetCurrentTask)();
    }
}

// Forward mmTaskBlock
__declspec(dllexport) void __stdcall mmTaskBlock() {
    if (fp_mmTaskBlock) {
        ((void (__stdcall*)())fp_mmTaskBlock)();
    }
}

// Forward mmTaskCreate
__declspec(dllexport) void __stdcall mmTaskCreate() {
    if (fp_mmTaskCreate) {
        ((void (__stdcall*)())fp_mmTaskCreate)();
    }
}

// Forward mmTaskSignal
__declspec(dllexport) void __stdcall mmTaskSignal() {
    if (fp_mmTaskSignal) {
        ((void (__stdcall*)())fp_mmTaskSignal)();
    }
}

// Forward mmTaskYield
__declspec(dllexport) void __stdcall mmTaskYield() {
    if (fp_mmTaskYield) {
        ((void (__stdcall*)())fp_mmTaskYield)();
    }
}

// Forward mmioAdvance
__declspec(dllexport) void __stdcall mmioAdvance() {
    if (fp_mmioAdvance) {
        ((void (__stdcall*)())fp_mmioAdvance)();
    }
}

// Forward mmioAscend
__declspec(dllexport) void __stdcall mmioAscend() {
    if (fp_mmioAscend) {
        ((void (__stdcall*)())fp_mmioAscend)();
    }
}

// Forward mmioClose
__declspec(dllexport) void __stdcall mmioClose() {
    if (fp_mmioClose) {
        ((void (__stdcall*)())fp_mmioClose)();
    }
}

// Forward mmioCreateChunk
__declspec(dllexport) void __stdcall mmioCreateChunk() {
    if (fp_mmioCreateChunk) {
        ((void (__stdcall*)())fp_mmioCreateChunk)();
    }
}

// Forward mmioDescend
__declspec(dllexport) void __stdcall mmioDescend() {
    if (fp_mmioDescend) {
        ((void (__stdcall*)())fp_mmioDescend)();
    }
}

// Forward mmioFlush
__declspec(dllexport) void __stdcall mmioFlush() {
    if (fp_mmioFlush) {
        ((void (__stdcall*)())fp_mmioFlush)();
    }
}

// Forward mmioGetInfo
__declspec(dllexport) void __stdcall mmioGetInfo() {
    if (fp_mmioGetInfo) {
        ((void (__stdcall*)())fp_mmioGetInfo)();
    }
}

// Forward mmioInstallIOProcA
__declspec(dllexport) void __stdcall mmioInstallIOProcA() {
    if (fp_mmioInstallIOProcA) {
        ((void (__stdcall*)())fp_mmioInstallIOProcA)();
    }
}

// Forward mmioInstallIOProcW
__declspec(dllexport) void __stdcall mmioInstallIOProcW() {
    if (fp_mmioInstallIOProcW) {
        ((void (__stdcall*)())fp_mmioInstallIOProcW)();
    }
}

// Forward mmioOpenA
__declspec(dllexport) void __stdcall mmioOpenA() {
    if (fp_mmioOpenA) {
        ((void (__stdcall*)())fp_mmioOpenA)();
    }
}

// Forward mmioOpenW
__declspec(dllexport) void __stdcall mmioOpenW() {
    if (fp_mmioOpenW) {
        ((void (__stdcall*)())fp_mmioOpenW)();
    }
}

// Forward mmioRead
__declspec(dllexport) void __stdcall mmioRead() {
    if (fp_mmioRead) {
        ((void (__stdcall*)())fp_mmioRead)();
    }
}

// Forward mmioRenameA
__declspec(dllexport) void __stdcall mmioRenameA() {
    if (fp_mmioRenameA) {
        ((void (__stdcall*)())fp_mmioRenameA)();
    }
}

// Forward mmioRenameW
__declspec(dllexport) void __stdcall mmioRenameW() {
    if (fp_mmioRenameW) {
        ((void (__stdcall*)())fp_mmioRenameW)();
    }
}

// Forward mmioSeek
__declspec(dllexport) void __stdcall mmioSeek() {
    if (fp_mmioSeek) {
        ((void (__stdcall*)())fp_mmioSeek)();
    }
}

// Forward mmioSendMessage
__declspec(dllexport) void __stdcall mmioSendMessage() {
    if (fp_mmioSendMessage) {
        ((void (__stdcall*)())fp_mmioSendMessage)();
    }
}

// Forward mmioSetBuffer
__declspec(dllexport) void __stdcall mmioSetBuffer() {
    if (fp_mmioSetBuffer) {
        ((void (__stdcall*)())fp_mmioSetBuffer)();
    }
}

// Forward mmioSetInfo
__declspec(dllexport) void __stdcall mmioSetInfo() {
    if (fp_mmioSetInfo) {
        ((void (__stdcall*)())fp_mmioSetInfo)();
    }
}

// Forward mmioStringToFOURCCA
__declspec(dllexport) void __stdcall mmioStringToFOURCCA() {
    if (fp_mmioStringToFOURCCA) {
        ((void (__stdcall*)())fp_mmioStringToFOURCCA)();
    }
}

// Forward mmioStringToFOURCCW
__declspec(dllexport) void __stdcall mmioStringToFOURCCW() {
    if (fp_mmioStringToFOURCCW) {
        ((void (__stdcall*)())fp_mmioStringToFOURCCW)();
    }
}

// Forward mmioWrite
__declspec(dllexport) void __stdcall mmioWrite() {
    if (fp_mmioWrite) {
        ((void (__stdcall*)())fp_mmioWrite)();
    }
}

// Forward mmsystemGetVersion
__declspec(dllexport) void __stdcall mmsystemGetVersion() {
    if (fp_mmsystemGetVersion) {
        ((void (__stdcall*)())fp_mmsystemGetVersion)();
    }
}

// Forward sndPlaySoundA
__declspec(dllexport) void __stdcall sndPlaySoundA() {
    if (fp_sndPlaySoundA) {
        ((void (__stdcall*)())fp_sndPlaySoundA)();
    }
}

// Forward sndPlaySoundW
__declspec(dllexport) void __stdcall sndPlaySoundW() {
    if (fp_sndPlaySoundW) {
        ((void (__stdcall*)())fp_sndPlaySoundW)();
    }
}

// Forward timeBeginPeriod
__declspec(dllexport) void __stdcall timeBeginPeriod() {
    if (fp_timeBeginPeriod) {
        ((void (__stdcall*)())fp_timeBeginPeriod)();
    }
}

// Forward timeEndPeriod
__declspec(dllexport) void __stdcall timeEndPeriod() {
    if (fp_timeEndPeriod) {
        ((void (__stdcall*)())fp_timeEndPeriod)();
    }
}

// Forward timeGetDevCaps
__declspec(dllexport) void __stdcall timeGetDevCaps() {
    if (fp_timeGetDevCaps) {
        ((void (__stdcall*)())fp_timeGetDevCaps)();
    }
}

// Forward timeGetSystemTime
__declspec(dllexport) void __stdcall timeGetSystemTime() {
    if (fp_timeGetSystemTime) {
        ((void (__stdcall*)())fp_timeGetSystemTime)();
    }
}

// Forward timeGetTime
__declspec(dllexport) void __stdcall timeGetTime() {
    if (fp_timeGetTime) {
        ((void (__stdcall*)())fp_timeGetTime)();
    }
}

// Forward timeKillEvent
__declspec(dllexport) void __stdcall timeKillEvent() {
    if (fp_timeKillEvent) {
        ((void (__stdcall*)())fp_timeKillEvent)();
    }
}

// Forward timeSetEvent
__declspec(dllexport) void __stdcall timeSetEvent() {
    if (fp_timeSetEvent) {
        ((void (__stdcall*)())fp_timeSetEvent)();
    }
}

// Forward waveInAddBuffer
__declspec(dllexport) void __stdcall waveInAddBuffer() {
    if (fp_waveInAddBuffer) {
        ((void (__stdcall*)())fp_waveInAddBuffer)();
    }
}

// Forward waveInClose
__declspec(dllexport) void __stdcall waveInClose() {
    if (fp_waveInClose) {
        ((void (__stdcall*)())fp_waveInClose)();
    }
}

// Forward waveInGetDevCapsA
__declspec(dllexport) void __stdcall waveInGetDevCapsA() {
    if (fp_waveInGetDevCapsA) {
        ((void (__stdcall*)())fp_waveInGetDevCapsA)();
    }
}

// Forward waveInGetDevCapsW
__declspec(dllexport) void __stdcall waveInGetDevCapsW() {
    if (fp_waveInGetDevCapsW) {
        ((void (__stdcall*)())fp_waveInGetDevCapsW)();
    }
}

// Forward waveInGetErrorTextA
__declspec(dllexport) void __stdcall waveInGetErrorTextA() {
    if (fp_waveInGetErrorTextA) {
        ((void (__stdcall*)())fp_waveInGetErrorTextA)();
    }
}

// Forward waveInGetErrorTextW
__declspec(dllexport) void __stdcall waveInGetErrorTextW() {
    if (fp_waveInGetErrorTextW) {
        ((void (__stdcall*)())fp_waveInGetErrorTextW)();
    }
}

// Forward waveInGetID
__declspec(dllexport) void __stdcall waveInGetID() {
    if (fp_waveInGetID) {
        ((void (__stdcall*)())fp_waveInGetID)();
    }
}

// Forward waveInGetNumDevs
__declspec(dllexport) void __stdcall waveInGetNumDevs() {
    if (fp_waveInGetNumDevs) {
        ((void (__stdcall*)())fp_waveInGetNumDevs)();
    }
}

// Forward waveInGetPosition
__declspec(dllexport) void __stdcall waveInGetPosition() {
    if (fp_waveInGetPosition) {
        ((void (__stdcall*)())fp_waveInGetPosition)();
    }
}

// Forward waveInMessage
__declspec(dllexport) void __stdcall waveInMessage() {
    if (fp_waveInMessage) {
        ((void (__stdcall*)())fp_waveInMessage)();
    }
}

// Forward waveInOpen
__declspec(dllexport) void __stdcall waveInOpen() {
    if (fp_waveInOpen) {
        ((void (__stdcall*)())fp_waveInOpen)();
    }
}

// Forward waveInPrepareHeader
__declspec(dllexport) void __stdcall waveInPrepareHeader() {
    if (fp_waveInPrepareHeader) {
        ((void (__stdcall*)())fp_waveInPrepareHeader)();
    }
}

// Forward waveInReset
__declspec(dllexport) void __stdcall waveInReset() {
    if (fp_waveInReset) {
        ((void (__stdcall*)())fp_waveInReset)();
    }
}

// Forward waveInStart
__declspec(dllexport) void __stdcall waveInStart() {
    if (fp_waveInStart) {
        ((void (__stdcall*)())fp_waveInStart)();
    }
}

// Forward waveInStop
__declspec(dllexport) void __stdcall waveInStop() {
    if (fp_waveInStop) {
        ((void (__stdcall*)())fp_waveInStop)();
    }
}

// Forward waveInUnprepareHeader
__declspec(dllexport) void __stdcall waveInUnprepareHeader() {
    if (fp_waveInUnprepareHeader) {
        ((void (__stdcall*)())fp_waveInUnprepareHeader)();
    }
}

// Forward waveOutBreakLoop
__declspec(dllexport) void __stdcall waveOutBreakLoop() {
    if (fp_waveOutBreakLoop) {
        ((void (__stdcall*)())fp_waveOutBreakLoop)();
    }
}

// Forward waveOutClose
__declspec(dllexport) void __stdcall waveOutClose() {
    if (fp_waveOutClose) {
        ((void (__stdcall*)())fp_waveOutClose)();
    }
}

// Forward waveOutGetDevCapsA
__declspec(dllexport) void __stdcall waveOutGetDevCapsA() {
    if (fp_waveOutGetDevCapsA) {
        ((void (__stdcall*)())fp_waveOutGetDevCapsA)();
    }
}

// Forward waveOutGetDevCapsW
__declspec(dllexport) void __stdcall waveOutGetDevCapsW() {
    if (fp_waveOutGetDevCapsW) {
        ((void (__stdcall*)())fp_waveOutGetDevCapsW)();
    }
}

// Forward waveOutGetErrorTextA
__declspec(dllexport) void __stdcall waveOutGetErrorTextA() {
    if (fp_waveOutGetErrorTextA) {
        ((void (__stdcall*)())fp_waveOutGetErrorTextA)();
    }
}

// Forward waveOutGetErrorTextW
__declspec(dllexport) void __stdcall waveOutGetErrorTextW() {
    if (fp_waveOutGetErrorTextW) {
        ((void (__stdcall*)())fp_waveOutGetErrorTextW)();
    }
}

// Forward waveOutGetID
__declspec(dllexport) void __stdcall waveOutGetID() {
    if (fp_waveOutGetID) {
        ((void (__stdcall*)())fp_waveOutGetID)();
    }
}

// Forward waveOutGetNumDevs
__declspec(dllexport) void __stdcall waveOutGetNumDevs() {
    if (fp_waveOutGetNumDevs) {
        ((void (__stdcall*)())fp_waveOutGetNumDevs)();
    }
}

// Forward waveOutGetPitch
__declspec(dllexport) void __stdcall waveOutGetPitch() {
    if (fp_waveOutGetPitch) {
        ((void (__stdcall*)())fp_waveOutGetPitch)();
    }
}

// Forward waveOutGetPlaybackRate
__declspec(dllexport) void __stdcall waveOutGetPlaybackRate() {
    if (fp_waveOutGetPlaybackRate) {
        ((void (__stdcall*)())fp_waveOutGetPlaybackRate)();
    }
}

// Forward waveOutGetPosition
__declspec(dllexport) void __stdcall waveOutGetPosition() {
    if (fp_waveOutGetPosition) {
        ((void (__stdcall*)())fp_waveOutGetPosition)();
    }
}

// Forward waveOutGetVolume
__declspec(dllexport) void __stdcall waveOutGetVolume() {
    if (fp_waveOutGetVolume) {
        ((void (__stdcall*)())fp_waveOutGetVolume)();
    }
}

// Forward waveOutMessage
__declspec(dllexport) void __stdcall waveOutMessage() {
    if (fp_waveOutMessage) {
        ((void (__stdcall*)())fp_waveOutMessage)();
    }
}

// Forward waveOutOpen
__declspec(dllexport) void __stdcall waveOutOpen() {
    if (fp_waveOutOpen) {
        ((void (__stdcall*)())fp_waveOutOpen)();
    }
}

// Forward waveOutPause
__declspec(dllexport) void __stdcall waveOutPause() {
    if (fp_waveOutPause) {
        ((void (__stdcall*)())fp_waveOutPause)();
    }
}

// Forward waveOutPrepareHeader
__declspec(dllexport) void __stdcall waveOutPrepareHeader() {
    if (fp_waveOutPrepareHeader) {
        ((void (__stdcall*)())fp_waveOutPrepareHeader)();
    }
}

// Forward waveOutReset
__declspec(dllexport) void __stdcall waveOutReset() {
    if (fp_waveOutReset) {
        ((void (__stdcall*)())fp_waveOutReset)();
    }
}

// Forward waveOutRestart
__declspec(dllexport) void __stdcall waveOutRestart() {
    if (fp_waveOutRestart) {
        ((void (__stdcall*)())fp_waveOutRestart)();
    }
}

// Forward waveOutSetPitch
__declspec(dllexport) void __stdcall waveOutSetPitch() {
    if (fp_waveOutSetPitch) {
        ((void (__stdcall*)())fp_waveOutSetPitch)();
    }
}

// Forward waveOutSetPlaybackRate
__declspec(dllexport) void __stdcall waveOutSetPlaybackRate() {
    if (fp_waveOutSetPlaybackRate) {
        ((void (__stdcall*)())fp_waveOutSetPlaybackRate)();
    }
}

// Forward waveOutSetVolume
__declspec(dllexport) void __stdcall waveOutSetVolume() {
    if (fp_waveOutSetVolume) {
        ((void (__stdcall*)())fp_waveOutSetVolume)();
    }
}

// Forward waveOutUnprepareHeader
__declspec(dllexport) void __stdcall waveOutUnprepareHeader() {
    if (fp_waveOutUnprepareHeader) {
        ((void (__stdcall*)())fp_waveOutUnprepareHeader)();
    }
}

// Forward waveOutWrite
__declspec(dllexport) void __stdcall waveOutWrite() {
    if (fp_waveOutWrite) {
        ((void (__stdcall*)())fp_waveOutWrite)();
    }
}
