#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct {
    int size;
    int count;
    int *items;

} Stack;

int make_stack(Stack* stack, int size);
void free_stack(Stack* stack);
void push(Stack* s, int item);
int pop(Stack* s);
int top(Stack* s);
int size(Stack* s);
int empty(Stack* s);
void clear(Stack* s);

#ifdef STACK_IMPLEMENTATION

int make_stack(Stack* stack, int size)
{
    stack->size = size;
    stack->count = 0;
    stack->items = malloc(size*sizeof(int));
    if (stack->items == NULL) return -1;
    return 0;
}

void free_stack(Stack* stack)
{
    free(stack->items);
}

void push(Stack* s, int item)
{
    if (s->count < s->size) s->items[s->count++] = item;
    else {
        s->size *= 2;
        s->items = realloc(s->items, (s->size)*sizeof(int));
        s->items[s->count++] = item;
    }
}

int pop(Stack* s)
{
    s->count--;
    return s->items[s->count];
}

int top(Stack* s)
{ 
    return s->items[s->count - 1];
}

int size(Stack* s)
{
    return s->count;
}

int empty(Stack* s)
{
    if (s->count == 0) return 1;
    return 0;
}

void clear(Stack* s)
{
    s->count = 0;
}

#endif // STACK_IMPLEMENTATION
#endif // STACK_H
