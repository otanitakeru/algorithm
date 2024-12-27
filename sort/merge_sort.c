/*
マージソート

分割統治法を用いたアルゴリズム

計算量: O(nlogn)

1. リストを半分に分割する
2. 分割したリストをそれぞれマージソートでソートする
3. ソート済みのリストをマージする
*/

#include<stdio.h>
#include "print_array.h"

void merge(int array[], int left, int mid, int right);
void merge_sort(int array[], int left, int right);

int array[6] = {5, 2, 4, 6, 1, 3};

int main(void){
    printf("Before: \n");
    print_int_array1d(array, 6);

    merge_sort(array, 0, 5);

    printf("\nAfter: \n");
    print_int_array1d(array, 6);

    return 0;
}

void merge(int array[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1], R[n2+1];

    for(int i = 0; i < n1; i++){
        
    }
}
