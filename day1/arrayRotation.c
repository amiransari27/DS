#include <stdio.h>
#define LIMIT 5
// Rotation of an array using temp variable
int main()
{
    int arr[] = {1,2,3,4,5,6,7}, d = LIMIT, n = 7;
    int tempArr[LIMIT] = {}, i;
    
    printf("Print element before rotation\n");
    // Print array
    for (i=0; i < n; i++){
         printf("a[%d] - %d \n", i, arr[i]);
    }

    // Put d elements into tempArr
    for (i=0; i < d; i++){        
        tempArr[i] = arr[i];
    }

    // Shift element to left side
    for (i=d; i < n; i++){
        arr[i-d] = arr[i];        
    }

    // Put tempArr data to orignal array
    for (i=n-d; i < n; i++){
        arr[i] = tempArr[i-(n-d)];
    }

    printf("Print element after rotation\n");
    // Print array
    for (i=0; i < n; i++){
         printf("a[%d] - %d \n", i, arr[i]);
    }
    return 0; 
}