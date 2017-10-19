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
public:
	// Constructors
	Fraction();
	Fraction(int);
	Fraction(int, int);

	// Accessors
	int numerator();
	int denominator();

	// Fraction unary operator overload
	Fraction &operator-(); // Negation
	Fraction &operator++(); // Pre increment
	Fraction operator++(int); // Post increment

	// Binary operator overload
	friend Fraction operator+(const Fraction &left, const Fraction &right); // Addition
	friend Fraction operator-(const Fraction &left, const Fraction &right); // Subtraction
	friend Fraction operator*(const Fraction &left, const Fraction &right); // Multiplication
	friend Fraction operator/(const Fraction &left, const Fraction &right); // Division

	Fraction &operator+=(const Fraction &right); // Addition and assignment

	// Comparison operators
	friend bool operator<(const Fraction &left, const Fraction &right); // Less than
	friend bool operator<=(const Fraction &left, const Fraction &right); // Less than or equal to
	friend bool operator==(const Fraction &left, const Fraction &right); // Equal to
	friend bool operator!=(const Fraction &left, const Fraction &right); // Not equal to
	friend bool operator>=(const Fraction &left, const Fraction &right); // Greater than or equal to
	friend bool operator>(const Fraction &left, const Fraction &right); // Greater than

	friend ostream &operator<<(ostream &out, const Fraction &right); // Used with cout
	friend istream &operator>>(istream &in, Fraction &right); // Used with cin

private:
	// Variable Declaration
	int numer, denom;

	int gcd(int, int); // Method to find gcd
};



// Fraction exception class
class FractionException{
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};
