/*
バブルソート
計算量: O(n^2)

・隣り合う要素の大小を比較して、順番が逆であれば交換する
*/

#include <stdio.h>

#include "print_array.h"
#include "swap.h"

int array[6] = {5, 2, 4, 6, 1, 3};

void bubble_sort(int array[], int array_size);

int main(void){
    printf("Before: \n");
    print_int_array(array, 6);

    bubble_sort(array, 6);

    printf("\nAfter: \n");
    print_int_array(array, 6);

    return 0;
}

void bubble_sort(int array[], int array_size){
    for(int i=0; i < array_size - 1; i++){
        for(int j = array_size - 1; j > i; j--){
            if(array[j] < array[j-1]){
                swap(&array[j], &array[j-1]);
            }
        }
    }
}
