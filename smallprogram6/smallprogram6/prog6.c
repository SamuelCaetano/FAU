//Samuel Caetano
//COP2220 Introduction to C
//04/02/2018
//prog6, Interactive program using loops, arrays, and input and output file processing.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Reads from numInput.txt.
void readFile(int ary[]);
//Prints-Displays all integers in the array.
void printIntegers(int ary[]);
//Sums up all numbers in the array and returns it.
int addUp(int nums[]);
//Locates the smallest number in the array and returns it.
int locateSmallest(int nums[]);

int main() {
	int ary[12];
	//Reads from the file
	readFile(ary);
	//Prints all integers in the array
	printIntegers(ary);

	int sum = addUp(ary);
	int smallest = locateSmallest(ary);

	printf("Sum is: %d\n", sum);
	printf("Smallest is: %d\n", smallest);

	//Write smallest integer to the file.
	FILE* fPtr;
	fPtr = fopen("resOut.txt", "w");
	fprintf(fPtr, "%d", smallest);

	//Closes file after done being used.
	fclose(fPtr);

	return 0;
}

//Reads from the file and stores integers in the array.
void readFile(int ary[]) {
	FILE* fPtr;
	fPtr = fopen("numInput.txt", "r");
	if (!fPtr) {
		printf("No file found!");
	}
	else {
		for (int x = 0; x < 12; x++) {
			fscanf(fPtr, "%d", &ary[x]);
		}
	}
	fclose(fPtr);
}

//Prints out all the integers in the array.
void printIntegers(int ary[]) {
	for (int x = 0; x < 12; x++) {
		printf("%d\n", ary[x]);
	}
}

//Sums all the integers in the array.
int addUp(int num[]) {
	int sum = 0;
	for (int x = 0; x < 12; x++) {
		sum += num[x];
	}
	return sum;
}

//Locates the smallest integer in the array.
int locateSmallest(int num[]) {
	int smallest = num[0];
	for (int x = 1; x < 12; x++) {
		if (smallest > num[x]) {
			smallest = num[x];
		}
	}
	return smallest;
}