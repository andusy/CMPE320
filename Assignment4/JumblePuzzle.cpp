/*
 * JumblePuzzle.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Andus Yu
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <time.h>

#include "JumblePuzzle.h"

int myrandom (int i) { return std::rand()%i;} // Random number generator function

JumblePuzzle::JumblePuzzle(const std::string& word, const std::string& difficulty){
	srand(time(NULL)); // Seed srand
	int wordLen = word.size(); // Get the length of the entered word

	if (wordLen < 3 || wordLen > 10){ // Check if the word is between 3 and 10 characters
		throw BadJumbleException("The word must be between 3 and 10 characters in length!");
	}

	// Check the difficulty entered by the user
	if (difficulty == "easy"){ // User entered easy
		size = wordLen * JumblePuzzle::EASY;
	} else if (difficulty == "medium"){ // User entered medium
		size = wordLen * JumblePuzzle::MED;
	} else if (difficulty == "hard"){ // User entered hard
		size = wordLen * JumblePuzzle::HARD;
	} else { // User entered an invalid difficulty string
		throw BadJumbleException("Invalid difficulty entered!");
	}

	jumble = new char*[size];

	// Create new arrays onto the heap
	for (int i = 0; i < size; i++){
		jumble[i] = new char [size];
	}

	// Fill the 2d array with random characters
	for (int i = 0; i < size; i ++){
		for (int j = 0; j < size; j++){
			jumble[i][j] = (char)(myrandom(26) + 'a'); // Random number from 0-25 + 'a' (ascii values 97-122)
		}
	}

	// Generate random row and column for the word to be placed
	row = rand() % size;
	col= rand() % size;
	std::vector<int> dir {'n','e','s','w'}; // Possible directions to choose from
	std::random_shuffle(dir.begin(), dir.end(), myrandom); // Shuffle the contents of the vector
	direction = dir[dir.size()-1]; // Set the direction to the last element of the direction vector

	for (int i = 0; i < wordLen; i++){
		if (direction == 'n'){ // Up
			if (wordLen <= (row+1)){
				jumble[row - i][col] = word.at(i);
			} else {
				dir.pop_back(); // Remove the last element of the directions
				direction = dir[dir.size()-1]; // Set the direction to the last element of the direction vector
			}
		} else if (direction == 'e'){ // Right
			if (wordLen <= (size-col)){
				jumble[row][col + i] = word.at(i);
			} else {
				dir.pop_back(); // Remove the last element of the directions
				direction = dir[dir.size()-1]; // Set the direction to the last element of the direction vector
			}
		} else if (direction == 's'){ // Down
			if (wordLen <= (size - row)){
				jumble[row + i][col] = word.at(i);
			} else {
				dir.pop_back(); // Remove the last element of the directions
				direction = dir[dir.size()-1]; // Set the direction to the last element of the direction vector
			}
		} else if (direction == 'w'){ // Left
			if (wordLen <= (col + 1)){
				jumble[row][col - i] = word.at(i);
			} else {
				dir.pop_back(); // Remove the last element of the directions
				direction = dir[dir.size()-1]; // Set the direction to the last element of the direction vector
			}
		}
	}
}

// Copy Constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& jp){
	size = jp.getSize();
	row = jp.getRowPos();
	col = jp.getColPos();
	direction = jp.getDirection();

	jumble = new char*[size]; // New character pointer

	// Create new arrays onto the heap
	for (int i = 0; i < size; i++){
		jumble[i] = new char[size];
	}

	charArrayPtr* copy = jp.getJumble(); // A copy of the jumble entered as a parameter

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			jumble[i][j] = copy[i][j]; // Copy the values from the entered jumble into the new one
		}
	}
}

// Destructor
JumblePuzzle::~JumblePuzzle(){
	for (int i = 0; i < size; i++){
		delete jumble[i];
	}
	delete jumble; // Delete the pointer to the puzzle
}

// Accessors
charArrayPtr* JumblePuzzle::getJumble() const{ return jumble;} // Return the puzzle
int JumblePuzzle::getSize() const{ return size;} // Return the size of the puzzle
int JumblePuzzle::getRowPos() const{ return row;} // Return the row position of the first letter
int JumblePuzzle::getColPos() const{ return col;} // Return the column position of the first letter
char JumblePuzzle::getDirection() const { return direction;}// Return the direction the word is going as a char


JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& other){
	if (this != &other){ // Check if the same object is being passed
		size = other.getSize(); // Set the size
		row = other.getRowPos(); // Set the row
		col = other.getColPos(); // Set the column
		direction = getDirection(); // Set the direction

		// Destruct old jumble
		this -> ~JumblePuzzle();

		jumble =  new char*[size];

		// Create new arrays onto the heap
		for (int i = 0; i < size; i++){
			jumble[i] = new char[size];
		}

		charArrayPtr* copy = other.getJumble(); // Set a reference to the jumble being copied

		// Copy elements from old jumble to new one
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				jumble[i][j] = copy[i][j];
			}
		}
	}
	return *this;
}

BadJumbleException::BadJumbleException(const std::string& message): message(message){}
std::string& BadJumbleException::what(){return message;}
