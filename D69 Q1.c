//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

// Function for Topological Sort
void topoSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};

    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push nodes with indegree 0
    Queue q;
    initQueue(&q);

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: BFS
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);
        count++;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    // Step 4: Cycle check
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

// Driver code
int main() {
    int V = 6;

    // Adjacency Matrix
    int adj[MAX][MAX] = {0};

    // Example graph
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(V, adj);

    return 0;
}