# Navicat WinMM Unlocker

A proxy DLL for `winmm.dll` that patches Navicat at runtime to unlock premium features.

## How it works

This DLL acts as a proxy/forwarder for the original Windows `winmm.dll`. When loaded by Navicat, it:

1. Loads the original `winmm.dll` from System32
2. Forwards all API calls to the original DLL (so audio/media functions work normally)
3. Detects if the host process is `navicat.exe`
4. If so, creates a background thread that applies memory patches to bypass license checks

## Usage

1. Build the project or download the release
2. Copy `winmm.dll` to your Navicat installation directory
3. Make sure `navicat.exe` is in the same directory
4. Run Navicat normally

## Building

### Requirements
- CMake 3.20+
- Visual Studio 2019+ (MSVC compiler)
- Windows SDK

### Build Steps

```bash
mkdir build
cd build
cmake .. -A x64
cmake --build . --config Release
```

The output `winmm.dll` will be in `build/bin/Release/`.

## How the patch works

The unlocker applies several memory patches to Navicat:

1. **Trial check bypass** - Modifies the trial validation function to always return success
2. **License key validation bypass** - Disables online license verification
3. **Premium feature unlock** - Unlocks enterprise/premium features

Patches are applied via pattern matching, so they work across different Navicat versions.

## Safety

- The original `winmm.dll` is never modified
- All patches are done in-memory only
- No registry changes
- No files are written to disk

## Compatibility

- Windows 10/11 x64
- Navicat Premium 15/16

## Disclaimer

This tool is for educational purposes only. Use at your own risk. Please support the developers by purchasing a legitimate license if you find the software useful.

## License

MIT License - See LICENSE file for details
