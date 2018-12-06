//Samuel Caetano
//COP2220 Introduction to C
//02/12/2018
//prog4, interactive program that can do simple calculations with integers and doubles using of user defined functions.

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#include <stdio.h>

//Function Prototypes
int GetInteger(void);
int CalculateAreaSquare(int length);
double CalculateCircumferenceCircle(int radius);

int main()
{
	//Declare integers
	int radius, length, squareArea;
	//Declare doubles
	double circleCir;
	//Greet the user
	printf("Greetings User!\n");
	//Prompt for a radius
	printf("Please enter the radius you would like for a circle: ");
	//Sets the variable radius equal to the return of the call to the GetInteger function.
	radius = GetInteger();
	//Set the variable circleCir to equal the circle circumference by passing the function CalculateCircumferenceCircle(int radius) the radius.
	circleCir = CalculateCircumferenceCircle(radius);
	//Displays radius and circumference of the circle.
	printf("The radius of your circle is %d and the circumference of your circle is %.3f\n", radius, circleCir);
	//Prompts the user for the length to be used for the side of a square.
	printf("Please enter a length for the side of a square: ");
	//Sets the variable length equal to the return of the call to the GetInteger function.
	length = GetInteger();
	//Sets the variable squareArea to equal the area of the circle by passing the functiton CalculateAreaSquare(int length) the length.
	squareArea = CalculateAreaSquare(length);
	//Displays the side length and the area of the square.
	printf("The length you chose for the square is %d and the area of that square is %d\n", length, squareArea);
}

//GetInteger Function
int GetInteger()
{
	int integer;
	scanf("%d", &integer);
	return integer;
}


//CalculateCircumferenceCircle Function
double CalculateCircumferenceCircle(int radius)
{
	double circumference = radius * 2 * PI;
	return circumference;
}

//CalculateAreaSquare Function
int CalculateAreaSquare(int length)
{
	int area = length*length;
	return area;
}