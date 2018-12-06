/*
Samuel Caetano
COP2220-006
04/27/2018
Large Program 4 - Inventory, Write an interactive program that will allow a user to manage an inventory of songs.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

//Only problem is for some reason the menu runs twice

typedef struct
{
	int id;
	char artist[20];
	char title[20];
	int length;
	double cost;
	double retail;
}inventory;

//Greets the user
void greetUser();

//runs the menu and gets the user choice
char runMenu();

//displays the ids in the list
void displayIDs();

//hardcodes five entries
int hardcodeInventory(struct inventory* ptr);

//prints the contents of the list onto the screen
void showRecords(int count, struct inventory* ptr);

//prints a report to a file
void writeRecords(int count, struct inventory* ptr);

//adds an item to the list
int addRecord(int count, struct inventory* ptr);

//removes an item form the list
int deleteRecord(int count, int prodID, struct inventory* ptr);

//updates the item in the list
void updateRecord(int count, int prodID, struct inventory* ptr);

//clears all items from the list
void clearRecords(int count, struct inventory* ptr);

int main()
{
	char input = 'P';
	inventory inv[max];
	int count = 0;
	int itemID;
	count = hardcodeInventory(inv);

	greetUser();

	while (input != 'Q')
	{
		input = runMenu();
		switch (toupper(input))
		{
		case 'P':showRecords(count, inv);
			break;
		case 'A':count = addRecord(count, inv);
			break;
		case 'C':clearRecords(count, inv); count = 0;
			break;
		case 'S':writeRecords(count, inv);
			break;
		case 'D':printf("\nEnter the itemID to delete:");
			scanf("%d", &itemID);
			count = deleteRecord(count, itemID, inv);
			break;
		case 'U':printf("\nEnter the item's id to update:");
			scanf("%d", &itemID);
			updateRecord(count, itemID, inv);
			break;
		case 'Q':printf("\nQuitting.....");
			exit(0);
			break;
		}
	}

	return 0;

}

//hardcodes the inventory, returns count
int hardcodeInventory(inventory* ptr)
{
	//Item 1
	(ptr + 0)->id = 421;
	strcpy((ptr + 0)->artist, "Incubus");
	strcpy((ptr + 0)->title, "NiceToKnowYou");
	(ptr + 0)->length = 231;
	(ptr + 0)->cost = 0.55;
	(ptr + 0)->retail = 2.29;

	//Item 2
	(ptr + 1)->id = 444;
	strcpy((ptr + 1)->artist, "Dirty.Heads");
	strcpy((ptr + 1)->title, "CabinByTheSea");
	(ptr + 1)->length = 222;
	(ptr + 1)->cost = 0.25;
	(ptr + 1)->retail = 0.99;

	//Item 3
	(ptr + 2)->id = 321;
	strcpy((ptr + 2)->artist, "MilkyChance");
	strcpy((ptr + 2)->title, "StolenDance");
	(ptr + 2)->length = 244;
	(ptr + 2)->cost = 0.25;
	(ptr + 2)->retail = 0.99;

	//Item 4
	(ptr + 3)->id = 123;
	strcpy((ptr + 3)->artist, "GeorgeEzra");
	strcpy((ptr + 3)->title, "Budapest");
	(ptr + 3)->length = 200;
	(ptr + 3)->cost = 0.25;
	(ptr + 3)->retail = 1.29;

	//Item 5
	(ptr + 4)->id = 83;
	strcpy((ptr + 4)->artist, "PearlJam");
	strcpy((ptr + 4)->title, "YellowLedbetter");
	(ptr + 4)->length = 303;
	(ptr + 4)->cost = 0.25;
	(ptr + 4)->retail = 1.29;
	
	return 5;
}

//prints the contents of the list onto the screen
void showRecords(int count, inventory *ptr)
{
	int i;
	if (count == 0)
	{
		printf("\n No current records to display");
	}
	else{
		printf("\nAll Inventory Records");
		for (i = 0; i<count; i++)
		{
			printf("\n--Item %d--\n\nThe id is: %d\nThe artist is: %s\nThe song title is: %s\nThe length of the song (in seconds) is: %d\nThe cost of the song is: $%.2f\nThe retail price of the song is: $%.2f\n", i+1, (ptr + i)->id, (ptr + i)->artist, (ptr + i)->title, (ptr + i)->length, (ptr + i)->cost, (ptr + i)->retail);
		}
	}
}

//prints a report to a file
void writeRecords(int count, inventory*ptr)
{
	int i;
	FILE *fptr;
	fptr = (fopen("inventory.txt", "w"));

	if (!fptr)
	{
		printf("Error, no file found!");
		exit(1);
	}

	if (count == 0)
	{
		fprintf(fptr, "\n No current records to display");
	}
	else
	{
		for (i = 0; i<count; i++)
		{
			fprintf("\n--Item %d--\n\nThe id is: %d\nThe artist is: %s\nThe song title is: %s\nThe length of the song (in seconds) is: %d\nThe cost of the song is: $%.2f\nThe retail price of the song is: $%.2f\n", i + 1, (ptr + i)->id, (ptr + i)->artist, (ptr + i)->title, (ptr + i)->length, (ptr + i)->cost, (ptr + i)->retail);
		}
	}

	printf("\nCurrent inventory report stored in inventory.txt");
	
	fclose(fptr);
}

//adding a new record to inventory
int addRecord(int count, inventory* ptr)
{
	int i = count;

	printf("\nPlease enter id, artist, song title, length, cost, and retail price of the song\n");

	scanf("%d %s %s %d %lf %lf", &(ptr + i)->id, (ptr + i)->artist, (ptr + i)->title, &(ptr + i)->length, &(ptr + i)->cost, &(ptr + i)->retail);

	printf("\nA new record has been added successfully");

	return i + 1;

}

//deleting a item from inventory
int deleteRecord(int count, int itemID, inventory* ptr)
{
	int i;

	for (i = 0; i<count; i++)
	{
		if (itemID == (ptr + i)->id)
		{
			if (i < count) {
				int diff = count - i;
				while (diff > 0) {
					(ptr + i)->id = (ptr + count-diff)->id;
					*(ptr + i)->artist = *(ptr + count-diff)->artist;
					*(ptr + i)->title = *(ptr + count-diff)->title;
					(ptr + i)->length = (ptr + count-diff)->length;
					(ptr + i)->cost = (ptr + count-diff)->cost;
					(ptr + i)->retail = (ptr + count-diff)->retail;
					diff--;
				}
			}
			else 
			{
			(ptr + i)->id = 0;
			*(ptr + i)->artist = '\0';
			*(ptr + i)->title = '\0';
			(ptr + i)->length = 0;
			(ptr + i)->cost = 0.0;
			(ptr + i)->retail = 0.0;
			}

			count = count - 1;

			printf("\nRecord has been deleted");
		}
	}

	if (i == count - 1)
	{
		printf("\nItem was not found");
	}

	return count;
}

//modify an item in inventory
void updateRecord(int count, int itemID, inventory* ptr)
{
	printf("\nCurrently Available ID's:\n");
	displayIDs(count, ptr);

	int i;
	for (i = 0; i < count; i++)
	{
		if (itemID == (ptr + i)->id)
		{
			printf("\nPlease enter the new id, artist, song title, length, cost, and retail price of the song\n");
			scanf("%d %s %s %d %lf %lf", &(ptr + i)->id, (ptr + i)->artist, (ptr + i)->title, &(ptr + i)->length, &(ptr + i)->cost, &(ptr + i)->retail);
			printf("\nRecord has been modified");
		}
	}

	if (i == count - 1)
	{
		printf("\nItem not found");
	}
}

// clearing all the available records from inventory
void clearRecords(int count, inventory* ptr)
{
	int i;
	for (i = 0; i<count; i++)
	{
		(ptr + i)->id = 0;
		*(ptr + i)->artist = '\0';
		*(ptr + i)->title = '\0';
		(ptr + i)->length = 0;
		(ptr + i)->cost = 0.0;
		(ptr + i)->retail = 0.0;
	}

	printf("\nAll records have been deleted");

};

//greets user
void greetUser() {
	printf("\nHello user, welcome to the song inventory\n");
	printf("This program manages a list of songs, with each song having its own specific details\n");
}

//runs menu and gets the user's choice
char runMenu() {
	char choice;
	printf("\n\n P....Print the inventory list onto the screen\n");
	printf("\n A....Add a new song entry\n");
	printf("\n C....Clear all records\n");
	printf("\n S....Create a current report(save it to a file)\n");
	printf("\n D....Delete a song from the list(inventory)\n");
	printf("\n U....Update a song\n");
	printf("\n Q...Quit\n");

	printf("\n Enter a choice:");

	scanf("%c", &choice);

	return choice;
}

//displays the ids in the inventory
void displayIDs(int count, inventory* ptr) {
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%d\n", (ptr + i)->id);
	}
}