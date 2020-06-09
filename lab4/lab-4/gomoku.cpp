#include "gomoku.h"


ostream& operator<<(ostream& s, const gomoku& gb) {	
	//iterate thru gomoku board
	//print out game piece at each spot in board
	for (int i = gb.size - 1; i >= 0; --i) {
		cout << i;//print out coloumn frame
		for (int j = 0; j < gb.size; ++j) {
			if (i>maxSingleDigit) {
				if (j < minDoubleDigit) {
					//x>=10 & y<10, so add space at end
					cout << gb.b[i][j].display << " ";
				}
				else {
					//x>=10 & y>=10, so add two space at end
					cout << gb.b[i][j].display << "  ";
				}
			}
			else {
				if (j < minDoubleDigit) {
					//x<10 & y<10, so add space in front
					cout << " " << gb.b[i][j].display;
				}
				else {
					//x<10 & y>=10, so add space in front and space at end
					cout << " " << gb.b[i][j].display << " ";
				}
			}
			
		}
		cout << endl;
	}
	cout << "X";
	for (int i = 0; i < gb.size; i++) {
		//print out bottom row frame with space btwn
		cout << " " << i;
	}
	cout << endl;

	return s;
}

//initializiation for gomku with argument for size and pieces in a row
gomoku::gomoku(int s, int in_a_row_from_user) {
	size = s+1;
	in_a_row_user = in_a_row_from_user; 
	for (int i = 0; i <= size; ++i) {
		vector<game_piece> vec;
		b.push_back(vec);
		for (int j = 0; j <= size; ++j) {
			game_piece g;
			g.color_piece = invalidLabel;
			g.name_piece = "";
			g.display = " ";
			b[i].push_back(g);
		}
	}
	player = "W";
}

//constructor for gomoku with size argument, but no pieces ina r ow argument
gomoku::gomoku(int s) {
	in_a_row_user = in_a_row;
	size = s+1;
	for (int i = 0; i <= size; ++i) {
		vector<game_piece> vec;
		b.push_back(vec);
		for (int j = 0; j <= size; ++j) {
			game_piece g;
			g.color_piece = invalidLabel;
			g.name_piece = "";
			g.display = " ";
			b[i].push_back(g);


		}
	}
	player = "W";
}

//default constructor-- no argument for board size or in arow
///defautls to 19x19 and 5 in a row 
gomoku::gomoku() {
	//default constructor
	//initialize every spot in gomoku board as empty/ blank piece
	in_a_row_user = in_a_row;
	for (int i = 0; i <= size; ++i) {
		vector<game_piece> vec;
		b.push_back(vec);
		for (int j = 0; j <= size; ++j) {
			game_piece g;
			g.color_piece = invalidLabel;
			g.name_piece = "";
			g.display = " ";
			b[i].push_back(g);

			
		}
	}
	player = "W";
}

//print function for gomoku--calls overload op 
void gomoku::print() {
	cout << *this; //endl; or note
}

bool gomoku::done() {
	//determine if somone won
	for (int i = 0; i < size; ++i) {
		for (int k = 0; k < size; ++k) {
			//iterate thru length and width of board 
			//stop if piece is same as current player (black or white)
			if (this->b[i][k].display == player) {
				//DOUBLE CHECK FOR ALL:
				//width and height are correct. will work properly but we will get points off if its wrong
				//l< width_gomoku VS l<= width_gomoku

				//check left
				int left_counter = 0;
				int l = i;
				while (this->b[l][k].display == player && l >= 0 && l < size) {
					left_counter++;
					--l;
					if (left_counter == in_a_row_user) {
						return true;
					}
				}
				//check right
				int right_counter = 0;
				int r = i;
				while (this->b[r][k].display == player && r>=0 && r<size) {
					right_counter++;
					r++;
					if (right_counter == in_a_row_user) {
						return true;
					}
				}
				//check up
				int up_counter = 0;
				int u = k;
				while (u >= 0 && u < size && this->b[i][u].display == player) {
					up_counter++;
					u++;
					if (up_counter == in_a_row_user) {
						return true;
					}
				}
				//check down
				int down_counter = 0;
				int d = k;
				while (this->b[i][d].display == player && d >= 0 && d < size) {
					down_counter++;
					d++;
					if (down_counter == in_a_row_user) {
						return true;
					}
				}
				//check diagonal right
				int diagonal_right_counter = 0;
				int w = i;
				int h = k;
				while (this->b[w][h].display == player && w >= 0 && w < size && h >= 0 && h < size) {
					//add 1 to each 
					diagonal_right_counter++;
					w++;
					h++;
					if (diagonal_right_counter == in_a_row_user) {
						return true;
					}
				}
				//check diagonal left
				int diagonal_left_counter = 0;
				int w2 = i;
				int h2 = k;
				while (w2 >= 0 && w2 < size && h2 >= 0 && h2 < size && this->b[w2][h2].display == player) {
					//minus 1 to width plus 1 to height
					diagonal_left_counter++;
					w2--;
					h2++;
					if (diagonal_left_counter == in_a_row_user) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
//check to see if there are 5 blank spaces in a row
//do we want this to be perfect or close enough?
bool gomoku::draw() {
	//determine if its a tie
	if (this->done() == true) {
		return false;
	}
	//check for blank spaces--same as for done function but checking for blanks instead of b or w
	string blank = " ";
	for (int i = 1; i < size; i++) {
		for (int k = 1; k < size; k++) {
			if (this->b[i][k].display == blank) {
				//check left
				int left_counter = 0;
				int l = i;
				//decrease i by 1 each time, and check to see if spot to at --i is empty
				//if it is for 5 in a row then possible to win so return false
				//all others are the same but for different direction
				while ( l >= 0 && l < size && this->b[l][k].display == blank) {
					left_counter++;
					--l;
					
					if (left_counter == in_a_row_user) {
						return false;
					}
				}
				//check right
				int right_counter = 0;
				int r = i;
				while ( r >= 0 && r < size && this->b[r][k].display == blank) {
					right_counter++;
					r++;
					
					if (right_counter == in_a_row_user) {
						return false;
					}
				}
				//check up
				int up_counter = 0;
				int u = k;
				while ( u >= 0 && u < size && this->b[i][u].display == blank) {
					up_counter++;
					u++;
					
					if (up_counter == in_a_row_user) {
						return false;
					}
				}
				//check down
				int down_counter = 0;
				int d = k;
				while (this->b[i][d].display == blank && d >= 0 && d < size) {
					down_counter++;
					--d;
					
					if (down_counter == in_a_row_user) {
						return false;
					}
				}
				//check diagonal right
				int diagonal_right_counter = 0;
				int w = i;
				int h = k;
				while ( w >= 0 && w < size && h >= 0 && h < size && this->b[w][h].display == blank) {
					//add 1 to each 
					diagonal_right_counter++;
					w++;
					h++;
					
					if (diagonal_right_counter == in_a_row_user) {
						return false;
					}
				}
				//check diagonal left
				int diagonal_left_counter = 0;
				int w2 = i;
				int h2 = k;
				while ( w2 >= 0 && w2 < size && h2 >= 0 && h2 < size && this->b[w2][h2].display == blank) {
					//minus 1 to width, plus 1 to heihgt
					diagonal_left_counter++;
					w2--;
					h2++;
					if (diagonal_left_counter == in_a_row_user) {
						return false;
					}
				}
			}
		}
	}
	//end check for 5 blanks in a row

	//next check to see if player that just played can connect any of his already placed players
	//so B' ' ' ' 'B would be valid but BBB' 'W would not
	//this code only runs if above does first return a value
	//might not need above 

	for (int i = 1; i < size; i++) {
		for (int k = 1; k < size; k++) {
			//iterate thru board, if current player's chip is found pause iteration
			if (this->b[i][k].display == player) {
				//DOUBLE CHECK FOR ALL:
				//width and height are correct. will work properly but we will get points off if its wrong
				
				//check left
				int left_counter = 0;
				int l = i;
				//decrease i by 1 each time, and check to see if spot to at --i is empty or same chip
				//if it is for 5 in a row then possible to win so return false
				//all others are the same but for different direction
				while ( l >= 0 && l < size && (this->b[l][k].display == blank || this->b[l][k].display == player)) {
					++left_counter;
					--l;
					if (left_counter == in_a_row_user) {
						return false;
					}
				}
				//check right
				int right_counter = 0;
				int r = i;
				while ((this->b[r][k].display == blank || this->b[r][k].display == player) && r >= 0 && r < size) {
					right_counter++;
					r++;
					if (right_counter == in_a_row_user) {
						return false;
					}
				}
				//check up
				int up_counter = 0;
				int u = k;
				while ( u >= 0 && u < size && (this->b[i][u].display == blank || this->b[i][u].display == player)) {
					up_counter++;
					u++;
					if (up_counter == in_a_row_user) {
						return false;
					}
				}
				//check down
				int down_counter = 0;
				int d = k;
				while (d >= 0 && d < size && (this->b[i][d].display == blank || this->b[i][d].display == player)) {
					down_counter++;
					--d;
					if (down_counter == in_a_row_user) {
						return false;
					}
				}
				//check diagonal right
				int diagonal_right_counter = 0;
				int w = i;
				int h = k;
				while ( w >= 0 && w < size && h >= 0 && h < size && (this->b[w][h].display == blank || this->b[w][h].display == player)) {
					//add 1 to each 
					diagonal_right_counter++;
					w++;
					h++;
					if (diagonal_right_counter == in_a_row_user) {
						return false;
					}
				}
				//check diagonal left
				int diagonal_left_counter = 0;
				int w2 = i;
				int h2 = k;
				while ( w2 >= 0 && w2 < size && h2 >= 0 && h2 < size && ((this->b[w2][h2].display == blank || this->b[w2][h2].display == player))) {
					//minus 1 to width, plus 1 to heihgt
					diagonal_left_counter++;
					w2--;
					h2++;
					if (diagonal_left_counter == in_a_row_user) {
						return false;
					}
				}
			}
		}
	}
	//if above doesnt return false then game must be a draw
	return true;
}
int gomoku::turn() {
	unsigned int row;
	unsigned int col;

	if (player == "W") {
		player = "B";
	}

	else if (player == "B") {
		player = "W";
	}

	bool isValid = false;
	while (!isValid) {
		int result = prompt(row, col);
		//swap row and col bc i messed it up elsewhere
		int col2 = row;
		row = col;
		col = col2;
		if (result == quit) {
			return quit;
		}
		else {
			if (row > 0 && (int) row < size && col > 0 && (int) col < size && b[row][col].display == " ")
			{
				
 				isValid = true;
				b[row][col].display = player;
				
			}
			else {
				cout << "the position is not valid" << endl;
			}
		}
	}
	print();
	return success;
}