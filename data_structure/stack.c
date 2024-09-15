/*
スタック
*/

#include <stdio.h>
#include <stdbool.h>

#include "print_array.h"

static int MAX_SIZE = 10;

int stack[10];

int top = 0;

void push(int x);
int pop(void);
bool is_empty(void);
int is_full(void);

int main(void){
    for(int i = 0; i < 10; i++){
        push(i);
    }

    print_int_array1d(stack, 10);
    puts("");

    for(int i = 0; i < 5; i++){
        pop();
    }

    print_int_array1d(stack, 10);
    puts("");

    for(int i = 0; i < 5; i++){
        push(i);
    }

    print_int_array1d(stack, 10);
    puts("");

    for(int i = 0; i < 10; i++){
        pop();
    }

    return 0;
}

void push(int x){
    if(is_full()){
        printf("stack is full\n");
        return;
    }
    stack[top] = x;
    top++;
}

int pop(void){
    if(is_empty()){
        printf("stack is empty\n");
        return -1;
    }
    top--;
    int return_value = stack[top];
    stack[top] = 0;
    return return_value;
}

bool is_empty(void){
    return top == 0;
}

int is_full(void){
    return top == MAX_SIZE;
}


