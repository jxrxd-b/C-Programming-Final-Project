#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"

int main() {
	char choice;

	printf("Welcome to the phone book!\n\n");

	choice = getPhonebookMenuChoice();

	void setPhonebookMenu(choice);

	printf("%c", choice);
	//test print
}