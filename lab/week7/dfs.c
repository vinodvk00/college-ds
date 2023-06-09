#include<stdio.h>
#define size 5

int stack[size], visited[size], a[size][size], i, j, n, top = -1;

void push(int x);
int pop();
int isEmpty();
void dfs(int v);

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n"); 

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        visited[i] = 0;
    }

    printf("DFS traversal: ");
    dfs(0);

    return 0;
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void dfs(int v){
    int x;
    push(v);
    visited[v] = 1;

    while(!isEmpty()){
        x = pop();
        printf("%d\t", x);

        for(i = 0; i < n; i++){
            if(a[x][i] == 1 && visited[i] == 0){
                push(i);
                visited[i] = 1;
            }
        }
    }
}
