#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate int pointer on the heap
    _Ptr<int> iptr = malloc<int>(sizeof(int));
    if(iptr == NULL) _Checked {
        _Unchecked { printf("Memory allocation failed.\n"); };
        return 1;
    }
    *iptr = 42;  // Use iptr as a non-array
    printf("iptr points to %d\n", *iptr);

    // Allocate int array on the heap
    _Array_ptr<int> iarr : count(5) = malloc<int>(5 * sizeof(int));
    if(iarr == NULL) _Checked {
        _Unchecked { printf("Memory allocation failed.\n"); };
        return 1;
    }
    for(int i=0; i<5; i++) _Checked {
        iarr[i] = i;  // Use iarr as an array
    }
    printf("iarr contains: ");
    for(int i=0; i<5; i++) {
        printf("%d ", iarr[i]);
    }
    printf("\n");

    // Allocate void pointer on the heap
    void *vptr = malloc(sizeof(int));
    if(vptr == NULL) _Checked {
        _Unchecked { printf("Memory allocation failed.\n"); };
        return 1;
    }
    *((int*)vptr) = 99;  // Use vptr as a non-array
    printf("vptr points to %d\n", *((int*)vptr));

    // Allocate void array on the heap
    void *varr = malloc(5 * sizeof(int));
    if(varr == NULL) _Checked {
        _Unchecked { printf("Memory allocation failed.\n"); };
        return 1;
    }
    for(int i=0; i<5; i++) {
        ((int*)varr)[i] = i + 10;  // Use varr as an array
    }
    printf("varr contains: ");
    for(int i=0; i<5; i++) {
        printf("%d ", ((int*)varr)[i]);
    }
    printf("\n");

    // Free all allocated memory
    free<int>(iptr);
    free<int>(iarr);
    free<void>(vptr);
    free<void>(varr);

    return 0;
}

