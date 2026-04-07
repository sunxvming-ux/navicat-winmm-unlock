cmake_minimum_required(VERSION 3.20)
project(navicat-winmm-unlock VERSION 1.0 LANGUAGES C)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add the DLL target
add_library(winmm SHARED
    src/dllmain.c
    src/hooks.c
    src/forward.c
)

# Include directories
target_include_directories(winmm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Compile definitions
target_compile_definitions(winmm PRIVATE
    WIN32_LEAN_AND_MEAN
    _WINDOWS
    _USRDLL
    NAVICAT_UNLOCK_EXPORTS
)

# Link libraries
target_link_libraries(winmm PRIVATE
    kernel32
    user32
    psapi
)

# Set output properties
set_target_properties(winmm PROPERTIES
    OUTPUT_NAME "winmm"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    PREFIX ""
)

# Use the .def file for exports
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/winmm.def ${CMAKE_CURRENT_BINARY_DIR}/winmm.def COPYONLY)
target_link_options(winmm PRIVATE "/DEF:${CMAKE_CURRENT_BINARY_DIR}/winmm.def")

# MSVC specific flags
if(MSVC)
    target_compile_options(winmm PRIVATE
        /W3
        /O2
        /MT
        /GS-
        /fp:precise
        /Zc:wchar_t
        /Zc:forScope
        /Zc:inline
    )

    target_link_options(winmm PRIVATE
        /MACHINE:X64
        /SUBSYSTEM:WINDOWS
        /ENTRY:DllMainCRTStartup
    )
endif()

# Installation
install(TARGETS winmm
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES
    README.md
    LICENSE
    DESTINATION .
)
