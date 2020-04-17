// Number of Islands
/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 * An island is surrounded by water and is formed 
 * by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 */
#include <stdio.h>
void markIslandVisited(int *, int, int, int, int);

int main()
{
    int arr[4][5] = {
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    int totalIsland = 0;

    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (arr[i][j] == 1)
            {
                markIslandVisited((int *)arr, i, j, rows, cols);
                totalIsland += 1;
            }
        }
    }

    printf("Number of island are %d \n", totalIsland);

    return 0;
}

void markIslandVisited(int *arr, int x, int y, int rows, int cols)
{
    int *ptr;
    if (x < 0 || x >= rows || y < 0 || y >= cols || *((arr + x * cols) + y) != 1)
    {
        return;
    }

    ptr = ((arr + x * cols) + y);

    *ptr = 2;

    markIslandVisited(arr, x, y + 1, rows, cols);
    markIslandVisited(arr, x + 1, y, rows, cols);
    markIslandVisited(arr, x, y - 1, rows, cols);
    markIslandVisited(arr, x - 1, y, rows, cols);
}
