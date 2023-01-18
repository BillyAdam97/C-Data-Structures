#ifndef POINT_H
#define POINT_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Point
{
    int x;
    int y;
    bool isLeaf;
    struct Point* left;
    struct Point* right;
} Point;

Point* createPoint(int x, int y);
int cmpX(const void* a, const void* b);
int cmpY(const void* a, const void* b);
void swap(Point* p1, Point* p2);
void freePoint(Point* p);
#endif