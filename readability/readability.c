#include <stdio.h>
#include <math.h>
#include <string.h>
#include "cs50.h"
int* count_letters(string text,int Count[3]);
void Caculate_result(int result[]);
int main(void)
{
    string text = get_string("Text:  ");
    int Count[3]={0};
    int* results = count_letters(text, Count);
    Caculate_result(results);
    return 0;
}
int* count_letters(string text,int Count[3])
{
    int letters = 0,words =1,sentences = 0;
    for (int i = 0; i<strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    printf("letters: %i\n", letters);
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);
    Count[0] = letters;
    Count[1] = words;
    Count[2] = sentences;
    return Count;
}
void Caculate_result(int result[])
{
    double L = (double)result[0] / (double)result[1] * 100;
    double S = (double)result[2] / (double)result[1] * 100;
    printf("L: %f\n", L);
    printf("S: %f\n", S);
    double index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}