/*
Samuel Caetano
COP2220-006
04/16/2018
Large Program 3 - Hangman, Write an interactive program that will allow a user to play the game of Hangman. 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXGUESSES 6

//provides instruction to the user on how to play
void HangmanRules();

//this function asks the user if they want to play another game
void PlayAgain(char *againPtr);

//this function runs one game
//input: character from the file, void return type
//all other functions to Play one round of a game 
//are called from within the PlayOneGame function
void PlayOneGame(char solution[]);

//this function changes a character array to all uppercase letters
void UpperCaseWord(char word[]);

//this function creates the starword array
void CreateStarword(char starword[], int length);

//this function gets the users guess letter and adds it to the lettersGuessed array
//returns the letter entered by the user
char GetTheLetterGuess(char lettersGuessed[], int *numPtr);

//this function replaces any asterik in the starword with the current character entered by the user
int ReplaceStars(char solution[], char starword[], char letter);

//this function gets the guess word,
//compares the solution and the guess word 
//tells the user if they have won and returns a 1
//otherwise it returns a 0
int DidYouWin(char solution[]);

int main() {

	char resp = 'Y';
	char sol[25];
	char star[25];
	char guesses[25];
	char userguess[25];
	HangmanRules();
	FILE *iPtr;
	iPtr = fopen("hangmanWords.txt", "r");

	do {
		fscanf(iPtr, " %s", sol);
		UpperCaseWord(&sol);
		PlayOneGame(&sol);
		PlayAgain(&resp);

	} while (toupper(resp) == 'Y');

	return 0;
}

void HangmanRules() {
	printf("Welcome to the hangman!\n\n");
	printf("You will be given a word from a file to guess.\n");
	printf("You may guess letters one at a time\n");
	printf("You are able to have up to 6 incorrect letter guesses\nand if you have guessed correctly, you have a chance at guessing the word!\n\n");
}

void PlayAgain(char *againPtr) {

	printf("Please Enter Y (yes) to play again or N (no) to stop\n\n");
	scanf(" %c", againPtr);

}

void PlayOneGame(char solution[]) {
	char starword[30] = "";
	char lettersGuessed[30] = "";
	int length = strlen(solution);
	int count = 0;
	int win = 0;
	int guesses = 0;

	CreateStarword(starword, length);

	do {
		printf("Starword is: %s\n", starword);
		printf("Here are the letters guessed so far: %s\n", lettersGuessed);
		printf("Guess a letter: \n");
		char guess = GetTheLetterGuess(lettersGuessed, &count);
		for (int x = 0; x < strlen(starword); x++) {
			if (starword[x] == guess) {
				starword[x] = toupper(guess);
			}
		}
		if (ReplaceStars(solution, starword, guess) == 1) {
			printf("Starword is: %s\n", starword);
			printf("You have successfully guessed a letter, you may now guess the word: \n");
			win = DidYouWin(solution);
		}
		count++;
		guesses++;
	} while (win == 0 && guesses < MAXGUESSES);

	if (guesses == MAXGUESSES) {
		printf("You have run out of guesses, and have lost the game!\n");
	}

}

void UpperCaseWord(char word[]) {
	int length = strlen(word);
	for (int x = 0; x < length; x++) {
		word[x] = toupper(word[x]);
	}
}

void CreateStarword(char starword[], int length) {
	for (int x = 0; x < length; x++) {
		starword[x] = '*';
	}
	starword[length] = '\0';
}

char GetTheLetterGuess(char lettersGuessed[], int *numPtr) {
	scanf(" %c", &lettersGuessed[*numPtr]);
	return lettersGuessed[*numPtr];
}

int ReplaceStars(char solution[], char starword[], char letter) {
	int guessed = 0;
	for (int x = 0; x < strlen(solution); x++) {
		if (toupper(letter) == solution[x]) {
			starword[x] = solution[x];
			guessed = 1;
		}
	}
	return guessed;
}

int DidYouWin(char solution[]) {
	char userGuess[25] = "";
	scanf(" %s", &userGuess);
	UpperCaseWord(userGuess);
	if (strcmp(solution, userGuess) == 0) {
		printf("Congratulations, you guessed the word: %s\n", solution);
		return 1;
	}
	else {
		return 0;
	}
}