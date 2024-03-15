#include "countingsort.h"

int count[COUNTING_SORT_MAX_VALUE + 1];
MyData sorted[COUNTING_SORT_SIZE];

void countingSort(MyData* arr, int size) {
  for (int index = 0; index < size; index++) {
    count[arr[index].priority]++;
  }

  for (int index = 1; index <= COUNTING_SORT_MAX_VALUE; index++) {
    count[index] = count[index - 1] + count[index];
  }

  for (int index = size - 1; index >= 0; index--) {
    sorted[--count[arr[index].priority]] = arr[index];
  }

  for (int index = 0; index < size; index++) {
    arr[index] = sorted[index];
  }
}