#include "Abbreviator.h"


int Abbreviator::ChooseValueType()
{
	int val;

	cout << "Choose Value Type\n";
	cout << "1. Monetary Value\n";
	cout << "2. Data Storage Value\n";
	cout << "3. Exit\n";

	cin >> val;

	switch (val)
	{
	case 1:
		chosenVal = ValueType::Monetary;
		break;
		
	case 2:
		chosenVal = ValueType::Data;
		break;
	}

	return val;
}

void Abbreviator::WaitForValue(bool type)
{
	string valType;

	int value;

	switch (chosenVal)
	{
	case Monetary:
		valType = "Money!";
		break;

	case Data:
		valType = "Data Storage!";
		break;
	}
	
	cout << "\n **********\n";
	cout << "You have chosen" << valType << endl;
	cout << "Enter value to Abbreviate\n";
	cin >> value;
	cout << "Value Abbreviation = " << AbbreviateValue(value) << endl;
}

string Abbreviator::AbbreviateValue(int val)
{
	string finalVal;

	int T_Val = val;

	int ArrayIndex;
	string MonetarySuffix[] = { "", "k", "m", "Bn", "Tr" };
	string DataSuffix[] = { "", "KB", "MB", "GB", "TB" };

	bool isMonetary = chosenVal ? Monetary : Data;

	switch (chosenVal)
	{
	case Monetary:
		
		T_Val /= 1000;

	case Data:

		T_Val /= 1024;
	}

	//while (val >= 1000 && ArrayIndex < )



	return finalVal;
}