#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>


typedef struct Contact {
	char firstName[50];
	char lastName[50];
	char phoneNum[15];
	int age;


	//test test
	// Team 3 Final Project



}Contact;

typedef struct Phonebook {
	Contact contacts[100];
	int count;
}PhoneBook;

Contact addContact();

void displayContacts(PhoneBook *pb);

deleteContact(char* phoneNum);

searchContacts(char* name, char* phoneNum);

int getPhonebookMenu(int choice);

void setPhonebookMenu(int choice);




#endif