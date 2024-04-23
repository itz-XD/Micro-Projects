#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 3

// Structure to hold question and answer
typedef struct
{
    char question[200];
    char options[4][100];
    int correctAnswer;
} Question;

// Function to initialize questions
void initializeQuestions(Question questions[])
{
    strcpy(questions[0].question, "Eight Bits make up a");
    strcpy(questions[0].options[0], "1. megabyte");
    strcpy(questions[0].options[1], "2. kilobyte");
    strcpy(questions[0].options[2], "3. byte");
    strcpy(questions[0].options[3], "4. None");
    questions[0].correctAnswer = 3;

    strcpy(questions[1].question, "Arrange in ascending order the units of memory TB, KB, GB, MB");
    strcpy(questions[1].options[0], "1. TB>MB>GB>KB");
    strcpy(questions[1].options[1], "2. TB>GB>MB>KB");
    strcpy(questions[1].options[2], "3. MB>GB>TB>KB");
    strcpy(questions[1].options[3], "4. GB>MB>KB>TB");
    questions[1].correctAnswer = 2;

    strcpy(questions[2].question, "Which one is the result of the output given by a computer");
    strcpy(questions[2].options[0], "1. Data");
    strcpy(questions[2].options[1], "2. Istruction");
    strcpy(questions[2].options[2], "3. Excursion");
    strcpy(questions[2].options[3], "4. Information");
    questions[2].correctAnswer = 4;
}

// Function to display quiz instructions
void displayInstructions(char name[])
{
    printf("\n||-->>     Welcome to Quiz about Computers.     <<--||\n\n");
    // printf("Enter your name : %s\n\n", name);
    printf("||  Enter your name : ");
    scanf("%s", name);
    printf("\n%s, hit Space-Bar to start your quiz\n", name);
    while (getch() != ' ')
        ;
}

// Function to display question
void displayQuestion(Question question, int questionNum, int score)
{
    system("cls");
    printf("Questions :: [%d/%d]    ||    Score :: %d\n", questionNum, MAX_QUESTIONS, score);
    printf("----------------------------------------------------------\n\n");
    printf("Question %d:\n%s\n%s\n%s\n%s\n%s\n", questionNum, question.question,
           question.options[0], question.options[1], question.options[2], question.options[3]);
    printf("\nChoose your answer : ");
}

// Function to display result and options
void displayResult(char name[], int score)
{
    printf("\n=================================================================\n");
    printf("%s, you scored %d out of %d.\n", name, score, MAX_QUESTIONS);
    printf("=================================================================\n\n");
    printf("[r] - Restart the quiz\n");
    printf("[q] - Quit the quiz\n\n");
    printf("Choose your option :: \n\n");
}

int main()
{
    char name[50];
    Question questions[MAX_QUESTIONS];
    initializeQuestions(questions);
    int score, choice;
    char answer;

    // printf("Enter your name : ");
    // scanf("%s", name);

    while (1)
    {
        score = 0;
        displayInstructions(name);

        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            displayQuestion(questions[i], i + 1, score);
            scanf(" %c", &answer);

            // Convert character answer to integer choice
            choice = answer - '0';

            // Check if answer is correct
            if (choice == questions[i].correctAnswer)
            {
                score++;
            }
        }

        displayResult(name, score);

        while (1)
        {
            char option = getch();
            if (option == 'r')
            {
                break;
            }
            else if (option == 'q')
            {
                return 0;
            }
        }
    }

    return 0;
}