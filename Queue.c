#include "Queue.h"

struct Queue* createQ()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) return NULL;
    q->head=NULL;
    q->tail=NULL;
    q->size=0;
    return q;
}

void pushQ(struct Queue* q, void* val)
{
    if (!q->head) {
        struct QNode* tmp = (struct QNode*)malloc(sizeof(struct QNode));
        if (!tmp) return;
        tmp->next=NULL;
        tmp->val=val;
        q->head=tmp;
        q->tail=q->head;
        q->size++;
        return;
    }
    struct QNode* tmp = (struct QNode*)malloc(sizeof(struct QNode));
    if (!tmp) return;
    tmp->val = val;
    q->tail->next=tmp;
    q->tail=tmp;
    q->size++;
}

void* frontQ(struct Queue* q)
{
    if (q->head) return q->head->val;
    return NULL;
}

void* backQ(struct Queue* q)
{
    if (q->tail) return q->tail->val;
    return NULL;
}

void popQ(struct Queue* q)
{
    if (!q->head) return;
    struct QNode* tmp = q->head;
    q->head=q->head->next;
    q->size--;
    if (emptyQ(q)) {
        q->head=NULL;
        q->tail=NULL;
    }
    free(tmp);
}

int sizeQ(struct Queue* q)
{
    return q->size;
}

int emptyQ(struct Queue* q) 
{
    if (q->size==0) return 1;
    else return 0;
}

void freeQ(struct Queue* q)
{
    struct QNode* tmp;
    while (q->head!=NULL) {
        tmp=q->head;
        q->head=q->head->next;
        free(tmp);
    }
    free(q);
}
