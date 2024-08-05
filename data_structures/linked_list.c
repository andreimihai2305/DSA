#include <stdio.h>
#include "./linked_list.h"


int main(void)
{
    printf("Hello from LinkedList\n");
    Node head = {0};
    
   
    if (init_list(&head) != 0)
    {
        printf("ERROR: Could not allocate list.\n");
        return 1;
    }

    head.value = 1;
    append_node(&head, 2);
    append_node(&head, 3);
    append_node(&head, 4);
    add_node(&head, 2, 5);
    
    printf("5: %d\n", find_node(&head, 5)); 
    printf("6: %d\n", find_node(&head, 6));
    
    traverse_list(&head);

    return 0;
}

