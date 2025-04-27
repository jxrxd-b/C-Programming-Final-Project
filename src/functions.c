#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/functions.h"

int getAddressBookMenuChoice() {
    int choice;
    printf("Address Book Menu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contacts\n");
    printf("5. Edit Contact\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    if (scanf_s("%d", &choice) != 1) {
        fprintf(stderr, "Problems processing your selection.\n");
        choice = -1;
        while (getchar() != '\n');
    }
    return choice;
}

void setAddressBookMenu(int choice, AddressBook* addressbook) {
    switch (choice) {
    case 1:
        addContact(addressbook);
        break;
    case 2:
        displayContacts(addressbook);
        break;
    case 3: {
        char phoneNum[15];
        printf("Enter the phone number of the contact to delete: ");
        if (scanf_s("%14s", phoneNum, (unsigned)sizeof(phoneNum)) != 1) {
            fprintf(stderr, "Problems processing your selection.\n");
            while (getchar() != '\n');
            break;
        }
        deleteContact(addressbook, phoneNum);
        break;
    }
    case 4: {
        char searchTerm[50];
        printf("Enter the first name to search contacts: ");
        if (scanf_s("%49s", searchTerm, (unsigned)sizeof(searchTerm)) != 1) {
            fprintf(stderr, "Error reading search term.\n");
            break;
        }
        searchContacts(addressbook, searchTerm);
        break;
    }
    case 5:
        editContact(addressbook);
        break;
    case 6:
        printf("Exiting...\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}

void searchContacts(AddressBook* addressbook, char* searchTerm) {
    bool found = false;
    for (int i = 0; i < addressbook->count; i++) {
        if (strstr(addressbook->contacts[i].firstName, searchTerm) != NULL) {
            printf("\nContact %d:\n", i + 1);
            printf("First Name: %s\n", addressbook->contacts[i].firstName);
            printf("Last Name: %s\n", addressbook->contacts[i].lastName);
            printf("Phone Number: %s\n", addressbook->contacts[i].phoneNum);
            printf("Age: %d\n", addressbook->contacts[i].age);
            printf("Street Address: %s\n", addressbook->contacts[i].streetAddress);
            printf("City: %s\n", addressbook->contacts[i].city);
            printf("State: %s\n", addressbook->contacts[i].state);
            printf("----------------------------------------\n");
            found = true;
        }
    }
    if (!found) {
        printf("\nNo contacts found matching the input.\n");
    }
}

Contact addContact(AddressBook* addressbook) {
    if (addressbook == NULL) {
        fprintf(stderr, "AddressBook is not initialized.\n");
    }
    if (addressbook->count >= 100) {
        fprintf(stderr, "AddressBook is full. Cannot add more contacts.\n");
        Contact emptyContact = { 0 };
        return emptyContact;
    }

    Contact contact;

    printf("\n\n\nEnter first name: ");
    scanf_s("%49s", contact.firstName, (unsigned)_countof(contact.firstName));

    printf("Enter last name: ");
    scanf_s("%49s", contact.lastName, (unsigned)_countof(contact.lastName));

    printf("Enter phone number: ");
    scanf_s("%14s", contact.phoneNum, (unsigned)_countof(contact.phoneNum));

    printf("Enter age: ");
    scanf_s("%d", &contact.age);

    printf("Enter street address: ");
    scanf_s(" %[^\n]s", contact.streetAddress, (unsigned)_countof(contact.streetAddress));

    printf("Enter city: ");
    scanf_s("%49s", contact.city, (unsigned)_countof(contact.city));

    printf("Enter state: ");
    scanf_s("%49s", contact.state, (unsigned)_countof(contact.state));

    addressbook->contacts[addressbook->count] = contact;
    addressbook->count++;

    printf("\nNew Contact Added!\n\n");
    printf("First Name: %s\n", contact.firstName);
    printf("Last Name: %s\n", contact.lastName);
    printf("Phone Number: %s\n", contact.phoneNum);
    printf("Age: %d\n", contact.age);
    printf("Street Address: %s\n", contact.streetAddress);
    printf("City: %s\n", contact.city);
    printf("State: %s\n\n\n\n", contact.state);

    return contact;
}

void displayContacts(AddressBook* addressbook) {
    for (int i = 0; i < addressbook->count; i++) {
        printf("\n\n\nContact %d:\n", i + 1);
        printf("First Name: %s\n", addressbook->contacts[i].firstName);
        printf("Last Name: %s\n", addressbook->contacts[i].lastName);
        printf("Phone Number: %s\n", addressbook->contacts[i].phoneNum);
        printf("Age: %d\n", addressbook->contacts[i].age);
        printf("Street Address: %s\n", addressbook->contacts[i].streetAddress);
        printf("City: %s\n", addressbook->contacts[i].city);
        printf("State: %s\n\n\n\n", addressbook->contacts[i].state);
    }
}

void deleteContact(AddressBook* addressbook, char* phoneNum) {
    for (int i = 0; i < addressbook->count; i++) {
        if (strcmp(addressbook->contacts[i].phoneNum, phoneNum) == 0) {
            for (int j = i; j < addressbook->count - 1; j++) {
                addressbook->contacts[j] = addressbook->contacts[j + 1];
            }
            addressbook->count--;
            printf("\n\nContact with phone number %s deleted.\n\n\n", phoneNum);
            return;
        }
    }
}

void editContact(AddressBook* addressbook) {
    char phoneNum[15];
    printf("Enter the phone number of the contact to edit: ");
    if (scanf_s("%14s", phoneNum, (unsigned)sizeof(phoneNum)) != 1) {
        fprintf(stderr, "Error reading phone number.\n");
        return;
    }

    for (int i = 0; i < addressbook->count; i++) {
        if (strcmp(addressbook->contacts[i].phoneNum, phoneNum) == 0) {
            printf("\nContact found!\n\n");
            printf("First Name: %s\n", addressbook->contacts[i].firstName);
            printf("Last Name: %s\n", addressbook->contacts[i].lastName);
            printf("Phone Number: %s\n", addressbook->contacts[i].phoneNum);
            printf("Age: %d\n\n", addressbook->contacts[i].age);

            printf("\nInput what you would like to change (firstName, lastName, phoneNum, age, streetAddress, city, state): ");
            char field[20];
            if (scanf_s("%19s", field, (unsigned)sizeof(field)) != 1) {
                fprintf(stderr, "Error reading field.\n");
                return;
            }

            if (strcmp(field, "firstName") == 0) {
                printf("Enter new first name: ");
                scanf_s("%49s", addressbook->contacts[i].firstName, (unsigned)sizeof(addressbook->contacts[i].firstName));
            }
            else if (strcmp(field, "lastName") == 0) {
                printf("Enter new last name: ");
                scanf_s("%49s", addressbook->contacts[i].lastName, (unsigned)sizeof(addressbook->contacts[i].lastName));
            }
            else if (strcmp(field, "phoneNum") == 0) {
                printf("Enter new phone number: ");
                scanf_s("%14s", addressbook->contacts[i].phoneNum, (unsigned)sizeof(addressbook->contacts[i].phoneNum));
            }
            else if (strcmp(field, "age") == 0) {
                printf("Enter new age: ");
                scanf_s("%d", &addressbook->contacts[i].age);
            }
            else if (strcmp(field, "streetAddress") == 0) {
                printf("Enter new street address: ");
                scanf_s(" %[^\n]s", addressbook->contacts[i].streetAddress, (unsigned)sizeof(addressbook->contacts[i].streetAddress));
            }
            else if (strcmp(field, "city") == 0) {
                printf("Enter new city: ");
                scanf_s("%49s", addressbook->contacts[i].city, (unsigned)sizeof(addressbook->contacts[i].city));
            }
            else if (strcmp(field, "state") == 0) {
                printf("Enter new state: ");
                scanf_s("%49s", addressbook->contacts[i].state, (unsigned)sizeof(addressbook->contacts[i].state));
            }
            else {
                printf("Invalid input.\n");
            }

            printf("\nContact updated!\n");
            return;
        }
    }

    printf("\nPhone number not found.\n");
}