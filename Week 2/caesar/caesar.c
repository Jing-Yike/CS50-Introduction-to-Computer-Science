#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Conver argv[1] from a `string` to an `int`
    int a = atoi(argv[1]);
    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");
    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], a));
    }
    printf("\n");
}

bool only_digits(string s)
{
    // Check if the input string is composed by digits only
    for (long i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char a;
    // Rotate uppercase
    if (isupper(c))
    {
        int u = c - 'A' + n;
        a = 'A' + u % 26;
    }
    // Rotate lowercase
    else if (islower(c))
    {
        int l = c - 'a' + n;
        a = 'a' + l % 26;
    }
    else
    {
        a = c;
    }
    return a;
}