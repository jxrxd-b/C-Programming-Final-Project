#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>


typedef struct Contact {
	char name[50];
	char phoneNum[15];
	int age;
}Contact;

typedef struct Phonebook {
	struct Contact contacts[100];
	int count;
}PhoneBook;

addContact(char* name, char* phoneNum);

displayContacts();

deleteContact(char* phoneNum);

searchContacts(char* name, char* phoneNum);

#endif