/*
Samuel Caetano	        Total Points:  20
Due Date:  6/14/2018
Due Time: 11:59pm
Course:  C0P3014
Assignment:  Assignment 5
Professor: Dr. Lofton Bullard

Description: Extension of assignment 3, A program that calculates the net cost of a call (net_cost), the
tax on a call (call_tax) and the total cost of that call (total_cost). Outputs the calls Info to a file. Uses three functions, input, output, and process. Utilizes a file input and output data streams.
*/

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

class call_record
{
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

//Function Prototypes: Input, Output, and Process
void Input(ifstream &, call_record &);
void Output(const call_record &);
void Process(call_record &);

//Function Implementations will go here

///*************************************************************************************
//Name:  Input
//Precondition: The variables cell_number, relays, call_length have not been initialized in a call record.
//Postcondition: The variables cell_number, relays, call_length have been initalized and have been set the values specified in the file datastream line in a call record.
//Description: Get input (values of cell_number, relays, and call_length) from a data file and store in call record.

void Input(ifstream & in, call_record & call_records) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	//Reads input from file and stores it in customer_record
	in >> call_records.cell_number;
	in >> call_records.relays;
	in >> call_records.call_length;
}

///*************************************************************************************
//Name:  Output
//Precondition: The variables out (ofstream) cell_number, relays, call_length have been initialized and set to constants and net_cost, call_tax, and total_cost_of_call have their constant values initialized as well based on what was retrieved from the file.
//Postcondition: cout precision has been set and output from the customer_record has been displayed to the screen.
//Description:  Sets the format of cout, and outputs from customer_record to the weekly_call_info text file.
//*************************************************************************************

void Output(ofstream & out, const call_record & customer_record)
{
	fstream stream;
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	//Outputs call info to output stream file.
	out << customer_record.cell_number << "\t" << customer_record.relays << "\t" << customer_record.call_length << "\t" << customer_record.net_cost << "\t" << customer_record.tax_rate << "\t" << customer_record.call_tax << "\t" << customer_record.total_cost << endl << endl;
}

///*************************************************************************************
//Name:  Process
//Precondition: The variables relays, call_length have been initialized and set to constants, net_cost, call_tax, and total_cost_of_call are not initialized in the customer_record but will be calculated.
//Postcondition: All caculations have been made in order to be passed to the customer_record which will then be used for output.
//Description: To determine the tax_rate and perform all calculations.
//*************************************************************************************

//Note: there are 3 input parameter and 3 output parameters
void Process(call_record & customer_record)
{
	/*Step 1: put your code here to determine the net_cost using the formula: relays / 50.0 * .40 * call_length;

	Step 2: put your if-else statement here to determine the tax rate.
	condition 1 if relays <= 1  && relays <= 5 then  tax_rate is .01 and call_tax = net_cost * tax_rate
	condiion  2 if relays >=6 && relays <=1 then tax_rate is .03 and call_tax = net_cost * tax
	and so forth

	Step 3:put your code here to determine the total_cost using the formula: total_cost = net_cost + call_tax;

	*/

	//Calculate the net cost of a call.
	customer_record.net_cost = (customer_record.relays / 50.00 * 0.40 * customer_record.call_length);

	if (0 <= customer_record.relays && customer_record.relays <= 5) {
		customer_record.tax_rate = 0.01;
	}
	else if (6 <= customer_record.relays && customer_record.relays <= 11) {
		customer_record.tax_rate = 0.03;
	}
	else if (12 <= customer_record.relays && customer_record.relays <= 20) {
		customer_record.tax_rate = 0.05;
	}
	else if (21 <= customer_record.relays && customer_record.relays <= 50) {
		customer_record.tax_rate = 0.08;
	}
	else {
		customer_record.tax_rate = 0.12;
	}

	//Calculate the tax on the call.
	customer_record.call_tax = customer_record.net_cost * customer_record.tax_rate;

	//Calculate the total cost of the call.
	customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;
}

//Here is my driver to test my program
int main()
{
	call_record customer_record;

	ifstream in;    //declaring an input file stream
	ofstream out;
	in.open("call_data.txt");
	out.open("weekly_call_info.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			Input(in, customer_record);
			Process(customer_record);
			Output(out, customer_record);
		}
	}

	in.close();
	out.close();

	return 0;
}
