/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency List Node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min Heap
typedef struct {
    int size;
    HeapNode* arr[MAX];
} MinHeap;

// Create adjacency node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Swap heap nodes
void swap(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(MinHeap* heap, int index) {
    while (index && heap->arr[index]->dist < heap->arr[(index - 1) / 2]->dist) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left]->dist < heap->arr[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->arr[right]->dist < heap->arr[smallest]->dist)
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap* heap, int v, int d) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->dist = d;

    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract minimum
HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    HeapNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);

    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n + 1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int source;
    scanf("%d", &source);

    int dist[n + 1];
    bool visited[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    MinHeap heap;
    heap.size = 0;

    dist[source] = 0;
    insertHeap(&heap, source, 0);

    while (heap.size > 0) {
        HeapNode* minNode = extractMin(&heap);
        int u = minNode->vertex;

        if (visited[u]) continue;
        visited[u] = true;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}