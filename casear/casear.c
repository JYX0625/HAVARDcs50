/*This is a simple Caesar cipher implementation*/
//需改进点：1、用循环链表实现加密循环；2、考虑k为负数的情况
#include <stdio.h>
#include <string.h>
#include "cs50.h"
int transfer(string argv);
void encrypt(string plaintext,int key);
int main(int argc,string argv[])
{
   if(argc!=2)
    {
        printf("invalid argument count");
        return 1;
    }
    for(int i=0;i<strlen(argv[1]);i++)
    { 
        if (argv[1][i]<48||argv[1][i]>57)
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    int key=transfer(argv[1]);
    printf("key is %d\n",key);
    string plaintext=get_string("plaintext:  ");
    encrypt(plaintext, key);
}
int transfer(string argv)
{
   int key=0,sum=0;
    for(int i=0;i<strlen(argv);i++)
     {
          key=argv[i]%48;
          for(int j=0;j<strlen(argv)-i-1;j++)
          {
                key=key*10;
          }
            sum=sum+key;
     }
    return sum%26;
}
void encrypt(string plaintext,int key)
{
    for(int i=0;i<strlen(plaintext);i++)
    {
        if(plaintext[i]>=65&&plaintext[i]<=90||plaintext[i]>=97&&plaintext[i]<=122)
        {
            if(key<=90-plaintext[i]&&(plaintext[i]>=65&&plaintext[i]<=90)||key<=122-plaintext[i]&&(plaintext[i]>=97&&plaintext[i]<=122))
            {
                 plaintext[i]=(plaintext[i]+key);
                 printf("ciphertex0: %s\n", plaintext);
            }
            else
            {
                plaintext[i]=(plaintext[i]+key-26); 
                printf("ciphertext1: %s\n", plaintext);
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
