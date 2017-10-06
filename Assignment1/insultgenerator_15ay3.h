/*
 * insultgenerator_15ay3.h
 *
 *  Created on: Sep 23, 2017
 *      Author: Andus Yu
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// FileException class
class FileException{
public:
	FileException(const string& message);
	string& what();
private:
	string message;
};

// NumInsultsOutOfBounds class
class NumInsultsOutOfBounds{
public:
	NumInsultsOutOfBounds(const string& message);
	string& what();
private:
	string message;
};

// InsultGenerator class
class InsultGenerator{
public:
	// Variable Declaration
	vector<string> col1; // List of words from the first column
	vector<string> col2; // List of words from the second column
	vector<string> col3; // List of words from the third column
	const int LEGALMAX = 10000; // Legal number of insults
	const string FILE_TO_READ = "InsultsSource.txt"; // The text file containing the words to be read

	// Constructor
	InsultGenerator(){ // Empty Constructor
	}

	// Functions
	void initialize(void); // Loads all the source phrases from the InsultsSource.txt file into the attributes
	string talkToMe(void); // Returns a single insult, generated at random
	vector<string> generate(int numToGenerate); // Generates the requested number of unique insults
	void generateAndSave(string fileName, int numToGenerate); // Generates the requested number of unique insults and saves them to the file name
};
