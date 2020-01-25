#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "trie.h"

//create new node
node* newNode()
{
    node* newOne = (node*)malloc(sizeof(node));
    newOne->count = 0;
    newOne->isLeaf = false; 
    size_t i;
    for (i = 0; i <Letters; i++)
    {
        newOne->children[i] = NULL;
    }
    return newOne;
}

//insert to the tree
void insert(node* root , char* str)
{
    node* pointer = root;
    size_t i = 0;
    for (i = 0; i < (int)strlen(str); i++)
    {
        if(!pointer->children[*(str + i) - 97])
        {
            pointer->children[*(str + i) - 97] = newNode();
            pointer->children[*(str + i) - 97]->letter = str[i];
        }
        pointer = pointer->children[*(str + i) - 97];
    }
    pointer->isLeaf=true;
    pointer->count == pointer->count + 1;
}

//print the tree
void print(node* root , char arr[] , int level)
{
    node* pointer = root;
    int i;
    if(pointer == NULL)
    {
        return;
    }
    
    if(pointer->isLeaf != false)
    {
        arr[level]='\0';
        printf("%s \t %ld \n" , arr , pointer->count);
    }
    
    for(i = 0; i < Letters;i++)
    {
        if(pointer->children[i] != NULL)
        {
            arr[level] = pointer->children[i]->letter;
            print(pointer->children[i] , arr , level + 1);
        }
    }

}

//print the tree in reverse
void printReverse(node* root , char arr[] , int level)
{
    node* pointer = root;
    int i;
    if(pointer == NULL)
    {
        return;
    }
    
    
    for(i = Letters; i >= 0; i--)
    {
        if(pointer->children[i] != NULL)
        {
            arr[level] = pointer->children[i]->letter;
            printReverse(pointer->children[i] , arr , level + 1);
        }
    }
    
    if(pointer->isLeaf != false)
    {
        arr[level] = '\0';
        printf("%s %ld \n" , arr , pointer->count);
    }
}

//free the memory of the tree
void FreeTheTree(node* root)
{
    node* pointer = root;
    size_t i;
    for (i = 0; i < Letters; i++)
    {
        if (pointer->children[i] != NULL)
        {
            FreeTheTree(pointer->children[i]);
        }
    }
    free(pointer);
}




