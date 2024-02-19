#include "mydata.h"
#include "common.h"

int comparePriorityAsc(MyData* left, MyData* right)
{
    if (left->priority <= right->priority)
    {
        return 1;
    }

    return 0;
}

int comparePriorityDesc(MyData* left, MyData* right)
{
    if (left->priority >= right->priority)
    {
        return 1;
    }
    return 0;
}
