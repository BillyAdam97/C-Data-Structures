#include "LinkedList.h"

struct LinkedList* createLL()
{
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head=NULL;
    list->tail=NULL;
    list->size=0;
    return list;
}

void addHead(int value, struct LinkedList* list)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = value;
    node->next = NULL;
    node->prev = NULL;
    if (!list->head) {
        list->head=node;
        list->tail=node;
    }
    else {
        node->next = list->head;
        node->prev = list->head->prev;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}

void addTail(int value, struct LinkedList* list)
{
    if (!list->tail) {
        addHead(value,list);
        return;
    }
    else {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->val = value;
        node->next = NULL;
        node->prev = NULL;
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        list->size++;
    }
}

void addAtIndex(int value, int index, struct LinkedList* list)
{
    if (index<0 || index>list->size) return;
    if (index==0) {
        addHead(value,list);
        return;
    }
    else if (index==list->size) {
        addTail(value,list);
        return;
    }
    else {
        int half;
        if (list->size) half = list->size/2;
        else half =0;
        struct Node* tmp = NULL;
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->val = value;
        node->next = NULL;
        node->prev = NULL;
        if (index<=half) {
            tmp = list->head;
            for (int i=0; i<index-1; i++) {
                tmp=tmp->next;
            }
            node->next = tmp->next;
            node->prev = tmp;
            node->next->prev = node;
            tmp->next = node;
        }
        else {
            tmp = list->tail;
            for (int i=list->size-1; i>index; i--) {
                tmp=tmp->prev;
            }
            node->next = tmp;
            node->prev = tmp->prev;
            node->prev->next = node;
            tmp->prev = node;
        }
        list->size++;
    }
}

void removeAtIndex(int index, struct LinkedList* list)
{
    if (index<0 || index>=list->size) return;
    if (!list->head) {
        return;
    }
    if (index==0) {
        struct Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        list->size--;
        return;
    }
    else if (index==list->size-1) {
        struct Node* tmp = list->tail;
        list->tail = list->tail->prev;
        free(tmp);
        list->size--;
        return;
    }
    else {
        int half;
        if (list->size) half = list->size/2;
        else half =0;
        struct Node* tmp = NULL;
        struct Node* tmp2 = NULL;
        if (index<=half) {
            tmp = list->head;
            for (int i=0; i<index-1; i++) {
                tmp = tmp->next;
            }
            tmp2 = tmp->next;
            tmp->next = tmp2->next;
            tmp2->next->prev = tmp;
            free(tmp2);
            list->size--;
        }
        else {
            tmp = list->tail;
            for (int i=list->size-1; i>index; i--) {
                tmp = tmp->prev;
            }
            tmp2 = tmp->prev;
            tmp->prev = tmp2->prev;
            tmp2->prev->next = tmp;
            free(tmp2);
            list->size--;
        }
    }
}

int getHead(struct LinkedList* list)
{
    return list->head->val;
}

int getTail(struct LinkedList* list)
{
    return list->tail->val;
}

int getByIndex(int index, struct LinkedList* list)
{
    if (index<0 || index>=list->size) {
        return -1;
    }
    if (!list->head) {
        return -1;
    }
    if (index==0) {
        return list->head->val;
    }
    else if (index==list->size-1) {
        return list->tail->val;
    }
    else {
        int half;
        if (!list->size) {
            half = list->size/2;
        }
        else {
            half=0;
        }
        struct Node* tmp=NULL;
        if (index<=half) {
            tmp = list->head;
            for (int i=0; i<index; i++) {
                tmp=tmp->next;
            }
        }
        else {
            tmp = list->tail;
            for (int i=list->size-1; i>index; i--) {
                tmp=tmp->prev;
            }
        }
        return tmp->val;
    }
    return -1;
}

int sizeofLL(struct LinkedList* list)
{
    return list->size;
}

void freeLL(struct LinkedList* list)
{
    struct Node* tmp;
    while (list->head) {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
    free(list);
}