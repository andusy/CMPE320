/*
 * ShapesGood.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Andus Yu
 */

#ifndef SHAPESGOOD_H_
#define SHAPESGOOD_H_

#pragma once

#include <string>

// Shapes that can be labeled
class Label{
public:
	Label(std::string); // Constructor to set the label
	virtual ~Label() {}; // Destructor

protected:
	std::string shapeLabel; // Shape's label
	virtual void addLabel() = 0; // Labels the shape
};

// Shapes that can be filled
class Fillable{
public:
	Fillable(std::string); // Constructor to set the label
	virtual ~Fillable() {}; // Destructor

protected:
	std::string fillColor; // Color
	virtual void addFill() = 0; // Fills the shape
};

class Shape{
public:
	Shape(int, int, std::string);
	virtual ~Shape(){};

	// Accessors
	int getLength() const {return length;}
	int getWidth() const {return width;}

	virtual void draw() = 0; // Draws the outline, possibly filling the outline, possibly adding a label

private:
	// Shape Attributes
	int length;
	int width;

protected:
	std::string border; // Inherited attribute

	// Function to be implemented in each inherited class (Draws the border)
	virtual void drawBorder() = 0;
};

class Square : public Shape{
public:
	Square(int, int, std::string);
	virtual void draw(){
		drawBorder();
	}
protected:
	virtual void drawBorder();
};

class FilledSquare : public Square, Fillable{
public:
	FilledSquare(int, int, std::string, std::string);
	virtual void draw(){
		drawBorder();
		addFill();
	}
protected:
	virtual void addFill();
};

class FilledTextSquare : public FilledSquare, Label{
public:
	FilledTextSquare(int, int, std::string, std::string, std::string);
	virtual void draw(){
		drawBorder();
		addLabel();
	}
protected:
	virtual void addLabel();
};

class Circle : public Shape{
public:
	Circle(int, int, std::string);
	virtual void draw(){
		drawBorder();
	}
protected:
	virtual void drawBorder();
};

class FilledCircle : public Circle, Fillable{
public:
	FilledCircle(int, int, std::string, std::string);
	virtual void draw(){
		drawBorder();
		addFill();
	}
private:
	virtual void addFill();
};

class Arc : public Shape{
public:
	Arc(int, int, std::string);
	virtual void draw(){
		drawBorder();
	}
private:
	virtual void drawBorder();
};

#endif /* SHAPESGOOD_H_ */
