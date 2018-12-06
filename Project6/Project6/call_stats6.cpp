/*
Samuel Caetano	        Total Points : 20
Due Date: 7/26/2018
Due Time: 11:59pm
Course: C0P3014
Assignment: Assignment 9
Professor: Dr.Lofton Bullard

Description: Extension of assignment 5 that utilizes classes. Opens and reads from a file in order to calculate the costs of each call in the file,
able to search and delete elements from an array and display the output.
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

class call_class
{
public:
	call_class();
	~call_class(); //de-allocates all memory allocate to call_DB by operator new.
	bool is_empty() const; //inline implementation
	bool is_full() const;//inline implementation
	int search(const string key) const;//returns location if item in listl; otherwise return -1
	void add(); //adds a call record to call_DB
	void remove(const string key); //removes an item from the list
	void double_size();
	void process();
	void print() const; //prints all the elements in the list to the screen
private:
	int count;
	int size;
	call_record *call_DB;
};




/************************************************************************************************************************************/
//Name: default constructor
//Precondition: A file named callstats_data.txt exists and the variables in call_class have been declared but not initialized.
//Postcondition: The text file is opened in order to read its contents.
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record, 
//call_DB. If the count is equal to the size the function, double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
call_class::call_class()
{
	//Initialize the variables.
	count = 0;
	size = 5;

	//Create a new 'Instance' (object) of the call_record.
	call_DB = new call_record[size];

	//Declare input stream.
	ifstream in;

	//Open file
	in.open("callstats_data.txt");

	if (in.fail()) {
		cout << "Failed to open the file/File does not exist!" << endl;
	}
	else {
		while (!in.eof())
		{
			//Check if it is full
			if (is_full())
			{
				double_size();
			}

			in >> call_DB[count].firstname;
			in >> call_DB[count].lastname;
			in >> call_DB[count].cell_number;
			in >> call_DB[count].relays;
			in >> call_DB[count].call_length;

			count++;
		}

		process();

		//Close file
		in.close();
	}
}

/***********************************************************************************************************************************/
//Name: is_empty
//Precondition: Whether or not call_DB is empty is unknown. 
//Postcondition: Returns true if count is 0 (empty), else returns false.
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/
bool call_class::is_empty() const
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: Whether or not call_DB is empty is unknown.
//Postcondition: Returns true if count is equal to the max size (size), else returns false.
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
bool call_class::is_full() const
{
	if (count == size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: A key has been given to search for its location.
//Postcondition: Returns the location of the key in the array if it is found, else returns -1.
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int call_class::search(const string key) const
{
	for(int x=0; x<count; x++)
	{
		if(key == call_DB[x].cell_number)
		{
			return x;
		}
	}
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: An array exists where a new call_record can be added.
//Postcondition: The new member has been added to the array, thus increasing the count by 1.
//Decription: adds a call_record to call_DB; if call_DB is full, double_size is called to increase the size of call_DB. The user 
//            is prompted to enter the firstname, lastname, cell number, relays and call length. 
/********************************************************************************************************************************/
void call_class::add()
{
	if(is_full())
	{
		double_size();
	}

	int c = count;

	cout << "Enter the first name of the new member: " << endl;
	cin >> call_DB[c].firstname;

	cout << "Enter the last name of the new member: " << endl;
	cin >> call_DB[c].lastname;

	cout << "Enter the phone number of the new member: " << endl;
	cin >> call_DB[c].cell_number;

	cout << "Enter the number of relays: " << endl;
	cin >> call_DB[c].relays;

	cout << "Enter the call length in minutes: " << endl;
	cin >> call_DB[c].call_length;

	count++;

	process();
}

/********************************************************************************************************************************/
//Name: remove
//Precondition: The key being searched for is currently unknown if it exists.
//Postcondition: If the search key has been found, then its record has been removed from call_DB.
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void call_class::remove(const string key)
{
	if(is_empty())
	{
		return;
	}
	else
	{
		while (search(key) != -1) {
			int searchkey = search(key);

			for (int currentkey = searchkey; currentkey < count; currentkey++)
			{
				int shiftedkey = currentkey + 1;

				call_DB[currentkey].firstname = call_DB[shiftedkey].firstname;
				call_DB[currentkey].lastname = call_DB[shiftedkey].lastname;
				call_DB[currentkey].cell_number = call_DB[shiftedkey].cell_number;
				call_DB[currentkey].relays = call_DB[shiftedkey].relays;
				call_DB[currentkey].call_length = call_DB[shiftedkey].call_length;
				call_DB[currentkey].net_cost = call_DB[shiftedkey].net_cost;
				call_DB[currentkey].tax_rate = call_DB[shiftedkey].tax_rate;
				call_DB[currentkey].call_tax = call_DB[shiftedkey].call_tax;
				call_DB[currentkey].total_cost = call_DB[shiftedkey].total_cost;
			}
			count--;
		}
	}
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: The size of the array has possibly reached its max size.
//Postcondition: The capacity of the array has been doubled in size.
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void call_class::double_size()
{
	size *= 2;
	call_record *temp = new call_record[size];

	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;
	call_DB = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: Net cost, tax rate, call tax, and total cost have not been calculated for each call record.
//Postcondition: Net cost, tax rate, call tax, and total cost have been calculated for each call record.
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void call_class::process()
{
	for (int x=0; x<count; x++)
	{
		call_DB[x].net_cost = (call_DB[x].relays / (50.0 / 0.40))*call_DB[x].call_length;

		if (call_DB[x].relays >= 0 && call_DB[x].relays <= 5)
		{
			call_DB[x].tax_rate = 0.01;
		}
		else if (call_DB[x].relays >= 6 && call_DB[x].relays <= 11)
		{
			call_DB[x].tax_rate = 0.03;
		}
		else if (call_DB[x].relays >= 12 && call_DB[x].relays <= 20)
		{
			call_DB[x].tax_rate = 0.05;
		}
		else if (call_DB[x].relays >= 21 && call_DB[x].relays <= 50)
		{
			call_DB[x].tax_rate = 0.08;
		}
		else
		{
			call_DB[x].tax_rate = 0.12;
		}
		call_DB[x].call_tax = (call_DB[x].net_cost*call_DB[x].tax_rate);
		call_DB[x].total_cost = call_DB[x].net_cost + call_DB[x].call_tax;
	}
}


/****************************************************************************************************************************/
//Name: print
//Precondition: Output of the calculations has been prepared to be written to the screen.
//Postcondition: Outputs every call record's resultant calculations onto the screen.
//Decription: prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void call_class::print() const
{
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	for (int i = 0; i<count; i++)
	{
		cout << call_DB[i].firstname << "  " << call_DB[i].lastname << "  " << call_DB[i].relays << "  " << call_DB[i].cell_number << "  " << call_DB[i].call_length << " " << call_DB[i].net_cost << " " << call_DB[i].tax_rate << " " << call_DB[i].call_tax << " " << call_DB[i].total_cost << endl;
	}
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: call_DB possibly has allocated memory.
//Postcondition: call_DB's allocated memory has been de-allocated.
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
call_class::~call_class()
{
	cout << "De-Allocating memory in call_DB!" << endl;
	delete[]call_DB;
}


//driver to test the functionality of your class.
int main()
{
	call_class MyClass;

	MyClass.print();


	return 0;
}