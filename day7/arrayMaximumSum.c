/**
 * Find maximum value of Sum( i*arr[i]) 
 * with only rotations on given array allowed
 */
// C program to find max value of i*arr[i]
#include <stdio.h>
int maxSum(int[], int);
int findMaxElement(int[], int);
void rotate(int[], int, int);

int main()
{
    // int arr[] = {1, 20, 2, 10};
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n, sum;

    n = sizeof(arr) / sizeof(arr[0]);

    sum = maxSum(arr, n);

    printf("Max sum of array is %d \n", sum);
    return 0;
}

int maxSum(int arr[], int n)
{
    int i, sum = 0, maxElementIndex, d;
    // find max element's index
    maxElementIndex = findMaxElement(arr, n);

    if (maxElementIndex < n - 1)
    {
        d = maxElementIndex + 1;
        // rotate element by d elements
        rotate(arr, d, n);
    }

    for (i = 0; i < n; i++)
    {
        sum += i*arr[i];
    }

    return sum;
}

int findMaxElement(int arr[], int n)
{
    int i, max, index = 0;
    max = arr[0];
    for (i = 1; i < n - 1; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void rotate(int arr[], int d, int n)
{
    int i, tmp;
    while (d > 0)
    {
        tmp = arr[0];
        for (i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[i] = tmp;
        d--;
    }
}