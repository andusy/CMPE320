#pragma once

#ifdef ANDUSYUFRACTIONCALCULATOR_EXPORTS
#define FRACTION_CALCULATOR __declspec(dllexport)
#else
#define FRACTION_CALCULATOR __declspec(dllimport)
#endif

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Fraction class
class Fraction {
public:
	// Constructors
	FRACTION_CALCULATOR Fraction();
	FRACTION_CALCULATOR Fraction(int);
	FRACTION_CALCULATOR Fraction(int, int);

	// Accessors
	FRACTION_CALCULATOR int numerator();
	FRACTION_CALCULATOR int denominator();

	// Fraction unary operator overload
	FRACTION_CALCULATOR Fraction &operator-(); // Negation
	FRACTION_CALCULATOR Fraction &operator++(); // Pre increment
	FRACTION_CALCULATOR Fraction operator++(int); // Post increment

	// Binary operator overload
	FRACTION_CALCULATOR friend Fraction operator+(const Fraction &left, const Fraction &right); // Addition
	FRACTION_CALCULATOR friend Fraction operator-(const Fraction &left, const Fraction &right); // Subtraction
	FRACTION_CALCULATOR friend Fraction operator*(const Fraction &left, const Fraction &right); // Multiplication
	FRACTION_CALCULATOR friend Fraction operator/(const Fraction &left, const Fraction &right); // Division

	FRACTION_CALCULATOR Fraction &operator+=(const Fraction &right); // Addition and assignment

	// Comparison operators
	FRACTION_CALCULATOR friend bool operator<(const Fraction &left, const Fraction &right); // Less than
	FRACTION_CALCULATOR friend bool operator<=(const Fraction &left, const Fraction &right); // Less than or equal to
	FRACTION_CALCULATOR friend bool operator==(const Fraction &left, const Fraction &right); // Equal to
	FRACTION_CALCULATOR friend bool operator!=(const Fraction &left, const Fraction &right); // Not equal to
	FRACTION_CALCULATOR friend bool operator>=(const Fraction &left, const Fraction &right); // Greater than or equal to
	FRACTION_CALCULATOR friend bool operator>(const Fraction &left, const Fraction &right); // Greater than

	FRACTION_CALCULATOR friend ostream &operator<<(ostream &out, const Fraction &right); // Used with cout
	FRACTION_CALCULATOR friend istream &operator>>(istream &in, Fraction &right); // Used with cin

private:
	// Variable Declaration
	int numer, denom;

	FRACTION_CALCULATOR int gcd(int, int); // Method to find gcd
};



// Fraction exception class
class FractionException {
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};
