/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

.*/
#include <stdio.h>
#include <stdlib.h>

/* Structure of linked list node */
struct node {
    int data;              // stores data
    struct node *next;     // pointer to next node
};

/* Function to create linked list */
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
    int x;

    // loop to create n nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        // allocate memory for new node
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        // if list is empty
        if (head == NULL) {
            head = temp = newNode;
        } 
        // if list already has nodes
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

/* Function to rotate linked list to the right by k places */
struct node* rotateRight(struct node* head, int k) {

    // if list is empty, has one node, or no rotation needed
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct node *temp = head;
    int count = 1;

    // count number of nodes
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // handle case when k is greater than number of nodes
    k = k % count;
    if (k == 0)
        return head;

    // make linked list circular
    temp->next = head;

    // find new tail position (n-k)th node
    int steps = count - k;
    struct node *newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    // new head is next of new tail
    struct node *newHead = newTail->next;

    // break the circular link
    newTail->next = NULL;

    return newHead;
}

/* Function to display linked list */
void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    // read number of nodes
    scanf("%d", &n);

    // create linked list
    struct node* head = createList(n);

    // read value of k
    scanf("%d", &k);

    // rotate linked list
    head = rotateRight(head, k);

    // display result
    display(head);

    return 0;
}