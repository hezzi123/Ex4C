#include "trie.h"
// #include "Trie.c"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define A 65
#define Z 90
#define a 97
#define z 122

//main
int main(int argc, char const *argv[])
{
    int size = 256;
    char* word = (char*)malloc(sizeof(char)*size);
    char* temp = NULL;
    int counter = 0;
    int finish = 0;
    node* root = newNode();
    char ch = getchar();
    while (ch != EOF || (ch == EOF && finish != 1))
    {
        if(ch <= Z && ch >= A)
        {
            ch += 32;
        }
        if ( ch >= a && ch <= z && ch != ' ' && ch != '\0' && ch != '\t' && ch != '\n')
        {
            if(counter == size) 
            {
                temp = (char*)realloc(word , (size + 30) * sizeof(char));
                size += 30;
                if (word != NULL && temp == NULL) 
                {
                    free(word);
                    return -1;
                }
                word = (char*)calloc(size , sizeof(char));
                strcpy(word , temp);
                free(temp);
            }
            word[counter] = ch;
            counter++;

        }
        if (ch == EOF || (ch == ' ' || ch == '\0' || ch == '\t' || ch == '\n'))
        {
            word[counter] = '\0';
            if(word[0] != ' ' && counter >= 1)
            {
                insert(root , word);
            }
            counter = 0;
        }
        if(ch == EOF) 
        {
            finish = 1;
        }
        ch = getchar();
    }
    
    if (argc == 2 && strcmp(argv[1] , "r") == 0)
    {
        printReverse(root, word, 0);
    }
    else
    {
        print(root, word, 0);
    }
    FreeTheTree(root);
	free(word);
    return 0;
}