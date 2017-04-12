/*
 Dijkstra's shortest path algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxN 400 // maximum amount of vertices in graph
#define INFINITY 999

char find_shortest_path(int connections[maxN][maxN], int start, int end, int N) {
    int node[N], label[N], previous[N];
    int i, j, length, minimum_distance;
    for (i = 1; i <= N; i++) {
        node[i] = 0;
        label[i] = INFINITY;
    }
    label[start] = 0;
    
//    for (i = 0; i < N; i++) {
//        printf("%d %d \n", node[i], label[i]);
//    }
    
    minimum_distance = 1;
    
    for (i = 1; i <= N; i++) {
        if (node[i] == 0 && label[i] < label[minimum_distance]) {
            minimum_distance = i;
        }
    }
    
    printf("%d mind\n", minimum_distance);
    
    for (i = 1; i <= N; i++) {
        if (connections[minimum_distance][i] != 0) {
            length = label[minimum_distance] + connections[minimum_distance][i];
            if (label[i] > length) {
                label[i] = length;
                previous[i] = minimum_distance;
            }
        }
    }
    node[minimum_distance] = 1;
    
//    printf("%d\n", length);
    
    
    printf("\n");
    for (i = 1; i <= N; i++) {
        printf("%d %d \n", node[i], label[i]);
    }

    
    return 0;
}

int main() {
    int i, j, N, start, end, length;
    int connections[maxN][maxN];
    char fileName[20];
    char fromFile[30];
    char cities[maxN][30];
    
    FILE *fp = NULL;
    fp = fopen("linnad_teine.txt", "r");
    N = 0;
    
    while (!feof(fp)) {
        fgets(fromFile, 30, fp);
        length = strlen(fromFile);
        if (length > 1 && fromFile[length - 1] == '\n') {
            fromFile[length - 1] = '\0';
            N = N + 1;
            // Copies the string pointed to
            strcpy(cities[N], fromFile);
        }
    }
    fclose(fp);
    for (i = 1; i <= N; i++) {
        printf("%d %s\n", i, cities[i]);
    }
    
    // Sets the connections/cost matrix
    fp = fopen("seosed_teine.txt", "r");
    while (!feof(fp)) {
        fscanf(fp, "%d %d %d", &start, &end, &length);
        connections[start][end] = length;
        connections[end][start] = length;
    }
    // Prints out connections matrix with cost (weight between edges)
    fclose(fp);
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            printf("%3d", connections[i][j]);
        }
        printf("\n");
    }
    
    printf("Enter the starting point:\n");
    scanf("%d", &start);
    printf("Enter the destination point:\n");
    scanf("%d", &end);
    //path = find_shortest_path(connections, start, end, N);
    find_shortest_path(connections, start, end, N);
    
    
    
    return 0;
}








