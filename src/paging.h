#ifndef PAGING_H
#define PAGING_H

#define FRAME_SIZE 8
#define NUM_FRAMES (MEMORY_SIZE / FRAME_SIZE)

typedef struct {
    int processId;
    int frames[32];
    int numFrames;
} PageTableEntry;

void initializePaging();
int allocatePaged(int processId, int size);
void freePaged(int processId);
void displayPageTable();

#endif