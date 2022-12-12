#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createTreeNode(int val);
int searchVal(struct TreeNode* root, int val);
struct TreeNode* insertVal(struct TreeNode* root, int val);
void printBST(struct TreeNode* root);
void inorderTraversal(struct TreeNode* root);
void preorderTraversal(struct TreeNode* root);
void postorderTraversal(struct TreeNode* root);
struct TreeNode* successor(struct TreeNode* root);
struct TreeNode* deleteVal(struct TreeNode* root, int val);
void freeTree(struct TreeNode* root);

#endif