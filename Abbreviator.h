#pragma once

#include "EValueType.h"
#include <iostream>

using namespace std;

class Abbreviator
{

public:

	char inputValue;
	bool hasChosenType;
	bool isNumeric;

	ValueType chosenVal = Monetary;

	int ChooseValueType();
	void WaitForValue(bool type);
	string AbbreviateValue(int val);

};

