#include "gameBase.h"
#include "tictactoe.h"
#include "gomoku.h"

//makes sure that players switch off each turn
//returns print statements depending on draw, turn, win or quit
int gameBase::play() {
	int count = 0;
	print();

	while (true)
	{
		if (player.compare("player one")==0) {
			player = "player two";
		}
		else {
			player = "player one";
		}
		int xxx = turn();
		if (done() == true)
		{
			
			cout << this->player << " has won the game!" << endl;
			return success;
		}
		if (draw() == true) {
			cout << "No winning moves remain. Total turns played was " << (count + 1) << endl;
			return turns;
		}
		cout << "!!" << endl;
		if (xxx == quit) {
			cout << "game is over. Player quit. Total turns: " << count << endl;
			return quit;
		}
		count = count + 1;
	}
}


//prompts user and makes input readable for functions
int gameBase::prompt(unsigned int& row, unsigned int& col) {
	string s;
	while (true) {
		cout << "Enter a valid coordinate or type quit to end play" << endl;
		cin >> s;
		if (s == "quit") {
			return quit;
		}
		size_t position = s.find(',');
		if (position >= 0 && position < s.size()) {
			s.replace(position, one, " ");
			istringstream stream(s);
			if (stream >> row && stream >> col) {
				return success;



			}
		}
	}
	return success;
}

//checks user input for either gomoku with n dimensions, original gomoku, gomoku with dimension and number in a row or tictactoe
//so that the correct game is played
gameBase* gameBase::check(int i, char* array[]) {
	string gameName = array[one]; 
	string g = "gomoku";
	if (i == 2 && gameName.compare("tictactoe") ==0){
		gameBase* zero_pointer = new tictactoe();
		return zero_pointer;
	}
	else if (i==4 && gameName == g && atoi(array[two]) > three && atoi(array[three]) > one && atoi(array[two]) > atoi(array[three])) {
		gameBase* gomoku_pointer = new gomoku(atoi(array[two]), atoi(array[three]));
		return gomoku_pointer;
	}
	else if ( i == 3 && gameName == g &&  atoi(array[two]) > three) {
		gameBase* gomoku_pointer = new gomoku(atoi(array[two]));
		return gomoku_pointer;
	}
	else if (gameName == g) {
		gameBase* gomoku_pointer = new gomoku();
		return gomoku_pointer;
	}
	else {
		return 0; 
	}
	
}