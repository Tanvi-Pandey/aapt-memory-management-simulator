#ifndef METRICS_H
#define METRICS_H

typedef struct {
    int allocationsAttempted;
    int allocationsSucceeded;
    int allocationsFailed;
} Metrics;

void initializeMetrics(Metrics *m);
void printMetrics(Metrics *m);

#endif