#ifndef COLLATZ_COLLATZ_H
#define COLLATZ_COLLATZ_H

#include "options.h"
#include "stdint.h"
#ifdef ENABLE_STEP_DEBUGGING
#include "stdio.h"
#endif


typedef struct st_collatz {
    uint64_t value;

#ifdef ENABLE_STATISTICS
    uint64_t steps;
    uint64_t maximum;
#endif

} collatz_t;

void reset(collatz_t * p_collatz, uint64_t start);
void collatz(collatz_t * p_collatz);


#endif //COLLATZ_COLLATZ_H
