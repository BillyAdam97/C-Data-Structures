#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>

struct SNode {
    void* val;
    struct SNode* next;
};

typedef struct Stack {
    int size;
    struct SNode* head;
} Stack;

struct Stack* createS();
void pushS(struct Stack* s, void* val);
void* topS(struct Stack* s);
void popS(struct Stack* s);
int sizeS(struct Stack* s);
int emptyS(struct Stack* s);
void freeS(struct Stack* s);

#endif
