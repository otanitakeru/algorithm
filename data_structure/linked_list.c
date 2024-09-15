/*
連結リスト
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *prev;
    struct Node *next;
}Node;

Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil -> next = nil;
    nil -> prev = nil;
}

void insert(int key){
    Node *new = (Node *)malloc(sizeof(Node));
    new -> key = key;
    new -> next = nil -> next;
    nil -> next -> prev = new;
    nil -> next = new;
    new -> prev = nil;
}

void delete(Node *t){
    if(t == nil) return;
    t -> prev -> next = t -> next;
    t -> next -> prev = t -> prev;
    free(t);
}

void deleteFirst(){
    delete(nil -> next);
}

void deleteLast(){
    delete(nil -> prev);
}

void printList(){
    Node *cur = nil -> next;
    while(cur != nil){
        printf("%d ", cur -> key);
        cur = cur -> next;
    }
    puts("");
}

int main(void){
    init();

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printList();

    deleteFirst();
    deleteLast();

    printList();

    return 0;
}