/*
挿入ソート
配列の先頭から順に、その要素を適切な位置に挿入していくソート

計算量: O(n^2)

・先頭の要素をソート済みとする
    ・次の要素を取り出し、ソート済みの部分に適切な位置に挿入する

*/

#include <stdio.h>

#include "print_array.h"

int array[6] = {5, 2, 4, 6, 1, 3};

void insertion_sort(int array[], int array_size);

int main(void){
    printf("Before: \n");
    print_int_array(array, 6);

    insertion_sort(array, 6);

    printf("\nAfter: \n");
    print_int_array(array, 6);

    return 0;
}

void insertion_sort(int array[], int array_size){
    int j,v;
    for(int i=1; i < array_size; i++){
        v = array[i];
        j = i - 1;
        while ( j >= 0 && array[j] > v){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = v;
    }
}
