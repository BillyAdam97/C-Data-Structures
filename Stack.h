#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>

struct SNode {
    int val;
    struct SNode* next;
};

struct Stack {
    int size;
    struct SNode* head;
};

struct Stack* createS();
void pushS(struct Stack* s, int val);
int topS(struct Stack* s);
void popS(struct Stack* s);
int sizeS(struct Stack* s);
int emptyS(struct Stack* s);
void freeS(struct Stack* s);

#endif