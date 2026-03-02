/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
.*/
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};

/* Insert node at end of circular linked list */
void insert(struct node **head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;   // circular link
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = *head;      // circular link
}

/* Traverse and print circular linked list */
void display(struct node *head)
{
    if (head == NULL)
        return;

    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

/* Main function */
int main()
{
    struct node *head = NULL;
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(&head, value);
    }

    display(head);

    return 0;
}