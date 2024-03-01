#ifndef _MERGESORT_H
#define _MERGESORT_H
#include "mydata.h"

#define MAX_SIZE 10

void mergeSort(MyData* arr, int (*compare)(MyData*, MyData*), int startIndex,
               int endIndex);
#endif
