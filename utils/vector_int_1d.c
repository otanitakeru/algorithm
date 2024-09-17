/*
vectorをC言語で実装する (*1次元のint型に対応する簡易的なもの*)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "vector_int_1d.h"

bool vector_int_1d_is_empty(VectorInt1d *v){
    return v -> size == 0;
}

void vector_int_1d_init(VectorInt1d *v){
    v -> data = (int *)malloc(sizeof(int) * VECTOR_MINIMUM_CAPACITY);
    v -> size = 0;
    v -> capacity = VECTOR_MINIMUM_CAPACITY;
}

void vector_int_1d_push_back(VectorInt1d *v, int x){
    if(_vector_int_1d_should_grow(v)){
        _vector_int_1d_resize(v, v -> capacity * 2);
    }
    v -> data[v -> size] = x;
    v -> size++;
}

void vector_int_1d_pop_back(VectorInt1d *v){
    if(vector_int_1d_is_empty(v)){
        assert("vector is empty");
    }
    v -> size--;
    if(_vector_int_1d_should_shrink(v)){
        _vector_int_1d_resize(v, v -> capacity / 2);
    }
}

int vector_int_1d_get(VectorInt1d *v, int index){
    if(index < 0 || index >= v -> size){
        assert("index is out of range");
    }
    return v -> data[index];
}

void vector_int_1d_insert(VectorInt1d *v, int index, int x){
    if(index < 0 || index >= v -> size){
        assert("index is out of range");
    }
    v -> data[index] = x;
}

void vector_int_1d_erase(VectorInt1d *v, int index){
    if(index < 0 || index >= v -> size){
        assert("index is out of range");
    }
    for(int i = index; i < v -> size - 1; i++){
        v -> data[i] = v -> data[i + 1];
    }
    v -> size--;
    if(_vector_int_1d_should_shrink(v)){
        _vector_int_1d_resize(v, v -> capacity / 2);
    }
}

void vector_int_1d_deep_copy(VectorInt1d *v1, VectorInt1d *v2){
    v2 -> data = (int *)malloc(sizeof(int) * v1 -> capacity);
    for(int i = 0; i < v1 -> size; i++){
        v2 -> data[i] = v1 -> data[i];
    }
    v2 -> size = v1 -> size;
    v2 -> capacity = v1 -> capacity;
}

void vector_int_1d_reverse(VectorInt1d *v){
    for(int i = 0; i < v -> size / 2; i++){
        int tmp = v -> data[i];
        v -> data[i] = v -> data[v -> size - i - 1];
        v -> data[v -> size - i - 1] = tmp;
    }
}

void vector_int_1d_find(VectorInt1d *v, int x){
    for(int i = 0; i < v -> size; i++){
        if(v -> data[i] == x){
            printf("index: %d\n", i);
            return;
        }
    }
    printf("not found\n");
}

void vector_int_1d_remove(VectorInt1d *v, int x){
    for(int i = 0; i < v -> size; i++){
        if(v -> data[i] == x){
            vector_int_1d_erase(v, i);
            i--;
        }
    }
}

void vector_int_1d_swap_elements(VectorInt1d *v, int index1, int index2){
    if(index1 < 0 || index1 >= v -> size || index2 < 0 || index2 >= v -> size){
        assert("index is out of range");
    }
    int tmp = v -> data[index1];
    v -> data[index1] = v -> data[index2];
    v -> data[index2] = tmp;
}

int vector_int_1d_binary_search_lower(VectorInt1d *v, int x){
    int left = 0;
    int right = v -> size;

    while(left < right){
        int mid = (left + right) / 2;
        if(v -> data[mid] < x){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int vector_int_1d_binary_search_upper(VectorInt1d *v, int x){
    int left = 0;
    int right = v -> size;

    while(left < right){
        int mid = (left + right) / 2;
        if(v -> data[mid] <= x){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int vector_int_1d_size(VectorInt1d *v){
    return v -> size;
}

int vector_int_1d_capacity(VectorInt1d *v){
    return v -> capacity;
}

void vector_int_1d_print(VectorInt1d *v){
    printf("[ ");
    for(int i = 0; i < v -> size; i++){
        printf("%d ", v -> data[i]);
    }
    printf("]\n");
}

void vector_int_1d_free(VectorInt1d *v){
    free(v -> data);
}

bool _vector_int_1d_should_grow(VectorInt1d *v){
    return v -> size == v -> capacity;
}

bool _vector_int_1d_should_shrink(VectorInt1d *v){
    return v -> size <= v -> capacity / 4;
}

void _vector_int_1d_resize(VectorInt1d *v, int new_capacity){
    if(new_capacity < VECTOR_MINIMUM_CAPACITY){
        new_capacity = VECTOR_MINIMUM_CAPACITY;
    }
    int *new_data = (int *)malloc(sizeof(int) * new_capacity);
    for(int i = 0; i < v -> size; i++){
        new_data[i] = v -> data[i];
    }

    free(v -> data);
    v -> data = new_data;
    v -> capacity = new_capacity;
}
