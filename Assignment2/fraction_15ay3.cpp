/*
 * fraction_15ay3.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: Andus Yu
 */

#include "fraction_15ay3.h"

int main(){
	return 0;
}

// Exception class definitions
FractionException::FractionException(const string& message) : message(message){}
string& FractionException::what(){return message;}
