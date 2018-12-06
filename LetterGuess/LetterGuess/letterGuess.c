/*
Samuel Caetano
02/19/2018
Large Program 1, Interactive program where the user plays a game and guesses a series of letters retrieved from a file.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_GUESSES 5

#include <stdio.h>
#include<ctype.h>

/*
─────▄██▀▀▀▀▀▀▀▀▀▀▀▀▀██▄─────
────███───────────────███────
───███─────────────────███───
──███───▄▀▀▄─────▄▀▀▄───███──
─████─▄▀────▀▄─▄▀────▀▄─████─
─████──▄████─────████▄──█████
█████─██▓▓▓██───██▓▓▓██─█████
█████─██▓█▓██───██▓█▓██─█████
█████─██▓▓▓█▀─▄─▀█▓▓▓██─█████
████▀──▀▀▀▀▀─▄█▄─▀▀▀▀▀──▀████
███─▄▀▀▀▄────███────▄▀▀▀▄─███
███──▄▀▄─█──█████──█─▄▀▄──███
███─█──█─█──█████──█─█──█─███
███─█─▀──█─▄█████▄─█──▀─█─███
███▄─▀▀▀▀──█─▀█▀─█──▀▀▀▀─▄███
████─────────────────────████
─███───▀█████████████▀───████
─███───────█─────█───────████
─████─────█───────█─────█████
───███▄──█────█────█──▄█████─
─────▀█████▄▄███▄▄█████▀─────
──────────█▄─────▄█──────────
──────────▄█─────█▄──────────
───────▄████─────████▄───────
─────▄███████───███████▄─────
───▄█████████████████████▄───
─▄███▀───███████████───▀███▄─
███▀─────███████████─────▀███
▌▌▌▌▒▒───███████████───▒▒▐▐▐▐
─────▒▒──███████████──▒▒─────
──────▒▒─███████████─▒▒──────
───────▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒───────
─────────████░░█████─────────
────────█████░░██████────────
──────███████░░███████───────
─────█████──█░░█──█████──────
─────█████──████──█████──────
──────████──████──████───────
──────████──████──████───────
──────████───██───████───────
──────████───██───████───────
──────████──████──████───────
─██────██───████───██─────██─
─██───████──████──████────██─
─███████████████████████████─
─██─────────████──────────██─
─██─────────████──────────██─
────────────████─────────────
─────────────██──────────────

______   _______             _______                      _______  _       _________  _________ _______    _______  _        _______             _______    _______  _______  _______  _______   _____
(  __  \ (  ___  )  |\     /|(  ___  )|\     /|  |\     /|(  ___  )( (    /|\__   __/  \__   __/(  ___  )  (  ____ )( \      (  ___  )|\     /|  (  ___  )  (  ____ \(  ___  )(       )(  ____ \ / ___ \
| (  \  )| (   ) |  ( \   / )| (   ) || )   ( |  | )   ( || (   ) ||  \  ( |   ) (        ) (   | (   ) |  | (    )|| (      | (   ) |( \   / )  | (   ) |  | (    \/| (   ) || () () || (    \/( (   ) )
| |   ) || |   | |   \ (_) / | |   | || |   | |  | | _ | || (___) ||   \ | |   | |        | |   | |   | |  | (____)|| |      | (___) | \ (_) /   | (___) |  | |      | (___) || || || || (__     \/  / /
| |   | || |   | |    \   /  | |   | || |   | |  | |( )| ||  ___  || (\ \) |   | |        | |   | |   | |  |  _____)| |      |  ___  |  \   /    |  ___  |  | | ____ |  ___  || |(_)| ||  __)       ( (
| |   ) || |   | |     ) (   | |   | || |   | |  | || || || (   ) || | \   |   | |        | |   | |   | |  | (      | |      | (   ) |   ) (     | (   ) |  | | \_  )| (   ) || |   | || (          | |
| (__/  )| (___) |     | |   | (___) || (___) |  | () () || )   ( || )  \  |   | |        | |   | (___) |  | )      | (____/\| )   ( |   | |     | )   ( |  | (___) || )   ( || )   ( || (____/\    (_)
(______/ (_______)     \_/   (_______)(_______)  (_______)|/     \||/    )_)   )_(        )_(   (_______)  |/       (_______/|/     \|   \_/     |/     \|  (_______)|/     \||/     \|(_______/     _

*/

//This function provides instructions to the user on how to play the game.
//@return void return type
void LetterGuessRules();

//This function runs one game. It for checks either 5 incorrect guesses or correct guess.
//@param takes in a char which is the letter to be checked.
//@return returns a 0 if the game is over and the player did not guess the letter, otherwise it returns 1.
int PlayOneGame(char);

//This function prompts the player to make a guess and returns that guess
//This function is called from inside the PlayOneGame() function described above
//@return returns the guess of the user input.
char GetGuess();

//This function is called from inside the PlayOneGame() function described above
//It lets the user know if the guess comes alphabet ically before or after the answer
//@param takes in two characters, the guess from the player and the solution letter from the file
//@return returns 1 if the guess matches the solution and returns a 0 if they do not match.
int CompareSolutionToGuess(char, char);

//This function asks and gets the number of games the user wants to play.
//@return returns number of games the user wants to play.
int GameCount();

int main()

{
	//Declare Variables
	//Initialize numGames to 3 and i to 0
	int numGames = 3, i = 0, numGuesses = 0;
	char solution, guess;

	//Declare file pointer to the filer letters.txt
	FILE *ptr;

	//Use fopen to retrieve and open access to the file.
	//Pass fopen two arguments: the file name, access type (i.e. "r" for read or "w" for write).

	//Initialize ptr to equal the pointer returned by fopen.
	ptr = fopen("letters.txt", "r");

	//Function call to LetterGuessRules()
	//Prompts the user and displays the rules of the game.
	LetterGuessRules();

	//A check to see if the file exist, if the pointer does NOT (!) exist, print out a statement for the user to know what went wrong.
	if (!ptr)
	{
		//Prints out a statement if a null pointer is found.
		printf("Make sure the file is in the Resource File Directory! File was not found!\n");
	}

	//Set numGames = GameCount()
	numGames = GameCount();

	//print num games onto screen to test:
	//printf("numGames is: %d", numGames);

	printf("There are %d solution letters.\n", numGames);

	//This for loop will allow the user to play more than one game
	for (i = 0; i < numGames; i++)
	{
		//lets play game (x)
		printf("Lets play game %d\n", i+1);

		//get a solution letter from file - use fscanf
		fscanf(ptr, " %c", &solution);

		//print the solution back onto the screen to test:
		//SOLUTION TEST: fprintf("The solution letter in the files is %c\n", &solution);

		//change the solution to uppercase
		solution = toupper(solution);

		//call the PlayOneGame function and pass it the solution
		int gameResult = PlayOneGame(solution);
	}

	printf("Thank you for playing letter guess!\n");

	//closes file pointer (for safety)
	fclose(ptr);

	return 0;
}

//This function provides instructions to the user and provides them with rules on how to play the game.
void LetterGuessRules()
{
	printf("Welcome to Letter Guess!\n\n");
	printf("First, you will enter the number of games you want to play (1 - 8 games).\n");
	printf("For each individual game, you have 5 chances to guess each letter.\n");
	printf("Let's Begin:\n\n");
}

//this function runs one game. It for checks either 5 incorrect guesses or correct guess.

//It returns a 0 if the game is over and the player did not guess the letter, otherwise it returns 1.

int GameCount()

{
	int numGames;

	//Prompt user for number of games to play.
	printf("How many games would you like to play: ");
	
	//Scan in the number of games to play from the keyboard.
	scanf("%d", &numGames);

	return numGames;

}

int PlayOneGame(char solution)

{

	int win = 0;
	int numGuesses = 0;

	while (numGuesses < MAX_GUESSES && win == 0) {
		//Gets the user's guess.
		char guess = GetGuess();
		//Change guess to uppercase.
		guess = toupper(guess);
		//Compare guess with solution to check if win.
		win = CompareSolutionToGuess(guess, solution);
		//Increment numGuesses by 1.
		numGuesses++;
	}

	if (win == 1) {
		printf("\nCongratulations, you have guesses the correct letter and have won the game!\n\n");
	}
	else {
		printf("\nBoo Hoo, you have lost that round!\n\n");
	}

	return win;

}

//this function prompts the player to make a guess and returns that guess

//this function is called from inside the PlayOneGame() function described above

char GetGuess()

{

	char guess;

	printf("Enter a letter: ");

	scanf(" %c", &guess);

	return (char)toupper(guess);

}

//this function takes two arguments, the guess from the player

//and the solution letter from the file.

//It lets the user know if the guess comes alphabetically before or after the answer

//The function returns 1 if the guess matches the solution and returns a 0 if they do not match
int CompareSolutionToGuess(char guess, char solution)

{
	int result = 0;

	if (guess == solution)

	{
		result = 1;
	}
	else if (guess < solution)

	{
		printf("\nThe solution letter comes after your guess (%c)\n", guess);
		result = 0;
	}
	else
	{
		printf("\nThe letter comes before your guess (%c)\n", guess);
		result = 0;
	}

	return result;

}