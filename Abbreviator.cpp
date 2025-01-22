#include "Abbreviator.h"


int Abbreviator::ChooseValueType()
{
	int val;

	cout << "Choose Value Type\n";
	cout << "1. Monetary Value\n";
	cout << "2. Data Storage Value\n";
	cout << "0. Exit\n";

	cin >> val;

	switch (val)
	{
	case 1:
		chosenVal = ValueType::Monetary;
		break;
		
	case 2:
		chosenVal = ValueType::Data;
		break;

	case 0:
		break;
	}

	return val;
}

int Abbreviator::InputValueToAbbreviate()
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
	
	cout << "\n **************** \n";
	cout << "You have chosen " << valType << endl;
	cout << "Enter the value to Abbreviate\n";
	cout << "Or Type 0 to exit\n";

	cin >> value;
	
	if (value == 0)
	{
		return 0;
	}
	cout << "\n";
	cout << "Value Abbreviation = " << AbbreviateValue(value) << "\n";
	
	return 3;
}

string Abbreviator::AbbreviateValue(int val)
{
	string finalVal;

	int T_Val = val;
	int sufID = 0;

	const string MonetarySuffix[] = { "", "k", "m", "Bn", "Tr" };
	const string DataSuffix[] = { "KB", "MB", "GB", "TB", "PB" };

	auto suffixes = chosenVal == ValueType::Monetary ? MonetarySuffix : DataSuffix;

	finalVal = to_string(val);

	double valLength = trunc(finalVal.size());

	while (T_Val >= 1000 && sufID <= 4)
	{
		T_Val /= 1000;
		sufID++;
	}

	finalVal = to_string(T_Val);
	
	if (valLength <= 3)
	{
		return finalVal;
	}

	string totalStr = to_string(val);
	int length = totalStr.size();
	int digitID = length % 3 == 0 ? 3 : length % 3;

	char nextDigit = totalStr[digitID];

	if (digitID < length && nextDigit != '0')
	{
		finalVal += "." + totalStr.substr(digitID, 1);
	}

	finalVal.append(suffixes[sufID]);

	return finalVal;
}



/*

*********** NOTES ***************

Below is the first implementation of the Abbreviator' decimal system.
I was trying to parse vales as strings.
I divided the length of the input string by separators into segments.
These segments if != 0 chose relative trailing values to add to the final string.

This method required me to manually describe the values to put before and after the decimal (if any) and seemed a bit hard coded.
Due to this reason, I wanted to try a more direct approach so I used the above method.



IMPLEMENTATION 1 :



	double segments = totalStr.size() / 4;

	switch (decVal)
	{
	case 0:
		break;

	default:
		string dec = to_string(segments);

		double whole;
		double frac = modf(segments, &whole);

		cout << whole << endl;
		cout << frac << endl;

		switch (dec.find("."))
		{
		default:
			break;
		case 1:

			if (decVal != 0)
			{
				bool beforeDec = frac != 0;
				if (!beforeDec)
				{
					initVal.append(".");
					initVal += decVal;
					break;
				}
				else
				{
					int spaces = frac < 0.5f ? 1 : 2;
					initVal += "." ;

					for (int i = 1; i <= spaces; i++)
					{
						initVal += finalVal[i];
					}

					break;

				}
			}
		}
		break;
	}
	return finalVal;
}

*/