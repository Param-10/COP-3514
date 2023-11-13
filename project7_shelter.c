// Name: Paramveer Singh Bhele
// UNumber: U82076898
// Description : Project 7 - Shelter
// First we define all 2 values for max animals and max number of characters allowed. Next we define a structure to store the information of an animal while the weight is in decimal.
//In the main function, we first create an array to store the information on animals. We also initialize an variable to keep track of the number of animals.
//Then we open a file named animals and read it. If there is any error opening the file then a message is printed. 
//Next we run a while loop which scans the inputfile and then increments numAnimals to calculate the number of animals in the file. The file is closed after reading.
//The user then inputs the species and gender of the animal to be searched for. Then a output file named results.txt is written and if there is an error opening the file then a message is printed.
//The file is then read and the information of the animal is searched for. If the information is found then the information is written to the output file.
//A for loop is used to compare the input values and the values in the Animal array. The name, age and weight of the animal is printed in the output file. 
//Then the output files are closed and the name of the output file is printed.

#include <stdio.h>   // Includes standard input/output header file
#include <stdlib.h>  // Includes standard library header file
#include <string.h>  // Includes string manipulation functions header file

#define MAX_ANIMALS 200 // maximum number of animals
#define MAX_CHARS 100   // maximum number of characters for strings
struct Animal {  // Define a structure to hold information about an animal
    char name[MAX_CHARS];     // name of the animal
    char species[MAX_CHARS];  // species of the animal
    char gender[MAX_CHARS];   // gender of the animal
    int age;                  // age of the animal
    double weight;            // weight of the animal in decimal
};
int main() {
    struct Animal animals[MAX_ANIMALS]; // Create an array to store information about animals
    int numAnimals = 0;                 // Initialize a variable to count the number of animals
    FILE *inputf = fopen("animals.txt", "r"); // Open a file named "animals.txt" for reading
    if (!inputf) {
        printf("Error opening file animals.txt\n"); // If there's an error opening the file, print a message
        return 1; // Return an error code to exit the program
    }
    while (fscanf(inputf, "%s %s %s %d %lf", //calculates the total number of animals in the file
                  animals[numAnimals].name,
                  animals[numAnimals].species,
                  animals[numAnimals].gender,
                  &animals[numAnimals].age,
                  &animals[numAnimals].weight) == 5) { // Read information from the file as long as there are 5 successfully read values
        numAnimals++; // Increment the number of animals read
    }
    fclose(inputf); // Close the input file after reading
    //variables to store the input values to be searched
    char speciesInput[MAX_CHARS];
    char genderInput[MAX_CHARS];
    printf("Enter species: ");
    scanf("%s", speciesInput); //enter a species and store it in 'speciesInput'
    printf("Enter gender: ");
    scanf("%s", genderInput);  //enter a gender and store it in 'genderInput'
    FILE *outputf = fopen("results.txt", "w"); // Open a file named "results.txt" for writing
    if (outputf == NULL) {
        perror("Error opening file"); // If there's an error opening the file, print an error message
        return 1; // Return an error code to exit the program
    }
    for (int i = 0; i < numAnimals; i++) { // Iterate through the list of animals
        if (strcmp(animals[i].species, speciesInput) == 0 && // Check if the species matches the user's input
            strcmp(animals[i].gender, genderInput) == 0) {  // Check if the gender matches the user's input
            fprintf(outputf, "%s %d %.2lf\n", // Write the name, age, and weight of matching animals to the output file
                    animals[i].name, animals[i].age, animals[i].weight);
        }
    }
    fclose(outputf); // Close the output file after writing
    printf("Output file name: results.txt\n"); // Print the name of the output file
    return 0; 
}
