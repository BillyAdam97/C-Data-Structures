#include "Point.h"

Point* createPoint(int x, int y)
{
    Point* p = (Point*)malloc(sizeof(Point));
    if (p==NULL) return NULL;
    p->x=x;
    p->y=y;
    p->left=NULL;
    p->right=NULL;
    p->isLeaf=false;
    return p;
}

int cmpX(const void* a, const void* b)
{
    Point* a1 = (Point*) a;
    Point* b1 = (Point*) b;
    return a1->x-b1->x;
}

int cmpY(const void* a, const void* b)
{
    Point* a1 = (Point*) a;
    Point* b1 = (Point*) b;
    return a1->y-b1->y;
}

void swap(Point* p1, Point* p2)
{
    Point t = *p1;
    *p1=*p2;
    *p2=t;
}

void freePoint(Point* p)
{
    if (!p) return;
    freePoint(p->left);
    freePoint(p->right);
    free(p);
}