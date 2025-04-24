#include <stdio.h>     
#include <stdlib.h>
#include <stdbool.h>   
#include "../include/functions.h"


/*
* Name:				getPhoneBookMenuChoice()
* Parameters:		none
* Processes:		displays options and gets a char choice
* Return Value: 	choice
*/
int getPhonebookMenuChoice() {
	int choice;
	printf("Phonebook Menu:\n");
	printf("1. Add Contact\n");
	printf("2. Display Contacts\n");
	printf("3. Delete Contact\n");
	printf("4. Search Contacts\n");
	printf("5. Edit contact\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	if (scanf_s("%d", &choice) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		choice = -1;
		while (getchar() != '\n');
	}
	return choice;
}

/*
* Name:				setPhoneBookMenu
* Parameters:		choice
* Processes:		uses Choice to run function options, that add, display, delete, and search contacts 
* Return Value: 	Choice
*/
void setPhonebookMenu(int choice, PhoneBook *phonebook) {
	
	switch (choice) {
	case 1:
		addContact(phonebook);
		break;
	case 2:
		displayContacts(phonebook);
		break;
	case 3: {
		char phoneNum[15];
		printf("Enter the phone number of the contact to delete: ");
		if (scanf_s("%14s", phoneNum, (unsigned)sizeof(phoneNum)) != 1) {
			fprintf(stderr, "Problems processing your selection.\n");
			while (getchar() != '\n');
			break;
		}
		while (getchar() != '\n');
		deleteContact(phonebook, phoneNum);
		break;
	}
	case 4:
		char searchTerm[50];
		printf("Enter the first name to search contacts: ");
		if (scanf_s("%49s", searchTerm, (unsigned)sizeof(searchTerm)) != 1) {
			fprintf(stderr, "Error reading search term.\n");
			break;
		}
		searchContacts(phonebook, searchTerm);
		break;
		break;
	case 5:
		editContact(phonebook);
		break;
	case 6:
		printf("Exiting...\n");
		break;
	default:
		printf("Invalid choice. Please try again.\n");
	}
}

/*
* Name:				searchContacts()
* Parameters:		phonebook, searchTerm                 
* Processes:		Searches for contacts in the phonebook by first name
* Return Value: 	none
*/
void searchContacts(PhoneBook* phonebook, char* searchTerm) {
	bool found = false;
	for (int i = 0; i < phonebook->count; i++) {
		if (strstr(phonebook->contacts[i].firstName, searchTerm) != NULL) {
			printf("\nContact %d:\n", i + 1);
			printf("First Name: %s\n", phonebook->contacts[i].firstName);
			printf("Last Name: %s\n", phonebook->contacts[i].lastName);
			printf("Phone Number: %s\n", phonebook->contacts[i].phoneNum);
			printf("Age: %d\n", phonebook->contacts[i].age);
			printf("----------------------------------------\n");
			found = true;
		}
	}
	if (!found) {
		printf("\nNo contacts found matching the input.\n");
	}
}

/*
* Name:				addContact()
* Parameters:		phonebook
* Processes:		Adds a new contact to the phonebook
* Return Value: 	Contact
*/
Contact addContact(PhoneBook *phonebook) {

		if (phonebook == NULL) {
			fprintf(stderr, "Phonebook is not initialized.\n");
		}
		if (phonebook->count >= 100) {
			fprintf(stderr, "Phonebook is full. Cannot add more contacts.\n");
			Contact emptyContact = { 0 };
			return emptyContact;
		}

		Contact contact;

		// First name
		printf("\n\n\nEnter first name: ");
		if (scanf_s("%49s", contact.firstName, (unsigned)_countof(contact.firstName)) != 1) {
			fprintf(stderr, "Error reading first name.\n");
			contact.firstName[0] = '\0';
		}

		// Last name
		printf("Enter last name: ");
		if (scanf_s("%49s", contact.lastName, (unsigned)_countof(contact.lastName)) != 1) {
			fprintf(stderr, "Error reading last name.\n");
			contact.lastName[0] = '\0';
		}

		// Phone number
		printf("Enter phone number: ");
		if (scanf_s("%14s", contact.phoneNum, (unsigned)_countof(contact.phoneNum)) != 1) {
			fprintf(stderr, "Error reading phone number.\n");
			contact.phoneNum[0] = '\0';
		}

		// Age
		printf("Enter age: ");
		if (scanf_s("%d", &contact.age) != 1) {
			fprintf(stderr, "Error reading age.\n");
			contact.age = 0;
		}

		// Add contact to phonebook
		phonebook->contacts[phonebook->count] = contact;
		phonebook->count++;

		// Output the entered information back to the user
		printf("\nNew Contact!\n\n");
		printf("First Name: %s\n", contact.firstName);
		printf("Last Name: %s\n", contact.lastName);
		printf("Phone Number: %s\n", contact.phoneNum);
		printf("Age: %d\n\n\n\n\n\n", contact.age);

		return contact;
}

/*
* Name:				displayContacts()
* Parameters:		phonebook
* Processes:		Displays all contacts in the phonebook
* Return Value: 	none
*/
void displayContacts(PhoneBook* phonebook) {
	for (int i = 0; i < phonebook->count; i++) {
		printf("\n\n\nContact %d:\n", i + 1);
		printf("First Name: %s\n", phonebook->contacts[i].firstName);
		printf("Last Name: %s\n", phonebook->contacts[i].lastName);
		printf("Phone Number: %s\n", phonebook->contacts[i].phoneNum);
		printf("Age: %d\n\n\n\n\n", phonebook->contacts[i].age);
	}
}

/*
* Name:				deleteContact()
* Parameters:		phonebook, phonNum
* Processes:		Deletes a contact from the phonebook based on phone number.
* Return Value: 	none
*/
void deleteContact(PhoneBook* phonebook, char* phoneNum) {
	for (int i = 0; i < phonebook->count; i++) {
		if (strcmp(phonebook->contacts[i].phoneNum, phoneNum) == 0) {
			for (int j = i; j < phonebook->count - 1; j++) {
				phonebook->contacts[j] = phonebook->contacts[j + 1];
			}
			phonebook->count--;
			printf("\n\nContact with phone number %s deleted.\n\n\n", phoneNum);
			return;
		}
	}
}

/*
* Name:				editContact()
* Parameters:		phonebook
* Processes:		Allows the user to edit a contact's details by searching for contact using phone number.
* Return Value: 	none
*/
void editContact(PhoneBook* phonebook) {
	char phoneNum[15];
	printf("Enter the phone number of the contact to edit: ");
	if (scanf_s("%14s", phoneNum, (unsigned)sizeof(phoneNum)) != 1) {
		fprintf(stderr, "Error reading phone number.\n");
		return;
	}

	for (int i = 0; i < phonebook->count; i++) {
		if (strcmp(phonebook->contacts[i].phoneNum, phoneNum) == 0) {
			printf("\nContact found!\n\n");
			printf("First Name: %s\n", phonebook->contacts[i].firstName);
			printf("Last Name: %s\n", phonebook->contacts[i].lastName);
			printf("Phone Number: %s\n", phonebook->contacts[i].phoneNum);
			printf("Age: %d\n\n", phonebook->contacts[i].age);

			printf("\nInput what you would like to change (first name, last name, phone number, age): ");
			char field[20];
			if (scanf_s("%19s", field, (unsigned)sizeof(field)) != 1) {
				fprintf(stderr, "Error reading field.\n");
				return;
			}

			if (strcmp(field, "first name") == 0) {
				printf("Enter new first name: ");
				if (scanf_s("%49s", phonebook->contacts[i].firstName, (unsigned)sizeof(phonebook->contacts[i].firstName)) != 1) {
					fprintf(stderr, "Error reading first name.\n");
				}
			}
			else if (strcmp(field, "last name") == 0) {
				printf("Enter new last name: ");
				if (scanf_s("%49s", phonebook->contacts[i].lastName, (unsigned)sizeof(phonebook->contacts[i].lastName)) != 1) {
					fprintf(stderr, "Error reading last name.\n");
				}
			}
			else if (strcmp(field, "phone number") == 0) {
				printf("Enter new phone number: ");
				if (scanf_s("%14s", phonebook->contacts[i].phoneNum, (unsigned)sizeof(phonebook->contacts[i].phoneNum)) != 1) {
					fprintf(stderr, "Error reading phone number.\n");
				}
			}
			else if (strcmp(field, "age") == 0) {
				printf("Enter new age: ");
				if (scanf_s("%d", &phonebook->contacts[i].age) != 1) {
					fprintf(stderr, "Error reading age.\n");
				}
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
