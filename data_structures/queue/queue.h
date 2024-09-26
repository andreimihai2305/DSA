#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include "dynamic_array.h"


typedef struct  {
    DynamicArray* queue;
    int* front;
    int* back;
} Queue;

Queue* init_queue(int size);
int push(Queue* q, int item);
int pop(Queue* q);
int front(Queue* q);
int back(Queue* q);
int size(Queue* q);
bool empty(Queue* q);

#ifdef QUEUE_IMPLEMENTATION

Queue* init_queue(int size)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) return NULL;
    q->queue = (DynamicArray*)malloc(sizeof(DynamicArray));

    d_alloc(q->queue,  size);
    q->front = q->queue->items;
    q->back  = q->queue->items;

    return q;
}

int push(Queue* q, int item)
{
    if (q == NULL || q->queue == NULL) return -1;

    if (dynamic_append(q->queue, item) != 0) return -1;

    if (q->queue->count > 1) q->back += 1;

    return 0;

}

int pop(Queue* q)
{
    if (q == NULL || q->queue == NULL || q->queue->count == 0) return -1;
    int item = *q->front;
    q->queue->count--;
    q->front += 1;
    if (q->front > q->back)
    {
        q->front = q->queue->items;
        q->back = q->queue->items;
    }
    return item;
}

int front(Queue* q)
{
    if (q == NULL || q->queue == NULL || q->queue->count == 0) return -1;
    return *q->front;

}
int back(Queue* q)
{
    if (q == NULL || q->queue == NULL || q->queue->count == 0) return -1;
    return *q->back;
}

int size(Queue* q)
{
    if (q == NULL || q->queue == NULL) return -1;
    return q->queue->count - 1;
}

bool empty(Queue* q)
{
    if (q == NULL || q->queue == NULL) return true;
    else if (q->queue->count == 0) return true;
    else return false;
}

#endif // QUEUE_IMPLEMENTATION

#endif // QUEUE_H
