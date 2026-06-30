#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memory.h"
#include "first_fit.h"
#include "paging.h"
#include "metrics.h"

#define NUM_REQUESTS 5000

void runFirstFitWorkload()
{
    Metrics m;
    initializeMetrics(&m);

    initializeMemory();

    srand((unsigned)time(NULL));

    clock_t start = clock();

    for (int i = 1; i <= NUM_REQUESTS; i++)
    {
        int pid = (i % 99) + 1;
        int size = rand() % 20 + 5;

        m.allocationsAttempted++;

        if (allocateFirstFit(pid, size) != -1)
            m.allocationsSucceeded++;
        else
            m.allocationsFailed++;

        /* Create fragmentation */
        if (i % 5 == 0)
        {
            int freePid = ((i - 2) % 99) + 1;
            freeMemory(freePid);
        }
    }

    clock_t end = clock();

    printf("\n========== FIRST FIT ==========\n");

    displayMemory();
    printMetrics(&m);

    printf("Execution Time : %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    FILE *fp = fopen("results/results.txt", "w");

    if (fp != NULL)
    {
        fprintf(fp, "========== FIRST FIT ==========\n");
        fprintf(fp, "Attempts      : %d\n", m.allocationsAttempted);
        fprintf(fp, "Succeeded     : %d\n", m.allocationsSucceeded);
        fprintf(fp, "Failed        : %d\n", m.allocationsFailed);
        fprintf(fp, "ExecutionTime : %.6f seconds\n",
                (double)(end - start) / CLOCKS_PER_SEC);

        fclose(fp);
    }
}

void runPagingWorkload()
{
    Metrics m;
    initializeMetrics(&m);

    initializePaging();

    /* Use the same random sequence as First-Fit */
    srand((unsigned)time(NULL));

    clock_t start = clock();

    for (int i = 1; i <= NUM_REQUESTS; i++)
    {
        int pid = (i % 99) + 1;
        int size = rand() % 20 + 5;

        m.allocationsAttempted++;

        if (allocatePaged(pid, size) != -1)
            m.allocationsSucceeded++;
        else
            m.allocationsFailed++;

        if (i % 5 == 0)
        {
            int freePid = ((i - 2) % 99) + 1;
            freePaged(freePid);
        }
    }

    clock_t end = clock();

    printf("\n========== PAGING ==========\n");

    displayMemory();
    displayPageTable();
    printMetrics(&m);

    printf("Execution Time : %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    FILE *fp = fopen("results/results.txt", "a");

    if (fp != NULL)
    {
        fprintf(fp, "\n========== PAGING ==========\n");
        fprintf(fp, "Attempts      : %d\n", m.allocationsAttempted);
        fprintf(fp, "Succeeded     : %d\n", m.allocationsSucceeded);
        fprintf(fp, "Failed        : %d\n", m.allocationsFailed);
        fprintf(fp, "ExecutionTime : %.6f seconds\n",
                (double)(end - start) / CLOCKS_PER_SEC);

        fclose(fp);
    }
}