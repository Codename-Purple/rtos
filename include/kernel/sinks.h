#ifndef SINKS_H
#define SINKS_H

#include <stdint.h>

struct sink {
    uint8_t level_mask; /* Levels supported by this sink */
    /*
     * Pointer to a "put character" function.
     * @param 1 character to print
     * @param 2 pointer to a context to be handled by the function. Can be NULL.
     */
    void (*putc)(int, void*);

    struct sink* next;  /* Pointer to next sink */
};


#endif
