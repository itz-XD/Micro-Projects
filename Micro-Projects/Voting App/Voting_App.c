#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 4

// Structure to hold candidate information
typedef struct
{
    char name[20];
    int votes;
} Candidate;

// Function to initialize candidates
void initializeCandidates(Candidate candidates[])
{
    strcpy(candidates[0].name, "Ajay");
    candidates[0].votes = 0;

    strcpy(candidates[1].name, "Rohit");
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Shivendra");
    candidates[2].votes = 0;

    strcpy(candidates[3].name, "Ravi");
    candidates[3].votes = 0;
}

// Function to display candidates
void displayCandidates(Candidate candidates[])
{
    printf("\nList of Candidates Vote                      (s)\n");
    printf("------------------------------------------------\n\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("[%d] > %-20s %d\n", i, candidates[i].name, candidates[i].votes);
    }
}

int main()
{
    // Initialize candidates
    Candidate candidates[MAX_CANDIDATES];
    initializeCandidates(candidates);

    char choice;
    int index;

    // Display the voting box
    printf("+----------------------------------------------+\n");
    printf("|         >>    Vote for your CR    <<         |\n");
    printf("+----------------------------------------------+\n");
    printf("\n");

    // Display the list of candidates
    displayCandidates(candidates);

    // Prompt user for vote
    printf("\nPress respective key to vote ::\n");

    while (1)
    {
        scanf(" %c", &choice);

        // Convert character choice to integer index
        index = choice - '0';

        // Check if index is valid
        if (index >= 0 && index < MAX_CANDIDATES)
        {
            // Increase the vote count for the selected candidate
            candidates[index].votes++;

            // Clear the screen
            system("cls");

            // Display the voting box
            printf("+----------------------------------------------+\n");
            printf("|         >>    Vote for your CR    <<         |\n");
            printf("+----------------------------------------------+\n");
            printf("\n");

            // Display updated candidates
            displayCandidates(candidates);

            // Prompt user for vote
            printf("\nPress respective key to vote ::\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}