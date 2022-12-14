#include "CircularBuffer.h"

CircularBuffer* createCB(int _maxsize)
{
    CircularBuffer* buffer = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    buffer->size = _maxsize+1;
    buffer->buff = malloc(sizeof(int) * (buffer->size));
    buffer->head=0;
    buffer->tail=0;
    return buffer;
}

int bufferEmpty(CircularBuffer* cb)
{
    return (cb->head==cb->tail);
}

int bufferFull(CircularBuffer* cb)
{
    return ((cb->head-cb->tail+cb->size)%cb->size) == 1;
}

void freeCB(CircularBuffer* cb)
{
    free(cb->buff);
    free(cb);
}

void pushCB(CircularBuffer* cb, int val)
{
    if (bufferFull(cb)) return;

    cb->buff[cb->tail]=val;
    cb->tail = (cb->tail+1)%cb->size;
}

int popCB(CircularBuffer* cb)
{
    if (bufferEmpty(cb)) return INT_MIN;

    int result = cb->buff[cb->head];
    cb->head = (cb->head+1)%cb->size;
    
    return result;
}