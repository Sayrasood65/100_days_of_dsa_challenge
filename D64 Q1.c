/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>

#define MAX 100

// DFS function
void dfs(int v, int visited[], int adj[MAX][MAX], int n) {
    printf("%d ", v);     // print current node
    visited[v] = 1;       // mark as visited

    // visit all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }
}

int main() {
    int n, adj[MAX][MAX], visited[MAX] = {0};
    int s;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Perform DFS
    printf("DFS Traversal: ");
    dfs(s, visited, adj, n);

    return 0;
}