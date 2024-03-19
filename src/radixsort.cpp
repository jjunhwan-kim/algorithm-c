
#include "radixsort.h"

static int count[RADIX_SORT_256_BASE];
static MyData sorted[RADIX_SORT_SIZE];

void radixSortBydecimal(MyData* arr, int size) {
  int decimal = 1;

  for (int i = 0; i < RADIX_SORT_DECIMAL_DIGIT; i++) {
    // 카운트 배열 초기화
    for (int j = 0; j < 10; j++) {
      count[j] = 0;
    }

    for (int j = 0; j < size; j++) {
      count[arr[j].priority / decimal % 10]++;
    }

    for (int j = 1; j < 10; j++) {
      count[j] = count[j - 1] + count[j];
    }

    for (int j = size - 1; j >= 0; j--) {
      sorted[--count[arr[j].priority / decimal % 10]] = arr[j];
    }

    for (int j = 0; j < size; j++) {
      arr[j] = sorted[j];
    }

    decimal *= 10;
  }
}

void radixSortBy256(MyData* arr, int size) {
  // 256진수 4자리 정렬
  for (int i = 0; i < 32; i += 8) {
    // 카운트 배열 초기화
    for (int j = 0; j < RADIX_SORT_256_BASE; j++) {
      count[j] = 0;
    }

    for (int j = 0; j < size; j++) {
      count[(arr[j].priority >> i) & RADIX_SORT_256_MASK]++;
    }

    for (int j = 1; j < RADIX_SORT_256_BASE; j++) {
      count[j] += count[j - 1];
    }

    for (int j = size - 1; j >= 0; j--) {
      sorted[--count[(arr[j].priority >> i) & RADIX_SORT_256_MASK]] = arr[j];
    }

    for (int j = 0; j < size; j++) {
      arr[j] = sorted[j];
    }
  }
}