#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct Bucket {
    struct BucketNode* head;  
};

struct BucketNode {
    uint64_t key;
    int value;
    struct BucketNode* next;
};

struct HashMap {
    int size;
    int items;
    struct Bucket* arr;
};

struct HashMap* createHM(int sizeofHM);
int hmGet(struct HashMap* hm, uint64_t key);
uint32_t hash(struct HashMap* hm, uint64_t key);
int findHM(struct HashMap* hm, uint64_t key);
void insertHM(struct HashMap* hm, uint64_t key, int value);
void eraseHM(struct HashMap* hm, uint64_t key);
void freeHM(struct HashMap* hm);
int sizeHM(struct HashMap* hm);

#endif