#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
	char phone[PHONE_LEN+1];
	char last[NAME_LEN+1];
	char first[NAME_LEN+1];
	int party_size;
	struct guest *next;
};


struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct guest *new_list = NULL;  
  printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = add_guest(new_list);
                break;
      case 'p': print_list(new_list);
                break;
      case 'q': clear_list(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct guest *add_guest(struct guest *list){
  struct guest *new_guest = (struct guest*)malloc(sizeof(struct guest));
   printf("Enter phone number: ");
   scanf("%s", (*new_guest).phone);
   if (new_guest == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
   struct guest *ptr = list;
   while (ptr != NULL) {
    if (strcmp((*ptr).phone, (*new_guest).phone) == 0) {
      printf("guest already exists.\n");
      return NULL;
      } else {
      ptr = (*ptr).next;
    }
   }
   new_guest -> next = NULL;
   printf("Enter guest's last name: ");
   read_line((*new_guest).last, NAME_LEN + 1);
   printf("Enter guest's first name: ");
   read_line((*new_guest).first, NAME_LEN + 1);
   printf("Enter party size: ");
   scanf("%d", &(*new_guest).party_size);
   if (list == NULL) {
    list = new_guest;
      } else {
        ptr = list;
        while ((*ptr).next!= NULL) {
            ptr = (*ptr).next;
        }
        (*ptr).next = new_guest;
      }
      return list;
} 


void print_list(struct guest *list){
  struct guest *ptr = list;
  while (ptr != NULL) {
    printf("%-15s%-20s%-20s%5d\n", (*ptr).phone, (*ptr).last, (*ptr).first, (*ptr).party_size);
    ptr = (*ptr).next;
  }
}

void clear_list(struct guest *list){
  struct guest *ptr = list;
   while (ptr != NULL) {
    struct guest *temp = ptr;
    ptr = (*ptr).next;
    free(temp);
  }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
