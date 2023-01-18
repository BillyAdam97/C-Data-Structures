#include "KDTree.h"

KDTree* createKDTree(Point* p[], int n)
{
    KDTree* tree = (KDTree*)malloc(sizeof(KDTree));
    if (tree==NULL) return NULL;
    tree->points=p;
    tree->root=insertPoints(p,0,n,0, n);
    tree->treeSize=n;
    return tree;
}

Point* insertPoints(Point* p[], int start, int end, int depth, int n)
{
    if (start>=end) return NULL;
    int mid = start+(end-start)/2;
    int currDepth = depth%2;
    if (currDepth==0) {
        printf("Here1\n");
        qsort(p,n,sizeof(Point*),cmpX);
    }
    else {
        printf("Here2\n");
        qsort(p,n,sizeof(Point*),cmpY);
    }
    p[mid]->left=insertPoints(p,start,mid,depth+1, n);
    p[mid]->right=insertPoints(p,mid+1,end,depth+1, n);
    if (p[mid]->left==NULL && p[mid]->right==NULL) p[mid]->isLeaf=true;
    else p[mid]->isLeaf=false;
    return p[mid];
}

void findNearestNeighbour(Point* root, Point** best, float* currBest, Point* p, int depth)
{
    if (root==NULL) return;
    if (root->isLeaf) {
        float x = root->x-p->x;
        float y = root->y-p->y;
        float len = sqrt(x*x+y*y);
        if (len<*currBest) {
            *currBest=len;
            *best = root;
            printf("%i, %i\n", (*best)->x, (*best)->y);
        }
        return;
    }
    int d=depth%2;
    if (d==0) {
        if (p->x<root->x) {
            findNearestNeighbour(root->left, best, currBest, p, depth+1);
            if (p->x+(*currBest)>=root->x) {
                findNearestNeighbour(root->right, best, currBest, p, depth+1);
            }
        }
        else {
            findNearestNeighbour(root->right, best, currBest, p, depth+1);
            if (p->x-(*currBest)<=root->x) {
                findNearestNeighbour(root->left, best, currBest, p, depth+1);
            }
        }
    }
    else {
        if (p->y<root->y) {
            findNearestNeighbour(root->left, best, currBest, p, depth+1);
            if (p->y+(*currBest)>=root->y) {
                findNearestNeighbour(root->right, best, currBest, p, depth+1);
            }
        }
        else {
            findNearestNeighbour(root->right, best, currBest, p, depth+1);
            if (p->y-(*currBest)<=root->y) {
                findNearestNeighbour(root->left, best, currBest, p, depth+1);
            }
        }
    }
    float x = root->x-p->x;
    float y = root->y-p->y;
    float len = sqrt(x*x+y*y);
    if (len<*currBest) {
        *currBest=len;
        *best = root;
        printf("%i, %i\n", (*best)->x, (*best)->y);
    }
    return;
}

void printTree(Point* root)
{
    if (root==NULL) return;
    printf("%i, %i\n",root->x,root->y);
    printTree(root->left);
    printTree(root->right);
}

void freeKDTree(KDTree* tree)
{
    if (tree==NULL) return;
    if (tree->points!=NULL) {
        for (int i=0; i<tree->treeSize; i++) {
            if (tree->points[i]!=NULL) free(tree->points[i]);
        }
    }
    free(tree);
}