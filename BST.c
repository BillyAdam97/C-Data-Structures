#include "BST.h"

struct TreeNode* createTreeNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) return NULL;
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int searchVal(struct TreeNode* root, int val)
{
    if (!root) return 0;
    if (val==root->val) {
        return 1;
    }
    else if (val<root->val) {
        return searchVal(root->left, val);
    }
    else {
        return searchVal(root->right, val);
    }
}

struct TreeNode* insertVal(struct TreeNode* root, int val)
{
    if (!root) {
        return createTreeNode(val);
    }
    else if (val<root->val) {
        root->left=insertVal(root->left, val);
    }
    else if (val>root->val){
        root->right=insertVal(root->right, val);
    }
    return root;
}

void inorderTraversal(struct TreeNode* root)
{
    if (!root) return;
    inorderTraversal(root->left);
    printf("%i,",root->val);
    inorderTraversal(root->right);
}

void preorderTraversal(struct TreeNode* root)
{
    if (!root) return;
    printf("%i,",root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode* root)
{
    if (!root) return;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    printf("%i,",root->val);
}

struct TreeNode* successor(struct TreeNode* root)
{
    struct TreeNode* tmp = root;

    while (tmp && tmp->left != NULL) {
        tmp=tmp->left;
    }

    return tmp;
}

struct TreeNode* deleteVal(struct TreeNode* root, int val)
{
    if (!root) return NULL;

    if (val<root->val) {
        root->left = deleteVal(root->left, val);
    }
    else if (val>root->val) {
        root->right = deleteVal(root->right, val);
    }
    else {
        if (!root->left) {
            struct TreeNode* tmp = root->right;
            free(root);
            return tmp;
        }
        else if (!root->right) {
            struct TreeNode* tmp = root->left;
            free(root);
            return tmp;
        }

        struct TreeNode* tmp = successor(root->right);
        root->val = tmp->val;
        root->right = deleteVal(root->right, tmp->val);
    }
    return root;
}

void freeTree(struct TreeNode* root)
{
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}