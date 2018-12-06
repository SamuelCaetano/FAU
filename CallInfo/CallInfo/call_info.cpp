/*
Samuel Caetano	        Total Points:  20
Due Date:  5/25/2018
Due Time: 11:59pm
Course:  C0P3014
Assignment:  Assignment 2
Professor: Dr. Lofton Bullard

Description: A program that calculates the net cost of a call (net_cost), the
tax on a call (call_tax) and the total cost of that call (total_cost). Displays the calls Info. Uses three functions, input, output, and process.
*/
#include <iostream> //standard library for i/o
#include <iomanip> //for precision setting to round to the nearest hundredth
#include <string>

using namespace std;

//Function Prototypes: Input, Output, and Process
void Input(string & cell_number, int & relays, int & call_length);
void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call);
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call);

double tax_rate;

//Function Implementations will go here

///*************************************************************************************
//Name:  Input
//Precondition: The variables cell_number, relays, call_length have not been initialized.
//Postcondition: The variables cell_number, relays, call_length have been initalized and have been set to their values by the user.
//Description: Get input (values of cell_number, relays, and call_length) from the user.

void Input(string & cell_number, int & relays, int & call_length)
{
	//Gets user input.
	cout << "Enter the phone number: " << endl;
	cin >> cell_number;
	cout << "Enter the number of relays: " << endl;
	cin >> relays;
	cout << "Enter the call length in minutes: " << endl;
	cin >> call_length;
}

///*************************************************************************************
//Name:  Output
//Precondition: The variables cell_number, relays, call_length have been initialized and set to constants and net_cost, call_tax, and total_cost_of_call have their constant values initialized as well.
//Postcondition: cout precision has been set and output has been displayed to the screen.
//Description:  Sets the format of cout, and outputs info to the screen.
//*************************************************************************************

void Output(const string cell_number, const int relays, const int call_length, const double & net_cost, const double & call_tax, const double & total_cost_of_call)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/

	cout << "Cell Phone Number | Relays | Minutes | Net Cost | Tax Rate | Call Tax | Total Call Cost" << endl;
	cout << cell_number << "\t" << relays << "\t" << call_length << "\t" << net_cost << "\t" << tax_rate << "\t" << call_tax << "\t" << total_cost_of_call << endl;
}

///*************************************************************************************
//Name:  Process
//Precondition: The variables relays, call_length have been initialized and set to constants, net_cost, call_tax, and total_cost_of_call are not initialized
//Postcondition: All caculations have been made in order to be passed to the output.
//Description: To determine the tax_rate and perform all calculations.
//*************************************************************************************

//Note: there are 3 input parameter and 3 output parameters
void Process(const int relays, const int call_length, double & net_cost, double & call_tax, double & total_cost_of_call)
{
	/*Step 1: put your code here to determine the net_cost using the formula: relays / 50.0 * .40 * call_length;

	Step 2: put your if-else statement here to determine the tax rate.
	condition 1 if relays <= 1  && relays <= 5 then  tax_rate is .01 and call_tax = net_cost * tax_rate
	condiion  2 if relays >=6 && relays <=1 then tax_rate is .03 and call_tax = net_cost * tax
	and so forth

	Step 3:put your code here to determine the total_cost using the formula: total_cost = net_cost + call_tax;

	*/

	//Calculate the net cost of a call.
	net_cost = (relays / 50.00 * 0.40 * call_length);

	if (0 <= relays && relays <= 5) {
		tax_rate = 0.01;
	}
	else if (6 <= relays && relays <= 11) {
		tax_rate = 0.03;
	}
	else if (12 <= relays && relays <= 20) {
		tax_rate = 0.05;
	}
	else if (21 <= relays && relays <= 50) {
		tax_rate = 0.08;
	}
	else {
		tax_rate = 0.12;
	}

	//Calculate the tax on the call.
	call_tax = net_cost * tax_rate;

	//Calculate the total cost of the call.
	total_cost_of_call = net_cost + call_tax;
}

//Here is my driver to test my program
int main()
{
	string user_response = "y";
	string cell_number;
	int relays;
	int  call_length;
	double net_cost;
	double call_tax;
	double total_cost_of_call;

	while (user_response == "y" || user_response == "Y")
	{
		Input(cell_number, relays, call_length);
		Process(relays, call_length, net_cost, call_tax, total_cost_of_call);
		Output(cell_number, relays, call_length, net_cost, call_tax, total_cost_of_call);

		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
	}

	return 0;
}
