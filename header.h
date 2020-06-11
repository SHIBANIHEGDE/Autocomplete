#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
char s[20];

//This represents the Ternary Search tree node
 
struct Node
{
    //to store the character of a word
    char data;
    // Flag to indicate whether it is last character of one of the words
    unsigned isEndOfString: 1;
    /*
    The pointers to three children nodes which will point to a node
    whose character value is lesser, equal or greater than the current node respectively.
    */
    struct Node *left, *eq, *right;
    
};


//Defing functions used to implement auto-suggestion feature
struct Node* newNode(char data);
void insert(struct Node** root, char *word);
void traverseTSTUtil(struct Node* root, char* buffer, int depth);
void traverseTST(struct Node* root);
int searchTST(struct Node *root, char *word);
