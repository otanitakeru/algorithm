/*
cppで定義されているvectorをC言語で実装する
ただ、メモリの確保をしない、簡単な実装にする
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "swap.h"

#define MAX_SIZE 10

typedef struct{
    int data[MAX_SIZE];
    int size;
} SimpleVector;

bool simple_vector_is_empty(SimpleVector *v){
    return v -> size == 0;
}

void simple_vector_init(SimpleVector *v){
    v -> size = 0;
}

void simple_vector_push_back(SimpleVector *v, int x){
    if(v -> size == MAX_SIZE){
        assert("vector is full");
    }
    v -> data[v -> size] = x;
    v -> size++;
}

void simple_vector_pop_back(SimpleVector *v){
    if(simple_vector_is_empty(v)){
        assert("vector is empty");
    }
    v -> size--;
}

int simple_vector_get(SimpleVector *v, int index){
    if(index < 0 || index >= v -> size){
        assert("index is out of range");
    }
    return v -> data[index];
}

void simple_vector_insert(SimpleVector *v, int index, int x){
    if(index < 0 || index >= v -> size){
        assert("index is out of range");
    }
    v -> data[index] = x;
}

void simple_vector_erase(SimpleVector *v, int index){
    if(index < 0 || index >= v -> size){
        assert("index is out of range");
    }
    for(int i = index; i < v -> size - 1; i++){
        v -> data[i] = v -> data[i + 1];
    }
    v -> size--;
}

int simple_vector_size(SimpleVector *v){
    return v -> size;
}

void simple_vector_print(SimpleVector *v){
    printf("[ ");
    for(int i = 0; i < v -> size; i++){
        printf("%d ", v -> data[i]);
    }
    puts("]");
}

void simple_vector_clear(SimpleVector *v){
    v -> size = 0;
}

int simple_vector_find(SimpleVector *v, int x){
    for(int i = 0; i < v -> size; i++){
        if(v -> data[i] == x){
            return i;
        }
    }
    return -1;
}

void simple_vector_remove(SimpleVector *v, int x){
    for(int i = 0; i < v -> size; i++){
        if(v -> data[i] == x){
            simple_vector_erase(v, i);
            i--;
        }
    }
}

void simple_vector_reverse(SimpleVector *v){
    for(int i = 0; i < v -> size / 2; i++){
        swap(&v -> data[i], &v -> data[v -> size - i - 1]);
    }
}

void simple_vector_deep_copy(SimpleVector *v1, SimpleVector *v2){
    for(int i = 0; i < v1 -> size; i++){
        v2 -> data[i] = v1 -> data[i];
    }
    v2 -> size = v1 -> size;
}

int main(void){
    SimpleVector v;
    simple_vector_init(&v);

    for(int i = 0; i < 10; i++){
        simple_vector_push_back(&v, i);
    }

    simple_vector_print(&v);

    simple_vector_pop_back(&v);

    simple_vector_print(&v);

    simple_vector_insert(&v, 3, 100);

    simple_vector_print(&v);

    simple_vector_erase(&v, 3);

    simple_vector_print(&v);

    printf("%d\n", simple_vector_find(&v, 4));

    simple_vector_remove(&v, 3);

    simple_vector_print(&v);

    printf("%d\n", simple_vector_get(&v, 3));

    printf("%d\n", simple_vector_size(&v));

    simple_vector_reverse(&v);

    simple_vector_print(&v);

    return 0;
}