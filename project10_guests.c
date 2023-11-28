// Name : Paramveer Singh Bhele
// UNumber : U82076898
// Description : This file contains the main function for the project.
// the main function is defined which prompts the user to enter an operation code, then calls a function to perform the requested action. this is looped until q is entered indicating to quit.
// and a error message is printed if the user doesn't enter the correct operation.

// imports the libraries and required files
#include <stdio.h>
#include <stdlib.h>
#include "guest.h"
#include "read_line.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/

int main(void) {
    char code;

    struct guest* new_list = NULL;

    printf("Operation Code: a for adding to the list at the end, r for removing from the list, p for printing the list; q for quit.\n");

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
        case 'a':
            new_list = add_guest(new_list);
            break;
        case 'r':
            new_list = remove_guest(new_list);
            break;
        case 'p':
            print_list(new_list);
            break;
        case 'q':
            clear_list(new_list);
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}
