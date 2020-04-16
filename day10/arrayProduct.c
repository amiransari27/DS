// A Product Array Puzzle
// Given an array nums of n integers where n > 1,
// return an array output such that output[i] is equal
// to the product of all the elements of nums except nums[i].

/**
 * arr[]  = {1, 2, 3, 4, 5}
 * left = [1,0,0,0,0], right = [0,0,0,0,1], prod = []
 * 
 * loop(i) i=1, left[i] = arr[0] * left[0], left = [1,1,0,0,0] 
 * loop(i) i=2, left[i] = arr[1] * left[1], left = [1,1,2,0,0] 
 * loop(i) i=3, left[i] = arr[2] * left[2], left = [1,1,2,6,0] 
 * loop(i) i=4, left[i] = arr[3] * left[3], left = [1,1,2,6,24]
 * 
 * loop(j) j=3 right[j] = arr[4] * right[4] right = [0,0,0,5,1]
 * loop(j) j=2 right[j] = arr[3] * right[3] right = [0,0,20,5,1]
 * loop(j) j=1 right[j] = arr[2] * right[2] right = [0,60,20,5,1]
 * loop(j) j=0 right[j] = arr[1] * right[1] right = [120,60,20,5,1]
 *  
 * loop(i) i=0, prod[i] = prod[i] * right[i], prod[0] = 1*120 
 * loop(i) i=1, prod[i] = prod[i] * right[i], prod[1] = 1*60 
 * loop(i) i=2, prod[i] = prod[i] * right[i], prod[0] = 2*20 
 * loop(i) i=3, prod[i] = prod[i] * right[i], prod[0] = 6*5 
 * loop(i) i=4, prod[i] = prod[i] * right[i], prod[0] = 24*1 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void productArray(int[], int);

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The product array is: \n");
    productArray(arr, n);

    return 0;
}

void productArray(int arr[], int n)
{
    if (n == 1)
    {
        printf("0");
        return;
    }

    //allocate memory to temp arrays
    int *left = (int *)malloc(sizeof(int) * n);
    int *right = (int *)malloc(sizeof(int) * n);

    //allocate memory to product array
    int *prod = (int *)malloc(sizeof(int) * n);

    int i, j;

    //set left most array element
    left[0] = 1;

    //set right most array element
    right[n - 1] = 1;

    for (i = 1; i < n; i++)
    {
        left[i] = arr[i - 1] * left[i - 1];
    }

    for (j = n - 2; j >= 0; j--)
    {
        right[j] = arr[j + 1] * right[j + 1];
    }

    for (i = 0; i < n; i++)
    {
        prod[i] = left[i] * right[i];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", prod[i]);
    }

    printf("\n");

    return;
}