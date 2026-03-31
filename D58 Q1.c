/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTree(int preorder[], int inorder[],
                       int preStart, int preEnd,
                       int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    struct Node* root = createNode(preorder[preStart]);

    // Find root in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, preorder[preStart]);

    int leftSize = inIndex - inStart;

    // Left subtree
    root->left = buildTree(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           inIndex - 1);

    // Right subtree
    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inIndex + 1,
                            inEnd);

    return root;
}

// Postorder traversal (Left → Right → Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Input preorder
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    // Input inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    // Build tree
    struct Node* root = buildTree(preorder, inorder,
                                 0, n - 1,
                                 0, n - 1);

    // Print postorder
    postorder(root);

    return 0;
}