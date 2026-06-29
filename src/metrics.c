#include <stdio.h>

#include "memory.h"
#include "metrics.h"

void initializeMetrics(Metrics *m)
{
    m->allocationsAttempted = 0;
    m->allocationsSucceeded = 0;
    m->allocationsFailed = 0;

    m->usedMemory = 0;
    m->freeMemory = 0;
    m->utilization = 0;
    m->fragmentation = 0;
}

void calculateMemoryMetrics(Metrics *m)
{
    int largestFreeBlock = 0;
    int currentBlock = 0;

    for(int i = 0; i < MEMORY_SIZE; i++)
    {
        if(memory[i] == 0)
        {
            m->freeMemory++;
            currentBlock++;

            if(currentBlock > largestFreeBlock)
                largestFreeBlock = currentBlock;
        }
        else
        {
            m->usedMemory++;
            currentBlock = 0;
        }
    }

    m->utilization =
        ((double)m->usedMemory / MEMORY_SIZE) * 100;

    if(m->freeMemory == 0)
        m->fragmentation = 0;
    else
        m->fragmentation =
            100.0 *
            (1.0 - ((double)largestFreeBlock / m->freeMemory));
}

void printMetrics(Metrics *m)
{
    calculateMemoryMetrics(m);

    printf("\n== PERFORMANCE METRICS ==\n");

    printf("Attempts      : %d\n", m->allocationsAttempted);
    printf("Succeeded     : %d\n", m->allocationsSucceeded);
    printf("Failed        : %d\n", m->allocationsFailed);

    printf("Used Memory   : %d bytes\n", m->usedMemory);
    printf("Free Memory   : %d bytes\n", m->freeMemory);

    printf("Utilization   : %.2lf%%\n", m->utilization);
    printf("Fragmentation : %.2lf%%\n", m->fragmentation);
}