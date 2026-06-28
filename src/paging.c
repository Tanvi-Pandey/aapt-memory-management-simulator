#include <stdio.h>
#include "memory.h"
#include "paging.h"

PageTableEntry pageTable[50];
int pageCount = 0;

void initializePaging() {

    pageCount = 0;

    for(int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
}

int allocatePaged(int processId, int size) {

    int framesNeeded =
        (size + FRAME_SIZE - 1) / FRAME_SIZE;

    PageTableEntry entry;

    entry.processId = processId;
    entry.numFrames = 0;

    for(int frame = 0;
        frame < NUM_FRAMES && entry.numFrames < framesNeeded;
        frame++) {

        int start = frame * FRAME_SIZE;

        int freeFrame = 1;

        for(int i = start;
            i < start + FRAME_SIZE;
            i++) {

            if(memory[i] != 0) {
                freeFrame = 0;
                break;
            }
        }

        if(freeFrame) {

            for(int i = start;
                i < start + FRAME_SIZE;
                i++) {

                memory[i] = processId;
            }

            entry.frames[entry.numFrames++] = frame;
        }
    }

    if(entry.numFrames < framesNeeded) {

        freePaged(processId);
        return -1;
    }

    pageTable[pageCount++] = entry;

    return 1;
}

void freePaged(int processId) {

    for(int i = 0; i < MEMORY_SIZE; i++) {

        if(memory[i] == processId)
            memory[i] = 0;
    }

    for(int i = 0; i < pageCount; i++) {

        if(pageTable[i].processId == processId) {

            pageTable[i] =
                pageTable[pageCount - 1];

            pageCount--;
            break;
        }
    }
}

void displayPageTable() {

    printf("\nPage Table\n");

    for(int i = 0; i < pageCount; i++) {

        printf("P%d -> ",
               pageTable[i].processId);

        for(int j = 0;
            j < pageTable[i].numFrames;
            j++) {

            printf("%d ",
                pageTable[i].frames[j]);
        }

        printf("\n");
    }
}