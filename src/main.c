#include <stdio.h>

#include "memory.h"
#include "first_fit.h"

int main() {

    initializeMemory();

    printf("Initial Memory\n");
    displayMemory();

    allocateFirstFit(1, 20);
    allocateFirstFit(2, 15);
    allocateFirstFit(3, 10);

    printf("After Allocations\n");
    displayMemory();

    freeMemory(2);

    printf("After Freeing Process 2\n");
    displayMemory();

    allocateFirstFit(4, 12);

    printf("After Allocating Process 4\n");
    displayMemory();

    return 0;
}