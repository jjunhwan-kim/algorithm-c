#ifndef RADIX_SORT_H
#define RADIX_SORT_H
#include "mydata.h"

#define RADIX_SORT_SIZE 10000  // 데이터 개수
#define RADIX_SORT_DECIMAL_DIGIT 4  // 10진 기수 정렬 사용시 데이터 자리수

#define RADIX_SORT_256_BASE (1 << 8)                   // 256진 기수 정렬
#define RADIX_SORT_256_MASK (RADIX_SORT_256_BASE - 1)  // 255

void radixSortBydecimal(MyData* arr, int size);
void radixSortBy256(MyData* arr, int size);
#endif
