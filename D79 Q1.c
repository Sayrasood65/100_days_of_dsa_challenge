/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Min Heap Node
typedef struct {
    int vertex;
    int weight;
} HeapNode;

// Min Heap Structure
typedef struct {
    int size;
    HeapNode* arr[MAX];
} MinHeap;

// Create new adjacency node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
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

// Heapify up
void heapifyUp(MinHeap* heap, int index) {
    while (index && heap->arr[index]->weight < heap->arr[(index - 1) / 2]->weight) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left]->weight < heap->arr[smallest]->weight)
        smallest = left;

    if (right < heap->size && heap->arr[right]->weight < heap->arr[smallest]->weight)
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap* heap, int v, int w) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->weight = w;

    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract min
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

    bool visited[n + 1];
    for (int i = 1; i <= n; i++) visited[i] = false;

    MinHeap heap;
    heap.size = 0;

    insertHeap(&heap, 1, 0); // start from node 1

    int totalWeight = 0;

    while (heap.size > 0) {
        HeapNode* minNode = extractMin(&heap);
        int u = minNode->vertex;
        int w = minNode->weight;

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += w;

        Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->vertex]) {
                insertHeap(&heap, temp->vertex, temp->weight);
            }
            temp = temp->next;
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}