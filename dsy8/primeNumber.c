// find out the given number is prime number
// it has only two distinct divisors: 1 and itself
// like 7, it can only divisible by 1 and 7 itself
#include <stdio.h>

int main()
{
    int num = 11;
    int i;
    for (i = 2; i < num; i++)
    {
        if (num % 2 == 0)
        {
            printf("Given number %d is not a prime number\n", num);
            return 0;
        }
    }

    printf("Given number %d is a prime number\n", num);

    return 0;
}