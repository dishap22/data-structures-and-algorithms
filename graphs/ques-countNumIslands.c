#include <stdio.h>
#include <stdlib.h>

void DFS(int** M, int i, int j, int ROW, int COL) {
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1) return;

    if (M[i][j] == 1) {
        M[i][j] = 0;
        DFS(M, i + 1, j, ROW, COL); // right side traversal
        DFS(M, i - 1, j, ROW, COL); // left side traversal
        DFS(M, i, j + 1, ROW, COL); // upward side traversal
        DFS(M, i, j - 1, ROW, COL); // downward side traversal
        DFS(M, i + 1, j + 1, ROW, COL); // upward-right side traversal
        DFS(M, i - 1, j - 1, ROW, COL); // downward-left side traversal
        DFS(M, i + 1, j - 1, ROW, COL); // downward-right side traversal
        DFS(M, i - 1, j + 1, ROW, COL); // upward-left side traversal
    }
}

int countIslands(int** M, int ROW, int COL) {
    int count = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (M[i][j] == 1) {
                count++;
                DFS(M, i, j, ROW, COL); // traversal starts from current cell
            }
        }
    }
    return count;
}

// Driver Code
int main()
{
    int ROW = 5;
    int COL = 5;
    int** M = (int**)malloc(ROW * sizeof(int*));
    for (int i = 0; i < ROW; i++) {
        M[i] = (int*)malloc(COL * sizeof(int));
    }

    // Initializing the matrix
    M[0][0] = 1;
    M[0][1] = 1;
    M[0][2] = 0;
    M[0][3] = 0;
    M[0][4] = 0;
    M[1][0] = 0;
    M[1][1] = 1;
    M[1][2] = 0;
    M[1][3] = 0;
    M[1][4] = 1;
    M[2][0] = 1;
    M[2][1] = 0;
    M[2][2] = 0;
    M[2][3] = 1;
    M[2][4] = 1;
    M[3][0] = 0;
    M[3][1] = 0;
    M[3][2] = 0;
    M[3][3] = 0;
    M[3][4] = 0;
    M[4][0] = 1;
    M[4][1] = 1;
    M[4][2] = 1;
    M[4][3] = 0;
    M[4][4] = 1;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("Number of islands is: %d\n", countIslands(M, ROW, COL));

    // Freeing dynamically allocated memory
    for (int i = 0; i < ROW; i++) {
        free(M[i]);
    }
    free(M);
    return 0;
}
