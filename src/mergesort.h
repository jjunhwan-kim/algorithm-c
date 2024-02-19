#ifndef _MERGESORT_H
#define _MERGESORT_H

#define MAX_SIZE 10

void mergeSort(MyData* arr, int (*compare)(MyData*, MyData*), int left, int right);
#endif
