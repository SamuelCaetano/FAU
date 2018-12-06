/************************************************************************************************************************

Name: Samuel Caetano               Z#: Z23423426
Course: COP3014
Professor: Dr. Lofton Bullard
Due Date: 6/28/2018             Due Time: 11:59
Total Points: 20
Assignment 6: call_stats4.cpp

Description: Extension of assignment 4, A program that calculates the net cost of a call (net_cost), the
tax on a call (call_tax) and the total cost of that call (total_cost). Outputs the calls into a DB array.

Note:  In this assignment you will

1. Read the contents of a datafile one record at a time into an array of
records;
2. Process the data stored in an array of records;
3. Print the records stored in an array to a datafile using an ofstream
(output file stream) object;
4. Use an array of record records;
6. Use an ifstream object;
7. Use an ofstream object;
*************************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream> 
#include <iomanip>
using namespace std;

const int SIZE = 200; //the capacity of the array which is the total amount
					  //of memory allocated to the array.  The is a static
					  //array, therefore the compiler will manage its memory,
					  //allocate and de-allocate the memory.


					  //sample record (class with no functionality)
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


//function prototype -- allows compiler to setup for function calls
void Input(call_record call_DB[], int & count);
void Output(const call_record call_DB[], const int & count);
void Process(call_record call_DB[], const int & count);

///*************************************************************************************
//Name:  Input
//Precondition: The variables cell_number, relays, call_length of each array index have not been initialized in a call record.
//Postcondition: The variables cell_number, relays, call_length have been initalized and have been set the values specified in the file datastream line in a call record at the specified count index of the call_DB array.

//Description: Get input (values of cell_number, relays, and call_length) from a data file and store in call record in the call_DB array.
//*************************************************************************************

void Input(call_record call_DB[], int & count)
{
	ifstream in; //input file stream object declaration
	count = 0;  //remember to initialize count before the first come

	in.open("call_data.txt"); //bind the file "call_data.txt" to the input
							  //file stream "in".

	if (in.fail()) //if file not found print message and exit program
	{
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}

	//Remember to use a while loop when reading from a file because
	//you do not know how many records you will be reading. 
	while (!in.eof())
	{
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;

		count++;
	}


	in.close();
}

///*************************************************************************************
///*************************************************************************************
//Name:  Output
//Precondition: The variables out (ofstream) cell_number, relays, call_length have been initialized and set to constants and net_cost, call_tax, and total_cost_of_call have their constant values initialized as well based on what was retrieved from the file afer being processed.
//Postcondition: cout precision has been set and output from each customer record in the call_DB has been printed to the output file "weekly4_call_info.txt"

//Description:  Sets the format of cout, and outputs from customer_record to the weekly_call_info text file.
//*************************************************************************************

void Output(const call_record call_DB[], const int & count)
{
	ofstream out; //declare the output file stream "out".

	out.open("weekly6_call_info.txt");//bind the file "weekly4_call_info.txt" to
									  //to the output file stream "out".

									  //Use the magic formula to format your output.  Remember that you
									  //are not using "cout".  In this example we are using "out".
									  //eg... out.setf(showpoint);

	if (out.fail()) // if problem opening file, print message and exit program
	{
		cout << "Output file did not open correctly" << endl;
		exit(1);
	}

	//Set showpoint and precision
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	// use a "for" loop here to
	// print the output to file
	int i;
	for (i = 0; i < count; i++) {
		out << call_DB[i].cell_number << "\t" << call_DB[i].relays << "\t" << call_DB[i].call_length << "\t" << call_DB[i].net_cost << "\t" << call_DB[i].tax_rate << "\t" << call_DB[i].call_tax << "\t" << call_DB[i].total_cost << endl;
	}

	out.close();
}

///*************************************************************************************
//Name:  Process
//Precondition: The variables relays, call_length have been initialized and set to constants, net_cost, call_tax, and total_cost_of_call are not initialized in the customer_record but will be calculated for each of the records in the array.
//Postcondition: All caculations have been made in order to be passed to each customer_record in the array which will then be used for output.

//Description: To determine the tax_rate and perform all calculations for each of the call_records in the array call_DB.
//*************************************************************************************

void Process(call_record call_DB[], const int & count)
{
	int i; // index for the "for" loop..

		   //Remember to use a "for" loop when you know how many items
		   //you will be processing.  Use the dot operator when you are
		   //accessing fields in a record.  For example, when we need
		   //to access the relay field in the first record in the array use 
		   //call_DB[0].relay   .

	for (i = 0; i < count; i++)
	{
		call_DB[i].net_cost = call_DB[i].relays / 50.0 * .40 * call_DB[i].call_length;

		if (0 <= call_DB[i].relays && call_DB[i].relays <= 5) {
			call_DB[i].tax_rate = 0.01;
		}
		else if (6 <= call_DB[i].relays && call_DB[i].relays <= 11) {
			call_DB[i].tax_rate = 0.03;
		}
		else if (12 <= call_DB[i].relays && call_DB[i].relays <= 20) {
			call_DB[i].tax_rate = 0.05;
		}
		else if (21 <= call_DB[i].relays && call_DB[i].relays <= 50) {
			call_DB[i].tax_rate = 0.08;
		}
		else {
			call_DB[i].tax_rate = 0.12;
		}

		//Calculate call tax
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;

		//Calculate total cost
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
	}

}

int main()
{

	call_record call_DB[SIZE];
	int count = 0;

	Input(call_DB, count); //this function will read all the input stored in a file
						   //into the array call_DB
	Process(call_DB, count); //this function will process each call_record stored
							 //in the array call_DB.

	Output(call_DB, count);//this function prints all the fields
						   //of every record stored in the array call_DB to an output file.  
						   //Each record with be print on a separate line in the output file.

	return 0;
}