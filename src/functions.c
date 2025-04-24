#include <stdio.h>     
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
		if (phonebook->count < 100) {
			phonebook->contacts[phonebook->count++] = addContact();
		}
		else {
			printf("Phonebook is full.\n");
		}
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



Contact addContact() {
	Contact contact;

	printf("Enter first name: ");
	if (scanf_s("%49s", contact.firstName, (unsigned)sizeof(contact.firstName)) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.firstName[0] = '\0';
	};

	printf("Enter last name: ");
	if (scanf_s("%49s", contact.lastName, (unsigned)sizeof(contact.lastName)) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.lastName[0] = '\0';
	};

	printf("Enter phone number: ");
	if (scanf_s("%14s", contact.phoneNum, (unsigned)sizeof(contact.phoneNum)) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.phoneNum[0] = '\0';
	};

	printf("Enter age: ");
	if (scanf_s("%d", &contact.age) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.age = -1;
		while (getchar() != '\n');
	};

	return contact;
}

void displayContacts(PhoneBook* pb) {
	for (int i = 0; i < pb->count; i++) {
		printf("Contact %d:\n", i + 1);
		printf("First Name: %s\n", pb->contacts[i].firstName);
		printf("Last Name: %s\n", pb->contacts[i].lastName);
		printf("Phone Number: %s\n", pb->contacts[i].phoneNum);
		printf("Age: %d\n", pb->contacts[i].age);
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