/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: February 26, 2020
Programming Assignment: PA4
Description: Create a program that solves two tasks: 1) get a string from the user, compute and display the letter histogram, the letter with the maximum number of occurrences, the number of occurrences of the letter with the maximum number of occurrences, and the frequency of the letter with the maximum number of occurrences; 2) read in information about a driver from a file, display the package information you read in, compute and display the ID of the heaviest package, weight of the heaviest package, and average weight of all the packages.
Notes: Main function cpp file
*/
#include "PA4.h"
// TODO: add parameters to main() for command line args
int main(int argc, char * argv[]) {
	// run task 1
	runTask1();
	
	// run task 2
	if (argc == 2) {
		runTask2(argv[1]);
	}
	return 0;
}
