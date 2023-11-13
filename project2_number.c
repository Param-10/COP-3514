//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 2 - Task 1
//first function checks if the number is a multiple of 3 by using the modulus operator.
//next function uses a while loop to check if any of the digits of the number contain 3. it checks the last digit of the number and if it was 3 then it returns true.
//main takes the user input and then the if statement calls the functions ans checks if it is true for both contains 3 and multiple of 3. 

#include <stdio.h>

int Multiple3(int num) { //function which returns true if the number is a multiple of 3.
    return num % 3 == 0; // checks if the remainder is 0 when divided by 3
}
int contains3(int num) { //function which checks if any of the digits contain '3'
    while (num > 0) { 
        if (num % 10 == 3) { //checks if the last digit of the number was 3
            return 1;} // if it was 3 then it will return true
        num /= 10;} //removes the last digit from the number
    return 0;
}

int main() {
    int num_input; // to store the user's input

    printf("Enter input: ");
    scanf("%d", &num_input); // takes the input from the user. 

    if (contains3(num_input) && Multiple3(num_input)) { // calls the functions and checks if they satisfy the conditions
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}