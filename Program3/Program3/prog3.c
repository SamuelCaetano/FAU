/*
Samuel Caetano
02/04/2018
Small Program 3, Interactive program using integers and doubles for basic geometric math.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.) Declare needed variables
int radius, length, squareArea, squarePerimeter;
double circleArea, circleCir;
double PI = 3.141592;

//Main Function
int main() {
	//2.) Greets User
	printf("Greetings User\n");

	//3.) Prompts the user to enter a radius
	printf("Please enter a radius for a circle:\n");

	//4.) Gets the user entered value for the radius from the keyboard
	scanf("%d", &radius);

	//5.) Calculates Area of the Circle
	circleArea = PI*(radius*radius);

	//6.) Responds with the Area of the user's Circle
	printf("The area of your circle which has a radius of %d is %.3f\n", radius, circleArea);

	//7.) Calculates Circumference of the Circle
	circleCir = 2*PI*radius;

	//8.) Responds with the Circumference of the user's Circle
	printf("The circumference of your circle is %.3f\n", circleCir);

	//9.) Prompt for the side length of a square
	printf("Enter a number for the side of a square:\n");

	//10.) Gets the number for the side length of a square from the user's keyboard
	scanf("%d", &length);

	//11.) Calculates the Area of a Square
	squareArea = length * length;

	//12.) Responds with the Area of the square
	printf("The area of the square with the side length provided of %d is %d\n", length, squareArea);

	//13.) Calculates the Perimeter of the square
	squarePerimeter = 4 * length;

	//14.) Responds with the Perimeter of the square
	printf("The perimeter of yoru square is %d\n", squarePerimeter);

	return 0;
}