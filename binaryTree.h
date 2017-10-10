/***************************************************
*
* @title: Binary Tree Header File
* @author: Alexander Mark Thompson
* @description: This file is a header file that is 
*               to be used in the 'binaryTree.c' 
*               file.
*
***************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTree 
{
	int value;

	struct BinaryTree *left;
	struct BinaryTree *right;
	struct BinaryTree *parent;

} binTree;

extern binTree *newTreeNode(int value, binTree *left, binTree *right, binTree *parent);
#endif
