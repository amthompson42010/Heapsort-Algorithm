/***********************************************************
*
* @title: Queue Header File
* @author: Alexander Mark Thompson
* @description: This file creates structures for queue nodes
*               and defines functions used in 'queue.c'
*
************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_

#include "binaryTree.h"

typedef struct Queue
{
    binTree *value;
    struct Queue *front;
    struct Queue *rear;
} que;

typedef struct queueHead
{

    que *head;
    int size;

} queHead;

extern queHead *newQueue();
extern void EnqueueFront(queHead *h, binTree *v);
extern binTree *DequeueFront(queHead *h);
extern void EnqueueBack(queHead *h, binTree *v);
extern binTree *DequeueBack(queHead *h);
extern void destroyTheQueue(queHead *h);

#endif
