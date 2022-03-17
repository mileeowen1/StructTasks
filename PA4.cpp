/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: February 26, 2020
Programming Assignment: PA4
Description: Create a program that solves two tasks: 1) get a string from the user, compute and display the letter histogram, the letter with the maximum number of occurrences, the number of occurrences of the letter with the maximum number of occurrences, and the frequency of the letter with the maximum number of occurrences; 2) read in information about a driver from a file, display the package information you read in, compute and display the ID of the heaviest package, weight of the heaviest package, and verage weight of all the packages.
Notes: Function definition cpp file
*/
#include "PA4.h"
////////////////////////////////////
// TASK 1
////////////////////////////////////
/*************************************************************
 * Function: runTask1()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function runs task 1.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that answer and execute
 *				task 1.
*************************************************************/
void runTask1() {
	string userString = "";
	char letter;
	int count = 0;
	double frequency = 0.0;
	
	// create an array of structs
	LetterOccurrence myLetterOccurs[123];
	
	// loop to keep getting input from the user until they enter quit
	do {
		cout << "Please type in a string: ";
		getline(cin, userString);
		// reads input and processes it, computes, and displays information
		if (userString != "quit") {
			processString(userString, myLetterOccurs);
			computeMaximumOccurences(myLetterOccurs, &letter, &count, &frequency);
			displayHistogram(myLetterOccurs,count);
			cout << "The letter with the maximum number of occurrences: " << letter << endl;
			cout << "The number of occurrences of the letter with the maximum number of occurrences: " << count << endl;
			cout << "The frequency of the letter with the maximum number of occurrences: " << frequency << endl << endl;
		}
		else {
			cout << "Quitting Task 1..." << endl << endl;
		}	
	} while (userString != "quit");
}
/*************************************************************
 * Function: processString()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function takes the string input and
 *				updates the values in the struct.
 * Input parameters: The string and struct array.
 * Returns: nothing
 * Pre: The string and struct array had to have been scanned 
 *				in by the user.
 * Post: The content of the string is broken up and values are
 *				stored/updated in its corresponding place in
 *				array.
 *************************************************************/
void processString(const string s, LetterOccurrence letters[]) {
	double totalCounter = 0.0;
	char c;
	
	// zeroes out the values in the struct array
	for (int i = 0; i < 123; i++) {
		letters[i].count = 0;
		letters[i].frequency = 0.0;
	}
	
	// updates the values for the count
	for (int j = 0; j < s.length(); j++) {
		c = s.at(j);
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
			letters[c].count++;
			totalCounter++;
		}
	}
	
	// updates the values for the frequency
	for (int k = 0; k < 123; k++) {
		if (k >= 'A' && k <= 'Z' || k >= 'a' && k <= 'z') {
			letters[k].frequency = letters[k].count / totalCounter;
		}
	}
}
/*************************************************************
 * Function: computeMaximumOccurences()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function uses a for loop to check the 
 *				indices of the array to find the max letter
 *				count.
 * Input parameters: The struct array, pointer to the max
 *				letter char, count int, and freq double (o.p.).
 * Returns: nothing
 * Pre: The struct array, pointer to the max letter char, count
 *				int, and freq double (o.p.) had to have been
 *            	scanned in by the user.
 * Post: The values/info for the most occurring letter is
 *				assigned to the corresponding variables by
 *				output parameters.
 *************************************************************/
void computeMaximumOccurences(const LetterOccurrence letters[], char * c, int * count, double * freq) {
	int i, max = 'A';
    
    // loop that updates the index for the max letter occurence
    for (i = 'A'; i < 'z'; i++) {
        if (letters[max].count < letters[i].count) {
            max = i;
        }
    }
    
    // assigns the value to corresponding variables
    *c = max;
    *count = letters[max].count;
    *freq = letters[max].frequency;
}
/*************************************************************
 * Function: displayHistogram()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function displays the letter histogram
 *				for the string input.
 * Input parameters: The struct array and the max number.
 * Returns: nothing
 * Pre: The struct array and the max number had to have been
 *            	scanned in by the user.
 * Post: The letter histogram is displayed to the terminal.
 *************************************************************/
void displayHistogram(const LetterOccurrence letters[], int maxNum) {

	// outputs an * for how many times the letter is in the string else outputs a space
	for (int i = maxNum; i > 0; i--) {
		for (int j = 0; j < 123; j++) {
			if (j >= 'A' && j <= 'Z' || j >= 'a' && j <= 'z') {
				if (letters[j].count >= i) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" << endl;
}
////////////////////////////////////
// TASK 2
////////////////////////////////////
/*************************************************************
 * Function: runTask2()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function runs task 2.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that answer and execute
 *				task 2.
*************************************************************/
void runTask2(string fileName) {
	ifstream inputFile;
	string driver = "";
	int numPacks = 0;
	int heavyID = 0;
	double heavyWeight = 0;
	double averageWeight = 0.0;
	Package * driverPackages = NULL;
	
	// open file
	openinputFile(inputFile, fileName);
	
	// assign declared struct to function call
	driverPackages = loadPackages(inputFile, &driver, &numPacks);
	
	// display the package information
	cout << endl << "Number of packages on " << driver << "'s truck: " << numPacks << endl << endl;
	cout << "Package Information" << endl << "___________________" << endl << endl;
	for (int i = 0; i < numPacks; i++) {
		cout << "Package ID: " << driverPackages[i].id << endl;
		cout << "Package Weight: " << driverPackages[i].weight << endl;
		cout << "Package Width: " << driverPackages[i].width << endl;
		cout << "Package Length: " << driverPackages[i].length << endl;
		cout << "Package Height: " << driverPackages[i].height << endl << endl;
	}
	
	// compute and display the package stats
	computePackageStats(driverPackages, numPacks, &heavyID, &heavyWeight, &averageWeight);
	cout << "Package Stats" << endl << "_____________" << endl << endl;
	cout << "ID of heaviest package: " << heavyID << endl;
	cout << "Weight of heaviest package: " << heavyWeight << endl;
	cout << "Average weight of packages on truck: " << averageWeight << endl;
	
	// properly free dynamically allocated memory
	delete [] driverPackages;
	driverPackages = nullptr;
}
 /*************************************************************
 * Function: openinputFile()
 * Date Created: 01/21/20
 * Date Last Modified: 01/21/20          
 * Description: This function opens file for reading in.
 * Input parameters: The ifstream file must be pass by 
 *				reference and the name of the file.
 * Returns: nothing
 * Pre: The ifstream file must be pass by 
 *				reference and the name of the file had to have 
 *            	been scanned in by the user.
 * Post: The file is opened or not and a message is displayed.
 *************************************************************/
void openinputFile(ifstream& inputFile, string iname) {
	
	// opens file for reading & outputs message
	inputFile.open(iname);
	if (inputFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
/*************************************************************
 * Function: loadPackages()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function reads in the values from the file
 *				and generates an array of structs.
 * Input parameters: The ifstream file must be pass by 
 *				reference, a pointer to the string for driver
 *				name, and pointer to int for number or packages.
 * Returns: the created array
 * Pre: The ifstream file must be pass by reference and the
 *				size of the array had to have been scanned
 *            	in by the user.
 * Post: The struct array is returned by pointer notation.
 *************************************************************/
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
	int packageID = 0, packageWidth = 0, packageLength = 0, packageHeight = 0;
	double packageWeight = 0.0;
	string line;
	int counter = 0;
	Package * packages = NULL;
	
	// read through file to get number to packages
	getline(inFile, *driverName);
	while (!inFile.eof()) {
		getline(inFile, line);
		if (inFile.good()) {
			counter++;
		}
	}
	*numPackages = counter / 6;
	inFile.clear();
	inFile.seekg(0, ios::beg);
	
	// dynamically allocate array
	packages = new Package[*numPackages];
	
	// read in information and assign it to the struct array
	getline(inFile, *driverName);
	for (int i = 0; i < *numPackages; i++) {
		inFile >> packageID;
		packages[i].id = packageID;
		inFile >> packageWeight;
		packages[i].weight = packageWeight;
		inFile >> packageWidth;
		packages[i].width = packageWidth;
		inFile >> packageLength;
		packages[i].length = packageLength;
		inFile >> packageHeight;
		packages[i].height = packageHeight;
	}
	return packages;
}
/*************************************************************
 * Function: computePackageStats()
 * Date Created: 02/24/20
 * Date Last Modified: 02/26/20          
 * Description: This function uses a for loop to check the 
 *				indices of the array to find the heaviest
 *				package.
 * Input parameters: The const struct array, const number of
 *				packages, pointer to heaviestId int, 
 *				heaviestWeight double, and avgWeight double
 *				(by output parameters).
 * Returns: nothing
 * Pre: The const struct array, const number of packages,
 *				pointer to heaviestId int, heaviestWeight
 *				double, and avgWeight double (by output
 *				parameters) had to have been
 *            	scanned in by the user.
 * Post: The values/info for the most heaviest package (id,
 *				weight, and average of all the packages weight)
 *				is assigned to the corresponding variables by
 *				output parameters.
 *************************************************************/
void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
	double totalWeight = 0.0;
	int heaviest = 0;
    
    // loop that updates the index for the heaviest package and gets the total weight
    for (int i = 0; i < numPackages; i++) {
        if (packages[heaviest].weight < packages[i].weight) {
            heaviest = i;
        }
        totalWeight += packages[i].weight;
    }
    
    // assigns the value to corresponding variables
	*heaviestId = packages[heaviest].id;
	*heaviestWeight = packages[heaviest].weight;
	*avgWeight = totalWeight / numPackages;
}
