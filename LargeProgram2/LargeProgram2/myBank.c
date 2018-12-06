//Samuel Caetano
//COP2220 Introduction to C
//03/26/2018
//myBank: To compile, build, and execute an interactive program broken up into user defined functions using both pass by reference and pass by copy parameters, simple loops and conditions.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <ctype.h>
#define MAXCREDIT -4500

// Displays the list of options available
//prompts for the user’s selection and sets the value of the selection
void RunBankChoices(int *choice);

//greets the user
void Greeting();

//Takes one double argument and one character argument
//displays the current balance of the account ('C' checking, 'S' savings, 'R' credit)
void AccountBalance(double account, char letter);

//takes reference to all the bank account money values and the menu selection
//Makes the decsion of which trnsaction should be done
void TransactionDecision(int num, double *cPtr, double *sPtr, double *rPtr);

//takes a reference to the selected account balance
//gets the added amount from the user and adds it to the account
void DepositMoney(double *accountPtr);

//takes a reference to the selected account balance
//gets the withdrawal amount from the user
//checks to see if there is enough money available OR enough credit available
//subtracts the money from the account if available
void WithdrawMoney(double *accountPtr, char letter);

int main() {
	int choice;
	double checking = 480.45, savings = 124.62, credit = -2134.78;

	//Greets the user
	Greeting();

	AccountBalance(checking, 'C');
	AccountBalance(savings, 'S');
	AccountBalance(credit, 'R');

	do{
		RunBankChoices(&choice);
		if (choice >= 1 && choice <= 7 || choice == -1) {
			TransactionDecision(choice, &checking, &savings, &credit);
		}
		else {
			printf("\n\nInvalid Choice!\n\n");
		}
	}while (choice != -1);
	
	printf("\n\nGoodbye!\n\n");

	return 1;
}

void Greeting() {
	//Greeting Messages
	printf("Welcome to the Bank of COP 2220\n\n");
	printf("It is a pleasure to be managing your checkin, saving, and credit accounts.\n\n");
}

void RunBankChoices(int *choice) {
	//Menu Options
	printf("\n(1) to DEPOSIT to CHECKING\n");
	printf("(2) to WITHDRAW from CHECKING\n");
	printf("(3) to DEPOSIT to SAVINGS\n");
	printf("(4) to WITHDRAW from SAVINGS\n");
	printf("(5) to DEPOSIT to CREDIT\n");
	printf("(6) to take an ADVANCE from CREDIT\n");
	printf("(7) for all ACCOUNT BALANCES\n");
	printf("\n(-1) to QUIT\n");

	printf("\n\nSelect an option:\n");

	scanf("%d", choice);

	printf("\nYour transaction chosen was: %d\n\n", *choice);
}

void AccountBalance(double account, char letter) {
	switch (toupper(letter)) {
	case 'C':
		printf("The account balance for your Checkings account is: %.2f\n", account);
		break;
	case 'S':
		printf("The account balance for your Savings account is: %.2f\n", account);
		break;
	case 'R':
		printf("The account balance for your Credit account is: %.2f\n", account);
		break;
	}
}

void TransactionDecision(int num, double *cPtr, double *sPtr, double *rPtr) {
	switch (num) {
	case 1:
		//Deposit Money to Checking
		DepositMoney(cPtr);
		AccountBalance(*cPtr, 'C');
	break;
	case 2:
		//Withdraw Money from Checking
		WithdrawMoney(cPtr, 'C');
		AccountBalance(*cPtr, 'C');
		break;
	case 3:
		//Deposit Money to Savings
		DepositMoney(sPtr);
		AccountBalance(*sPtr, 'S');
		break;
	case 4:
		//Withdraw Money from Savings
		WithdrawMoney(sPtr, 'S');
		AccountBalance(*sPtr, 'S');
		break;
	case 5:
		//Deposit Money to Credit
		DepositMoney(rPtr);
		AccountBalance(*rPtr, 'R');
		break;
	case 6:
		//Withdraw Money from Credit
		WithdrawMoney(rPtr, 'R');
		AccountBalance(*rPtr, 'R');
		break;
	case 7:
		//Display account balances
		AccountBalance(*cPtr, 'C');
		AccountBalance(*sPtr, 'S');
		AccountBalance(*rPtr, 'R');
		break;
	}
}

void DepositMoney(double *accountPtr) {
	double amount;
	printf("Please enter the amount you would like to deposit: \n");
	scanf("%lf", &amount);
	*accountPtr += amount;
}

void WithdrawMoney(double *accountPtr, char letter) {
	double amount;
	printf("Please enter the amount you would like to withdraw: \n");
	scanf("%lf", &amount);

	if (toupper(letter) == 'C' || toupper(letter) == 'S') {
		if ((*accountPtr - amount) >= 0) {
			*accountPtr -= amount;
		}
		else{
			printf("\n\nInsufficient Funds!\n\n");
		}
	}
	else{
		if ((*accountPtr - amount) >= MAXCREDIT) {
			*accountPtr -= amount;
		}
		else {
			printf("\n\nYou have exceeded your credit amount!\n\n");
		}
	}
}