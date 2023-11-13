//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 5 - Task 2
//The program reads a command line parameter (which should be a string) to see if it consists of consecutive alphabetical characters.
//To begin, the inOrder function starts by initializing with the first character of the input string. It then determines if the character is an alphabet. If not, it returns -1, indicating that the input was invalid.
//To ensure consistency, the character is changed to lowercase using tolower.
//The program then iterates over the remaining characters in the input string using a while loop. It conducts the same checks and comparisons as mentioned previously within the loop.
//If a non-alphabetic character is detected at any stage, the method returns -1 for invalid input.
//If the characters are not in the correct sequence, it returns 0. It returns 1 if the characters are in the correct sequence till the end of the string.
//In the main function, it checks to see if there is just one command line parameter (the program name counts as one). If not, the message "invalid input" is shown.
//It then runs the inOrder function with the given parameter and prints the appropriate message based on the outcome.
//The program ends by returning 0 to signify that it was successful.

#include <stdio.h>
#include <ctype.h>
// Function to check if characters in a string are in alphabetical order
int inOrder(char *input) {
    char previous, current;
    previous = *input; // Get the first character from the input
    // Check if the first character is an alphabet
    if (!isalpha(previous)) {
        return -1; // Return -1 for invalid input
    }
    previous = tolower(previous); // Convert to lowercase

    input++; // Move to the next character

    while (*input != '\0') {
        current = *input;
        // Check if the current character is an alphabet
        if (!isalpha(current)) {
            return -1; // Return -1 for invalid input
        }
        current = tolower(current); // Convert to lowercase
        // Check if the current character is in order with the previous one
        if (current < previous) {
            return 0; // Return 0 for not in order
        }
        previous = current; // Update previous character for comparison
        input++; // Move to the next character
    }
    return 1; // Return 1 for in order
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // Check if the number of command line arguments is not 2 (including the program name)
        printf("invalid input\n");
        return 0;
    }
    int result = inOrder(argv[1]); // Call the inOrder function with the provided command line argument
    if (result == -1) {
        printf("invalid input\n"); // Print "invalid input" if the inOrder function returns -1
    } else if (result == 0) {
        printf("not in order\n"); // Print "not in order" if the inOrder function returns 0
    } else {
        printf("in order\n"); // Print "in order" if the inOrder function returns 1
    }
    return 0;
}