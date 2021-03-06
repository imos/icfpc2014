#ifndef UTIL_FLAGS_H_
#define UTIL_FLAGS_H_

#include <gflags/gflags.h>

DECLARE_int32(print_for_test);
DECLARE_bool(silent);
DECLARE_bool(print_stats);
DECLARE_bool(print_color);
DECLARE_string(ghosts);

#endif  // UTIL_FLAGS_H_
