#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

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
  FILE *f;
  double utime0, stime0, wtime0;
  double utime1, stime1, wtime1;
  int n = 0;
  int num = 0;
  int queries[20] =
    { 322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644,
    1295390003, 450057883, 187645041, 1980098116, 152503, 5000,
    1493283650, 214826, 1843349527, 1360839354, 2109248666,
    2147470852, 0
  };
  int searchResult = 0;
  struct Node *root = NULL;

  if (argc != 2)
    return 0;

  n = atoi (argv[1]);
  buildTree (&root, n);
  //root = balanceTree (root, n);

  for (int i = 0; i < 20; i++)
    {
      char numAnalized[25];
      char fileName[50] = "tests/";
      sprintf (numAnalized, "%d", queries[i]);
      strcat (numAnalized, "-testing.txt");
      strcat (fileName, numAnalized);
      f = fopen (fileName, "a");

      uswtime (&utime0, &stime0, &wtime0);
      searchResult = searchInTree (root, queries[i]);
      uswtime (&utime1, &stime1, &wtime1);

      if (searchResult == 0)
	fprintf (f, "%d: not in tree\n", n);
      else
	fprintf (f, "%d: in tree\n", n);

      fprintf (f, "Tiempo real: %.10f s\n", wtime1 - wtime0);
      fclose (f);
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
