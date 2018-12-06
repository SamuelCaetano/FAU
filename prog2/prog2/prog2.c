/*
Samuel Caetano
01/28/2018
Small Program 2, Interactive program using printf, scanf, and simple math in C.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>

int getNumber(double number) {
	//takes number and adds to 5.
	int total = number + 5;
	return total;
}

//Main Function
int main() {

	int number;
	int total;
	char letter;
	char letterLowercase;
	char letterUppercase;

	printf("%d", getNumber(5));

	//Prompts the user.
	printf("Hello my name is Samuel Caetano\n");
	printf("Please enter a number you would like me to add %d to...\n", 435);
	//Scans for number.
	scanf("%d", &number);
	//Calculates the Sum.
	total = number + 435;
	//Provides Feedback.
	printf("Your original number was %d and the sum is %d.\n", number, total);
	//Prompts the user.
	printf("Please enter a letter...\n");
	//Scans for a letter.
	scanf(" %c", &letter);
	//Creates toupper and tolower case versions of the letter and stores them.
	letterLowercase = tolower(letter);
	letterUppercase = toupper(letter);
	//Provides Feedback.
	printf("Your original letter lowercased is %c and your letter uppercased is %c.\n", letterLowercase, letterUppercase);
	//End statement.
	printf("Have a nice day!\n");
	return 0;
}