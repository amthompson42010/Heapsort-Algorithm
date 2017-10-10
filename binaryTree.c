/***********************************************************
*
* @title: Binary Tree Node Creation
* @author: Alexander Mark Thompson
* @description: This file creates nodes for a binary tree
*               and then I create a function that initiates
*               the values for the node.
*
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

// Since newNode is used in newTreeNode
static binTree *newNode(void);

/**
* Returns a binary tree that can be edited later in the program.
*
* @param v {int} an integer value
* @param *l {binTree} a binary tree node for the left child
* @param *r {binTree} a binary tree node for the right child
* @param *p {binTree} a binary tree node for the parent node
* @return the binary tree
*/
binTree *newTreeNode(int v, binTree *l, binTree *r, binTree *p)
{
	binTree *tree = newNode();
	tree->value = v;
	tree->left = l;
	tree->right = r;
	tree->parent = p;
	return tree;
}

static binTree *newNode()
{
	binTree *n = (binTree *) malloc(sizeof(binTree));
	if(n == 0) { fprintf(stderr, "out of memory"); exit(-1); }
	return n;
}
