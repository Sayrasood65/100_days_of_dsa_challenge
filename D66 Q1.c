/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

// DFS function
bool dfs(int node, int parent, struct Node* adj[], bool visited[]) {
    visited[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }
    return false;
}

// Function to check cycle
bool isCycle(int V, struct Node* adj[]) {
    bool visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

// Driver code
int main() {
    int V = 4;

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Example edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    if (isCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}