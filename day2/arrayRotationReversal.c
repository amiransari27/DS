//C program for reversal algorithm of array rotation
// Time complexcity O(n)
#include <stdio.h>

void printArr(int[], int);
void rotateArray(int[], int, int);
void reverseArray(int [], int, int);

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;

    d = d%n;

    rotateArray(arr, d, n);

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
    if(d == 0)
        return;
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

void reverseArray(int arr[], int start, int end)
{
    int tmp;

    while(start < end)
    {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;

        start++;
        end--;
    }
}