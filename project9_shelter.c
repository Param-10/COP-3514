// Name: Paramveer Singh Bhele
// UNumber: U82076898
// Description: Project 9 - Shelter - Updated project 7
// The program starts by setting constants for the maximum number of animals and characters that can be used in strings.
// The structure 'Animal' is then defined to store information about an animal, such as its name, species, gender, age, and weight.
// For usage with the quicksort algorithm, the comparison function 'cmpfunc' is implemented.
// It compares animals first by species, then by age if the species are the same, and provides the result.
// The 'animals' array of type 'Animal' is generated in the main to keep information about animals. A variable called 'numAnimals' is set up to keep track of the number of animals.
// File "animals.txt"  is opened for reading. If the operation fails, an error message is presented.
// The while loop reads animal information from the input file, increments 'numAnimals', and repeats until all data is read. After that, the input file is closed.
// The 'qsort' function is used to sort the 'animals' array based on the 'cmpfunc' function, sorting by species first and then age second.
// To write to, an output file named "results.txt" is opened. If it cannot be opened, an error message is presented. 
// A for loop iterates through the sorted 'animals' array, writing the sorted data to the output file. After writing, the output file is closed.
// Finally, a message is written to the console with the name of the output file. The comparison function handles scenarios where the species are the same.

#include <stdio.h>   // Includes standard input/output header file
#include <stdlib.h>  // Includes standard library header file
#include <string.h>  // Includes string manipulation functions header file
#include <ctype.h>   // Includes character manipulation functions header file

#define MAX_ANIMALS 200 // maximum number of animals
#define MAX_CHARS 100   // maximum number of characters for strings

struct Animal {  // Define a structure to hold information about an animal
    char name[MAX_CHARS];     // name of the animal
    char species[MAX_CHARS];  // species of the animal
    char gender[MAX_CHARS];   // gender of the animal
    int age;                  // age of the animal
    double weight;            // weight of the animal in decimal
};

int cmpfunc(const void *a,const void *b)// Comparison function for qsort
{  int speciesComparison = strcmp((*((struct Animal *)a)).species, ((*(struct Animal *)b)).species); // First, cmpfunc species
    if (speciesComparison == 0)
    {
        int ageComparison = (*((struct Animal *)a)).age - (*((struct Animal *)b)).age; // If species are the same, cmpfunc by age
    return ageComparison;
    }
    return speciesComparison;
}

int main()
{
    struct Animal animals[MAX_ANIMALS];       // Create an array to store information about animals
    int numAnimals = 0;                       // Initialize a variable to count the number of animals
    FILE *inputf = fopen("animals.txt", "r"); // Open a file named "animals.txt" for reading
    if (!inputf)
    {
        printf("Error opening file animals.txt\n"); // If there's an error opening the file, print a message
        return 1;                                   // Return an error code to exit the program
    }
    while (fscanf(inputf, "%s %s %s %d %lf", animals[numAnimals].name, animals[numAnimals].species, animals[numAnimals].gender,
                                             &animals[numAnimals].age, 
                                             &animals[numAnimals].weight) == 5) // calculates the total number of animals in the file
    {                                                                                                                                                                                        // Read information from the file as long as there are 5 successfully read values
        numAnimals++; //increments the number of animals which are read                                                                                                                                                                        // Increment the number of animals read
    }
    qsort(animals, numAnimals, sizeof(struct Animal), cmpfunc); //sort using qsort and the cmpfunc function
    fclose(inputf); // Close the input file after reading variables to store the input values to be searched
    FILE *outputf = fopen("results.txt", "w"); // Open a file named "results.txt" for writing
    if (outputf == NULL)
    {
        perror("Error opening file"); // If there's an error opening the file, print an error message
        return 1;                     // Return an error code to exit the program
    }
    for (int i = 0; i < numAnimals; i++)
    { // Iterate through the list of animals to print the list
        fprintf(outputf, "%s %d %s %0.2lf %s\n", animals[i].species, animals[i].age, animals[i].name, animals[i].weight, animals[i].gender);
    }
    fclose(outputf);
    printf("Output file name: results.txt\n"); // Print the name of the output file
    return 0;
}
