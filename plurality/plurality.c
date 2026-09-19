#include "cs50.h"
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];
// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void sort(candidate candidates[], int left, int right);
int  main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Loop over all voters
        for (int i = 0; i < candidate_count; i++)
    { 
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
        return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
   sort(candidates, 0, candidate_count - 1);
   if(candidates[0].votes == 0)
   {
       printf("No winner.\n");
       return;
   }
    // Print the winner (or winners)
    int max_votes = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
void sort( candidate candidates[],int left,int right)//merge sort
{
    if(right==left)
    return;
    int mid=(left+right)/2;
    sort(candidates, left,mid);
    sort(candidates, mid+1,right);
    // Temporary array for sorting
    candidate temparr[MAX];
    candidate*p=&candidates[left];
    candidate*q=&candidates[mid+1];
    candidate*r=&temparr[0];
    
        while(p<=&candidates[mid]&&q<=&candidates[right])
        {
            if(p->votes<q->votes)
            {
                r->votes=q->votes;
                r->name=q->name;
                r++;
                q++;
            }
            else
            {
                r->votes=p->votes;
                r->name=p->name;
                r++;
                p++;
            }
        }
        if(p<=&candidates[mid])
        {
            while(p<=&candidates[mid])
            {
                r->votes=p->votes;
                r->name=p->name;
                r++;
                p++;
            }
        }
        else
        {
            while(q<=&candidates[right])
            {
                r->votes=q->votes;
                r->name=q->name;
                r++;
                q++;
            }
        }
      //move the sorted array back to the original array
        for(int i=0;i<right-left+1;i++)
        {
            candidates[left+i].votes=temparr[i].votes;
            candidates[left+i].name=temparr[i].name;
        }      
}