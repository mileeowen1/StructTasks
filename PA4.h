#ifndef PA4_H
#define PA4_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: February 26, 2020
Programming Assignment: PA4
Description: Create a program that solves two tasks: 1) get a string from the user, compute and display the letter histogram, the letter with the maximum number of occurrences, the number of occurrences of the letter with the maximum number of occurrences, and the frequency of the letter with the maximum number of occurrences; 2) read in information about a driver from a file, display the package information you read in, compute and display the ID of the heaviest package, weight of the heaviest package, and verage weight of all the packages.
Notes: Function prototypes and header file
*/
#include <iostream>
#include <fstream>
using namespace std;
// task 1
struct LetterOccurrence {
      int count;
      double frequency;
};
void runTask1();
void processString(const string, LetterOccurrence[]);
void computeMaximumOccurences(const LetterOccurrence[], char *, int *, double *);
void displayHistogram(const LetterOccurrence[], int);
// task 2
struct Package {
	int id;
	double weight;
	int length;
	int width;
	int height;
};
void runTask2(string);
void openinputFile(ifstream&, string);
Package * loadPackages(ifstream&, string *, int *);
void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
#endif
