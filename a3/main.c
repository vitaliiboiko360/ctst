#include <stdio.h>  
#include <stdlib.h>  


void foreach(int array[], int array_size, int(*func)(int)) {
    for(int i=0; i<array_size; ++i) {
        array[i] = func(array[i]);
    }
}

void foreachPrint(int array[], int array_size) {
    for(int i=0; i<array_size; ++i) {
        printf("arr[%d]=\t\t%d\n", i, array[i]);
    }
}

int assignRand(int arg) {
    (void)(arg);
    return rand();
}

int moduloHundred(int arg) {
    return arg % 100;
}

int main() {
    srand(1);
    const int SIZE_16 = 16;
    int array[SIZE_16];

    foreachPrint(array, SIZE_16);

    foreach(array, SIZE_16, assignRand);

    foreachPrint(array, SIZE_16);

    foreach(array, SIZE_16, moduloHundred);

    foreachPrint(array, SIZE_16);
}