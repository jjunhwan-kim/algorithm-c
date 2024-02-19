#include <stdio.h>
#include "mydata.h"
#include "common.h"
#include "heap.h"

int main()
{
    printf("Hello World!\n");
    printf("==================================================\n");

    Heap heap;
    MyData data[10] = {
        {5},
        {1},
        {4},
        {6},
        {7},
        {9},
        {2},
        {10},
        {3},
        {8}};

    initHeap(&heap, comparePriorityAsc);

    for (int i = 0; i < 10; i++)
    {
        pushHeap(&heap, &data[i]);
    }

    printf("Min Heap\n");
    for (int i = 0; i < 10; i++)
    {
        MyData* temp;
        popHeap(&heap, &temp);
        printf("%d\n", temp->priority);
    }

    printf("==================================================\n");

    return 0;
}
