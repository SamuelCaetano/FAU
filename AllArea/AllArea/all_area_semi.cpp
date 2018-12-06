/*
Samuel Caetano	        Total Points:  10
Due Date:  6/7/2018
Due Time: 11:59pm
Course:  C0P3014
Assignment:  Assignment 4
Professor: Dr. Lofton Bullard

Description: A program called “all_area_semi.cpp” that computes the area of an arbitrary
triangle.
*/
#include<iostream> //basic input output stream library
#include <iomanip> //for precision setting to round to the nearest hundredth
#include <cmath> //standard basic math library.
#include <string> //string library

using namespace std;

//include function prototypes

//Compute Function: Computes the area and perimeter of a triangle based on the length of the sides.
void Compute(int a, int b, int c, double &area, double &semiperimeter);


///*************************************************************************************
//Name: Compute
//Precondition: The variables a, b, and c have been initialized and set to the lenghts of the sides of the triangle, area and semiperimeter may NOT have been initialized.
//Postcondition: The area and perimeter of the triangle has been computed and has been passed by reference to their respective variables by &area and &semiperimeter.
//Description: Performs calculations of area and semiperimeter of the triangle based on the sides given and passes the result by reference to &area and &semiperimeter.
//*************************************************************************************

void Compute(int a, int b, int c, double &area, double &semiperimeter)
{
	//Computer the semiperimeter
	semiperimeter = (a + b + c) / 2.0;

	//Compute the area
	area = sqrt((semiperimeter * (semiperimeter-a)) * (semiperimeter-b) * (semiperimeter-c));
}

//Main Function: Used for testing the program.
int main()
{
	//declare variables a, b, c,area, and semiperimeter
	int a, b, c;
	double area, semiperimeter;
	//declare variable for while loop
	string user_response = "y";

	//while loop
	while (user_response == "y" || user_response == "Y")		//begin while loop
	{
		//Obtain the values for the sides of the triangle.
		cout << "Please enter side a of the triangle" << endl;
		cin >> a;
		cout << "Please enter side b of the triangle" << endl;
		cin >> b;
		cout << "Please enter side c of the triangle" << endl;
		cin >> c;

		//Check if the triangle is possible and if so proceed to compute.
		if ((a + b) > c) {
			//Call Computer
			Compute(a, b, c, area, semiperimeter);

			//Statements to format output.
			cout.setf(ios::showpoint);
			cout.precision(2);
			cout.setf(ios::fixed);

			//Display output from customer_record
			cout << "Side a | Side b | Side c | semi | area" << endl;
			cout << a << "\t" << b << "\t" << c << "\t" << semiperimeter << "\t" << area << endl;
		}
		else {
			cout << "This does not constitute as a triangle... Calculations for area and semiperimeter cannot be performed!\n\n";
		}

		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
	}
	//end while loop
	return 0;
}