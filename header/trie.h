#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../header/linkedList.h"
#include "../header/record.h"

#define MAX_KEYS 37

struct trieNode {

    struct trieNode *parent;
    struct trieNode *child[MAX_KEYS];
    bool isLeaf;
    struct listNode *dataList;
};

static int getChildIndex(char);
static bool isLeaf(struct trieNode *);
struct trieNode * createTrieNode(void);
static void freeTrieNode(struct trieNode *, void freeData(void *));
struct trieNode * retrieveTrieNode(struct trieNode *, char *);
void addToTrie(struct trieNode *, char *, void *);
void deleteFromTrie(struct trieNode *, char *, struct record *, void freeData(void *));
void freeTrie(struct trieNode *, void freeData(void *));

#endif