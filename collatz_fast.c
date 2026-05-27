#include "options.h"
#ifdef USE_FAST_IMPLEMENTATION

#include "collatz.h"


static uint64_t is_even(const uint64_t value) {
    return ( value ^ 1 ) == ( value + 1 );
}

static uint64_t is_pow2(const uint64_t value) {
    return ( ( value & ( value - 1 ) ) == 0 );
}


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

    if ( is_pow2( previous ) ) {
        return;
    }

    if ( is_even( previous ) ) {
        next = previous >> 1;
    } else {
        next = ( ( 3 * previous ) + 1 ) >> 1;
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
