/***********************************************************
*
* @title: Heap Sorting File
* @author: Alexander Mark Thompson
* @description: This file is the main funcitonality of the 
*               heapsort program. It reads in integers from
*               a given file, and then creates a binary tree
*               with them. Then it heapifies the data, which
*               simultaneously sorts it. Then the data is 
*               returned given the various options available
*               to the user.
*
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include "binaryTree.h"
#include "queue.h"
#include <time.h>

void heapify(binTree *node);
int compare(int, int);
int ProcessOptions(int, char **);
void Fatal(char *, ...);
char *fileName = 0;
int isD = 0;

int main(int argc, char *argv[])
{
    /** Used for the emperical evidence part,
    and left in to ensure I did not just copy
    the values from somewhere.
    clock_t begin, end;
    double time_spent;
    begin = clock();
    */

    int argumentIndex = 0;

    if(argc == 1) Fatal("%d arguments! \n", argc-1);

    argumentIndex = ProcessOptions(argc, argv);

    if(argumentIndex == argc){}

    int ch = 0;
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer == 0)
    {
	fprintf(stderr, "File could not be opened.\n");
        exit(0);
    }
    
    // Creates a new queue called q
    queHead *q = newQueue();
    // Creates a stack with a queue like structure
    queHead *stack = newQueue();

    // Where the root of the tree is created and initialized.
    fscanf(filePointer, "%d", &ch);
    binTree *root = newTreeNode(ch, NULL, NULL, NULL);
    binTree *current = root;

    // This sections is where the binary tree is actually 
    // created.
    fscanf(filePointer, "%d", &ch);
    while(!feof(filePointer))
    {
	binTree *node = newTreeNode(ch, NULL, NULL, NULL);
        if(current->left != NULL && current->right != NULL)
        {
	    binTree *temp = DequeueFront(q);
       	    EnqueueFront(stack, current);
            current = temp;
        }
        if(current->left == NULL)
        {
	    current->left = node;
   	    node->parent = current;
  	    EnqueueBack(q, node);
	}
        else if(current->right == NULL)
	{
	    current->right = node;
   	    node->parent = current;
	    EnqueueBack(q, node);
        }
	fscanf(filePointer, "%d", &ch);
    }
    EnqueueFront(stack, current);
    
    /**
    *  Remaining Nodes get pushed to the queue that is 
    *  acting as a stack.
    */
    while(q->size != 0)
    {
	binTree *temp = DequeueFront(q);
        EnqueueFront(stack, temp);
    }

    fclose(filePointer);
    
    /**
    *   Pops off stack, then adding to the queue for a 
    *   reverse level order, then heapifying.
    */
    while(stack->size > 0)
    {
	binTree *temp = DequeueFront(stack);
        EnqueueBack(q, temp);
	heapify(temp);
    }

    /**
    *  Properly removes the root off of the heap (i.e. 
    *  heapifying after the right most child is replaced
    *  as the root and then prints the value.
    */
    printf("Sorted Order: \n");
    while(q->size > 0)
    {
	int v = root->value;
        binTree *last = DequeueFront(q);
        root->value = last->value;

        if(last->parent != NULL)
        {
	    if(last->parent->left == last)
	    {
		last->parent->left = NULL;
  	    }
	    if(last->parent->right == last)
	    {
	   	last->parent->right = NULL;
 	    }

	    heapify(root);
	}
	free(last);
	printf("%d ", v);
    }
    printf("\n");

    // This section is used for when I was doing the emperical 
    // evidence.
    /**end = clock();
    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time taken: %lf\n", time_spent);
    */
    return 0;
}

/**
* Heapifies the binary tree.
*
* @param *treeNode {binTree} a binary tree node
*/
void heapify(binTree *treeNode)
{
    binTree *largest = NULL;
    binTree *le = treeNode->left;
    binTree *ri = treeNode->right;

    if(le != NULL && compare(le->value, treeNode->value))
    {
	largest = le;
    }
    else
    {
	largest = treeNode;
    }
    if(ri != NULL && compare(ri->value, largest->value))
    {
	largest = ri;
    }
    if(largest != treeNode)
    {
	int temp = treeNode->value;
	treeNode->value = largest->value;
	largest->value = temp;
	heapify(largest);
    }
}

/**
* Returns an integer after comparing two different
* values.
*
* @param value1 {int} First integer value
* @param value2 {int} Second integer value
* @return the less than or larger value.
*/
int compare(int value1, int value2)
{
    if(isD == 0)
    {
	return value1 < value2;
    }
    else
    {
	return value1 > value2;
    }
}

/**
* Fatal function used from options.c file
*/
void Fatal(char *fmt, ...)
{
    va_list ap;

    fprintf(stderr, "An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
}

/**
* ProcessOptions function that was used from the 
* options.c file and modified to take in to effect
* the '-v' and '-d' options.
*/
int ProcessOptions(int argc, char **argv)
{
    int argumentIndex;
    int argumentUsed;
    int separateArgument;
    char *argument;

    argumentIndex = 1;

    while(argumentIndex < argc && *argv[argumentIndex] == '-')
    {
	if(argv[argumentIndex][1] == '\0') return argumentIndex;

        separateArgument = 0;
 	argumentUsed = 0;
  	argument = 0;
        argument++;
	
	if(argv[argumentIndex][2] == '\0')
        {
	    argument = argv[argumentIndex+1];
	    separateArgument = 1;
	}
	else
	{
	    argument = argv[argumentIndex]+2;
	}
	switch(argv[argumentIndex][1])
	{
	case 'v':
	    printf("Author: Alexander Mark Thompson\nCS 201 Assignment 1\n\nMy implementation of a binary tree as a heap uses doubly linked \nlist, more so represented as a queue. Using heapify takes at \nmost log n time because it has to iterate left and right for \neach node, then it has to do this per node, so making\nthe total time complexity n log n.\n");
	    printf("\ndata size    |  my time   \n");
	    printf("-------------+------------\n");
  	    printf("      10     |  0.000243  \n");
	    printf("     100     |  0.000361  \n");
            printf("    1000     |  0.002076  \n");
	    printf("   10000     |  0.015602  \n");
	    printf("  100000     |  0.208217  \n");
	    printf(" 1000000     |  2.857984  \n");
            exit(0);
	case 'd':
	    printf("Sorting in decreasing order: \n");
	    isD = 1;
	    break;
	default:
	    Fatal("option %s not understood\n", argv[argumentIndex]);
        }
        if(separateArgument && argumentUsed)
	{
	    ++argumentIndex;
	}
	++argumentIndex;
    }
    
    fileName = argv[argc-1];

    return argumentIndex;
}
