#include <assert.h>

#include <cpu.h>
#include <kprintf.h>

void assert_impl(const char *function, int line, bool condition, char *condtion_str) {
    if (!condition) {
        assert_debugf(LOG_CRIT, "Condition %s failed!\n", function, line, condtion_str);
        _hcf();
    }
}
