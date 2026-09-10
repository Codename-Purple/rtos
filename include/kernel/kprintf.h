#ifndef KPRINTF_H
#define KPRINTF_H

#include <sinks.h>

#define TRACE_FMT(l)    "[ %s():%d::" l " ] "

enum log_lvl {
    LOG_INFO = 1,           /* normal logging */
    LOG_WARN  = (1 << 1),   /* warnings */
    LOG_CRIT  = (1 << 2),   /* critical errors */
    LOG_TRACE = (1 << 3),   /* trace */
};

/*
 * Register a sink.
 * @param sink the sink to add to the list of sinks
 */
void register_sink(struct sink* sink);

int kprintf(enum log_lvl lvl, const char* fmt, ...);

#define kprintf_info(fmt, ...)      kprintf(LOG_INFO, fmt, ##__VA_ARGS__)
#define kprintf_ok(fmt, ...)        kprintf(LOG_INFO, TRACE_FMT("ok") fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define kprintf_warn(fmt, ...)      kprintf(LOG_WARN, TRACE_FMT("WARN") fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define kprintf_error(fmt, ...)     kprintf(LOG_CRIT, TRACE_FMT("ERROR") fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define kprintf_panic(fmt, ...)     kprintf(LOG_CRIT, TRACE_FMT("PANIC") fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define kprintf_trace(fmt, ...)     kprintf(LOG_TRACE, TRACE_FMT("trace") fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#endif
