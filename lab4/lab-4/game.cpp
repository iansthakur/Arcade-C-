#include "game.h"


string colorToString(color c)
{
	if (c == red)
	{
		return "red";
	}
	if (c == black)
	{
		return "black";
	}

	if (c == white)
	{
		return "white";
	}

	if (c == noColor)
	{
		return "no Color";
	}

	return "invalid label";
}

color stringToColor(string c)
{
	if (c.compare("red") == 0)
	{
		return red;
	}
	if (c.compare("black") == 0)
	{
		return black;
	}

	if (c.compare("white") == 0)
	{
		return white;
	}

	if (c.compare("noColor") == 0)
	{
		return noColor;
	}

	return invalidLabel;
}



