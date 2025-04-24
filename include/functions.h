#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <string.h>

typedef struct Contact {
	char firstName[50];
	char lastName[50];
	int age;
	char phoneNum[15];


} Contact;

typedef struct Phonebook {
	Contact contacts[100];
	int count;
} PhoneBook;



int getPhonebookMenuChoice();

void setPhonebookMenu(int choice, PhoneBook *phonebook);

Contact addContact(PhoneBook* phonebook);

void deleteContact(PhoneBook *pb, char* phoneNum);

void searchContacts(PhoneBook* phonebook, char* searchTerm);

void displayContacts(PhoneBook* pb);

void editContact(PhoneBook* phonebook);

#endif
