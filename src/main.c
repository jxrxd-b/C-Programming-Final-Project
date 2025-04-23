#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"




int main() {
	char menuChoice;
	
	printf("Wlecome to the phone book!");

	menuChoice = getPhonebookMenuChoice();
	printf("%c", menuChoice);
	//test print

}