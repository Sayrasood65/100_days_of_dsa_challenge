/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// DFS function to detect cycle
bool dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        // If visited and in recursion stack → cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove from recursion stack
    recStack[node] = 0;
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Adjacency list
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    // Input edges (directed)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));

    // Check each component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}