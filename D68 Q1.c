//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
int visited[MAX];

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int n, int graph[n][n]) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i] && !visited[i]) {
            dfs(i, n, graph);
        }
    }

    push(node); // push after visiting all neighbors
}

// Topological Sort
void topoSort(int n, int graph[n][n]) {
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n, graph);
        }
    }

    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int graph[n][n];

    // Initialize graph
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topoSort(n, graph);

    return 0;
}