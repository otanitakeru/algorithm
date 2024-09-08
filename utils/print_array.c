/*
配列を表示する関数
*/

#include <stdio.h>

#include "print_array.h"

void print_int_array(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}