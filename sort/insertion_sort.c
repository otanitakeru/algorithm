#include "print_array.h"
#include <stdio.h>

int A[6] = {5, 2, 4, 6, 1, 3};

void insertion_sort(int A[], int N);

int main(void){
    printf("Before: \n");
    print_int_array(A, 6);

    insertion_sort(A, 6);

    printf("\nAfter: \n");
    print_int_array(A, 6);

    return 0;
}

void insertion_sort(int A[], int N){
    int i,j,v;
    for(i=1; i < N; i++){
        v = A[i];
        j = i - 1;
        while ( j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}
