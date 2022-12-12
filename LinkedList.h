#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};

struct LinkedList* createLL();
void addHead(int value, struct LinkedList* list);
void addTail(int value, struct LinkedList* list);
void addAtIndex(int value, int index, struct LinkedList* list);
void removeAtIndex(int index, struct LinkedList* list);
int getHead(struct LinkedList* list);
int getTail(struct LinkedList* list);
int getByIndex(int index, struct LinkedList* list);
int sizeofLL(struct LinkedList* list);
void freeLL(struct LinkedList* list);

#endif