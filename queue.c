/***********************************************************
*
* @title: Queue File
* @author: Alexander Mark Thompson
* @description: This file creates a queue, and has functions
*               to operate on that queue.
*
************************************************************/

#include "queue.h"
#include "binaryTree.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Created because they are used for functions that are
// above them being created.
static que *newQueueNode();
static void insertNodeBefore(que *, que *);

/**
* Returns a Queue structure that can be edited in other code.
*
* @param void
* @return a queue structure
*/
queHead *newQueue()
{
    queHead *queue = (queHead *) malloc(sizeof(queHead));
    queue->head = NULL;
    queue->size = 0;
    return queue;
}

/**
* Enqueues to the front of the queue.
*
* @param *he {queHead} a queue node that contains the head
* @param *val {binTree} a binary tree node
*/
void EnqueueFront(queHead *he, binTree *val)
{
    que *queue = newQueueNode();
   
    queue->value = val;
   
    if(he->size == 0)
    {
	he->head = queue;
        queue->front = queue;
        queue->rear = queue;
    }
    else
    {
	insertNodeBefore(he->head, queue);
    }
   
    he->head = queue;
    he->size++;
}

/**
* Enqueues to the back of the queue.
*
* @param *he {queHead} a queue node that contains the head
* @param *val {binTree} a binary tree node
*/
void EnqueueBack(queHead *he, binTree *val)
{
    que *queue = newQueueNode();
    queue->value = val;
   
    if(he->size == 0) 
    {
	he->head = queue;
        queue->front = queue;
        queue->rear = queue;
    }
    else
    {
	insertNodeBefore(he->head, queue);
    }

    he->size++;
}

/**
* Returns a binary tree node when dequeueing from the
* front of a queue.
*
* @param *he {queHead} a queue node that contians the head
* @return a binary tree node
*/
binTree *DequeueFront(queHead *he)
{
    assert(he->size > 0);

    que *temp = he->head;
    binTree *v = he->head->value;

    if(he->size == 1)
    {
	he->head = NULL;
    }
    else
    {
	temp->rear->front = temp->front;
        temp->front->rear = temp->rear;
        he->head = temp->front;
    }

    free(temp);
    he->size--;
 
    return v;
}

/**
* Returns a binary tree node when dequeueing from the
* back of a queue.
*
* @param *he {queHead} a queue node that contains the head.
* @return binary tree node
*/
binTree *DequeueBack(queHead *he)
{
    assert(he->size > 0);

    que *temp = he->head->rear;
    binTree *v = temp->value;

    if(he->size == 1)
    {
	he->head = NULL;
    }
    else
    {
	temp->rear->front = temp->front;
        temp->front->rear = temp->rear;
    }

    free(temp);
    he->size--;
  
    return v;
}

/**
* Destroys the Queue
*
* @param *he {queHead} a queue node that contains the head
*/
void destroyTheQueue(queHead *he)
{
    assert(he->size == 0);
    free(he);
}

static void insertNodeBefore(que *oldNode, que *newNode)
{
    newNode->front = oldNode;
    newNode->rear = oldNode->rear;
    newNode->front->rear = newNode;
    newNode->rear->front = newNode;
}

static que *newQueueNode()
{
    que *node = (que *) malloc(sizeof(que));
    if(node == 0) { fprintf(stderr, "out of memory"); exit(-1); }
    return node;
}
