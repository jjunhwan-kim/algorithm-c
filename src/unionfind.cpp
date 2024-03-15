#include "unionfind.h"

static int parent[UNION_FIND_SIZE];
static int rank[UNION_FIND_SIZE];

void initParent() {
  for (int index = 0; index < UNION_FIND_SIZE; index++) {
    parent[index] = index;
    rank[index] = 0;
  }
}

int findParent(int x) {
  if (parent[x] == x) {
    return x;
  }

  return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
  x = findParent(x);
  y = findParent(y);

  if (x == y) {
    return;
  }

  if (rank[x] > rank[y]) {
    parent[y] = x;
  } else if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    rank[x]++;
  }
}