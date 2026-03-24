/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

// Define structure (needed for normal C, not LeetCode)
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);
    
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

// Find LCA in BST
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Find LCA
    struct TreeNode* lca = findLCA(root, p, q);

    // Output
    if (lca != NULL)
        printf("%d\n", lca->val);

    return 0;
}