#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct {
    int* buff;
    int head;
    int tail;
    int size;
} CircularBuffer;

CircularBuffer* createCB(int _maxsize);
int bufferEmpty(CircularBuffer* cb);
int bufferFull(CircularBuffer* cb);
void freeCB(CircularBuffer* cb);
void pushCB(CircularBuffer* cb, int val);
int popCB(CircularBuffer* cb);

#endif