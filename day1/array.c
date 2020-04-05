#include <stdio.h>

/* int main()
{
    int arr[5];
    arr[0] = 5; 
    arr[2] = -10; 
    arr[3 / 2] = 2; // this is same as arr[1] = 2 
    arr[3] = arr[0]; 
  
    printf("%d %d %d %d", arr[0], arr[1], arr[2], arr[3]); 
  
    return 0;
} */

/* int main() 
{ 
    int arr[2]; 
  
    printf("%d ", arr[3]); 
    printf("%d ", arr[-2]); 
  
    return 0; 
} */

/* int main() 
{ 
  
    // Array declaration by initializing it with more 
    // elements than specified size. 
    int arr[2] = { 10, 20, 30, 40, 50 }; 

    printf("%d ", arr[1]); 

    return 0; 
}  */

int main(){
    int arr[5], i;

    printf("Size of integer in this compiler is %lu \n", sizeof(int));

    for (i = 0; i < 5; i++ ){
        printf("Address of a[%d] is %p - (%d) \n",i, &arr[i], arr[i]);
    }

    return 0;
}