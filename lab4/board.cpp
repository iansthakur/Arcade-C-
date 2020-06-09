#include "board.h"

int gamePiece(ifstream& input, vector<game_piece>& pieces, unsigned int& one, unsigned int& two)
{
	string s; 
	string type;
	string other; 
	string line_1; 
	unsigned int row; 
	unsigned int col; 
	int index = 0;
	bool good = false; 
	while (getline(input, line_1))
	{
		istringstream stream(line_1);
		if (stream >> s && stream >> type && stream >> other && stream >> col && stream >> row) {
			color t = stringToColor(s);
			if (col >= one || row >= two || col < 0 || row < 0 || t == invalidLabel ) {
				continue; 
			}
			index = (one * row) + col;
			game_piece piece;
			piece.color_piece = t; 
			piece.name_piece = type;
			piece.display = other;
			pieces[index] = piece; 

			good = true; 
		}
	}

	if (good == true) {
		return success;
	}

	else {
		return failedToFind;
	}
}



int dim(ifstream& input, unsigned int& one, unsigned int& two)
{



	if (input.is_open())
	{
		int i = 0;
		string line_1;

		getline(input, line_1); 

		while (line_1.empty())
		{
			getline(input, line_1);
		}
				 istringstream intOne (line_1); 
				 if (intOne >> one && intOne >> two) {
					 return success; 
				 }
				 else
				 {
					 return noDimExtraction; 
				 }
	}

	else
	{
		cout << "ERROR" << endl;
		return failureOpen;
	}


	return success;
}


int print(const vector<game_piece>& vec, unsigned int& one, unsigned int& two)
{
	if (one * two != vec.size()) {
		return sizeFail;
	}
	//can't use unsigned loop here because the loop would never stop
	for (int j = two - 1; j >= 0; --j) {
		for (unsigned int i = 0; i < one; ++i) {
			cout << vec[(j * two) + i].display;
		}
		cout << endl;
		
	}
	return success;
	
}

