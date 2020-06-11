
//Creating a new ternary search tree node
struct Node* newNode(char data)
{
    struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
    //initializating new node
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}

//Inserting words from dictionary into a Ternary Search Tree
void insert(struct Node** root, char *word)
{
    // If the tree is empty
    if (!(*root))
        *root = newNode(*word);//root will refer to the new word

    // If current character to be inserted is smaller than root node value, then move left.
    if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);// insert this word in left subtree of root

    // If current character to be inserted is greater than root node value, then move right.
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);// insert this word in right subtree of root

    // If current character to be inserted is equal to the node value, then move to middle.
    else
    {
        //if it's not the last character of the word
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);//then root becomes root->eq and the next character is sent to the insert function

        // the last character of the word
        else
            (*root)->isEndOfString = 1;//then set the endofstring to 1-->to indicate the string is complete
    }
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
	    printf("%s",s);
            printf( "%s\n",buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth + 1);

        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

// Searching a Node in the Ternary Search Tree
int searchTST(struct Node *root, char *word)
{
    //if root is empty then return 0
    if (!root)
        return 0;
 /*If current character of word is smaller than root's character,
 then search for this word in left subtree of root*/
    if (*word < (root)->data)
        return searchTST(root->left, word);
 /*If current character of word is greater than root's character,
 then search for this word in left subtree of root*/
    else if (*word > (root)->data)
        return searchTST(root->right, word);
 /*If current character of word is equal to root's character,
 then search for this word in the equality subtree of root*/
    else
    {
        if (*(word+1) == '\0')//if last character of the word
          {
	    traverseTST(root->right);//then traverse the right sub-tree
	    traverseTST(root->left);//then traverse the left sub-tree
	    traverseTST(root->eq);//then traverse the equality sub-tree

          }

        return searchTST(root->eq, word+1);/*call searchTST function till its the last charcter of the word*/
    }
}
