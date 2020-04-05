//Program to cyclically rotate an array by one
// input [1,2,3,4,5]
// output [5,1,2,3,4]
#include <stdio.h>

void rotate(int [], int);
void printArray(int [], int);

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i<n; i++)
    {
        printf("arr[%d] - %d\n", i, arr[i]);
    }
}

void rorate(int arr[], int n)
{
    int i, temp;
    temp = arr[n-1];
    for (i=n-1; i > 0 ; i--){
        arr[i] = arr[i-1];
    }
    arr[i] = temp;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n;
    n = sizeof(arr)/sizeof(arr[0]);

    rorate(arr, n);
    printArray(arr, n);

    return 0;
}