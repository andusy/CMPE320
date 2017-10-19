/*
 * fraction_15ay3.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: Andus Yu
 */

#include "fraction_15ay3.h"

// Fraction class constructor implementation
Fraction::Fraction(){
	numer = 0;
	denom = 1;
}

Fraction::Fraction(int num){
	numer = num;
	denom = 1;
}

Fraction::Fraction(int num1, int num2){
	if (num2 != 0){ // Checks if the denominator is not 0
		int reduce = gcd(num1, num2);
		num1 /= reduce;
		num2 /= reduce;
		if (num2 < 0){ // Denominator is negative
			if (num1 < 0){ // Numerator is also negative
				// Set both the numerator and denominator to positive
				numer = abs(num1);
				denom = abs(num2);
			} else { // Numerator is not negative
				// Set the numerator to negative and denominator to positive
				numer = 0 - num1;
				denom = abs(num2);
			}
		} else { // Denominator is not negative
			numer = num1;
			denom = num2;
		}
	} else { // Denominator is 0
		throw FractionException("Invalid Denominator"); // Throw FractionException
	}
}

// Finds the greatest common divisor between two integers
int Fraction::gcd(int n, int m){
	n = abs(n);
	m = abs(m);
	if (m <= n && n % m == 0){
		return m;
	} else if (n < m){
		return gcd(m,n);
	} else {
		return gcd(m, n%m);
	}
}

// Fraction class accessor implementation
int Fraction::numerator() { return numer; }
int Fraction::denominator() { return denom; }

// Fraction unary operator overload implementation
// Negation Operator
Fraction &Fraction::operator-(){
	numer *= -1;
	return *this;
}

// Pre Increment
Fraction &Fraction::operator++(){
	numer += denom;
	return *this;
}

// Post Increment
Fraction Fraction::operator++(int n){
	Fraction f (numer, denom);
	numer += denom;
	return f;
}

// Fraction binary operator overload implementation
// Addition
Fraction operator+(const Fraction &left, const Fraction &right){
	int n, d; // Temporary variables to calculate numerator and denominator
	n = left.numer * right.denom + right.numer * left.denom;
	d = left.denom * right.denom;
	Fraction f(n,d);
	return f;
}

// Subtraction
Fraction operator-(const Fraction &left, const Fraction &right){
	int n, d; // Temporary variables to calculate numerator and denominator
	n = left.numer * right.denom - right.numer * left.denom;
	d = left.denom * right.denom;
	Fraction f(n,d);
	return f;
}

// Multiplication
Fraction operator*(const Fraction &left, const Fraction &right){
	Fraction f(left.numer * right.numer, left.denom * right.denom);
	return f;
}

// Division
Fraction operator/(const Fraction &left, const Fraction &right){
	Fraction f(left.numer * right.denom, left.denom * right.numer);
	return f;
}

// Addition and assignment
Fraction &Fraction::operator+=(const Fraction &right){
	int n, d; // Temporary variables for numerator and denominator that will be reduced

	n = numer * right.denom + right.numer * denom;
	// Check the case where it is 0 + 0
	if (n == 0){
		return *this; // Don't change anything and return this
	}
	d = denom * right.denom;

	// Reduce the n and d and store store values into numerator and denominator
	int reduce = gcd(n, d);
	numer = n / reduce;
	denom = d / reduce;

	return *this;
}

// Comparison operator
// Less than
bool operator<(const Fraction &left, const Fraction &right){
	int n1, n2;
	// Calculate numerators with common denominator
	n1 = left.numer * right.denom;
	n2 = right.numer * left.denom;

	if (n1 < n2){ // First numerator is less than
		return true;
	} else {
		return false;
	}
}

// Less than or equal to
bool operator<=(const Fraction &left, const Fraction &right){
	int n1, n2;
	// Calculate numerators with common denominator
	n1 = left.numer * right.denom;
	n2 = right.numer * left.denom;

	if (n1 < n2 || n1 == n2){ // First numerator is less than or equal to
		return true;
	} else {
		return false;
	}
}

// Equal to
bool operator==(const Fraction &left, const Fraction &right){
	int n1, n2;
	// Calculate numerators with common denominator
	n1 = left.numer * right.denom;
	n2 = right.numer * left.denom;

	if (n1 == n2){ // First numerator is equal to
		return true;
	} else {
		return false;
	}
}

// Not equal
bool operator!=(const Fraction &left, const Fraction &right){
	int n1, n2;
	// Calculate numerators with common denominator
	n1 = left.numer * right.denom;
	n2 = right.numer * left.denom;

	if (n1 != n2){ // First numerator is not equal to
		return true;
	} else {
		return false;
	}
}

// Greater than or equal to
bool operator>=(const Fraction &left, const Fraction &right){
	int n1, n2;
	// Calculate numerators with common denominator
	n1 = left.numer * right.denom;
	n2 = right.numer * left.denom;

	if (n1 > n2 || n1 == n2){ // First numerator is greater than or equal to
		return true;
	} else {
		return false;
	}
}

// Greater than
bool operator>(const Fraction &left,const Fraction &right){
	int n1, n2;
	// Calculate numerators with common denominator
	n1 = left.numer * right.denom;
	n2 = right.numer * left.denom;

	if (n1 > n2){ // First numerator is greater than
		return true;
	} else {
		return false;
	}
}


// cout
ostream &operator<<(ostream &out, const Fraction &f){
	if (f.denom != 1){
		out << f.numer << "/" << f.denom << endl;
	} else {
		out << f.numer << endl;
	}
	return out;
}

// cin
istream &operator>>(istream &in, Fraction &f){
	char c;
	int n, d;
	// Sets the numerator
	in >> n;
	f.numer = n;

	// Check if the next character is a /
	c = in.peek();
	if(c == '/')
		in >> c;
	else
		return in;

	// Check if the denominator is invalid
	c = in.peek();
	if(c == '0')
		throw FractionException("Denominator can not be zero!");
	else if(isdigit(c)) {
		in >> d;
	    f.denom = d; // Set the denominator
	} else { // Default of no denominator is entered
		f.denom = 1;
	}
	return in;
}

// Exception class definitions
FractionException::FractionException(const string& message) : message(message){}
string& FractionException::what(){return message;}
