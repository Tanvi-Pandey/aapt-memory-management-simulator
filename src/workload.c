#include <stdio.h>

#include "memory.h"
#include "first_fit.h"
#include "paging.h"
#include "metrics.h"

void runFirstFitWorkload() {

    Metrics m;
    initializeMetrics(&m);

    initializeMemory();

    int sizes[] = {20, 15, 10, 25, 12, 18};

    for(int i = 0; i < 6; i++) {

        m.allocationsAttempted++;

        if(allocateFirstFit(i + 1, sizes[i]) != -1)
            m.allocationsSucceeded++;
        else
            m.allocationsFailed++;
    }

    printf("\n===== FIRST FIT =====\n");

    displayMemory();
    printMetrics(&m);
}

void runPagingWorkload() {

    Metrics m;
    initializeMetrics(&m);

    initializePaging();

    int sizes[] = {20, 15, 10, 25, 12, 18};

    for(int i = 0; i < 6; i++) {

        m.allocationsAttempted++;

        if(allocatePaged(i + 1, sizes[i]) != -1)
            m.allocationsSucceeded++;
        else
            m.allocationsFailed++;
    }

    printf("\n===== PAGING =====\n");

    displayMemory();
    displayPageTable();
    printMetrics(&m);
}