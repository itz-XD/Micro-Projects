#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Function to clear screen
void clearScreen() {
    system("cls");
}

// Function to display flash card question with countdown timer
void displayQuestion(char *question, int duration) {
    printf("Question : %s\t[ %d second timer ]\n", question, duration);
    for (int i = duration; i >= 0; i--) {
        printf("\rTime left: %d seconds", i);
        Sleep(1000); // Wait for 1 second
    }
    printf("\n");
}

// Function to display flash card answer
void displayAnswer(char *answer) {
    printf("Answer   : %s\n", answer);
    printf("Hit space key to see next question...\n");
}

int main() {
    char *questions[] = {
        "What is a computer?",
        "What is a language?",
        "What 'printf()' function returns?",
        "When was 'C' programming language introduced?"
    };

    char *answers[] = {
        "A computer is an electronic device which works on the principle of input-process-output.",
        "A method of communication by which we share our ideas and emotions.",
        "printf() returns an integer value same as the number of characters it prints.",
        "In 1972."
    };

    int durations[] = {5, 10, 10, 5};

    printf("This is a flash card program\n");
    printf("Press any key to continue . . . ");
    getch(); // Wait for any key press
    clearScreen();

    for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); i++) {
        displayQuestion(questions[i], durations[i]);
        clearScreen();
        displayAnswer(answers[i]);
        getch(); // Wait for space key press
        clearScreen();
    }

    printf("You have completed all questions.\n");
    printf("Press any key to continue . . . ");
    getch(); // Wait for any key press

    return 0;
}