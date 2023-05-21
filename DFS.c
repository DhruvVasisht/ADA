#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INF 9999

int n; 
int adjMatrix[MAX_NODES][MAX_NODES]; 

int visited[MAX_NODES]; 

void createGraph() {
    int i, j;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

void DFS(int currentNode) {
    int i;

    visited[currentNode] = 1;
    printf("%d ", currentNode);

    for (i = 0; i < n; i++) {
        if (adjMatrix[currentNode][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void DFSTraversal() {
    int startNode;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &startNode);

    printf("DFS traversal: ");
    DFS(startNode);
    printf("\n");
}

int main() {
    createGraph();
    DFSTraversal();

    return 0;
}
