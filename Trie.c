#include "Trie.h"

struct Trie* createTrie(char c)
{
    struct Trie* trie = (struct Trie*)malloc(sizeof(struct Trie));
    if (!trie) return NULL;
    trie->letter = c;
    trie->isWord = 0;
    for (int i=0; i<26; i++) {
        trie->children[i] = NULL;
    }
    return trie;
}

void insertWord(struct Trie* trie, char* str)
{
    struct Trie* root = trie;
    int ind;
    for (int i=0; str[i]!='\0'; i++) {
        ind = (int)str[i]-'a';
        if (root->children[ind]==NULL) {
            root->children[ind]=createTrie(str[i]);
        }
        root=root->children[ind];
    }
    root->isWord = 1;
}

int searchWord(struct Trie* trie, char* str)
{
    struct Trie* root = trie;
    int ind;
    for (int i=0; str[i]!='\0'; i++) {
        ind = (int)str[i]-'a';
        if (root->children[ind]==NULL) {
            return 0;
        }
        root=root->children[ind];
    }
    if (root!=NULL && root->isWord) {
        return 1;
    }
    return 0;
}

int searchPrefix(struct Trie* trie, char* str)
{
    struct Trie* root=trie;
    int ind;
    for (int i=0; str[i]!='\0'; i++) {
        ind = (int)str[i]-'a';
        if (root->children[ind]==NULL) {
            return 0;
        }
        root=root->children[ind];
    }
    if (root!=NULL) {
        return 1;
    }
    return 0;
}

void freeTrie(struct Trie* trie)
{
    for (int i=0; i<26; i++) {
        if (trie->children[i]) {
            freeTrie(trie->children[i]);
        }
    }
    free(trie);
}