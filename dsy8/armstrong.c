// find out the given number is strong number or not
// Armstrong number is a number that is equal to the sum of cubes of its digits.
// For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
// Like 3^3 + 7^3 + 1^3 == 371
#include <stdio.h>
#include <math.h>

int factorial(int);

int main()
{
    int num = 372;
    int tmpNum = num;
    int reminder;
    int sum = 0;

    while (num > 0)
    {
        reminder = num % 10;

        sum += pow(reminder, 3);

        num = num / 10;
    }

    if (tmpNum == sum)
    {
        printf("Given number %d is a armstrong number\n", tmpNum);
    }
    else
    {
        printf("Given number %d is not a armstrong number\n", tmpNum);
    }
    return 0;
}
