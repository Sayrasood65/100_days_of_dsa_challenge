/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        // Create new node
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        // If list is empty
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traverse and print list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}