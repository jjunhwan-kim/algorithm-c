#include <stdio.h>

#include "common.h"
#include "countingsort.h"
#include "heap.h"
#include "mergesort.h"
#include "mydata.h"
#include "radixsort.h"
#include "unionfind.h"

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

  MyData count[10] = {
      {3}, {3}, {2},  {2}, {1}, {4},
      {5}, {7}, {10}, {8}};  // 3 3 2 2 1 4 5 7 10 8 -> 1 2 2 3 3 4 5 7 8 10

  printf("Counting Sort\n");

  countingSort(count, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", count[i].priority);
  }

  printf("==================================================\n");

  MyData count2[10] = {
      {3}, {3}, {2},  {2}, {1}, {4},
      {5}, {7}, {10}, {8}};  // 3 3 2 2 1 4 5 7 10 8 -> 1 2 2 3 3 4 5 7 8 10

  printf("Radix Sort By Decimal Asc\n");

  radixSortBydecimal(count2, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", count2[i].priority);
  }

  printf("==================================================\n");

  MyData count3[10] = {
      {3}, {3}, {2},  {2}, {1}, {4},
      {5}, {7}, {10}, {8}};  // 3 3 2 2 1 4 5 7 10 8 -> 1 2 2 3 3 4 5 7 8 10

  printf("Radix Sort By 256 Asc\n");

  radixSortBydecimal(count3, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", count3[i].priority);
  }

  printf("==================================================\n");

  printf("Union Find\n");

  initParent();

  unionParent(1, 2);
  unionParent(1, 3);
  unionParent(2, 4);
  unionParent(4, 5);
  unionParent(6, 7);
  unionParent(6, 8);
  unionParent(7, 9);

  printf("parent[1]: %d\n", findParent(1));
  printf("parent[2]: %d\n", findParent(2));
  printf("parent[3]: %d\n", findParent(3));
  printf("parent[4]: %d\n", findParent(4));
  printf("parent[5]: %d\n", findParent(5));
  printf("parent[6]: %d\n", findParent(6));
  printf("parent[7]: %d\n", findParent(7));
  printf("parent[8]: %d\n", findParent(8));
  printf("parent[9]: %d\n", findParent(9));

  return 0;
}
