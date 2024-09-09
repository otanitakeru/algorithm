/*
シェルソート

挿入ソートの改良版

計算量: O(n^1.25)

・挿入ソートの改良版
    ・挿入ソートは、要素が適切な位置に挿入されるまで、その要素を左右に移動させる必要がある
    ・シェルソートは、要素を適切な位置に挿入する際に、一度に大きな距離だけ移動させることで、要素の移動回数を減らす
    ・挿入ソートの改良版として、要素の間隔を狭めていくことで、最終的には挿入ソートと同じようになる
*/

#include <stdio.h>

#include "print_array.h"

int array[6] = {5, 2, 4, 6, 1, 3};

void shell_sort(int array[], int array_size);
void insertion_sort(int array[], int array_size, int h);

int main(void){
    printf("Before: \n");
    print_int_array1d(array, 6);

    shell_sort(array, 6);

    printf("\nAfter: \n");
    print_int_array1d(array, 6);

    return 0;
}

void shell_sort(int array[], int array_size){
    int h = 1;
    while(h < array_size){
        h = 3 * h + 1;
    }
    while(h > 0){
        insertion_sort(array, array_size, h);
        h = h / 3;
    }
}

void insertion_sort(int array[], int array_size, int h){
    int j,v;
    for(int i=h; i < array_size; i++){
        v = array[i];
        j = i - h;
        while ( j >= 0 && array[j] > v){
            array[j+h] = array[j];
            j = j - h;
        }
        array[j+h] = v;
    }
}
