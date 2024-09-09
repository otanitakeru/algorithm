/*
選択ソート

配列の中から最小値を見つけ、それを配列の先頭に移動するという操作を繰り返すことで、配列全体を昇順に整列するアルゴリズム

計算量:　O(n^2)

*/

#include <stdio.h>

#include "print_array.h"
#include "swap.h"

int array[6] = {5, 2, 4, 6, 1, 3};

void selection_sort(int array[], int array_size);

int main(void){
    printf("Before: \n");
    print_int_array1d(array, 6);

    selection_sort(array, 6);

    printf("\nAfter: \n");
    print_int_array1d(array, 6);

    return 0;
}

void selection_sort(int array[], int array_size){
    int min_index;
    for(int i=0; i < array_size - 1; i++){
        min_index = i;
        for(int j = i + 1; j < array_size; j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            swap(&array[i], &array[min_index]);
        }
    }
}