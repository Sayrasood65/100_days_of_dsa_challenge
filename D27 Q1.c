/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *tail = NULL, *newnode;
    int x;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

int getLength(struct node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

struct node* findIntersection(struct node *head1, struct node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2)
        while (diff--) head1 = head1->next;
    else
        while (diff--) head2 = head2->next;

    while (head1 && head2)
    {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main()
{
    int n, m;
    struct node *head1, *head2, *intersection;

    scanf("%d", &n);
    head1 = createList(n);

    scanf("%d", &m);
    head2 = createList(m);

    /* 
       NOTE (IMPORTANT):
       For real intersection, you must connect second list to a node
       of first list manually (usually done by test case internally).
    */

    intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}