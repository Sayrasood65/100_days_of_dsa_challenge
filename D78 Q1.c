/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Add edge
void addEdge(Node** adj, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS
void dfs(int u, int* visited, Node** adj) {
    visited[u] = 1;

    Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->val]) {
            dfs(temp->val, visited, adj);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    Node** adj = (Node**)malloc((n + 1) * sizeof(Node*));
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u); // undirected
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    // start DFS from node 1
    dfs(1, visited, adj);

    // check all nodes visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}