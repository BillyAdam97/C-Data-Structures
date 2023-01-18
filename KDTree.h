#ifndef KDTREE_H
#define KDTREE_H
#include <stdlib.h>
#include <stdio.h>
#include "Point.h"
#include <math.h>

typedef struct KDTree
{
    Point** points;
    Point* root;
    int treeSize;
} KDTree;

KDTree* createKDTree();
Point* insertPoints(Point* p[], int start, int end, int depth, int n);
void findNearestNeighbour(Point* root, Point** best, float* currBest, Point* p, int depth);
void printTree(Point* root);
void freeKDTree(KDTree* tree);

#endif