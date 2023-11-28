// Name : Paramveer Singh Bhele
// UNumber : U82076898
// Description : This file contains the readline function which is used as an opperation on the list. 
// The #ifndef checks if READ_LINE_H is not defined yet. If not defined, it proceeds to the next lines.
// the readline function is predefinded for this project. it is used to read a line of the input.

// Import libraries and files
#include <ctype.h>
#include <stdio.h>
#include "read_line.h"

int read_line(char str[], int n) { //function to read the line of the input
  int ch, i = 0;

  while (isspace(ch = getchar())) //skip the leading whitespaces
    ;
  str[i++] = ch; //stores the first character in an array
  while ((ch = getchar()) != '\n') { //loop to keep on reading the characters until a newline is present
    if (i < n)
      str[i++] = ch;
    
   }
   //terminates the string
   str[i] = '\0';
   return i;
}
