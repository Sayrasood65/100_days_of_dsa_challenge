/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// BFS function
void bfs(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        // Traverse all adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, adj[MAX][MAX], s;

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

    // Input source vertex
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Call BFS
    bfs(adj, n, s);

    return 0;
}