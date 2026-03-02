/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    int n, x;
    struct node *head = NULL, *tail = NULL, *newnode, *temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}