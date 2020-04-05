// Search an element in a sorted and rotated array
// Input  {5, 6, 7, 8, 9, 10, 1, 2, 3};
// key = 3
// Output : Found at index 8
#include <stdio.h>

int pivotedBinarySearch(int[], int, int);
int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);
int search(int[], int, int, int);

int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    int res;

    // res = pivotedBinarySearch(arr, key, n);
    res = search(arr, 0, n-1, key);

    printf("Index of the element is : %d \n", res);
    return 0;
}

int pivotedBinarySearch(int arr[], int key, int n)
{
    int pivot = findPivot(arr, 0, n - 1);

    printf("pivot %d\n", pivot);

    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);

    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n - 1, key);
}

// {5, 6, 7, 8, 9, 10, 1, 2, 3} low=0, high=8 mid=4
// case 1: 4 < 8 && 9 > 10 return mid
// case 2: 4 > 0 && 9 < 8 return mid-1
// case 3 if: 5 >= 9 return findPivot(arr, low, mid-1)
// case 4 else: findPivot(arr, mid+1, high)

// low=5, high=8, mid=6
// case 1: 6 < 8 && 1 > 2 return mid
// case 2: 6 > 5 && 1 < 10 return mid-1

int findPivot(int arr[], int low, int high)
{
    if (low > high)
        return -1;
    if (low == high)
        return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid - 1;

    if (arr[mid] > arr[low])
        return findPivot(arr, mid + 1, high);

    return findPivot(arr, low, mid - 1);
}

int binarySearch(int arr[], int low, int high, int key)
{
    printf("low :%d high :%d \n", low, high);
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}

// {5, 6, 7, 8, 9, 10, 1, 2, 3} low=0, high=8 mid=4
// case 1:

int search(int arr[], int l, int h, int key)
{
    int mid;
    if (l > h)
        return -1;

    mid = (l+h)/2;
    if (arr[mid] == key)
        return mid;

    if (arr[l] <= arr[mid])
    {

        if (key >= arr[l] && key < arr[mid])
        {
            return search(arr, l, mid - 1, key);
        }
        return search(arr, mid + 1, h, key);
    }
 
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);
    
    return search(arr, l, mid-1, key);
}