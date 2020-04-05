// C program to rotate an array by
// d elements
// juggling
#include <stdio.h>
void printArr(int[], int);
void leftRotateArray(int[], int, int);
void rightRotateArray(int[], int, int);
int getGCD(int, int);

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, d = 3, n = 10;

    //Call rotate function
    rightRotateArray(arr, d, n);

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

void leftRotateArray(int arr[], int d, int n)
{
    int i, j, k, tmp;
    int gcd = getGCD(d, n);

    for (i = 0; i < gcd; i++)
    {
        tmp = arr[i];
        j = i;
        while (1)
        {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = tmp;
    }
}

// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} d=4 n=10
// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} tmp=9 j=9 i=0
//     {0, 1, 2, 3, 4, 5, 6, 7, 8, 5} tmp=9 j=9 k=5
//     {0, 1, 2, 3, 4, 1, 6, 7, 8, 5} tmp=9 j=5 k=1
//     {0, 7, 2, 3, 4, 1, 6, 7, 8, 5} tmp=9 j=1 k=-3 (7)
//     {0, 7, 2, 3, 4, 1, 6, 3, 8, 5} tmp=9 j=7 k=3
//     {0, 7, 2, 9, 4, 1, 6, 3, 8, 5} tmp=9 j=3 k=-1 (9)

// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} tmp=8 j=8 i=1
//     {0, 1, 2, 3, 4, 5, 6, 7, 4, 9} tmp=8 j=8 k=4
//     {0, 1, 2, 3, 0, 5, 6, 7, 4, 9} tmp=8 j=4 k=0
//     {6, 1, 2, 3, 0, 5, 6, 7, 4, 9} tmp=8 j=0 k=-4(6)
//     {6, 1, 2, 3, 0, 5, 2, 7, 4, 9} tmp=8 j=6 k=2
//     {6, 1, 8, 3, 0, 5, 2, 7, 4, 9} tmp=8 j=2 k=-2(8)

/* void rightRotateArray(int arr[], int d, int n)
{
    int i, j, k, tmp;
    int gcd = getGCD(d, n);

    for (i = 0; i < gcd; i++)
    {
        tmp = arr[n-(i+1)];
        j = n-(i+1);
        while (1)
        {
            k = j - d;
            if (k < 0)
                k = k + n;
            if (k == (n-(i+1)))
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = tmp;
    }
} */

void rightRotateArray(int arr[], int d, int n)
{
    int i, j, k, tmp;
    int gcd = getGCD(d, n);

    for (i = gcd; i > 0; i--)
    {
        tmp = arr[n-i];
        j = n-i;
        while (1)
        {
            k = j - d;
            if (k < 0)
                k = k + n;
            if (k == (n-i))
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = tmp;
    }
}

int getGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return getGCD(b, a % b);
    }
}