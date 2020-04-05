/**
 * Given a sorted and rotated array, 
 * find if there is a pair with a given sum
 */
// C++ program to find a pair with a given sum in a sorted and
// rotated array
#include <stdio.h>
#include <stdbool.h>

bool pairInSortedRotated(int [], int, int);

int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int sum = 111;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res;

    // res = pivotedBinarySearch(arr, key, n);
    res = pairInSortedRotated(arr, n, sum);

    if (res)
    {
        printf("Array has two element with sum %d\n", sum);
    }
    else
    {
        printf("Array does not have two element with sum %d\n", sum);
    }

    return 0;
}

bool pairInSortedRotated(int arr[], int n, int sum){

    // find the pivot element 
    int i, l, r;
    for(i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            break;
        }
    }
    l = (i+1)%n; // l is index of smallest element 
    r = i; // r is a index of largest element

    while (l != r)
    {
        if (arr[l] + arr[r] == sum)
        {
            return true;
        }

        if (arr[l] + arr[r] > sum){
            r = (n + r - 1)%n;
        }else{
            l = (l+1)%n;
        }

    }

    return false;

}