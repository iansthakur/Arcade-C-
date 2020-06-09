#pragma once
#include "gameBase.h"

class gomoku : public gameBase {
public:
	friend ostream& operator<<(ostream& s, const gomoku& gB);
	//default constructo
	gomoku();
	//constructor with just board size argument
	gomoku(int i);
	//constructor with board size arggument and in a row argument
	gomoku(int i, int j);

	//initialize the vector of game_pieces--for EC
	vector<vector<game_piece>> b; 
	//player var that is B or W piece rep
	string player;

	//functions for gomoku game
	
	//makes game use gomoku insertion operator instead of tictactoe one
	virtual void print();

	//checks to see if player won
	//returns true if 5 in a row are the same piece
	virtual bool done();

	//checks to see if its still possible for player to win
	//returns true if it is a tie
	virtual bool draw();

	//plays one turn of the game
	//returns int representing quit, success, or failure
	virtual int turn();

protected:
	int in_a_row_user = in_a_row; 
	int size =height_gomoku;
};
