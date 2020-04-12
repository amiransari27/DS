// find out the given number is palindrome number
// A palindromic number is a number that remains the same when its digits are reversed.
// Like 16461
#include <stdio.h>

int main()
{
    int num = 16462;
    int tmpNum = num;
    int reminder, reverse = 0;

    while (num > 0)
    {
        reminder = num % 10;

        reverse = (reverse * 10) + reminder;

        num = num / 10;
    }

    if (tmpNum == reverse)
    {
        printf("Given number %d is a palindrome number\n", tmpNum);
    }
    else
    {
        printf("Given number %d is not a palindrome number\n", tmpNum);
    }

    return 0;
}