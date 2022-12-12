#include "Stack.h"

struct Stack* createS()
{
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size=0;
    s->head=NULL;
    return s;
}

void pushS(struct Stack* s, int val)
{
    if (!s->head) {
        s->head = (struct SNode*)malloc(sizeof(struct SNode));
        s->head->next = NULL;
        s->head->val = val;
        s->size++;
        return;
    }
    struct SNode* tmp = (struct SNode*)malloc(sizeof(struct SNode));
    tmp->val = val;
    tmp->next = s->head;
    s->head = tmp;
    s->size++;
}

int topS(struct Stack* s)
{
    if (s->head) {
        return s->head->val;
    }
    return -1;
}

void popS(struct Stack* s)
{
    if (!s->head) return;
    struct SNode* tmp = s->head;
    s->head=s->head->next;
    free(tmp);
    s->size--;
}

int sizeS(struct Stack* s)
{
    return s->size;
}

int emptyS(struct Stack* s)
{
    if (s->size==0) return 1;
    else return 0;
}

void freeS(struct Stack* s)
{
    struct SNode* tmp;
    while (s->head!=NULL) {
        tmp = s->head;
        s->head=s->head->next;
        free(tmp);
    }
    free(s);
}