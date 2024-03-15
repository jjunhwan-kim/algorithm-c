#ifndef UNION_FIND_H
#define UNION_FIND_H
#include "mydata.h"

#define UNION_FIND_SIZE 10000  // 데이터 개수

void initParent();
int findParent(int x);
void unionParent(int x, int y);
#endif
