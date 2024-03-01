#include <stdio.h>

#include "common.h"
#include "heap.h"
#include "mergesort.h"
#include "mydata.h"

int main() {
  printf("Hello World!\n");
  printf("==================================================\n");

  Heap heap;
  MyData data[10] = {{5}, {1}, {4}, {6}, {7}, {9}, {2}, {10}, {3}, {8}};

  initHeap(&heap, comparePriorityAsc);

  for (int i = 0; i < 10; i++) {
    pushHeap(&heap, &data[i]);
  }

  printf("Min Heap\n");
  for (int i = 0; i < 10; i++) {
    MyData* temp;
    popHeap(&heap, &temp);
    printf("%d\n", temp->priority);
  }

  printf("==================================================\n");

  initHeap(&heap, comparePriorityDesc);

  for (int i = 0; i < 10; i++) {
    pushHeap(&heap, &data[i]);
  }

  printf("Max Heap\n");
  for (int i = 0; i < 10; i++) {
    MyData* temp;
    popHeap(&heap, &temp);
    printf("%d\n", temp->priority);
  }

  printf("==================================================\n");

  MyData asc[10] = {{5}, {1}, {4}, {6}, {7}, {9}, {2}, {10}, {3}, {8}};

  MyData desc[10] = {{5}, {1}, {4}, {6}, {7}, {9}, {2}, {10}, {3}, {8}};

  printf("Merge Sort Asc\n");

  mergeSort(asc, comparePriorityAsc, 0, 9);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", asc[i].priority);
  }

  printf("==================================================\n");

  printf("Merge Sort Desc\n");

  mergeSort(desc, comparePriorityDesc, 0, 9);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", desc[i].priority);
  }

  printf("==================================================\n");

  return 0;
}
