#include <arch.h>
#include <gdt.h>
#include <idt.h>

#include <sinks.h>
#include <kprintf.h>
#include <debug.h>

static const struct sink e9_sink = {
    .putc = dputc,
    .level_mask = LOG_INFO | LOG_WARN | LOG_CRIT | LOG_TRACE
};

void arch_entry() {
    register_sink(&e9_sink);

    gdt_init();
    kprintf_ok("GDT setup\n");

    idt_init();
    kprintf_ok("IDT setup\n");
}
