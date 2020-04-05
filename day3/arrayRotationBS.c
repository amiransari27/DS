//Block swap algorithm for array rotation
#include <stdio.h>

void printArr(int[], int);
void leftRotate(int[], int, int);
void leftRotate2(int[], int, int);
void swap(int[], int, int, int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    d = d % n;

    leftRotate2(arr, 5, 7);

    printArr(arr, n);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] - %d \n", i, arr[i]);
    }
}

// r{1, 2, 3, 4, 5, 6, 7} n=7,d=2 // {3, 4, 5, 6, 7, 1, 2}
//     s{6, 2, 3, 4, 5, 1, 7} fi=0,si=5,d=2,i=0
//     s{6, 7, 3, 4, 5, 1, 2} fi=0,si=5,d=2,i=1
// r{6, 7, 3, 4, 5, 1, 2} n=5, d=2
//     s{4, 7, 3, 6, 5, 1, 2} fi=0,si=3,d=2,i=0
//     s{4, 5, 3, 6, 7, 1, 2} fi=0,si=3,d=2,i=1
// r{4, 5, 3, 6, 7, 1, 2} n=3,d=2
//     s{3, 5, 4, 6, 7, 1, 2} fi=0,si=2,d=1,i=0
// r{3, 5, 4, 6, 7, 1, 2} n=2, d=1
//     s{3, 4, 5, 6, 7, 1, 2} fi=0,si=1,d=1,i=0
void leftRotate(int arr[], int d, int n)
{

    if (d == 0 || d == n)
        return;

    if (n - d == d)
    {
        swap(arr, 0, n - d, d);
        return;
    }

    if (d < n - d)
    {
        swap(arr, 0, n - d, d);
        leftRotate(arr, d, n - d);
    }
    else
    {
        swap(arr, 0, d, n - d);
        leftRotate(arr + n - d, 2 * d - n, d);
    }
}

// r{1, 2, 3, 4, 5, 6, 7} n = 7, d = 2 // {3, 4, 5, 6, 7, 1, 2}
//     w{1, 2, 3, 4, 5, 6, 7} i = 2,j = 5
//         s{6, 2, 3, 4, 5, 1, 7} fi = 0, si = 5, d = 2, i = 0
//         s{6, 7, 3, 4, 5, 1, 2} fi = 0, si = 5, d = 2, i = 1
//     w{6, 7, 3, 4, 5, 1, 2} i = 2, j = 3
//         s{4, 7, 3, 6, 5, 1, 2} fi = 0, si = 3, d = 2, i = 0
//         s{4, 5, 3, 6, 7, 1, 2} fi = 0, si = 3, d = 2, i = 1
//     w{4, 5, 3, 6, 7, 1, 2} i = 2, j = 1
//         s{3, 5, 4, 6, 7, 1, 2} fi = 0, si = 2, d = 1, i = 0
//     w{3, 5, 4, 6, 7, 1, 2} i = 1, j = 1
//         s{3, 4, 5, 6, 7, 1, 2} fi = 1, si = 2, d = 1, i = 0

void leftRotate2(int arr[], int d, int n)
{

    int i, j;

    if (d == 0 || d == n)
        return;

    i = d;
    j = n - d;

    while (i != j)
    {
        if (i < j)
        {
            swap(arr, d - i, d + j - i, i);
            j -= i;
        }
        else
        {
            swap(arr, d - i, d, j);
            i -= j;
        }
    }
    swap(arr, d - i, d, i);
}

void swap(int arr[], int fi, int si, int d)
{
    int i, temp;
    for (i = 0; i < d; i++)
    {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}
