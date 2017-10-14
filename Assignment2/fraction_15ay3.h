/*
 * fraction_netid.h
 *
 *  Created on: Oct 14, 2017
 *      Author: Andus Yu
 */

#include <string>
#include <iostream>

using namespace std;

// Fraction class
class Fraction{


};

// Fraction exception class
class FractionException{
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};
