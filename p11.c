/*11. Develop a Program in C for the following operations on Graph(G) of Cities a. Create a Graph of 
N cities using Adjacency Matrix. b. Print all the nodes reachable from a given starting node in a 
digraph using DFS/BFS method */

#include <stdio.h>
#include <stdlib.h>

// Global variables
int n, a[20][20], visited1[20], visited2[20], source;

// Function to read the adjacency matrix
void read_data() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to print reachability status
void print_data(int visited[]) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0)
            printf("\nVertex %d is not reachable.\n", i);
        else
            printf("\nVertex %d is reachable.\n", i);
    }
}

// Breadth-First Search (BFS) function
void BFS() {
    int f = 0, r = 0, q[20], i, j;

    // Initialize the queue with the source vertex
    q[r] = source;
    visited1[source] = 1;

    printf("\nBFS traversal starting from vertex %d:\n", source);
    while (f <= r) {
        i = q[f++];
        printf("--%d--", i);
        for (j = 0; j < n; j++) {
            if (a[i][j] == 1 && visited1[j] == 0) {
                visited1[j] = 1;
                q[++r] = j;
            }
        }
    }
    printf("\n");
}

// Depth-First Search (DFS) function
void DFS(int src, int *cnt) {
    visited2[src] = 1;
    printf("--%d--", src);

    for (int j = 0; j < n; j++) {
        if (a[src][j] == 1 && visited2[j] == 0) {
            (*cnt)++;
            DFS(j, cnt);
        }
    }
}

// Main function
int main() {
    int i, choice, count;

    // Read adjacency matrix
    read_data();
    printf("\t\t**ADJACENCY MATRIX FOR CITIES HAS BEEN CREATED SUCCESSFULLY**\n");

    while (1) {
        printf("\n1. BFS\n2. DFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Initialize visited array for BFS
                for (i = 0; i < n; i++) visited1[i] = 0;

                printf("Enter the source vertex (0 to %d): ", n - 1);
                scanf("%d", &source);

                if (source < 0 || source >= n) {
                    printf("Invalid source vertex!\n");
                    break;
                }

                BFS();
                print_data(visited1);
                break;

            case 2:
                // Initialize visited array for DFS
                for (i = 0; i < n; i++) visited2[i] = 0;

                printf("Enter the source vertex (0 to %d): ", n - 1);
                scanf("%d", &source);

                if (source < 0 || source >= n) {
                    printf("Invalid source vertex!\n");
                    break;
                }

                count = 1;
                printf("\nDFS traversal starting from vertex %d:\n", source);
                DFS(source, &count);
                printf("\n");

                print_data(visited2);

                // Check if the graph is connected
                if (count == n)
                    printf("The graph is connected.\n");
                else
                    printf("The graph is not connected.\n");
                break;

            case 3:
                exit(0);

            default:
                printf("\nEnter a valid choice.\n");
        }
    }
    return 0;
}
