#define QUEUE_IMPLEMENTATION
#include "queue.h"
#include <stdio.h>

int main(void)
{
    Queue *q = NULL;
    q = init_queue(10);
    printf("%d\n", pop(q));
    push(q, 1);
    push(q, 2);
    push(q, 4);
    for (int i = 0; i <= q->queue->count; i++)
    {
        printf("%d\n", *(q->queue->items+i));
    }

    printf("front: %p; back: %p\n", q->front, q->back);
    pop(q);
    printf("front: %p; back: %p\n", q->front, q->back);

    pop(q);
    pop(q);
    printf("front: %p; back: %p\n", q->front, q->back);

    pop(q);
    printf("front: %p; back: %p\n", q->front, q->back);
    push(q, 10);
    push(q, 11);
    printf("front: %p; back: %p\n", q->front, q->back);

    return 0;
}
