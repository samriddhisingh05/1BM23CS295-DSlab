#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int n, int start, int visited[MAX]) {
    int i;
    printf("%d ", start);
    visited[start] = 1;
for (i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, n, i, visited);
        }
    }
}

int main() {
    int graph[MAX][MAX], n, i, j, start;
    int visited[MAX] = {0}; 

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(graph, n, start, visited);
    printf("\n");

    return 0;
}
