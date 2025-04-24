#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"

int main() {
    PhoneBook phonebook;
    phonebook.count = 0;
    int choice;
    do {
        choice = getPhonebookMenuChoice();
        setPhonebookMenu(choice, &phonebook);
    } while (choice != 5);
    return 0;
}