#include "header.h"
#include "implementation.c"
int main()
{
    struct Node *root = NULL;
    FILE* file = fopen("Dataset/word_list.txt", "r"); 
    char line[256];


   //creating the dictionary by inserting each word of the text file into the Tree implemented.
    while (fgets(line, sizeof(line), file)) {
        
	int len=strlen(line);
	if(line[len-1]=='\n')
	{
		line[len-1]=0;
	}

         insert(&root,line);//start inserting each word from the text file
    }
    fclose(file);//close the file here
    int exit = 0;
    while(!exit)
    {
        printf("Enter your text or Enter 0 to exit: ");
        scanf("%s",s);
        if(strcmp("0",s)!=0)
        {
          searchTST(root, s)? printf("\nNot Found\n"): printf("\n");
        }
        else
        {
          break;
        }

    }

    return 0;
}
