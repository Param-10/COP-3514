// Name : Paramveer Singh Bhele
// UNumber : U82076898
// Description : This file contains struct guest declaration and prototypes for the functions in guest.c
// The #ifndef-#endif pair is used as guards to prevent multiple inclusions of the same header file
// The #ifndef checks if GUEST_H is not defined yet. If not defined, it proceeds to the next lines.
// in the guest structure a few more important variables related to the guests are initialized. next another structure consisting of the functions which are related to adding the guests.

#ifndef GUEST_H
#define GUEST_H
//define int lengths
#define NAME_LEN 30
#define PHONE_LEN 20

struct guest {
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;
    struct guest* next;
};

struct guest* add_guest(struct guest* list);
void print_list(struct guest* list);
void clear_list(struct guest* list);
struct guest* remove_guest(struct guest* list);

#endif
