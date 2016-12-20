#include <stdio.h>
#include <time.h>
#include <io.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "uniter.h"
#define BUFSIZE 50

#define MAX(a,b) ((a)>(b) ? a : b)
#define getrandom( min, max ) ((rand() % (int)((max) - (min))) + (min) + 1)
int l=12,c=1,x;

typedef struct node {
	     char *name;
	     struct node *left;
	     struct node *right;
	    };

typedef struct node *Link;
int FileTree;


char *GetRandWord()
{
char *p;
int len,i;

len = 3 + (rand() % 11);
p = (char *) malloc(len + 1);

for(i=0; i < len; i++)
  p[i] = (char) (65 + (rand() % 26));
p[len] = '\0';
return(p);
}

void TSort(root,str)
Link *root;
char *str;
{
 if (*root == NULL)
  {
    *root = (Link) malloc(sizeof(struct node));
   (*root)->name = str;
   (*root)->left=NULL;
   (*root)->right=NULL;
  }
 else
  {
   if(strcmp(str,(*root)->name)>0)
     TSort(&(*root)->right,str);
   else
     TSort(&(*root)->left,str);
  }
}


void SaveTree(root)
Link root;
{
 if (root != NULL)
  {
    SaveTree(root->left);
    write(FileTree,(char *) root->name, strlen(root->name)+1);
    SaveTree(root->right);
  }
}

void Show(root)
Link root;
{
 if (root != NULL)
  {
    Show(root->left);
    puts(root->name);
    Show(root->right);
  }
}


void ReadFile()
{
 int num;
 char *str;
 char pstr[BUFSIZE];

str = pstr;

while (read(FileTree,str,1) == 1) {
   if (*str == '\0') {
     puts(pstr);
     str = pstr;
     }
   else
   str++;
  }
}

int DeepTree(root)
Link root;
{
  if (root==NULL)
    {
     return 0;
    }
  else
    {
      return MAX(DeepTree(root->left), DeepTree(root->right) + 1);
    }
}


main()
{
 Link first=NULL;
 int i,prof=0;
 srand(time(NULL));

 for(i=0;i<10;i++)
     TSort(&first,GetRandWord());
 printf(CLR);
 if ((FileTree=open("albero.dat",O_BINARY | O_CREAT | O_WRONLY)) == -1)
   {
    perror("albero.dat");
    exit(-1);
   }

 puts("Show :");
 Show(first);
 puts("\nFile:");
 SaveTree(first);
 close(FileTree);
 if ((FileTree=open("albero.dat",O_RDONLY | O_BINARY)) == -1)
   {
    perror("albero.dat");
    exit(-1);
   }
 ReadFile();
 close(FileTree);
 printf("L'albero e' profondo: %d\n", DeepTree(first));
}
