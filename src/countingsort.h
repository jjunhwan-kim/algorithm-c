#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H
#include "mydata.h"

#define COUNTING_SORT_SIZE 10000       // 데이터 개수
#define COUNTING_SORT_MAX_VALUE 10000  // 데이터 최대 값

void countingSort(MyData* arr, int size);
#endif
