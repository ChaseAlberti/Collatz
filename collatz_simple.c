#include "options.h"
#ifdef USE_SIMPLE_IMPLEMENTATION

#include "collatz.h"


void reset(collatz_t * p_collatz, const uint64_t start) {
    p_collatz->value = start;

#ifdef ENABLE_STATISTICS
    p_collatz->maximum = start;
    p_collatz->steps = 0;
#endif
}

void collatz(collatz_t * p_collatz) {
    const uint64_t previous = p_collatz->value;
    uint64_t next = 0;

#ifdef ENABLE_STEP_DEBUGGING
    printf("   ---> %llu\n", previous);
#endif

    if ( previous == 1 ) {
        return;
    }

    if ( previous % 2 == 0 ) {
        next = previous / 2;
    } else {
        next = ( 3 * previous ) + 1;
    }

#ifdef ENABLE_STATISTICS
    p_collatz->steps++;

    if ( next > p_collatz->maximum ) {
        p_collatz->maximum = next;
    }
#endif

    p_collatz->value = next;
    collatz( p_collatz );
}

#endif
