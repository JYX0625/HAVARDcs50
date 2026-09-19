#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include  <ctype.h>
int count_score(string s, int scoresheet[26], string letters);
void who_wins(int score1, int score2);
int main() {
    string s1 = get_string("player1: ");
    string s2 = get_string("player2: ");
    int scoresheet[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int scores1=0,scores2=0;
    scores1=count_score(s1, scoresheet, letters);
    scores2=count_score(s2, scoresheet, letters);
    who_wins(scores1, scores2);
    return 0;
}
int count_score(string s, int scoresheet[26], string letters)
{
    int score = 0;
    s = strupr(s);
    for (int i = 0, n = strlen(s), j = 0; i < n; i++)
    {
        while (s[i] != letters[j]&&j < 26)
        {
            j++;
        }
        if (j >= 26)
        {
            j = 0;
            continue;
        }
        score += scoresheet[j];
        j = 0;
    }
    return score;
}
string strupr(string s)
{
     for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

void who_wins(int score1, int score2)
{
    if (score1 > score2)
    {
         printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}