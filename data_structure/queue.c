/*
キュー
*/

#include<stdio.h>
#include "print_array.h"

#define LEN 10

typedef struct{
    int data[LEN];
    int head;
    int tail;
} Queue;

void init(Queue *q);
void enqueue(Queue *q, int x);
int dequeue(Queue *q);
int is_empty(Queue *q);
int is_full(Queue *q);

int main(void){
    Queue q;
    
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    print_int_array1d(q.data, LEN);

    printf("%d\n", dequeue(&q));
    enqueue(&q, 4);

    print_int_array1d(q.data, LEN);

    return 0;
}

void init(Queue *q){
    q -> head = 0;
    q -> tail = 0;
    for (int i = 0; i < LEN; i++){
        q -> data[i] = 0;
    }
}

void enqueue(Queue *q, int x){
    if(is_full(q)){
        printf("queue is full\n");
        return;
    }
    q -> data[q -> tail] = x;
    q -> tail = (q -> tail + 1) % LEN;
}

int dequeue(Queue *q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return -1;
    }
    int x = q -> data[q -> head];
    q -> data[q -> head] = 0;
    q -> head = (q -> head + 1) % LEN;
    return x;
}

int is_empty(Queue *q){
    return q -> head == q -> tail;
}

int is_full(Queue *q){
    return (q -> tail + 1) % LEN == q -> head;
}

