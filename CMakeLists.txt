cmake_minimum_required(VERSION 3.20)
project(navicat-winmm-unlock VERSION 1.0 LANGUAGES C)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
set(CMAKE_C_STANDARD 11)

# Add the DLL target
add_library(winmm SHARED
    src/dllmain.c
    src/hooks.c
    src/forward.c
    winmm.def
)

# Include directories
target_include_directories(winmm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Compile definitions
target_compile_definitions(winmm PRIVATE
    WIN32_LEAN_AND_MEAN
    _WINDOWS
    _USRDLL
    _CRT_SECURE_NO_WARNINGS
)

# Link libraries
target_link_libraries(winmm PRIVATE
    kernel32
    user32
    psapi
    ucrt
    vcruntime
    msvcrt
)

# Set output properties
set_target_properties(winmm PROPERTIES
    OUTPUT_NAME "winmm"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    PREFIX ""
)

# MSVC specific settings
if(MSVC)
    target_compile_options(winmm PRIVATE /W3 /O2)
    # Use dynamic linking for CRT
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

# Installation
install(TARGETS winmm RUNTIME DESTINATION .)
install(FILES README.md LICENSE DESTINATION .)
