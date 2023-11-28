// Name : Paramveer Singh Bhele
// UNumber : U82076898
// Description : This file contains all the functions related to the operations on the list of guests.
// first we write the code for the add guest function. we first allocate the memory for a guest structure. then we ask the user to enter a phone number.
// next the user enters the last name, first name and the party size. if the list is empty then it is set to a new guest otherwise it goes through to the end of the list and then adds a new guest list.
// this phone number is checked if it is already present or not in the list and shows an error if it is already present
// this list is returned after updating it. in the print list function, i have used the formatting which was given in the project and used that to print the details according to the sample example.
// the clear list function, deallocates the list by using a temp variable to store the values.
// the remove_guest function removes a guest from the list based on phone number, last name, and first name. The function goes through the list, searching for the guest that matches the specified criteria. 
// If the guest is found, it adjusts the pointers to pass the guest to be removed and frees the memory occupied by that guest. The function returns the updated list.
// the remove guest function is similar to the add guest function but it just frees the pointer to remove the specified guest from the list.

// import libraries and files
#include "read_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h" 
#include "read_line.c"


struct guest* add_guest(struct guest* list) {
    struct guest *guest_new = (struct guest *)malloc(sizeof(struct guest)); // Allocate memory for a new guest structure
    printf("Enter phone number: "); // Prompts the user to enter their phone number and stores it in the guest struct
    scanf("%s", (*guest_new).phone);

    struct guest *point = list; // Create a pointer to go through the list
    while (point != NULL) { // Checks if the phone number already exists in the list.
        if (strcmp((*point).phone, (*guest_new).phone) == 0) {
            printf("guest already exists."); // If the same number is already present, this line is printed.
            free(guest_new); // Free the memory allocated for the new guest
            return list; // Return the original list without making any changes
        } else {
            point = (*point).next; // If no such guest is found, then move to the next guest in the list
        }
    }

   (*guest_new).next = NULL; //sets the next pointer of the guest to null, to indicate that it is the end of the list
   //prompts the user to enter the last name, first name and party size in the same order.
   printf("Enter guest's last name: ");
   read_line((*guest_new).last, NAME_LEN + 1);
   printf("Enter guest's first name: ");
   read_line((*guest_new).first, NAME_LEN + 1);
   printf("Enter party size: ");
   scanf("%d", &(*guest_new).party_size);

   if (list == NULL) { //if the list is empty then it is set to new guest
    list = guest_new;
      } 
      else { //otherwise it goes through the list and adds a new guest to the end
        point = list;
        while ((*point).next!= NULL) {
            point = (*point).next;
        }
        (*point).next = guest_new;
      }
      return list; //returns it after updating it
}

void print_list(struct guest* list) { //function to print the list
    struct guest *point = list; //create a pointer to go through the list
    while (point != NULL) { //go through the list and print the information if it is not null
        printf("%-15s%-20s%-20s%5d\n", (*point).phone, (*point).last, (*point).first, (*point).party_size);
        point = (*point).next;
  }
}

void clear_list(struct guest* list) { //clears the list
   struct guest *point = list; //creates a pointer to go through the list
   while (point != NULL) {
    struct guest *temp = point; //temp variable to store the pointer
    point = (*point).next;
    if(temp!=NULL){
      free(temp);}
  }
}

struct guest* remove_guest(struct guest* list) {
    // Allocate memory for a new guest structure to store user input for removing the guest data
    struct guest *guest_new = (struct guest *)malloc(sizeof(struct guest)); 
    struct guest* point = list; //pointer to go through the list
    struct guest* previous = NULL; //keep track of the previous node 
    // The user inputs the phone number, last name and first name
    printf("Enter phone number: ");
    scanf("%s", (*guest_new).phone);
    printf("Enter guest's last name: ");
    read_line((*guest_new).last, NAME_LEN + 1);
    printf("Enter guest's first name: ");
    read_line((*guest_new).first, NAME_LEN + 1);
    // Go through the list and find the guest with the same phone number, last name and first name to be removed
    while (point != NULL && (strcmp((*point).phone, (*guest_new).phone) != 0 || strcmp((*point).last, (*guest_new).last) != 0 || strcmp((*point).first, (*guest_new).first) != 0)) {
        previous = point;
        point = (*point).next;
    }
     // Check if the guest was not found in the list
    if (point == NULL) {
        printf("guest does not exist\n");
        return list;
    }
    // Adjust the pointers to pass the guest to be removed
    if (previous != NULL) {
        (*previous).next = (*point).next;
    } else {
        list = (*point).next;
    }
    // Free the memory occupied by the pointer to be removed
    free(point);
    return list; // Returns the list after removing the specified guest.
}
