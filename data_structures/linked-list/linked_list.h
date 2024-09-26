#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{

    int value;
    struct Node* next;

};
typedef struct Node Node;

int init_list(Node* head);
int append_node(Node* head, int value);
int add_node(Node* head, int pos, int value);
bool find_node(Node* head, int key);
void traverse_list(Node* head);

int init_list(Node* head)
{
    head = (Node*)malloc(sizeof(Node));
    if (head == NULL) return -1;
    return 0;
}

int append_node(Node* head, int value)
{
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    Node* new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL) return -1;

    new_node->value = value;
    new_node->next = NULL;
    temp->next = new_node;
    
    return 0;
}

int add_node(Node* head, int pos, int value)
{
    Node* temp = head;
    Node* prev;
    for (int i = 0; i < pos && temp->next != NULL; i++) 
    {   
        prev = temp;
        temp = temp->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return -1;

    new_node->value = value;
    prev->next = new_node;
    new_node->next = temp;

    return 0;
}

bool find_node(Node* head, int key)
{
    Node* temp = head;

    while(temp->next != NULL)
    {
        if(temp->value == key) return true;
        temp = temp->next;
    }
    return false;

}


void traverse_list(Node* head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        printf("Node Value: %d ---> ", temp->value);
        temp = temp->next;
    }


    printf("Node Value: %d\n", temp->value);

}

#endif // LINKED_LIST
