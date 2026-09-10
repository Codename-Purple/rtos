#ifndef DEBUG_H
#define DEBUG_H

#define ANSI_COLOR_RED    "\33[31m"         // critical errors
#define ANSI_COLOR_GREEN  "\33[32m"         // success
#define ANSI_COLOR_ORANGE "\33[33m"         // warning
#define ANSI_COLOR_GRAY   "\33[90m"         // trace
#define ANSI_COLOR_PURPLE "\33[0;35m"       // panic
#define ANSI_COLOR_RESET  "\33[0m"

#define ANSI_COLOR(c, s)    c s ANSI_COLOR_RESET

#endif
