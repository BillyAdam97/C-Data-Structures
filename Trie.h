#ifndef TRIE_H
#define TRIE_H
#include <stdlib.h>
#include <stdio.h>

struct Trie {
    char letter;
    struct Trie* children[26];
    int isWord;
};

struct Trie* createTrie(char c);
void insertWord(struct Trie* trie, char* str);
int searchWord(struct Trie* trie, char* str);
int searchPrefix(struct Trie* trie, char* str);
void freeTrie(struct Trie* trie);

#endif