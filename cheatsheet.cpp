// Comments

#include <iostream>
using namespace std; // I/O

// Variable types
short s; // 2 bytes
int i; // 4 bytes
long l; // 4 bytes
long long ll; // 8 bytes
float f; // 4 bytes
double d; // 8 bytes
long double ld; // 12 bytes
// Strings are defined using the string class

// Constant + initialization
const double CM_IN_INCH(2.54);

// Enum
enum Color{red, green, blue};
Color r = red;
switch(r){
	case red: cout << "red!"; break;
	case green: cout << "green!"; break;
	case blue: cout << "blue!"; break;
}

/*	Casting

	static_cast<type>(expression);
	const_cast<type>(expression);
	dynamic_cast<type>(expression);
	reinterpret_cast<type>(expression);
*/

// Casting Example
int aVal = static_cast<int>(4.8); // aVal = 4 (truncate not round)

/*

LHS: When creating a type, & gives you a
reference to a type, * gives you a pointer to a
variable of that type.

RHS: In an expression, & is the “address of”
operator yielding the memory address of a
variable.

* is “de-referencing”. When used with a pointer it
yields the value of the variable being pointed to.

*/

typedef long double dprecision; // Allows for dprecision to be used instead of long double for a type

// Arrays
int anArray[5];
int anArray[] = [2,7,3,0,1];
int anArray[5] = [2,7,3,0,1];

// Structures - a kind of class
// primitive object with no privacy
struct address{
	string name;
	int streetNumber;
	string street;
	string city;
	string province;
	string postalCode;
}; // <------- semicolon

// Dot operator
object.member

// De-referencing and membership
pointer->member

// Latter same as
(*pointer).member

var++; // Post increment

// Pointers 
int aVal = 100;
int* ptr_aVal = &aVal; // Pointer to aVal
cout << typeid(ptr_aVal).name() << endl; // Displays "Pi"

expr << expr // Bitwise shift left
expr >> expr // Bitwise shift right

// Bitwise operators
expr & expr // Bitwise AND
expr ^ expr // Bitwise exclusive OR (or XOR)
expr | expr // Bitwise OR

/*
A B A&B A|B A^B
0 0 0	0	0
0 1 0	1	1
1 0 0	1	1
1 1 1	1	0
*/

&& || // logical AND and logical OR

int x = y = z; // Same as

int x = (y = z);

val << n // Moves all bits in val to the left by n positions
// Zeroes are added to the least significant bit
// Same as multiplying a number by 2^n

x = x | 1 << n // Set the nth bit of any number, x, and not change the rest

if ((x & 1 << n) != 0) // Check to see if the nth bit is set

// Non zero integers are treated as being true, and zero is treated as being false

int x = 10;
if (x)

// Same as 

int x = 10;
if (x != 0)



