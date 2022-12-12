#include "HashMap.h"

struct HashMap* createHM(int sizeofHM)
{
    struct HashMap* hm = (struct HashMap*)malloc(sizeof(struct HashMap));
    if (!hm) return NULL;
    hm->size=sizeofHM;
    hm->items=0;
    hm->arr = (struct Bucket*)calloc(sizeofHM, sizeof(struct Bucket));
    if (!hm->arr) {
        free(hm);
        return NULL;
    }
    struct Bucket* tmp = hm->arr;
    for (int i=0; i<sizeofHM; i++, tmp++) {
        tmp->head=NULL;
    }
    return hm;
}

int hmGet(struct HashMap* hm, uint64_t key)
{
    int ind = hash(hm, key);
    struct Bucket* tmp = (hm->arr+ind);
    struct BucketNode* curr=tmp->head;
    while (curr && curr->key!=key) {
        curr=curr->next;
    }
    if (!curr) return -1;
    else return curr->value;
}

uint32_t hash(struct HashMap* hm, uint64_t key)
{
    //Robert Jenkins' bit mixing
    key = (~key) + (key<<18);
    key = key ^ (key>>31);
    key = key * 21;
    key = key ^ (key>>11);
    key = key + (key<<6);
    key = key ^ (key>>22);
    return (uint32_t) key % hm->size;
}

int findHM(struct HashMap* hm, uint64_t key)
{
    int ind = hash(hm, key);
    struct Bucket* tmp = (hm->arr+ind);
    struct BucketNode* curr=tmp->head;

    if (!curr) return 0;
    while(curr) {
        if (curr->key==key) return 1;
        curr=curr->next;
    }
    return 0;
}

void insertHM(struct HashMap* hm, uint64_t key, int value)
{
    int ind = hash(hm, key);
    struct Bucket* tmp = (hm->arr+ind);
    struct BucketNode* curr = tmp->head;
    if (!curr) {
        curr = (struct BucketNode*)malloc(sizeof(struct BucketNode));
        if (!curr) return;
        curr->key = key;
        curr->value = value;
        curr->next = NULL;
        tmp->head = curr;
        hm->items++;
        return;
    }
    while (curr->next) {
        if (curr->key==key) {
            curr->value = value;
            return;
        }
        curr=curr->next;
    }
    curr->next = (struct BucketNode*)malloc(sizeof(struct BucketNode));
    if (!curr->next) return;
    curr=curr->next;
    curr->key = key;
    curr->value = value;
    curr->next = NULL;
    hm->items++;
}

void eraseHM(struct HashMap* hm, uint64_t key)
{
    int ind = hash(hm, key);
    struct Bucket* tmp = (hm->arr+ind);
    struct BucketNode* curr = tmp->head;
    struct BucketNode* curr2 = curr->next;

    if (!curr) return;
    else if (curr->key==key) {
        tmp->head = curr2;
        free(curr);
        hm->items--;
        return;
    }
    while (curr2) {
        if (curr2->key==key) {
            curr->next = curr2->next;
            free(curr2);
            hm->items--;
            return;
        }
        curr=curr->next;
        curr2=curr2->next;
    }
    return;
}

void freeHM(struct HashMap* hm)
{
    struct Bucket* tmp;
    struct BucketNode* tmp2;
    struct BucketNode* tmp3;
    for (int i=0; i<hm->size; i++) {
        tmp = (hm->arr+i);
        if (tmp->head) {
            tmp2 = tmp->head;
            while (tmp2) {
                tmp3 = tmp2;
                tmp2 = tmp2->next;
                free(tmp3);
            }
        }
    }
    free(hm->arr);
    free(hm);
}

int sizeHM(struct HashMap* hm)
{
    return hm->items;
}