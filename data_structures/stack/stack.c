#include <stdio.h>
#define STACK_IMPLEMENTATION
#include "stack.h"


int main(void)
{
    Stack s = {0};
    if (make_stack(&s, 10) < 0) {
        printf("[ERROR] Could not allocate stack!\n");
        exit(1);
    }
    printf("Allocated Stack Succesfully!\n");

    push(&s, 10);
    push(&s, 10);
    push(&s, 11);
    push(&s, 154);
   
    printf("top: %d\n", top(&s));

    for (int i = 0; i < s.count; i++)
    {
        printf("%d ", s.items[i]);
    }
    printf("\n");

    printf("pop: %d\n", pop(&s));

    for (int i = 0; i < s.count; i++)
    {
        printf("%d ", s.items[i]);
    }

    printf("\n");
    printf("top:   %d\n", top(&s));
    printf("size:  %d\n", size(&s));
    printf("empty: %d\n", empty(&s));
    free_stack(&s);

    return 0;
}
