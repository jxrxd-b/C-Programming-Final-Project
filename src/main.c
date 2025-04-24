#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"

int main() {
	PhoneBook phonebook;
	phonebook.count = 0;
	char choice;
	printf("Welcome to the phone book!\n\n");
	do {
		choice = getPhonebookMenuChoice();
		setPhonebookMenu(choice, &phonebook);
	} while (choice != 5);
	return 0;
}
