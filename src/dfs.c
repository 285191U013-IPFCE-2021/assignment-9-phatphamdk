/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"
#include <assert.h>


void DFT (node * root){
  assert(root != NULL);                                         // If root == null the tree is empty
  stack *temp = (struct stack *)malloc(sizeof(struct stack *)); // Make stack named 'temp'
  temp = push(temp, root);                                      // Push root onto stack

  while (temp != NULL)
  {
    node *toppp = temp->node;
    temp = pop(temp);

    if (toppp->rchild != NULL){
      temp = push(temp, toppp->rchild); // Pushing right child onto stack
    }
    if (toppp->lchild != NULL){ // Pushing left child onto stack
      temp = push(temp, toppp->lchild);
    }  
  }
}

node *make_node (int num, node * left, node * right){
  struct node *n;                                 // creating a node pointer
  n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
  n->num = num;                                   // Setting the data
  n->lchild = left;                               // Setting the left children to left
  n->rchild = right;                              // Setting the right children to right
  return n;                                       // Finally returning the created node
}


void free_node (node * p){
  free_node(p->lchild);
  free_node(p->rchild);
  free(p);
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
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

stack *push (stack * topp, node * node){ 
  struct stack *temp = (struct stack *)malloc(sizeof(struct stack *));
  temp->node = newnode;
  temp->next = topp;
  return temp;
}

bool isEmpty (stack * topp)
{
  return topp = NULL;
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp){
  stack *toppp;
  printf("%d, ", topp->node->num);
  toppp = topp->next; //Popping the top element.
  free(topp);
  return toppp;
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
