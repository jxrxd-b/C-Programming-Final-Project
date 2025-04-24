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
	printf("5. Exit\n");
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
		// Search contacts
		break;
	case 5:
		printf("Exiting...\n");
		break;
	default:
		printf("Invalid choice. Please try again.\n");
	}
}



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
		printf("Enter first name: ");
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
		printf("\nNew Contact!\n");
		printf("First Name: %s\n", contact.firstName);
		printf("Last Name: %s\n", contact.lastName);
		printf("Phone Number: %s\n", contact.phoneNum);
		printf("Age: %d\n", contact.age);

		return contact;
}

void displayContacts(PhoneBook* pb) {
	if (pb->count == 0) {
		printf("No contacts to display.\n");
		return;
	}
	printf("Displaying contacts:\n");

	Contact temp;
	for (int i = 0; i < pb->count - 1; i++) {
		for (int j = i + 1; j < pb->count; j++) {
			if (strcmp(pb->contacts[i].lastName, pb->contacts[j].lastName) > 0) {
				temp = pb->contacts[i];
				pb->contacts[i] = pb->contacts[j];
				pb->contacts[j] = temp;
			}
		}
	}
	for (int i = 0; i < pb->count; i++) {
		printf("Name: %s %s, Phone: %s, Age: %d\n", pb->contacts[i].firstName, pb->contacts[i].lastName, pb->contacts[i].phoneNum, pb->contacts[i].age);
	}
}

void deleteContact(PhoneBook* pb, char* phoneNum) {
	for (int i = 0; i < pb->count; i++) {
		if (strcmp(pb->contacts[i].phoneNum, phoneNum) == 0) {
			for (int j = i; j < pb->count - 1; j++) {
				pb->contacts[j] = pb->contacts[j + 1];
			}
			pb->count--;
			printf("Contact with phone number %s deleted.\n", phoneNum);
			return;
		}
	}
}