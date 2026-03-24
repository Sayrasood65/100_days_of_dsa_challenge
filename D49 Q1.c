/*Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder Traversal (Sorted Output)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n, val, x;
    struct TreeNode* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertIntoBST(root, x);
    }

    // Value to insert
    scanf("%d", &val);

    // Insert new value
    root = insertIntoBST(root, val);

    // Output (Inorder traversal)
    inorder(root);

    return 0;
}