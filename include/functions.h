#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>

typedef struct Contact {
	char firstName[50];
	char lastName[50];
	int age;

	char phoneNum[15];

	char city[50];
	char state[50];
	char country[50];
	char adress[100];
	int zipCode;

	char email[50];

	char notes[100];   // 100 character limit (if too comolex, we'll get rid of this)
	char birthday[11]; // YYYY-MM-DD

} Contact;

typedef struct Phonebook {
	Contact contacts[100];
	int count;
} PhoneBook;

/*
* Name:				getPhoneBookMenuChoice()
* Parameters:		none
* Processes:		displays options and gets a char choice
* Return Value: 	choice
*/

int getPhonebookMenuChoice();

/*
* Name:				setPhoneBookMenu
* Parameters:		choice
* Processes:		uses Choice to run function options, that add, display, delete, and search contacts
* Return Value: 	void
*/

void setPhonebookMenu(int choice, PhoneBook *phonebook);




Contact addContact(PhoneBook *phonebook);

void deleteContact(PhoneBook *pb, char* phoneNum);

searchContacts(char* name, char* phoneNum);

void displayContacts(PhoneBook* pb);

#endif