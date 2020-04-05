// C program to rotate an array by
// d elements
#include <stdio.h>

void printArr(int[], int);
void rotateArray(int[], int, int);
void leftRotateByOne(int [], int);

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, d = 4, n = 10;

    //Call rotate function
    rotateArray(arr, d, n);

    // Call print function
    printArr(arr, n);
    return 0;
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] - %d \n", i, arr[i]);
    }
}

void rotateArray(int arr[], int d, int n)
{
    int i;
    for (i = 0; i < d; i++)
    {
        leftRotateByOne(arr, n);
    }
}

void leftRotateByOne(int arr[], int n)
{
    int i, tmp;
    tmp = arr[0];
    for (i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = tmp;
}
