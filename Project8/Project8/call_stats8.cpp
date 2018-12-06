/*
Samuel Caetano	        Total Points : 20		Z#: Z23423426
Due Date: 8/2/2018
Due Time: 11:59pm
Course: C0P3014
Assignment 11: call_stats8.cpp
Professor: Dr.Lofton Bullard

Description: an extension of Unit 10 Programming Assignment. You will modify your implementation of “call_class”. The class will still manage a dynamic array of call records. Opens and reads from a file
order to calculate the costs of each call in the file,
able to search and delete elements from an array and display the output and output to a file.
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
	call_class & operator-(const string key); //removes an item from the list
	void double_size();
	void process();
	friend ostream & operator<<(ostream & out_to_file, call_class & Org); //prints all the elements in the 
																		  //list to the screen.
private:
	int count;
	int size;
	call_record *call_DB;
};




/************************************************************************************************************************************/
//Name: default constructor
//Precondition: The file has not been opened.
//Postcondition: The text file has been opened and its contents have been read into the dynamic array.
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record, 
//call_DB. If the count is equal to the size the function, double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
call_class::call_class()
{
	count = 0;
	size = 5;

	call_DB = new call_record[size];

	ifstream in;

	in.open("callstats_data.txt");

	while (!in.eof())
	{
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

	in.close();
}

/***********************************************************************************************************************************/
//Name: is_empty
//Precondition: Whether or not the dynamic array is empty is unknown.
//Postcondition: Returns true if call_DB is empty, false if full.
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/
bool call_class::is_empty() const
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: Whether or not the dynamic array is full is unknown.
//Postcondition: Returns true if the call_DB is full, false if empty.
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
bool call_class::is_full() const
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: A key has been provided but its loccation is unkown.
//Postcondition: If the location of the key is found, return that index, otherwize -1 is returned.
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int call_class::search(const string key) const
{
	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].cell_number == key)
		{
			return i;
		}
	}
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: The array is as provided.
//Postcondition: A new member has been added to the array, and the array count has been increased by 1.
//Decription: adds the informaton for a call record to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void call_class::add()
{
	if (is_full())
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
//Name: operator-
//Precondition: Array is provided as is and a key is passed.
//Postcondition: If the key is found, it is removed form call_DB and the count is decremented.
//Decription: remove key from call_DB if it is there and re-arrange all class elements.
/*******************************************************************************************************************************/
call_class & call_class::operator-(const string key)
{
	if (!is_empty())
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
	return *this;
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: The size of the array could be too small and needs to be doubled.
//Postcondition: The storage capacity of the array has been doubled.
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
	for (int x = 0; x<count; x++)
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
//Name: operator<<
//Precondition: Output of the calculations has been prepared to be written to the screen.
//Postcondition: Outputs every call record's resultant calculations onto the screen and to a file.
//Decription: Overloading operator<< as a friend function. Prints every field of every call_record in call_DB 
//                   formatted to the screen.
/***************************************************************************************************************************/
ostream & operator<<(ostream & out, call_class & Org)
{
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	for (int i = 0; i < Org.count; i++)
	{
		cout << Org.call_DB[i].firstname << "  " << Org.call_DB[i].lastname << "  " << Org.call_DB[i].relays << "  " << Org.call_DB[i].cell_number << "  " << Org.call_DB[i].call_length << " " << Org.call_DB[i].net_cost << " " << Org.call_DB[i].tax_rate << " " << Org.call_DB[i].call_tax << " " << Org.call_DB[i].total_cost << endl;
	}

	ofstream output;

	output.open("stats7_output.txt");

	output.setf(ios::showpoint);
	output.precision(2);
	output.setf(ios::fixed);

	for (int i = 0; i < Org.count; i++)
	{
		output << Org.call_DB[i].firstname << " ";
		output << Org.call_DB[i].lastname << " \t";
		output << Org.call_DB[i].cell_number << "  \t";
		output << Org.call_DB[i].relays << "   \t";
		output << Org.call_DB[i].call_length << "  \t";
		output << Org.call_DB[i].net_cost << "  \t";
		output << Org.call_DB[i].tax_rate << "  \t";
		output << Org.call_DB[i].call_tax << "  \t";
		output << " " << Org.call_DB[i].total_cost << endl;
	}

	output.close();

	return out;
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: call_DB could contain information.
//Postcondition: call_DB no longer contains information.
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
call_class::~call_class()
{
	cout << "Destructor Called!" << endl;
	delete[]call_DB;
}


//driver to test the functionality of your class.
int main()
{
	call_class MyClass;
	cout << MyClass << endl;
	call_class YourClass = MyClass;

	return 0;
}