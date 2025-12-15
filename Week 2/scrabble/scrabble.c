#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string s);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt the players to give words
    string a = get_string("Player 1: ");
    string b = get_string("Player 2: ");
    // Calculate the scores of the inputs
    int p1 = get_score(a);
    int p2 = get_score(b);
    // Make comparison and give the result
    if (p1 > p2)
    {
        printf("Player 1 wins!");
    }
    else if (p1 < p2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
    printf("\n");
}

int get_score(string s)
{
    // Calculate and return the score of s
    int length = strlen(s);
    int score = 0;
    // Link the ASCII letters to array POINT and compute the score
    for (int i = 0; i < length; i++)
    {
        if (isupper(s[i]))
        {
            score += POINTS[s[i] - 'A'];
        }
        else if (islower(s[i]))
        {
            score += POINTS[s[i] - 'a'];
        }
    }
    return score;
}
