//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : errorCheck.cpp
// Description : Contains all the error checks
// Author      : David Haverland
// Mail        : david.hav8466@mediadesign.school.nz
//

// All the libraries

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "errorCheck.h"

using namespace std;



bool CheckNodeInputErrors(string _strNodeInput)
{
	if (_strNodeInput.front() == ',' or _strNodeInput.back() == ',')
	{
		// Failed check
		return false;
	}

	for (signed int i = 0; i < _strNodeInput.size() - 1; i++)
	{
		if (_strNodeInput.at(i) == ',' and _strNodeInput.at(i + 1) == ',')
		{
			// Failed check
			return false;
		}
	}




	// removes spaces
	string::iterator end_pos;
	end_pos = std::remove(_strNodeInput.begin(), _strNodeInput.end(), ' ');
	_strNodeInput.erase(end_pos, _strNodeInput.end());




	std::vector<string>::iterator it;
	string strAllStringsSeperate;
	vector<string> strings;
	strings.push_back(strAllStringsSeperate);

	std::string delimiter = ",";


	size_t pos = 0;

	string token;

	while ((pos = _strNodeInput.find(delimiter)) != string::npos) {

		token = _strNodeInput.substr(0, pos);

		_strNodeInput.erase(0, pos + delimiter.length());

		// Finds the meme i put in
		it = find(strings.begin(), strings.end(), token);
		if (it != strings.end())
		{
			return false;
		}
		else
		{
			strings.push_back(token);
		}
	}
	it = find(strings.begin(), strings.end(), _strNodeInput);
	if (it != strings.end())
	{
		return false;
	}
	else
	{
		strings.push_back(_strNodeInput);
	}

	// Passed check
	return true;
}


bool CheckForDigits(const string& str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}


bool CheckEdgeAmountErrors(string _strEdgeAmount)
{
	if (!CheckForDigits(_strEdgeAmount))
	{
		// Failed check
		return false;
	}

	int iEdgeAmount = stoi(_strEdgeAmount);

	if (iEdgeAmount > 0 and iEdgeAmount < 100)
	{
		// Passed check
		return true;
	}
	// Failed check
	return false;

}

bool CheckStringCoords(string _strCoords)
{
	// removes spaces
	string::iterator end_pos = remove(_strCoords.begin(), _strCoords.end(), ' ');
	_strCoords.erase(end_pos, _strCoords.end());

	if (count(_strCoords.begin(), _strCoords.end(), ',') != 1)
	{
		// Failed check
		return false;
	}

	std::string delimiter = ",";
	string token;
	size_t pos = 0;

	string _strCoordy;

	while ((pos = _strCoords.find(delimiter)) != string::npos)
	{
		_strCoordy = _strCoords.substr(0, pos);

		_strCoords.erase(0, pos + delimiter.length());
	}


	int iCoordX = stoi(_strCoords);
	int iCoordY = stoi(_strCoordy);

	if (iCoordX > 2 or iCoordX < 0)
	{
		// Failed check
		return false;
	}
	if (iCoordY > 2 or iCoordY < 0)
	{
		// Failed check
		return false;
	}


	// Passed check
	return true;
}


