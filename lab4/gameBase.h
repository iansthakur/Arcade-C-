

class gameBase {
protected:
	game_piece b[width][height];
	char player;
	friend ostream& operator<<(ostream& s, board& g);
	int longestentry;
	static gameBase* check(int i, char* array[]);
	virtual void done() = 0; 
	virtual void draw() = 0;
	virtual void turn() = 0;
	int prompt(unsigned int& row, unsigned int& col);
	virtual void print() = 0; 
};

