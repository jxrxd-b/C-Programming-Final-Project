#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>


struct Contact {
	char name[50];
	char phoneNum[15];
	int age;
};

struct Phonebook {
	struct Contact contacts[100];
	int count;
};

addContact(char* name, char* phoneNum);

displayContacts();

deleteContact(char* phoneNum);

searchContacts(char* name, char* phoneNum);

#endif