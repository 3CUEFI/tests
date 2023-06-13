#include <stdlib.h>
#include <stdio.h>

#pragma CHECKED_SCOPE on
struct IntSet _For_any(T) {
  _Ptr<T> rep;
  _Ptr<void(_Ptr<T> rep, int x)> add;
  _Ptr<int(_Ptr<T> rep, int x)> find;
};

// A set of ints represented as a linked list.
struct List {
  int head;
  _Ptr<struct List> tail;
};

int find(_Ptr<_Ptr<struct List >> elems, int x) {
  if (!elems)
	  return 0;
  _Ptr<struct List> curr = *elems;
  while (curr) {
    if (curr->head == x) return 1;
    curr = curr->tail;
  }
  return 0;
}

void add(_Ptr<_Ptr<struct List >>elems, int x) {
  if (find(elems, x)) return;
  _Ptr<struct List> node = malloc<struct List>(sizeof(struct List));
  node->head = x;
  node->tail = *elems;
  *elems = node;
}

#pragma CHECKED_SCOPE off
int main()
_Checked {
	_Ptr<struct List> list = NULL;
	struct IntSet<_Ptr<struct List>> listSet = {&list,&add, &find};
        _Exists(A, struct IntSet<A>) opaque_info = _Pack(listSet, _Exists(A, struct IntSet<A>), _Ptr<struct List> );
	_Unpack (T) struct IntSet<T> intSet = opaque_info;
		
	_Ptr<T> rep = intSet.rep;
	intSet.add(intSet.rep, 42);
	//intSet.add(list, 42); //error: passing '_Ptr<struct List>' to parameter of incompatible type '_Ptr<A>' (aka '_Ptr<(0, 0)>')
	int found = intSet.find(intSet.rep, 42); // found == 1

	_Unchecked{
		printf("found value is %d\n", found);
	}
	return 0;
}

