#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/functions.h"




int main() {

	ContactInfo var1;
	char input[50];

	printf("Please enter your firstName:\t");
	scanf_s("%49s", input, sizeof(input));
	//%49s limits the input to 49 characters, leaving space for the null terminator
	
	strcpy_s(var1.firstName, sizeof(var1.firstName), input);

	printf("%s", var1.firstName);


}