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
void Square::drawOutside(){
	std::cout << "\nDrawing a " + border + " square.";
}
// FilledSquare
FilledSquare::FilledSquare(int l, int w, std::string b, std::string fc) : Square(l,w,b), Fillable(fc){}

// Fill the square
void FilledSquare::fill(){
	std::cout << " With " + fillColor + " fill.";
}

// FilledTextSquare
FilledTextSquare::FilledTextSquare(int l, int w, std::string b, std::string fc, std::string lbl) :
	FilledSquare(l, w, b, fc), Label(lbl){}

// Add a label to the filled square
void FilledTextSquare::addLabel(){
	std::cout << " Containing the text: \"" << shapeLabel << "\".";
}

// Circle
// Constructor that creates a Circle object with the length, width, and border color as parameters
Circle::Circle(int l, int w, std::string b) : Shape(l, w, b){}

// Draw a border for the circle
void Circle::drawOutside(){
	std::cout << "\nDrawing a " + border + " circle.";
}

// FilledCircle
FilledCircle::FilledCircle(int l, int w, std::string b, std::string fc) : Circle(l,w,b), Fillable(fc){}

// Fill the circle
void FilledCircle::fill(){
	std::cout << " With " + fillColor + " fill.";
}

// Arc
// Constructor that creats an Arc object with the length, width, and border color as parameters
Arc::Arc(int l , int w, std::string b) : Shape(l, w, b){}

// Draw the Arc
void Arc::drawOutside(){
	std::cout << "\nDrawing a " + border + " arc.";
}
