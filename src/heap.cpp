#include "heap.h"

void initHeap(Heap* heap, int (*compare)(MyData*, MyData*)) {
  heap->size = 0;
  heap->compare = compare;
}

int pushHeap(Heap* heap, MyData* data) {
  if (heap->size >= HEAP_SIZE) {
    return 0;
  }

  heap->data[heap->size] = data;
  heap->size++;
  int currentIndex = heap->size - 1;
  // currentIndex > 0 means that the current node is not root node.
  // compare function returns 1 if the first parameter has a higher priority
  // than the second parameter, and 0 otherwise.
  while (currentIndex > 0 &&
         heap->compare(heap->data[currentIndex],
                       heap->data[(currentIndex - 1) / 2])) {
    MyData* temp = heap->data[(currentIndex - 1) / 2];
    heap->data[(currentIndex - 1) / 2] = heap->data[currentIndex];
    heap->data[currentIndex] = temp;
    currentIndex = (currentIndex - 1) / 2;
  }

  return 1;
}

int popHeap(Heap* heap, MyData** data) {
  if (heap->size <= 0) {
    return 0;
  }

  *data = heap->data[0];
  heap->data[0] = heap->data[heap->size - 1];
  heap->size--;

  int currentIndex = 0;
  int childIndex;

  // It means that the current node has child nodes.
  while (currentIndex * 2 + 1 <= heap->size - 1) {
    if (currentIndex * 2 + 1 == heap->size - 1) {
      childIndex = currentIndex * 2 + 1;
    } else {
      if (heap->compare(heap->data[currentIndex * 2 + 1],
                        heap->data[currentIndex * 2 + 2])) {
        childIndex = currentIndex * 2 + 1;
      } else {
        childIndex = currentIndex * 2 + 2;
      }
    }

    if (heap->compare(heap->data[currentIndex], heap->data[childIndex])) {
      break;
    }

    MyData* temp = heap->data[childIndex];
    heap->data[childIndex] = heap->data[currentIndex];
    heap->data[currentIndex] = temp;
    currentIndex = childIndex;
  }

  return 1;
}
