/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find height (maximum depth) of a binary tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;           // Base case: empty tree has depth 0
    int leftDepth = maxDepth(root->left); // Recursive depth of left subtree
    int rightDepth = maxDepth(root->right); // Recursive depth of right subtree
    return 1 + max(leftDepth, rightDepth);  // Add 1 for current node
}

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue structure for level-order insertion
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};

// Function to create a queue
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->size == q->capacity) return;
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

// Dequeue operation
struct TreeNode* dequeue(struct Queue* q) {
    if (q->size == 0) return NULL;
    struct TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// Function to build tree from level-order input
struct TreeNode* buildTree(int n) {
    if (n == 0) return NULL;
    int val;
    scanf("%d", &val);
    if (val == -1) return NULL;
    
    struct TreeNode* root = newNode(val);
    struct Queue* q = createQueue(n);
    enqueue(q, root);
    
    int count = 1;
    while (count < n) {
        struct TreeNode* curr = dequeue(q);
        int leftVal, rightVal;
        
        // Read left child
        if (count < n) {
            scanf("%d", &leftVal);
            count++;
            if (leftVal != -1) {
                curr->left = newNode(leftVal);
                enqueue(q, curr->left);
            }
        }
        
        // Read right child
        if (count < n) {
            scanf("%d", &rightVal);
            count++;
            if (rightVal != -1) {
                curr->right = newNode(rightVal);
                enqueue(q, curr->right);
            }
        }
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);            // Number of nodes
    struct TreeNode* root = buildTree(n); // Build tree from input
    printf("%d\n", maxDepth(root));       // Print height of tree
    return 0;
}