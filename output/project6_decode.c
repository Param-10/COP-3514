// Name: Paramveer Singh Bhele
// UNumber: U82076898
// Description : Project 6 - Decode
// This program prompts the user to enter the file name, reads the content, and extracts the first letter of each word.
//One form of encryption is to mix plaintext with a large amount of non-cipher material. 
//then write the resulting message to a file with the same name but an added prefix of decoded_.
//For example, if the file name is test.txt, then the output file name will be decoded_test.txt.
//The file is composed of letters and white spaces (spaces, tabs, newlines). White spaces serve as word separators.

#include <stdio.h>
#include <string.h>

// Function to decode words
void decode(char (*words)[101], int num_words, char *result) {
    int i;
    for (i = 0; i < num_words; i++) {
        *result = words[i][0];  // Take the first letter of each word
        result++;
    }
    *result = '\0';  // Add null terminator at the end to mark the end of the result string
}

int main() {
    char input_file_name[101];
    char words[1000][101];  // Array to store words from the file
    char result[1001];  // Array to store the decoded message

    printf("Enter the file name: ");
    fgets(input_file_name, sizeof(input_file_name), stdin);
    input_file_name[strcspn(input_file_name, "\n")] = '\0';  // Remove trailing newline (if any)

    // Open the file for reading
    FILE *input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_words = 0;
    while (fscanf(input_file, "%100s", words[num_words]) == 1) {
        num_words++;
    }

    fclose(input_file);

    // Generate the output file name
    char output_file_name[201];
    snprintf(output_file_name, sizeof(output_file_name), "decoded_%s", input_file_name);

    // Decode the message
    decode(words, num_words, result);

    // Write the result to the output file
    FILE *output_file = fopen(output_file_name, "w");

    if (output_file == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    fprintf(output_file, "%s\n", result);
    fclose(output_file);

    printf("Output file name:\n%s\n", output_file_name);

    return 0;
}
