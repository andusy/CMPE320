/*
 * insultgenerator_15ay3.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: Andus Yu
 */

#include <time.h>

#include "insultgenerator_15ay3.h"

using namespace std;

int main() {

	InsultGenerator ig;
	vector<string> insults;
	double start, finish;

	// The initialize() method should load all the source phrases from the InsultsSource.txt file into the attributes.
	// If the file cannot be read, the method should throw an exception.
	try {
		ig.initialize();
	} catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}

	// talkToMe() returns a single insult, generated at random.
	cout << "A single insult:" << endl;
	cout << ig.talkToMe() << endl;

	// Check number to generate limits.
	try {
		insults = ig.generate(-100);
	} catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	try {
		insults = ig.generate(40000);
	} catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}

	// generate() generates the requested number of unique insults.
	cout << "\n100 insults, all different:" << endl;
	insults = ig.generate(100);
	if (insults.size() > 0)
		for (int i = 0; i < 100; i++)
			cout << insults[i] << endl;
	else
		cerr << "Insults could not be generated!" << endl;

	// generateAndSave() generates the requested number of	 unique insults and saves them to the filename
	// supplied.  If the file cannot be written, the method should throw an exception.  Note that the
	// insults in the file should be in alphabetical order!
	// Check the number to generate limits first:
	try {
		ig.generateAndSave("Nothing.txt", 40000);
	} catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	cout << "\nSaving 1000 unique insults to a file...";
	try {
		ig.generateAndSave("SavedInsults.txt", 1000);
	} catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}
	cout << "done." << endl;

	// Test ability to generate the maximum number of insults and how long it takes.
	try {
		start = clock();
		insults = ig.generate(10000);
		finish = clock();

	} catch (NumInsultsOutOfBounds& e) {
		cerr << e.what() << endl;
	}
	cout << "\n" << insults.size() << " insults generated." << endl;
	cout << (finish - start) << " msec to complete." << endl;

	return 0;
} // end main


// InsultGenerator member functions
void InsultGenerator::initialize(){
	string str;
	ifstream in(FILE_TO_READ);
	int count = 0;

	if (in.is_open()){
		// Concatenate all of the lines in the text document to one string
		while(!in.eof()){
			in >> str; // Load word into str

			if (count % 3 == 0 ){ // Column 1
				col1.push_back(str); // Load string into column 1
			} else if (count % 3 == 1){ // Column 2
				col2.push_back(str); // Load string into column 2
			} else { // Column 3
				col3.push_back(str); // Load string into column 3
			}
			count ++; // Increment the counter
 		}
		in.close();
	} else {
		throw FileException("File cannot be read!");
	}
}

string InsultGenerator::talkToMe(){
	int rand1 = rand() % col1.size(); // Random word from column 1
	int rand2 = rand() % col2.size(); // Random word from column 2
	int rand3 = rand() % col3.size(); // Random word from column 3

	return "Thou " + col1[rand1] + " " + col2[rand2] + " " + col3[rand3] + "!";
}

vector<string> InsultGenerator::generate(int numToGenerate){
	if (numToGenerate > 0 && numToGenerate <= LEGALMAX){ // Number is between legal range
		vector<string> insults; // Create a string vector of the declared size

		for (int i = 0; i < numToGenerate; i++){
			insults.push_back(talkToMe()); // Call the talkToMe method and push that string into the vector
		}
		return insults; // Return the list of insults
	} else { // Number is not within legal range
		throw NumInsultsOutOfBounds("Number not within legal range!");
	}
}

void InsultGenerator::generateAndSave(string fileName, int numToGenerate){
	vector<string> insults = generate(numToGenerate); // Generate the number of insults specified

	ofstream out;
	out.open(fileName); // Open the file
	for (int i = 0; i < numToGenerate; i++){
		out << insults[i] + "\n"; // Write each insult to text file
	}
	out.close(); // Close the file

}

// Exception class definitions
FileException::FileException(const string& message) : message(message){}
string& FileException::what(){return message;}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message){}
string& NumInsultsOutOfBounds::what(){return message;}
