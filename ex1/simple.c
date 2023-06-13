//#include <stdio.h>
//#include <stdlib.h>

#define NULL (void*)0
extern _For_any(T) _Array_ptr<T> malloc(int size) : count(size);

int main() {
    // Allocate int pointer on the heap
    int *iptr = malloc<int>(sizeof(int));
    if(iptr == NULL) {
        return 1;
    }
    *iptr = 42;  // Use iptr as a non-array

    // Allocate int array on the heap
    int *iarr = malloc<int>(5 * sizeof(int));
    if(iarr == NULL) {
        return 1;
    }
    for(int i=0; i<5; i++) {
        iarr[i] = i;  // Use iarr as an array
    }
    for(int i=0; i<5; i++) {
    }
    printf("\n");
    // Allocate void pointer on the heap
    void *vptr = malloc<int>(sizeof(int));
    if(vptr == NULL) {
        return 1;
    }
    *((int*)vptr) = 99;  // Use vptr as a non-array

    // Allocate void array on the heap
    void *varr = malloc<int>(5 * sizeof(int));
    if(varr == NULL) {
        return 1;
    }

    return 0;
}

