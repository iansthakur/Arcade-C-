#include "game.h"


enum {
	noDimExtraction = 2,
	failedToFind = 3, 
	sizeFail = 4
};

int dim(ifstream& input, unsigned int& one, unsigned int& two);

int gamePiece(ifstream& input, vector<game_piece>& pieces, unsigned int& one, unsigned int& two);

int print(const vector<game_piece>& vec, unsigned int& one, unsigned int& two);