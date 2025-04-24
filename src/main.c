#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"


/*
* Name:				main()
* Parameters:		none
* Processes:		runs the phonebook program
* Return Value: 	0
*/
int main() {
    PhoneBook phonebook;
    phonebook.count = 0;
    int choice;
    do {
        choice = getPhonebookMenuChoice();
        setPhonebookMenu(choice, &phonebook);
    } while (choice != 6);
    return 0;
}
