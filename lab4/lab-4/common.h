#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

enum fileIdentifier {
	lab1Header, 
	failureOpen,
	failureNumLine,
	
};

enum testing {
	success,
	failure,
	numCorrectArg,
	argMax = 5,
	argMin = 1,
};

enum openingFiles{
	program_name,
	fileName,
};

enum formating {
	maxSingleDigit = 9,
	minDoubleDigit = 10,
};