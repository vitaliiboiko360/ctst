#include <stdlib.h>
#include <stdio.h>  
int main() {
    // void *malloc( size_t size );
    const int SIZE_16 = 16;
    int* p1 = malloc(sizeof(int)*SIZE_16);

    if (!p1) {
        return 1;
    }

    printf("p1 = %p\n", p1);

    for (int i=0; i<SIZE_16; ++i) {
        printf("%d\n", p1[i]);
    }

    free(p1);
}