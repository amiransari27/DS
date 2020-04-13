//Length of the largest subarray with contiguous elements
/**
 * arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45}; n = 10
 * loop(i) max_len = 1, i = 0, mn = 1, mx = 1
 *      loop(j) max_len = 1, j = 1, mn = 1, mx = 56, mx - mn = 55, j - i = 1  
 *      loop(j) max_len = 1, j = 2, mn = 1, mx = 58, mx - mn = 57, j - i = 2  
 *      loop(j) max_len = 1, j = 3, mn = 1, mx = 58, mx - mn = 57, j - i = 3  
 *      loop(j) max_len = 1, j = 4, mn = 1, mx = 90, mx - mn = 89, j - i = 4  
 *      loop(j) max_len = 1, j = 5, mn = 1, mx = 92, mx - mn = 91, j - i = 5  
 *      loop(j) max_len = 1, j = 6, mn = 1, mx = 94, mx - mn = 93, j - i = 6  
 *      loop(j) max_len = 1, j = 7, mn = 1, mx = 94, mx - mn = 93, j - i = 7  
 *      loop(j) max_len = 1, j = 8, mn = 1, mx = 94, mx - mn = 93, j - i = 8  
 *      loop(j) max_len = 1, j = 9, mn = 1, mx = 94, mx - mn = 93, j - i = 9  
 * 
 * loop(i) max_len = 1, i = 1, mn = 56, mx = 56
 *      loop(j) max_len = 1, j = 2, mn = 56, mx = 58, mx - mn = 2, j - i = 1  
 *      loop(j) max_len = 3, j = 3, mn = 56, mx = 58, mx - mn = 2, j - i = 2  
 * 
 * 
 */
#include <stdio.h>
int subArray(int[], int);
int getMin(int, int);
int getMax(int, int);

int main()
{
    // int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
    int arr[] = {11, 12, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int length = subArray(arr, n);

    printf("Length of the longest contiguous subarray is %d\n", length);

    return 0;
}

int subArray(int arr[], int n)
{
    int i, j, min, max, maxLenght = 1;

    for (i = 0; i < n - 1; i++)
    {
        min = max = arr[i];

        for (j = i + 1; j < n; j++)
        {
            min = getMin(min, arr[j]);
            max = getMax(max, arr[j]);

            if (max - min == j - i)
            {
                maxLenght = getMax(maxLenght, max - min + 1);
            }
        }
    }

    return maxLenght;   
}

int getMin(int x, int y)
{
    if(x < y)
        return x;

    return y;
}

int getMax(int x, int y)
{
    if(x < y)
        return y;

    return x;
}