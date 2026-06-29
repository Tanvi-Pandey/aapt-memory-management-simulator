#include <stdio.h>

#include "memory.h"
#include "first_fit.h"
#include "paging.h"
#include "metrics.h"

void runFirstFitWorkload()
{
    Metrics m;
    initializeMetrics(&m);

    initializeMemory();

    m.allocationsAttempted++;
    if (allocateFirstFit(1, 20) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    m.allocationsAttempted++;
    if (allocateFirstFit(2, 15) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    m.allocationsAttempted++;
    if (allocateFirstFit(3, 10) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    freeMemory(2);

    m.allocationsAttempted++;
    if (allocateFirstFit(4, 12) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    m.allocationsAttempted++;
    if (allocateFirstFit(5, 18) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    printf("\n== FIRST FIT ==\n");

    displayMemory();
    printMetrics(&m);
}

void runPagingWorkload()
{
    Metrics m;
    initializeMetrics(&m);

    initializePaging();

    m.allocationsAttempted++;
    if (allocatePaged(1, 20) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    m.allocationsAttempted++;
    if (allocatePaged(2, 15) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    m.allocationsAttempted++;
    if (allocatePaged(3, 10) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    freePaged(2);

    m.allocationsAttempted++;
    if (allocatePaged(4, 12) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    m.allocationsAttempted++;
    if (allocatePaged(5, 18) != -1)
        m.allocationsSucceeded++;
    else
        m.allocationsFailed++;

    printf("\n== PAGING ==\n");

    displayMemory();
    displayPageTable();
    printMetrics(&m);
}