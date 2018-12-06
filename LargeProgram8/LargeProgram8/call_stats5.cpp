/*
Samuel Caetano	        Total Points:  10
Due Date:  7/12/2018
Due Time: 11:59pm
Course:  C0P3014
Assignment:  Assignment 8
Professor: Dr. Lofton Bullard

Description: Extension of assignment 3 that utilizes Dynamic Arrays and takes advantage of the "new" and "delete" keywords.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class call_record
{
public:
	string firstname;
	string lastname;
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};


void Initialize(call_record *& call_DB, int & count, int & size);
bool Is_empty(const int count); //inline implementation
bool Is_full(const int count, int size);//inline implementation
int Search(const call_record *call_DB, const int count, const string key);//returns location if item in listl; otherwise return -1
void Add(call_record * &call_DB, int & count, int & size, const string key); //adds item inorder to the list
void Remove(call_record *call_DB, int & count, const string key); //removes an item from the list
void Double_size(call_record * &call_DB, int & count, int & size);
void Process(call_record *call_DB, const int & count);
void Print(const call_record *call_DB, int & count); //prints all the elements in the list to the screen
void Destroy_call_DB(call_record * &call_DB); //de-allocates all memory allocate to call_DB by operator new.



/************************************************************************************************************************************/
//Name: Initialize
//Precondition: A dynamic call_record array has been created and a call recod has been passed to this function along with the count and size.
//Postcondition: The data file has been read and the values of cell number, relay, and call length have been set to the call_DB.
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record, 
//call_DB. If the count because equal to the size the function double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
void Initialize(call_record * & call_DB, int & count, int & size)
{
	ifstream in;
	in.open("callstats_data.txt");
	count = 0;

	if (in.fail())
	{
		cout << "The file has not been found or was not able to be opened!" << endl;
		exit(1);
	}

	while (!in.eof()) {
		if (!Is_full(count, size)) {
			Double_size(call_DB, count, size);
		}
		in >> call_DB[count].firstname;
		in >> call_DB[count].lastname;
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;

		count++;
	}

	in.close();
}

/***********************************************************************************************************************************/
//Name: Is_empty
//Precondition: The integer count has been assigned a value and gets checked to see if it is 0 (empty).
//Postcondition: The integer count has been used to check if the call_DB is empty and returns true if it is empty, and false if not.
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/

//ONE WAY TO MAKE A FUNCTION INLINE IS TO PUT THE KEYWORD "inline" in from of the 
//FUNCTION HEADER AS SHOWN BELOW:
inline bool Is_empty(const int count)
{
	if (count == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

//ONE WAY TO MAKE A FUNCTION INLINE IS TO PUT THE KEYWORD "inline" in from of the 
//FUNCTION HEADER AS SHOWN BELOW:
/**********************************************************************************************************************************/
//Name: Is_full 
//Precondition: Integer's count and size have been initialized and get checked to see if the count has reached its capacity (size).
//Postcondition: The record call_DB has been evaluated to see if it is full or not baseed on the count and how it relates to size.
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
inline bool Is_full(const int count, int size)
{
	if (count == size) {
		return 0;
	}
	else {
		return -1;
	}
}

/**********************************************************************************************************************************/
//Name: Search
//Precondition: call_DB has been initialized, count has been initialized, and a key has been specified to be searched for.
//Postcondition: Locates the key (cell number in the call_DB call_record array and returns it if it exists).
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int Search(const call_record *call_DB, const int count, const string key)
{
	int x;
	for (x = 0; x < count; x++) {
		if (call_DB[x].cell_number == key) {
			return x; // returns the index it was found.
		}
		else {
			return -1;
		}
	}
	return 0;
}

/*********************************************************************************************************************************/
//Name: Add
//Precondition: call_DB, count, size have been initialized and a key has been provided to add.
//Postcondition: Manually adds a key to the array of records call_DB based on user input.
//Decription: add key to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void Add(call_record * &call_DB, int & count, int & size, const string key)
{
	int i = count;
	if (Is_full(count, size)) {
		Double_size(call_DB, count, size);
		call_DB[i].cell_number = key; //Sets a certain index of cell_number to be a key.

		cout << "Please Enter the First Name:" << '\n';
		cin >> call_DB[i].firstname;

		cout << "Please Enter the Last Name:" << '\n';
		cin >> call_DB[i].lastname;

		cout << "Please Enter the number of Relays:" << '\n';
		cin >> call_DB[i].relays;

		cout << "Please Enter the Call Length:" << '\n';
		cin >> call_DB[i].call_length;

		count++;
	}
	return;
}

/********************************************************************************************************************************/
//Name: Remove
//Precondition: call_DB and count have been initialized and a key has been provided to be searched for and removed.
//Postcondition: Searches the call_DB call record dynamic array and removes that instance where the key exists (if it exists).
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void Remove(call_record *call_DB, int & count, const string key)
{
	if (Is_empty(count) == 0) {
		return; //returns if the array is empty (Nothing to remove).
	}
	int location = Search(call_DB, count, key);

	if (location == -1) {
		return;
	}
	else if (location != -1) {
		int i;
		for (int i = location; i < count - 1; i++) {
			call_DB[i] = call_DB[i + 1];
		}
		count--;
	}
}

/******************************************************************************************************************************/
//Name: Double_Size
//Precondition: call_DB, count, and size have been initialized.
//Postcondition: Doubles the size by multiplying it by two, and creates a temporary call_record with the greater size that stores all of the values of the old call_DB.
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void Double_size(call_record * &call_DB, int & count, int & size)
{
	size *= 2; //Double the size of the array by multiplying it by 2.

	call_record * temp_call_record = new call_record[size]; //Creates a temporary call record with the saem size to store the previous values in order for them to be amended to the new array.
	
	int x;
	for (x = 0; x < count; x++) {
		temp_call_record[x] = call_DB[x];
	}

	cout << "The new size is now: " << size << '\n';
	delete [] call_DB; //Deletees the call_DB Dynamic Array using the delete [] keyword.
	call_DB = temp_call_record; //Sets the new array to be equal to the old array for all of the previously existing array indexies.
}


/******************************************************************************************************************************/
//Name: Process
//Precondition: call_DB and count have both been initialized.
//Postcondition: The tax rate has been determined for each call_DB record, and the calculations for net_cost, call_tax, and total_cost have been calculated for each one.
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void Process(call_record *call_DB, const int & count)
{
	//Calculate the net_cost, call_tax, and total_cost of each of the records in the call_DB.
	for (int x = 0; x < count; x++) {
		call_DB[x].net_cost = call_DB[x].relays / 50 * 0.40 * call_DB[x].call_length;

		call_DB[x].call_tax = call_DB[x].net_cost * call_DB[x].tax_rate;
		call_DB[x].total_cost = call_DB[x].net_cost + call_DB[x].call_tax;

		//Determine tax_rate based on the relay count.
		if (call_DB[x].relays <= 0 && call_DB[x].relays <= 5) {
			call_DB[x].tax_rate = 0.01;
		}
		else if (call_DB[x].relays <= 6 && call_DB[x].relays <= 11) {
			call_DB[x].tax_rate = 0.03;
		}
		else if (call_DB[x].relays <= 12 && call_DB[x].relays <= 20) {
			call_DB[x].tax_rate = 0.05;
		}
		else if (call_DB[x].relays <= 21 && call_DB[x].relays <= 50) {
			call_DB[x].tax_rate = 0.08;
		}
		else {
			call_DB[x].tax_rate = 0.12;
		}
	}
}


/****************************************************************************************************************************/
//Name: Print
//Precondition: call_DB and count have been inintialized.
//Postcondition: Runs through each record in the call_DB dynamic array and prints out the calculated call stats for each.
//Decription: prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void Print(const call_record *call_DB, int & count)
{
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	int x;
	for (x = 0; x < count; x++) {
		cout << "First Name: " << call_DB[x].firstname << "\t" << endl;
		cout << "Last Name: " << call_DB[x].lastname << "\t" << endl;
		cout << "Phone Number: " << call_DB[x].cell_number << "\t" << endl;
		cout << "Relays: " << call_DB[x].relays << "\t" << endl;
		cout << "Minutes: " << call_DB[x].call_length << "\t" << endl;
		cout << "Net Cost: " << call_DB[x].net_cost << "\t" << endl;
		cout << "Tax Rate: " << call_DB[x].tax_rate << "\t" << endl;
		cout << "Call Tax: " << call_DB[x].call_tax << "\t" << endl;
		cout << "Total: " << call_DB[x].total_cost << "\t" << endl << endl;
	}
}

/****************************************************************************************************************************/
//Name: Destroy_call_DB
//Precondition: A call_record call_DB exists and has been initialized
//Postcondition: call_DB has been deleted.
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void Destroy_call_DB(call_record * &call_DB)
{
	delete[] call_DB;
}



int main()
{
	int size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	int count = 0;
	call_record *call_DB = new call_record[size];
	string key;

	//Test each function:
	Initialize(call_DB, count, size);
	Is_empty(count);
	Is_full(count, size);
	Search(call_DB, count, key);
	Add(call_DB, count, size, key);
	Remove(call_DB, count, key);
	Double_size(call_DB, count, size);
	Process(call_DB, count);
	Print(call_DB, count);
	Destroy_call_DB(call_DB);

	return 0;
}


