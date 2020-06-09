
#include "Common.h"

enum color {
	red,
	black,
	white,
	invalidLabel,
	noColor
};
color stringToColor(string c);

struct game_piece 
{
	color color_piece = invalidLabel;
	string name_piece = ""; 
	string display = " ";
};

