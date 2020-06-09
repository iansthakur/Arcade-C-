#include "gameBase.h"
#include "tictactoe.h"

static gameBase* check(int i, char* array[]){
	if (array.length() != 2 ) {
		gameBase* zero_pointer = 0;//new gameBase;
		return zero_pointer;
	}
	else if (array[1] != "tictactoe") {
		cout << "invalid game choice" <<endl
	}

	

	board b = new board; 
	return this.b; 
	//unsure of return because pointer?
}

