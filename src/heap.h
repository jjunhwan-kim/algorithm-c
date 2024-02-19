#ifndef _HEAP_H
#define _HEAP_H

#define MAX_SIZE 10

typedef struct
{
    int size;
    MyData *data[MAX_SIZE];
    int (*compare)(MyData*, MyData*);
} Heap;

void initHeap(Heap* heap, int (*compare)(MyData*, MyData*));
int pushHeap(Heap* heap, MyData* data);
int popHeap(Heap* heap, MyData** data);
#endif
