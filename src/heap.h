#ifndef HEAP_H
#define HEAP_H
#include "mydata.h"

#define HEAP_SIZE 10000

typedef struct {
  int size;
  MyData* data[HEAP_SIZE];
  int (*compare)(MyData*, MyData*);
} Heap;

void initHeap(Heap* heap, int (*compare)(MyData*, MyData*));
int pushHeap(Heap* heap, MyData* data);
int popHeap(Heap* heap, MyData** data);
#endif
