#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>

typedef struct Contact {
    char firstName[50];
    char lastName[50];
    int age;
    char phoneNum[15];
    char streetAddress[100];
    char city[50];
    char state[50];
} Contact;

typedef struct AddressBook {
    Contact contacts[100];
    int count;
} AddressBook;

int getAddressBookMenuChoice();

void setAddressBookMenu(int choice, AddressBook* addressbook);

Contact addContact(AddressBook* addressbook);

void deleteContact(AddressBook* addressbook, char* phoneNum);

void searchContacts(AddressBook* addressbook, char* searchTerm);

void displayContacts(AddressBook* addressbook);

void editContact(AddressBook* addressbook);

#endif

