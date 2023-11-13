//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 2 - Task 2
//we use the ctype header from the c library which will allow us to use the isalpha function from this directive.
//getchar() will get the first character of the input. !isalpha will check if the character is an alphabet or not. if it is not then it will print invlid input.
//then convert this character to lowercase so that it can be compared with the next character later. 
//while loop will read the next character and this loop will go on until newline is encountered. next, it checks if the input is an alphabet or not.
//the current character is also converted to lowercase. if the current character has an ASCII lower than the previous one then the characters are not in order and the program is exited.
//but if the characters are in order than the print statement prints in order.

#include <stdio.h>
#include <ctype.h> //it is a header in the c standard library which will allow us to use the isalpha function

int main() {
    char previous, current; //variables to store the current and previous alphabets
    printf("Enter input: ");
    // Gets the first character
    previous = getchar();
    // Checks if the input is not an alphabetic character
    if (!isalpha(previous)) { //checks if the character is not an alphabet
        printf("invalid input\n");
        return 0;
    }
    previous = tolower(previous); // Convert to lowercase

    while ((current = getchar()) != '\n') { //reads characters from input and loops until /n
        // Check if the input is not an alphabetic character
        if (!isalpha(current)) { //checks if the current character is not an alphabet
            printf("invalid input\n");
            return 0;
        }
        current = tolower(current); // Convert to lowercase
        if (current < previous) { //checks if lowercase current is less than previous in terms of ASCII
            printf("not in order\n"); //if statement is true then the characters are not in order
            return 0;
        }
        previous = current; // to check the next character in the loop

    }
    printf("in order\n");

    return 0;
}
