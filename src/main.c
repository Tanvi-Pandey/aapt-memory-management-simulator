#include <stdio.h>

#include "memory.h"
#include "first_fit.h"
#include "paging.h"

int main() {

    initializePaging();

    allocatePaged(1, 20);
    allocatePaged(2, 12);
    allocatePaged(3, 30);

    displayMemory();
    displayPageTable();

    freePaged(2);

    printf("\nAfter Freeing P2\n");

    displayMemory();
    displayPageTable();

    return 0;
}