#include <stdio.h>
#include "metrics.h"

void initializeMetrics(Metrics *m) {
    m->allocationsAttempted = 0;
    m->allocationsSucceeded = 0;
    m->allocationsFailed = 0;
}

void printMetrics(Metrics *m) {

    printf("\nAttempts : %d\n",
           m->allocationsAttempted);

    printf("Successes: %d\n",
           m->allocationsSucceeded);

    printf("Failures : %d\n",
           m->allocationsFailed);
}