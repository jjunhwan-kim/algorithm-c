#include "mergesort.h"

MyData temp[MERGE_SORT_SIZE];

void merge(MyData arr[MERGE_SORT_SIZE], int (*compare)(MyData*, MyData*),
           int startIndex, int endIndex);

void mergeSort(MyData* arr, int (*compare)(MyData*, MyData*), int startIndex,
               int endIndex) {
  if (startIndex < endIndex) {
    int midIndex = (startIndex + endIndex) / 2;

    mergeSort(arr, compare, startIndex, midIndex);
    mergeSort(arr, compare, midIndex + 1, endIndex);
    merge(arr, compare, startIndex, endIndex);
  }
}

void merge(MyData arr[MERGE_SORT_SIZE], int (*compare)(MyData*, MyData*),
           int startIndex, int endIndex) {
  int midIndex = (startIndex + endIndex) / 2;
  int leftIndex = startIndex;
  int rightIndex = midIndex + 1;
  int index = 0;

  while (leftIndex <= midIndex && rightIndex <= endIndex) {
    if (compare(&arr[leftIndex], &arr[rightIndex])) {
      temp[index++] = arr[leftIndex++];
    } else {
      temp[index++] = arr[rightIndex++];
    }
  }

  while (leftIndex <= midIndex) {
    temp[index++] = arr[leftIndex++];
  }

  while (rightIndex <= endIndex) {
    temp[index++] = arr[rightIndex++];
  }

  for (int i = startIndex; i <= endIndex; i++) {
    arr[i] = temp[i - startIndex];
  }
}
