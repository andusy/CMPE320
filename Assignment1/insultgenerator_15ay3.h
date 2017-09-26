/*
 * insultgenerator_15ay3.h
 *
 *  Created on: Sep 23, 2017
 *      Author: Andus Yu
 */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

///////////////////////////////////////////////////////
////////	Split a string by a delimiter//////////////
template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
///////////////////////////////////////////////////////
class FileException {

};

class NumInsultsOutOfBounds{

};

class InsultGenerator{
public:
	// Variable Declaration
	string words[50]; // The list of words read from the text file

	// Constructor
	InsultGenerator(){ // Empty Constructor
	}

	// Functions
	void initialize(void); // Loads all the source phrases from the InsultsSource.txt file into the attributes
	void toString(void);
};

// InsultGenerator member functions
void InsultGenerator::initialize(){
	string str = "";
	string line;
	ifstream in("InsultsSource.txt");
	if (in.is_open()){

		// Concatenate all of the lines in the text document to one string
		while(getline(in,line)){
			str += line;
		}

		// Split the string by tabs into an array
		std::vector<std::string> insults = split(str, '\t');

		// Copy the words into the array
		for (int i = 0; i < 50; i++){
			words[i] = insults[i];
		}

		in.close();
	} else {
		cout << "Unable to open file";
	}
}

void InsultGenerator::toString(void){
	for (int i = 0; i < 50; i++){
		cout << words[i] << endl;
	}
}
