#include "collatz.h"
#include "options.h"
#include "stdint.h"
#include "stdio.h"

#ifdef ENABLE_STATISTICS
typedef struct st_statistic {
    uint64_t value;
    uint64_t index;
} statistic_t;
#endif


int main(void) {
    collatz_t coll;

#ifdef ENABLE_STATISTICS
    statistic_t statistic_max_value = { 0 };
    statistic_t statistic_max_steps = { 0 };
#endif

    for ( uint64_t index = 1; index < 1000000000; index++ ) {
        reset( &coll, index );
        collatz( &coll );

#ifdef ENABLE_STATISTICS
        if ( coll.maximum > statistic_max_value.value ) {
            statistic_max_value.value = coll.maximum;
            statistic_max_value.index = index;
        }

        if ( coll.steps > statistic_max_steps.value ) {
            statistic_max_steps.value = coll.maximum;
            statistic_max_steps.index = index;
        }

#ifdef ENABLE_STEP_DEBUGGING
        printf("Collatz of %llu took %llu steps.\nMaximum value in sequence was %llu.\n\n", index, coll.steps, coll.maximum);
#endif
#endif
    }

#ifdef ENABLE_STATISTICS
    printf("Maximum number %llu reached at index %llu.\n", statistic_max_value.value, statistic_max_value.index);
    printf("Maximum number of steps %llu reached at index %llu.\n\a", statistic_max_steps.value, statistic_max_steps.index);
#endif

    return 0;
}
