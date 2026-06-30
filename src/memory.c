#include <stdio.h>
#include "memory.h"

int memory[MEMORY_SIZE];

void initializeMemory()
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory[i] = 0;
    }
}

void displayMemory()
{
    printf("\n========== MEMORY STATE ==========\n\n");

    for (int frame = 0; frame < MEMORY_SIZE / FRAME_SIZE; frame++)
    {
        int start = frame * FRAME_SIZE;

        int pid = memory[start];

        if (pid == 0)
        {
            printf("Frame %2d : FREE\n", frame);
        }
        else
        {
            printf("Frame %2d : P%-5d [", frame, pid);

            for (int i = start; i < start + FRAME_SIZE; i++)
            {
                printf("%d", memory[i]);

                if (i != start + FRAME_SIZE - 1)
                    printf(" ");
            }

            printf("]\n");
        }
    }

    printf("\n");
}