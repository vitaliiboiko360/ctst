#include <stdio.h>  
int main() {
    const int SIZE_16 = 16;
    int array[SIZE_16];

    for (int i=0; i<SIZE_16; ++i) {
        printf("ar[%d]=%d\n",i,array[i]);
    }
}