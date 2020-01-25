#ifndef TRIE_H
#define TRIE_H
#include <stdbool.h>
#define Letters 26

typedef struct node
{
    char letter;
    long unsigned int count;
    struct node* children[Letters];
    bool isLeaf;
}node;
node* newNode();

void insert(node* , char*);

void print(node* , char[] , int);

void printReverse(node* , char[] , int);

void FreeTheTree(node*);

#endif