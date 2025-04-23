#include <stdio.h>     
#include <stdbool.h>   
#include "../include/functions.h"

Contact addContact() {
	Contact contact;

	printf("Enter first name: ");
	if (scanf("%49s", &contact.firstName) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.firstName[0] = '\0';
	};

	printf("Enter last name: ");
	if (scanf("%49s", &contact.lastName) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.lastName[0] = '\0';
	};

	printf("Enter phone number: ");
	if (scanf("%14s", &contact.phoneNum) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		contact.phoneNum[0] = '\0';
	};

	printf("Enter age: ");
	if (scanf("%d", &contact.age) != 1) {
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

int getPhonebookMenu(int choice) {
	int choice;
	printf("Phonebook Menu:\n");
	printf("1. Add Contact\n");
	printf("2. Display Contacts\n");
	printf("3. Delete Contact\n");
	printf("4. Search Contacts\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	if (scanf("%d", &choice) != 1) {
		fprintf(stderr, "Problems processing your selection.\n");
		choice = -1;
		while (getchar() != '\n');
	}
	return choice;
}

void setPhonebookMenu(int choice) {
	switch (choice) {
	case 1:
		addContact();
		break;
	case 2:
		displayContacts();
		break;
	case 3:
		// Delete contact
		break;
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

