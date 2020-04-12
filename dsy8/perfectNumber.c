// find the geven number is perfect number  or not
// Any number can be the perfect number in C
// if the sum of its positive divisors excluding the number itself is equal to that number

/**
 * n = 6
 * sum 1 + 2 + 3 == n (sum of all divisor of 6)
 */
#include <stdio.h>

int main()
{
    int num = 7;
    int i, sum = 0;

    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    if(num == sum){
        printf("Given number %d is a perfect number\n",num);
    }else{
        printf("Given number %d is not a perfect number\n",num);
    }

    return 0;
}