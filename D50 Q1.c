/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

// Preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n, val, x;
    struct TreeNode* root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        printf("Not Found");
    } else {
        preorder(result);
    }

    return 0;
}