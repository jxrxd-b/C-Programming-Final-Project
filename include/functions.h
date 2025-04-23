#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>


typedef struct Contact {
	char* firstName[50];
	char* lastName[50];
	char* phoneNum[15];
	int age;

	char phoneNum[15];
	//do you like this as a string or should we make it an int?
	
	char city[50];
	char state[50];
	char country[50];
	char adress[100];
	int	zipCode;

	char email[50];

	char notes[100];   // 100 character limit (if too comolex, we'll get rid of this)
	char birthday[11]; // YYYY-MM-DD

}Contact;

typedef struct Phonebook {
	Contact contacts[100];
	int count;
}PhoneBook;

Contact addContact();

void displayContacts(PhoneBook *pb);

deleteContact(char* phoneNum);

searchContacts(char* name, char* phoneNum);

int getPhonebookMenuChoice();

void setPhonebookMenu(int choice);




#endif