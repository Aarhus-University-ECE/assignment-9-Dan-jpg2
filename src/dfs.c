/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  printf("tree: \n");
  print_tree(root, 0);
  printf("\n depth first search with stack: \n");

  // creating stack
  stack *stack = malloc(sizeof(stack));
  node *temp = root;

  //push root node
  printf("%d, ", root->num);
  stack = push(stack, root);
  temp -> visited = true;
  bool done = false; 

  while (!done) 
  {
    while(temp -> lchild !=NULL) //keep moving to the left as far as possible and notes them as marked and "visited"
    {
      temp = temp -> lchild;
      printf("%d, ,", temp -> num); 
      stack = push(stack, temp); 

      temp -> visited = true; // Visited notes if the node has been "visited" and marked as a leafnode by parent
    } 
  // checks if nodes has child nodes left to examine. If not find own parent node and temp points to it. 
   while ((temp -> lchild == NULL || temp -> lchild -> visited == true) && (temp -> rchild == NULL || temp -> rchild -> visited == true))
   {
    if (stack -> next -> node == root && root -> rchild -> visited == true)
    {
      done = true;
    }
    stack = pop(stack);
    temp = stack -> node; 
   
   if (done)
   {
    break; 
   }
  }
  if (done)
  {
    break;
  }

  temp = temp -> rchild;
  printf("%d, ", temp -> num);
  stack = push(stack, temp);
  temp -> visited  = true;
}
  printf("\n"); 
}

node *make_node (int num, node * left, node * right)
{
	 node *treePointer = malloc(sizeof(node));

  //node with num, left & right child and wether or not visited
  (treePointer) -> num = num;
  (treePointer) -> visited = false;
  (treePointer) -> lchild = left;
  (treePointer) -> rchild = right; 

  return treePointer;  
}

void free_node (node * p) 
{
	free(p);
}


void print_node (node * p)
{
  if (p == NULL)
    printf("NULL\n");
  else 
    printf("%d", p -> num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1);
  printf (" ");
  printf ("| ");
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);
    

  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1); 
}

stack *push (stack * topp, node * node)
{
	stack *t = malloc(sizeof(stack)); //Create new stack node 

  t -> next = topp; //Add the tree node to add
  t -> node = node; //add previos topp node
  return t;   
}

bool isEmpty (stack * topp)
{
  return false; 
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 
// Pops first node in stack. Returns node after
// returned pointer points to parrent node. 
stack *pop (stack * topp) 
{
  stack *temp = topp;
  topp = topp -> next;
  free (temp);

  return topp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
