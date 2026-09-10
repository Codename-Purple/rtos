#ifndef ASSERT_H
#define ASSERT_H

#include <stdbool.h>
#include <kprintf.h>

#define assert_debugf(lvl, fmt, func, line, ...)  kprintf(lvl, TRACE_FMT("ASSERT") fmt, func, line, ##__VA_ARGS__)

void assert_impl(const char *function, int line, bool condition, char *condtion_str);
#define assert(c)   assert_impl(__FUNCTION__, __LINE__, c, #c)

#endif
