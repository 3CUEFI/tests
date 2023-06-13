#include <stdlib.h>

struct IntSet _For_any(T) {
  T *rep;
  void (*add)(T *rep, int x);
  void (*rem)(T *rep, int x);
  int (*find)(T *rep, int x);
};

struct List {
  int head;
  struct List *tail;
};

int find(struct List **elems, int x) {
  struct List *curr = *elems;
  while (curr) {
    if (curr->head == x) return 1;
    curr = curr->tail;
  }
  return 0;
}

void add(struct List **elems, int x) {
  if (find(elems, x)) return;
  struct List *node = malloc(sizeof(struct List));
  node->head = x;
  node->tail = *elems;
  *elems = node;
}

void rem(struct List **elems, int x) {
  // Implement the removal logic here.
}

struct IntSet<struct List *> listSet = {NULL, &add, &rem, &find};

// Use _Pack and _Unpack here properly when you have an existential struct.

struct IntSet<struct List *> intSet = listSet;
struct List **rep = intSet.rep;

(*intSet.add)(rep, 42);
int found = (*intSet.find)(rep, 42); // found == 1
(*intSet.rem)(rep, 42);
int found2 = (*intSet.find)(rep, 42); // found2 == 0

