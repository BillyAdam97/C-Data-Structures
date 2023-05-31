#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>

struct QNode {
    void* val;
    struct QNode* next;
};

typedef struct Queue {
    int size;
    struct QNode* head;
    struct QNode* tail;
} Queue;

struct Queue* createQ();
void pushQ(struct Queue* q, void* val);
void* frontQ(struct Queue* q);
void* backQ(struct Queue* q);
void popQ(struct Queue* q);
int sizeQ(struct Queue* q);
int emptyQ(struct Queue* q);
void freeQ(struct Queue* q);

#endif
