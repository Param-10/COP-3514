//Name: Paramveer Singh Bhele
//UNumber: U82076898
//Description : Project 4 - Task2 - Exclusive or
//in the main function, the program asks for the length of the first array and then asks to enter the 1st array elements. Then the same process for the 2nd array.
// then the function is called with the parameters and then the output is printed.
//according to the question, we have to create a function with the specific parameters. then we use the pointers to assign the values and a count variable to count the number of elements in array c.
//then we use a nested for loop to compare the elements of array a to b. the inner for loop will compare 1 element of array a to all the elemts of array b.
//if something is found, then it breaks the loop and moves on to the next element in array a. if not a match then the value of the element in array a is assigned to the array c and count is incremented.
//the same process is done to check the elements of array b to array a. in exclusive or, we are reqauired to compare the arrrays and find the unique elements which are not common. 
//so there can be some element which is in a and not in b and vice versa. that is the reason for doing a similar nested for loop again.
//and finally the value of count is assigned to the variable that size points to. 

#include <stdio.h>

void exclusive_or(int *a, int n1,  int *b, int n2, int *c, int *size) { //required function according to the question with these parameters.
    int *ptr_a = a; //pointer to an array of integers (a). It represents the first input array.
    int *ptr_b = b; //pointer to an array of integers (b). It represents the second input array.
    int *ptr_c = c; //pointer to an array of integers (c). It will be used to store the result of the exclusive OR operation.
    int count = 0; //used to keep track of the number of elements in the resulting array

    for (int i = 0; i < n1; i++) {
        int match = 0;
        for (int j = 0; j < n2; j++) {
            if (*ptr_a == *ptr_b) {
                match = 1; 
                break; //breaks the loop if point a is equal to pointer b and moves to the next 
            }
            ptr_b++; //increments the pointer to check the next array element
        }
        ptr_b = b;  // Reset ptr_b to the beginning of array b
        if (!match) { //if not a match
            *ptr_c = *ptr_a; //assigns the value of the array a element in the array c
            ptr_c++; //moves to the next position in the array c
            count++; //increments the count
        }
        ptr_a++; //moves to the next element in array a (outer for loop)
    }
    for (int i = 0; i < n2; i++) {
        int match = 0;
        ptr_a = a;  // Reset ptr_a to the beginning of array a
        for (int j = 0; j < n1; j++) {
            if (*ptr_b == *ptr_a) {
                match = 1;
                break; //breaks the loop if point a is equal to pointer b and moves to the next 
            }
            ptr_a++; //increments the pointer to check the next array element
        }
        if (!match) {
            *ptr_c = *ptr_b; //assigns the value of the array b element in the array c
            ptr_c++; //moves to the next position in the array c
            count++;
        }
        ptr_b++; //moves to the next element in array b (outer for loop)
    }
    *size = count; //assigning the value of count to the variable that size points to
}

int main() {
    int n1, n2;
    printf("Enter length of array #1: ");
    scanf("%d", &n1); //inputs the length of the first array
    int a[n1];
    printf("Enter array elements: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]); //inputs the 1st array elements
    }
    printf("Enter length of array #2: ");
    scanf("%d", &n2); //inputs the length of the 2nd array
    int b[n2];
    printf("Enter array elements: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]); //inputs the 2nd array elements
    }
    int c[n1 + n2]; //sets the size of array c to the total size of array a and b
    int size;

    exclusive_or(a, n1, b, n2, c, &size);

    printf("Output: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]); //prints the array elements in order.
    }
    printf("\n");
    return 0;
}