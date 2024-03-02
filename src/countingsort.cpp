#include "countingsort.h"

int count[MAX_VALUE + 1];
int countSum[MAX_VALUE + 1];
MyData sortedArr[MAX_SIZE];

void countingSort(MyData* arr, int size) {
  for (int index = 0; index < size; index++) {
    count[arr[index].priority]++;
  }

  countSum[0] = count[0];
  for (int index = 1; index <= MAX_VALUE; index++) {
    countSum[index] = countSum[index - 1] + count[index];
  }

  for (int index = size - 1; index >= 0; index--) {
    sortedArr[countSum[arr[index].priority] - 1] = arr[index];
    countSum[arr[index].priority]--;
  }

  for (int index = 0; index < size; index++) {
    arr[index] = sortedArr[index];
  }
}