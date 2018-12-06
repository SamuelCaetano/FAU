//Samuel Caetano
//COP2220 Introduction to C
//03/19/2018
//prog5, Interactive program using loops and user defined functions with pass by reference and pass by copy arguments.

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#include <stdio.h>
#include <ctype.h>

//Function Prototypes for GetInteger and CalculateBothCircle
int GetInteger(void);
void CalculateBothCircle(int radius, double* areaCirPtr, double* circumPtr);
int CalculateSumTotal(int number);
int CalculateProductTotal(int number);

//Main Function
int main()
{
	//Variable Declarations and Initializations
	int number, radius, sumTotal, productTotal;
	double circleArea, circleCir;
	
	//Small Program PART 1:
	//Set variables equal to their resulting values from the functions
	number = GetInteger();
	sumTotal = CalculateSumTotal(number);
	productTotal = CalculateProductTotal(number);
	//Print out the results
	printf("The sum total of the squares of your number is %d\n", sumTotal);
	printf("The product total of the squares of your number is %d\n", productTotal);



	//Small Program PART 2:
	//Set variables equal to their resulting values from the functions
	printf("You will be entering a radius!\n");
	radius = GetInteger();
	//Call CalculateBothCircle pass by reference function to calculate both circleArea and circleCir
	CalculateBothCircle(radius, &circleArea, &circleCir);
	//Print out the results
	printf("The area is %f\n", circleArea);
	printf("The circumference is %f\n", circleCir);

	return 0;
}

int GetInteger()
{
	int number;
	printf("Please enter an Integer:\n");
	scanf("%d", &number);
	return number;
}

void CalculateBothCircle(int radius, double* areaCircPtr, double* circumPtr)
{
	//Calculates area and circumference for the radius and stores it in the pointer reference
	*areaCircPtr = (PI * radius * radius);
	printf("The area is %f\n", *areaCircPtr);
	*circumPtr = (PI * 2 * radius);
	printf("The circumference is %f\n", *circumPtr);
}

int CalculateSumTotal(int number) {
	//Squares Total Initialization
	int squaresTotal = 0;
	int n = 1;

	//While Loop for calculation
	while (n <= number) {
		squaresTotal += n * n;
		n++;
	}

	return squaresTotal;
}

int CalculateProductTotal(int number) {
	int squaresProduct = 1;

	//For Loop for calculaltion
	for (int n = 1; n <= number; n++) {
		squaresProduct *= n * n;
	}

	return squaresProduct;
}
