#include <windows.h>
#include "hooks.h"

// This file contains forwarded functions for all winmm exports
// The actual forwarding is handled by the .def file,
// but we need to declare them here for proper linking

// Forwarder functions that are not hooked
// These are automatically forwarded to winmm_orig by the .def file
