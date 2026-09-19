#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>
int ALLalpha(string key);
int crptcheck(int argc, string key);
int IS_AlphaReapeat(string key);
int main(int argc,string argv[])
{   
 
     if(crptcheck(argc, argv[1])) return 1;
    string plaintext = get_string("plaintext: ");
    pre_crpttext(plaintext,argv[1]);
    printf("ciphertext: ");
    return 0;

}
int crptcheck(int argc, string key)
{
    
    if(argc!=2||strlen(key)!=26||ALLalpha(key)==1||IS_AlphaReapeat(key)==1)
    {
        printf("Usage: ./caesar key wrong\n");
        return 1;
    }
    else return 0;
}

int ALLalpha(string key)
{
    for(int i=0;i<strlen(key);i++)
    {
        if(!isalpha(key[i]))
        {
            return 1;
        }
    }
    return 0;
}
int IS_AlphaReapeat(string key)
{
    int count[26]={0};
    for(int i=0;i<strlen(key);i++)
    {
    int index= toupper(key[i])-'A';
    if(count[index]==1)
    {
        return 1;
    }
    else
    {
        count[index]=1;
    }
    }
    return 0;
}
void pre_crpttext(string plaintext, string key)
{
    for(int i=0;i<strlen(plaintext);i++)
    {
        if(isupper(plaintext[i]))
        {
            int index=plaintext[i]-'A';
            printf("%c",toupper(key[index]));
        }
        else if(islower(plaintext[i]))
        {
            int index=plaintext[i]-'a';
            printf("%c",tolower(key[index]));
        }
        else
        {
            printf("%c",plaintext[i]);
        }
    }
    printf("\n");
}