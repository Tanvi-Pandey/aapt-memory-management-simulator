#include <stdio.h>
#include "memory.h"

int memory[MEMORY_SIZE];

void initializeMemory() {
    for(int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
}

void displayMemory() {
    printf("\nMemory State:\n");

    for(int i = 0; i < MEMORY_SIZE; i++) {
        printf("%d", memory[i]);

        if((i + 1) % 32 == 0)
            printf("\n");
    }

    printf("\n");
}