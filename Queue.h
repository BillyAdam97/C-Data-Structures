#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>

struct QNode {
    int val;
    struct QNode* next;
};

struct Queue {
    int size;
    struct QNode* head;
    struct QNode* tail;
};

struct Queue* createQ();
void pushQ(struct Queue* q, int val);
int frontQ(struct Queue* q);
int backQ(struct Queue* q);
void popQ(struct Queue* q);
int sizeQ(struct Queue* q);
int emptyQ(struct Queue* q);
void freeQ(struct Queue* q);

#endif