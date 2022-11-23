#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const size_t num_commands = sizeof (array) / sizeof (array[0])
typedef int E;

struct listNode
{
    E element;
    struct listNode *next;
};

typedef struct listNode *Node;

void initList(Node node)
{
    node->next = NULL;
}

_Bool insertList(Node head, E element, int index)
{
    if (index < 1)
    {
        return 0;
    }

    while (--index)
    {
        /* code */
        head = head->next;
    }
}

_Bool inserList(Node head,E element,int index){
    if(index<1)return 0;
    while (--index){
        head = head->next;
        if(head==NULL)return 0;
    }
    
    Node node = malloc(sizeof(struct listNode));
    if (node==NULL) return 0;
    
    node->element = element;
    head->next = node;
    
    
}

void printList(Node head){
    while (head->next){
        head = head->next;
        printf("%d",head->element);
    }
    
}
int main()
{
    struct listNode head;
    initList(&head);
    return 0;
}