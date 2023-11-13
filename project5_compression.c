//Name: Paramveer Singh Bhele
//UNumber: U82076898
// Description : Project 5 - Task 1
// The main function initializes arrays input and output to hold the input and compressed output strings.
// It then prompts the user to enter a message.
// Calls the compress function to process the input and generate the compressed output.
// The compress Function takes two parameters, input (pointer to the input string) and output (pointer to the output string).
// It iterates through the input string, numing consecutive characters and compressing them.
// Appends the compressed characters to the output string.
// The last if statement handles the last set of characters and checks them.
// A null character is added to terminate the output string.

#include <stdio.h>

// Function prototypes
void compress(char *input, char *output);

int main() {
  // Initialize arrays to hold input and output strings
  char input[1001];
  char output[1001];

  // Prompt the user to enter a message
  printf("Enter message: ");

  // Read the input string from the user
  scanf("%s", input);

  // Call the compress function to process the input and generate the output
  compress(input, output);

  // Print the compressed output
  printf("Output: %s\n", output);

  return 0;
}

// Function to compress the input string
void compress(char *input, char *output) {
  char cur_char = *input;
  int num = 1;
  char *out = output;

  while (*input) {
    input++;
    if (*input == cur_char) {
     num++;
    } else {
      if  (num > 2) { // If num is greater than 2, compress the characters
        *out++ = num + '0';
        *out++ = cur_char;
      } else {
        while  (num > 0) { // Print character num times
          *out++ = cur_char;
         num--;
        }
      }
      cur_char = *input;
     num = 1;
    }
  }

  if  (num > 2) { // If num is greater than 2, compress the characters
    *out++ = num + '0';
    *out++ = cur_char;
  } else {
    while  (num > 0) { // Print character num times
      *out++ = cur_char;
     num--;
    }
  }

  *out = '\0'; // Add null character to terminate the output string
}
