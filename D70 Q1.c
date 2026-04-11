//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

// Min Heap node
struct HeapNode {
    int node, dist;
};

// Min Heap
struct MinHeap {
    struct HeapNode* arr;
    int size;
};

// Create graph node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(struct MinHeap* heap, int i) {
    while (i && heap->arr[(i - 1) / 2].dist > heap->arr[i].dist) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(struct MinHeap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < heap->size && heap->arr[l].dist < heap->arr[smallest].dist)
        smallest = l;

    if (r < heap->size && heap->arr[r].dist < heap->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Push into heap
void push(struct MinHeap* heap, int node, int dist) {
    heap->arr[heap->size].node = node;
    heap->arr[heap->size].dist = dist;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Pop min
struct HeapNode pop(struct MinHeap* heap) {
    struct HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Dijkstra function
void dijkstra(int n, struct Node* adj[], int src) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap heap;
    heap.arr = (struct HeapNode*)malloc(sizeof(struct HeapNode) * 1000);
    heap.size = 0;

    push(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode top = pop(&heap);
        int u = top.node;
        int d = top.dist;

        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}