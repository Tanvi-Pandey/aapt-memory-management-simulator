#ifndef METRICS_H
#define METRICS_H

typedef struct {

    int allocationsAttempted;
    int allocationsSucceeded;
    int allocationsFailed;

    int usedMemory;
    int freeMemory;

    double utilization;
    double fragmentation;

} Metrics;

void initializeMetrics(Metrics *m);

void calculateMemoryMetrics(Metrics *m);

void printMetrics(Metrics *m);

#endif