#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int num;
  struct Node *left;
  struct Node *right;
};

int searchInTree (struct Node *, int num);
struct Node *createNode (int);
struct Node *insertNum (struct Node *, int);
void balanceTree (struct Node *);
void buildTree (struct Node **, int);
void test (struct Node *);

int
main (int argc, char **argv)
{
  int queries[20] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644,
	      1295390003, 450057883, 187645041, 1980098116, 152503, 5000,
	      1493283650, 214826, 1843349527, 1360839354, 2109248666,
	      2147470852, 0};
  int n = 0;
  int num = 0;
  struct Node *root = NULL;

  if (argc != 2)
    return 0;

  n = atoi (argv[1]);
  buildTree (&root, n);
  //root = balanceTree (root, n);
  
  for (int i = 0; i < 20; i++)
    {
      if (searchInTree (root, queries[i]) == -1)
      	printf ("Not in tree\n");
      else
        printf ("%d in tree\n", queries[i]);
    }

  return 0;
}

int 
searchInTree (struct Node *root, int num)
{
  while (root != NULL)
    {
      if (num > root->num)
        root = root->right;
      else if (num < root->num)
        root = root->left;
      else
        return 1;
    }

  return 0;
}

struct Node *
createNode (int num)
{
  struct Node *temp = (struct Node *) malloc (sizeof (struct Node));
  temp->num = num;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

struct Node *
insertNum (struct Node *node, int num)
{
  if (node == NULL)
    return createNode (num);

  if (num < node->num)
    node->left = insertNum (node->left, num);
  else if (num > node->num)
    node->right = insertNum (node->right, num);

  return node;
}

void
buildTree (struct Node **root, int n)
{
  int num = 0;

  for (int i = 0; i < n; i++)
    {
      scanf ("%d", &num);
      *root = insertNum (*root, num);
    }
}
