#ifndef JUMBLEPUZZLE_H_
#define JUMBLEPUZZLE_H_

#include <string>

typedef char* charArrayPtr;

class JumblePuzzle{
public:
	JumblePuzzle(const std::string&, const std::string&); // Constructor taking in 2 strings (the word and the difficulty)
	JumblePuzzle(const JumblePuzzle&); // Copy constructor
	~JumblePuzzle(); // Destructor

	// Accessors
	charArrayPtr* getJumble() const;
	int getSize() const; // Gets the size of the puzzle
	int getRowPos() const; // Gets the row position
	int getColPos() const; // Gets the column position
	char getDirection() const; // Gets the direction

	JumblePuzzle& operator=(const JumblePuzzle&); // Assignment operator overload
private:
	// Constants representing the grid size for each difficulty
	const int EASY = 2;
	const int MED = 3;
	const int HARD = 4;

	charArrayPtr* jumble; // Return the puzzle
	int size; // Size of the grid
	int row; // Row the word starts at
	int col; // Column the word stars at
	char direction; // Direction the word is pointing
};

class BadJumbleException{
public:
	BadJumbleException(const std::string& message);
	std::string& what();
private:
	std::string message;
};


#endif
