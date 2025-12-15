#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // Prompt the user to give some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Print the reading level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int grade = round(index);
        printf("Grade %i\n", grade);
    }
}

int count_letters(string s)
{
    int letters = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalnum(s[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string s)
{
    int words, spaces = 0;
    int i = 0;
    int len = strlen(s);
    while (i < len)
    {
        if (isspace(s[i]))
        {
            spaces++;
        }
        i++;
    }
    words = spaces + 1;
    return words;
}

int count_sentences(string s)
{
    int sentences = 0;
    int i = 0;
    int len = strlen(s);
    while (i < len)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences++;
        }
        i++;
    }
    return sentences;
}
