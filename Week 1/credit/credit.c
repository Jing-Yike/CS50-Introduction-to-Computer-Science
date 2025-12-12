#include <cs50.h>
#include <stdio.h>

int checksum(long number);
int countDigits(long number);

int main(void)
{
    // Prompt the user for the credit card number
    long number = get_long("Number: ");
    // Calculate checksum
    int sum = checksum(number);
    if (number > 0 && sum % 10 == 0)
    {
        int d = countDigits(number);
        if (d == 15 && number / 100000000000000 % 10 == 3)
        {
            int d14 = number / 10000000000000 % 10;
            if (d14 == 4 || d14 == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (d == 13 && number / 1000000000000 % 10 == 4)
        {
            printf("VISA\n");
        }
        else if (d == 16)
        {
            int d16 = number / 1000000000000000 % 10;
            int d15 = number / 100000000000000 % 10;
            if (d16 == 4)
            {
                printf("VISA\n");
            }
            else if (d16 == 5 && (d15 == 1 || d15 == 2 || d15 == 3 || d15 == 4 || d15 == 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int checksum(long number)
{
    // Get digits
    int d1 = number % 10;
    int d2 = number / 10 % 10;
    int d3 = number / 100 % 10;
    int d4 = number / 1000 % 10;
    int d5 = number / 10000 % 10;
    int d6 = number / 100000 % 10;
    int d7 = number / 1000000 % 10;
    int d8 = number / 10000000 % 10;
    int d9 = number / 100000000 % 10;
    int d10 = number / 1000000000 % 10;
    int d11 = number / 10000000000 % 10;
    int d12 = number / 100000000000 % 10;
    int d13 = number / 1000000000000 % 10;
    int d14 = number / 10000000000000 % 10;
    int d15 = number / 100000000000000 % 10;
    int d16 = number / 1000000000000000 % 10;
    // Multiply every other digit by 2
    int m2 = 2 * d2;
    int m4 = 2 * d4;
    int m6 = 2 * d6;
    int m8 = 2 * d8;
    int m10 = 2 * d10;
    int m12 = 2 * d12;
    int m14 = 2 * d14;
    int m16 = 2 * d16;
    // Get digits after multiplication
    int A1 = m2 % 10;
    int A2 = m2 / 10 % 10;
    int B1 = m4 % 10;
    int B2 = m4 / 10 % 10;
    int C1 = m6 % 10;
    int C2 = m6 / 10 % 10;
    int D1 = m8 % 10;
    int D2 = m8 / 10 % 10;
    int E1 = m10 % 10;
    int E2 = m10 / 10 % 10;
    int F1 = m12 % 10;
    int F2 = m12 / 10 % 10;
    int G1 = m14 % 10;
    int G2 = m14 / 10 % 10;
    int H1 = m16 % 10;
    int H2 = m16 / 10 % 10;
    // Get sum
    int sum = d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15 + A1 + A2 + B1 + B2 + C1 + C2 + D1 + D2 +
              E1 + E2 + F1 + F2 + G1 + G2 + H1 + H2;
    return sum;
}

int countDigits(long number)
{
    int count;
    for (count = 0; number > 0; count++)
    {
        number = number / 10;
    }
    return count;
}