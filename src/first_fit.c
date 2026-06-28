#include <stdio.h>
#include "memory.h"
#include "first_fit.h"

int allocateFirstFit(int processId, int size) {

    int count = 0;
    int start = -1;

    for(int i = 0; i < MEMORY_SIZE; i++) {

        if(memory[i] == 0) {

            if(count == 0)
                start = i;

            count++;

            if(count == size) {

                for(int j = start; j < start + size; j++) {
                    memory[j] = processId;
                }

                return start;
            }

        } else {
            count = 0;
        }
    }

    return -1;
}

void freeMemory(int processId) {

    for(int i = 0; i < MEMORY_SIZE; i++) {

        if(memory[i] == processId) {
            memory[i] = 0;
        }
    }
}