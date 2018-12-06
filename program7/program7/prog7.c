/* Samuel Caetano
* COP2220 Intro to Programming in C
* user defined struct example
* 4/18/2018
*/

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct {
	char author[SIZE];
	char bookName[SIZE];
	int numPages;
	double cost;
}book;

//Function Prototypes

// fills the data fields of a book instance
//returns the filled book 
book Fillbook();

//fills the data fields of a book instance
//by reference using a pointer to a book
void FillbookPtr(book *bookptr);

//fills an array of books
void FillbookArray(book arrayC[], int *size);


//displays one book
void Displaybook(book anybook);

int main()
{

	//Declare variables
	book mybook, mybook1, mybook2;
	book booklist[SIZE];
	int cSize;
	int i;

	//Fill structures with a function
	mybook = Fillbook();
	mybook1 = Fillbook();

	//print using display function
	printf("\n---------Display mybook\n");
	Displaybook(mybook);
	printf("\n---------Display mybook1\n");
	Displaybook(mybook1);

	//Fill structure using pointers and dispay it
	FillbookPtr(&mybook2);
	printf("\n---------Display mybook2\n");
	Displaybook(mybook2);

	//Fill the array with the function
	printf("\n---------Fill array booklist\n");
	FillbookArray(booklist, &cSize);

	//display an array of books
	printf("\n---------Display array booklist\n");
	for (i = 0; i<cSize; i++)
	{
		Displaybook(booklist[i]);
	}

	return 0;
}

//Function Definitions


// fills the data fields of a book instance
//returns the filled book 
book Fillbook()
{
	//Declare local variables
	book tempC;
	//prompt and get information
	printf("\nplease enter the author of your book:  ");
	scanf("%s", tempC.author);
	//print to check
	printf("author:  %s\n", tempC.author);

	//prompt and get information
	printf("\nplease enter the name of your book:  ");
	scanf("%s", tempC.bookName);
	//print to check
	printf("bookName:  %s\n", tempC.bookName);

	//prompt and get information
	printf("\nplease enter the number of pages of your book:  ");
	scanf("%d", &tempC.numPages);
	printf("number of pages:  %d\n", tempC.numPages);

	//prompt and get information
	printf("\nplease enter the cost of your book:  ");
	scanf("%lf", &tempC.cost);
	printf("cost:  %.2f\n", tempC.cost);
	return tempC;
}



//displays one book
void Displaybook(book anybook)
{
	printf("\n\nAuthor:  %s\n", anybook.author);
	printf("Book Name:  %s\n", anybook.bookName);
	printf("Number of pages:  %d\n", anybook.numPages);
	printf("Cost:  %.2f\n", anybook.cost);
}


//fills the data fields of a book instance
//by reference using a pointer to a book
void FillbookPtr(book *bookptr)
{
	//prompt and get information
	printf("\nplease enter the author of your book:  ");
	scanf("%s", (*bookptr).author);

	//prompt and get information
	printf("\nplease enter the name of your book:  ");
	scanf("%s", bookptr->bookName);

	//prompt and get information
	printf("\nplease enter the number of pages of your book:  ");
	scanf("%d", &(*bookptr).numPages);

	//prompt and get information
	printf("\nplease enter the cost of your book:  ");
	scanf("%lf", &(*bookptr).cost);
}




//fills an array of books
void FillbookArray(book arrayC[], int *size)
{
	int i;
	//prompt the user
	printf("\nenter the number of books:  ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i = 0; i < *size; i++)
	{
		printf("enter author:  ");
		scanf("%s", arrayC[i].author);

		printf("enter book name:  ");
		scanf("%s", arrayC[i].bookName);

		printf("enter number of pages:  ");
		scanf("%d", &arrayC[i].numPages);

		printf("enter cost:  ");
		scanf("%lf", &arrayC[i].cost);
	}
}



/*please enter the author of your book:  king
author:  king

please enter the bookName of your book:  spade
bookName:  spade

please enter the number of pages of your book:  10
number of pages:  10

please enter the author of your book:  three
author:  three

please enter the bookName of your book:  heart
bookName:  heart

please enter the number of pages of your book:  3
number of pages:  3

---------Display mybook


author:  king
bookName:  spade
number of pages:  10

---------Display mybook1


author:  three
bookName:  heart
number of pages:  3

please enter the author of your book:  king

please enter the bookName of your book:  diamonds

please enter the number of pages of your book:  10

---------Display mybook2


author:  king
bookName:  diamonds
number of pages:  10

---------Fill array booklist

enter the number of books:  3
size:  3
enter author:  jack
enter bookName:  clubs
enter number of pages:  10
enter author:  four
enter bookName:  hearts
enter number of pages:  4
enter author:  ace
enter bookName:  spades
enter number of pages:  11

---------Display array booklist


author:  jack
bookName:  clubs
number of pages:  10


author:  four
bookName:  hearts
number of pages:  4


author:  ace
bookName:  spades
number of pages:  11
Press any key to continue . . .*/

