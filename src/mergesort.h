#ifndef MERGESORT_H
#define MERGESORT_H
#include "mydata.h"

#define MERGE_SORT_SIZE 10000

void mergeSort(MyData* arr, int (*compare)(MyData*, MyData*), int startIndex,
               int endIndex);
#endif
