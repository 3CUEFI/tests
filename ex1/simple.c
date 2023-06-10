#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate int pointer on the heap
    int *iptr = malloc(sizeof(int));
    if(iptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    *iptr = 42;  // Use iptr as a non-array
    printf("iptr points to %d\n", *iptr);

    // Allocate int array on the heap
    int *iarr = malloc(5 * sizeof(int));
    if(iarr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for(int i=0; i<5; i++) {
        iarr[i] = i;  // Use iarr as an array
    }
    printf("iarr contains: ");
    for(int i=0; i<5; i++) {
        printf("%d ", iarr[i]);
    }
    printf("\n");

    // Allocate void pointer on the heap
    void *vptr = malloc(sizeof(int));
    if(vptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    *((int*)vptr) = 99;  // Use vptr as a non-array
    printf("vptr points to %d\n", *((int*)vptr));

    // Allocate void array on the heap
    void *varr = malloc(5 * sizeof(int));
    if(varr == NULL) {
        printf("Memory allocation failed.\n");
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
    free(iptr);
    free(iarr);
    free(vptr);
    free(varr);

    return 0;
}

