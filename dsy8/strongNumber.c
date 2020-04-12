// find out the given number is strong number or not
// Strong number is a special number whose sum of factorial of digits is equal to the original number.
// For example: 145 is strong number. Since, 1! + 4! + 5! = 145
#include <stdio.h>
int factorial(int);

int main()
{
    int num = 146;
    int tmpNum = num;
    int reminder, sum = 0;

    while (num > 0)
    {
        reminder = num % 10;

        sum += factorial(reminder);

        num = num / 10;
    }

    if (tmpNum == sum)
    {
        printf("Given number %d is a strong number\n", tmpNum);
    }
    else
    {
        printf("Given number %d is not a strong number\n", tmpNum);
    }
    return 0;
}

int factorial(int num)
{
    if (num == 0)
        return 1;

    return num * factorial(num - 1);
}