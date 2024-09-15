/*
バブルソート
計算量: O(n^2)

・隣り合う要素の大小を比較して、順番が逆であれば交換する
*/

#include <stdio.h>

#include "vector_int_1d.h"

void bubble_sort(VectorInt1d v);

int main(void){
    VectorInt1d v;
    vector_int_1d_init(&v);
    
    vector_int_1d_push_back(&v, 5);
    vector_int_1d_push_back(&v, 2);
    vector_int_1d_push_back(&v, 4);
    vector_int_1d_push_back(&v, 6);
    vector_int_1d_push_back(&v, 1);
    vector_int_1d_push_back(&v, 3);

    vector_int_1d_print(&v);

    bubble_sort(v);

    vector_int_1d_print(&v);
    
    return 0;
}

void bubble_sort(VectorInt1d v){
    for(int i=0; i < v.size - 1; i++){
        for(int j = v.size - 1; j > i; j--){
            if(v.data[j] < v.data[j-1]){
                vector_int_1d_swap_elements(&v, j, j-1);
            }
        }
    }
}
