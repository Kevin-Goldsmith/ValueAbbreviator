#pragma once

#include "EValueType.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Abbreviator
{

public:

	char inputValue;
	bool hasChosenType;
	bool isNumeric;

	ValueType chosenVal = Monetary;

	int ChooseValueType();
	int InputValueToAbbreviate();
	string AbbreviateValue(int val);

};

