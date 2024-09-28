#include <stdio.h>
#define BINARY_TREE_IMPLEMENTATION
#include "binary_tree.h"

int main(void)
{
    
    Node n = {0};
    make_tree(&n);
    add_node(&n, LEFT);
    add_node(&n, RIGHT);
    add_node(n.left, RIGHT);

    printf("root left:  %p\n", n.left);
    printf("root right: %p\n", n.right);
    printf("root left -> left:    %p\n", n.left->left);
    printf("root left -> right:   %p\n", n.left->right);
    printf("root right -> left:   %p\n", n.right->left);
    printf("root right -> right:  %p\n", n.right->right);

    return 0;
}
