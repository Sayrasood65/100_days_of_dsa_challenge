/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order array
struct Node* buildTree(int arr[], int i, int n) {
    if (i >= n)
        return NULL;

    struct Node* root = newNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree (CBT)
int isCBT(struct Node* root, int index, int totalNodes) {
    if (root == NULL)
        return 1;

    if (index >= totalNodes)
        return 0;

    return isCBT(root->left, 2*index + 1, totalNodes) &&
           isCBT(root->right, 2*index + 2, totalNodes);
}

// Check Min Heap property
int isMinHeap(struct Node* root) {
    // Empty or leaf node
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 1;

    // Only left child exists
    if (root->right == NULL) {
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    }

    // Both children exist
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

// Main function to check Min Heap
int checkMinHeap(struct Node* root) {
    int totalNodes = countNodes(root);

    if (isCBT(root, 0, totalNodes) && isMinHeap(root))
        return 1;
    else
        return 0;
}

// Driver Code
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order traversal:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    if (checkMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}