#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

struct Node {
    struct Node *parent;
    struct Node *left;
    struct Node *right;

};

typedef struct Node Node;

typedef enum {
    LEFT,
    RIGHT
} Direction;


void make_tree(Node *root);
int add_node(Node *node, Direction dir);

#ifdef BINARY_TREE_IMPLEMENTATION

void make_tree(Node *root)
{
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
}

int add_node(Node *node, Direction dir)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return -1;
    new_node->parent = node;
    new_node->left = NULL;
    new_node->right = NULL;

    if (dir == LEFT) node->left = new_node;
    else node->right = new_node;
    return 0;
}



#endif // BINARY_TREE_IMPLEMENTATION
#endif // BINARY_TREE_H 
