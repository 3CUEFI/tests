//#include <stdio.h>
//#include <stdlib.h>

#define NULL (void*)0
extern _For_any(T) _Array_ptr<T> malloc(int size) : count(size);

int main() {
    // Allocate int pointer on the heap
    _Ptr<int> iptr = malloc<int>(sizeof(int));
    if(iptr == NULL) _Checked {
        return 1;
    }
    *iptr = 42;  // Use iptr as a non-array

    // Allocate int array on the heap
    _Array_ptr<int> iarr : count(5) = malloc<int>(5 * sizeof(int));
    if(iarr == NULL) _Checked {
        return 1;
    }
    for(int i=0; i<5; i++) _Checked {
        iarr[i] = i;  // Use iarr as an array
    }
    for(int i=0; i<5; i++) _Checked {
    }
    printf("\n");
    // Allocate void pointer on the heap
    void *vptr = ((void *)malloc<int>(sizeof(int)));
    if(vptr == NULL) _Checked {
        return 1;
    }
    *((int*)vptr) = 99;  // Use vptr as a non-array

    // Allocate void array on the heap
    void *varr = ((void *)malloc<int>(5 * sizeof(int)));
    if(varr == NULL) _Checked {
        return 1;
    }

    return 0;
}

