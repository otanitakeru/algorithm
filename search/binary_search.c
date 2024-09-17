/*
二分探索法

計算量: O(logN)
*/

#include <stdio.h>

int binary_search_lower(int array[], int array_size, int key);
int binary_search_upper(int array[], int array_size, int key);

int main(void){
    int array[6] = {1, 2, 4, 5, 6};

    puts("binary_search_lower");
    printf("%d\n", binary_search_lower(array, 5, 0));
    printf("%d\n", binary_search_lower(array, 5, 1));
    printf("%d\n", binary_search_lower(array, 5, 2));
    printf("%d\n", binary_search_lower(array, 5, 3));
    printf("%d\n", binary_search_lower(array, 5, 4));
    printf("%d\n", binary_search_lower(array, 5, 5));
    printf("%d\n", binary_search_lower(array, 5, 6));
    printf("%d\n", binary_search_lower(array, 5, 7));

    puts("binary_search_upper");
    printf("%d\n", binary_search_upper(array, 5, 0));
    printf("%d\n", binary_search_upper(array, 5, 1));
    printf("%d\n", binary_search_upper(array, 5, 2));
    printf("%d\n", binary_search_upper(array, 5, 3));
    printf("%d\n", binary_search_upper(array, 5, 4));
    printf("%d\n", binary_search_upper(array, 5, 5));
    printf("%d\n", binary_search_upper(array, 5, 6));
    printf("%d\n", binary_search_upper(array, 5, 7));

    return 0;
}

// arrayの中でkey以上の値が初めて現れるindexを返す
int binary_search_lower(int array[], int array_size, int key){
    int left = 0;
    int right = array_size;

    while(left < right){
        int mid = (left + right) / 2;
        if (array[mid] < key){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
}

// arrayの中でkeyより大きい値が初めて現れるindexを返す
int binary_search_upper(int array[], int array_size, int key){
    int left = 0;
    int right = array_size;

    while(left < right){
        int mid = (left + right) / 2;
        if (array[mid] <= key){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return left;
}