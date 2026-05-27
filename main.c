#include "collatz.h"
#include "stdint.h"
#include "stdio.h"


int main(void) {
    collatz_t coll;

    for ( uint64_t index = 1; index < 10000000; index++ ) {
        reset( &coll, index );
        collatz( &coll );

        //printf("Collatz of %llu took %llu steps.\nMaximum value in sequence was %llu.\n\n", index, coll.steps, coll.maximum);
    }

    return 0;
}
