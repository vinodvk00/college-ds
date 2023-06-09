#include <stdio.h>

#define size 5

int queue[size], visited[size], a[size][size], i, j, n, front = -1, rear = -1;

void enqueue(int x);
int dequeue();
int isEmpty();
void bfs(int v);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("BFS traversal: ");
    bfs(0);

    return 0;
}

void enqueue(int x) {
    if (rear == size - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int element = queue[front];
        front++;
        return element;
    }
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

void bfs(int v) {
    enqueue(v);
    visited[v] = 1;

    while (!isEmpty()) {
        v = dequeue();
        printf("%d\t", v);

        for (i = 0; i < n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
