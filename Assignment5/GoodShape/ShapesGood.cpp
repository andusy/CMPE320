/*
 * ShapesGood.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: Andus Yu
 */

#include <iostream>
#include "ShapesGood.h"

// Label
Label::Label(std::string lb) : shapeLabel(lb){} // Set shape label

// Fillable
Fillable::Fillable(std::string fl) : fillColor(fl){} // Set fill color

// Shape
// Shape constructor that takes in the length, width, and border color of the shape
Shape::Shape(int l, int w, std::string b) : length(l), width(w), border(b){}

// Square
// Constructor that creates a Square object with the length, width, and border color as parameters
Square::Square(int l, int w, std::string b) : Shape(l,w,b){}

// Draw the border for the square
void Square::drawBorder(){
	std::cout << "Drawing a Square with a " << border << " border." << std::endl;
}
// FilledSquare
FilledSquare::FilledSquare(int l, int w, std::string b, std::string fc) : Square(l,w,b), Fillable(fc){}

// Fill the square
void FilledSquare::addFill(){
	std::cout << "Filling Square with " << fillColor << "." << std::endl;
}

// FilledTextSquare
FilledTextSquare::FilledTextSquare(int l, int w, std::string b, std::string fc, std::string lbl) :
	FilledSquare(l, w, b, fc), Label(lbl){}

// Add a label to the filled square
void FilledTextSquare::addLabel(){
	std::cout << "Label \"" << shapeLabel << "\" added to the shape." << std::endl;
}

// Circle
// Constructor that creates a Circle object with the length, width, and border color as parameters
Circle::Circle(int l, int w, std::string b) : Shape(l, w, b){}

// Draw a border for the circle
void Circle::drawBorder(){
	std::cout << "Drawing a Circle with a " << border << " border." << std::endl;
}

// FilledCircle
FilledCircle::FilledCircle(int l, int w, std::string b, std::string fc) : Circle(l,w,b), Fillable(fc){}

// Fill the circle
void FilledCircle::addFill(){
	std::cout << "Filling Circle with " << fillColor << "." << std::endl;
}

// Arc
// Constructor that creats an Arc object with the length, width, and border color as parameters
Arc::Arc(int l , int w, std::string b) : Shape(l, w, b){}

// Draw the Arc
void Arc::drawBorder(){
	std::cout << "Drawing an Arc with a " << border << " border." << std::endl;
}
