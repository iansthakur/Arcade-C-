#pragma once
#include "board.h"
#include <iomanip>


enum {
	width = 5,
	height = 5,
	in_a_row = 5, 
	one = 1,
	two = 2,
	three = 3,
	quit = 4,
	fail = 7,
	turns = 6,
	width_gomoku = 20,// +1,
	height_gomoku = 20,// +1,
	
};

class gameBase {
public:
	
 //virtual void methods
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn() = 0;
	//prompt method for user input 
	virtual int prompt(unsigned int& row, unsigned int& col);
	virtual void print() = 0; 


	int play();
	static gameBase* check(int i, char* array[]);

protected:
	game_piece b[width][height];
	
	int longestentry = two;
	
	
	string player = "player two";
};

