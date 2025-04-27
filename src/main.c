#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"

/*
* Name:				main()
* Parameters:		none
* Processes:		runs the address book program
* Return Value: 	0
*/
int main() {
    AddressBook addressbook;
    addressbook.count = 0;
    int choice;
    do {
        choice = getAddressBookMenuChoice();
        setAddressBookMenu(choice, &addressbook);
    } while (choice != 6);
    return 0;
}

