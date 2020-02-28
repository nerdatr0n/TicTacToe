//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : game.cpp
// Description : class for dealing with the game
// Author      : David Haverland
// Mail        : david.hav8466@mediadesign.school.nz
//

#include <iostream>
#include <string>
#include <algorithm>
#include "board.h"

using namespace std;

CBoard::CBoard()
{


	// Setting all spaces on bord to 0
	for (int i = 0; i < 3; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			m_pGrid[i][j] = Blank;
		}
	}


	m_pWinner = null;
	m_pCurrentPlayer = X;
}


CBoard::~CBoard()
{
}


void CBoard::ResetBoard()
{
	// Setting all spaces on bord to 0
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_pGrid[i][j] = Blank;
		}
	}


	m_pWinner = null;
	m_pCurrentPlayer = X;
}


bool CBoard::GetEnded()
{
	return false;
}


Player CBoard::GetWinner()
{
	// Avoids unnessacery actions
	if (m_pWinner != null)
	{
		return m_pWinner;
	}

	// iterates through all columns and rows
	for (int i = 0; i < 3; ++i)
	{
		
		if ((m_pGrid[i][0] == X and m_pGrid[i][1] == X and m_pGrid[i][2] == X) or (m_pGrid[0][i] == X and m_pGrid[1][i] == X and m_pGrid[2][i] == X))
		{
			return X;
		}
		else if ((m_pGrid[i][0] == O and m_pGrid[i][1] == O and m_pGrid[i][2] == O) or (m_pGrid[0][i] == O and m_pGrid[1][i] == O and m_pGrid[2][i] == O))
		{
			return O;
		}
	}

	// Checks for Diagonals 
	if ((m_pGrid[0][2] == X and m_pGrid[1][1] == X and m_pGrid[2][0] == X) or (m_pGrid[0][0] == X and m_pGrid[1][1] == X and m_pGrid[2][2] == X))
	{
		return X;
	}
	else if ((m_pGrid[0][2] == O and m_pGrid[1][1] == O and m_pGrid[2][0] == O) or (m_pGrid[0][0] == O and m_pGrid[1][1] == O and m_pGrid[2][2] == O))
	{
		return O;
	}



	return null;
}


Player CBoard::GetSpace(Vect2 _vPoint)
{
	// Checks that the point is valid
	if (_vPoint.x > 3 or _vPoint.x < 0 or _vPoint.y > 3 or _vPoint.y < 0)
	{
		return null;
	}
	
	return m_pGrid[_vPoint.x][_vPoint.y];
}


bool CBoard::HaveTurn(Vect2 _vPoint)
{

	// Checks that the point is valid
	if (GetSpace(_vPoint) != Blank)
	{
		return false;
	}


	m_pGrid[_vPoint.x][_vPoint.y] = m_pCurrentPlayer;


	// Switches player
	if (m_pCurrentPlayer == X)
	{
		m_pCurrentPlayer = O;
	}
	else
	{
		m_pCurrentPlayer = X;
	}

	return false;
}


void CBoard::DisplayBoard()
{
	cout << "	   0   1   2 " << endl;
	cout << "	  --- --- ---" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << "	" << i <<"| ";

		for (int j = 0; j < 3; ++j)
		{
			cout << PlayerEnumToChar(m_pGrid[i][j]) << " | ";
		}
		cout << endl;
		cout << "	  --- --- ---" << endl;
	}

}

Player CBoard::GetTurn()
{
	return m_pCurrentPlayer;
}

char CBoard::PlayerEnumToChar(Player _pEnum)
{
	if (_pEnum == X)
	{
		return 'X';
	}
	else if (_pEnum == O)
	{
		return 'O';
	}

	return ' ';
}

Vect2 StringToVector(string _strCoordInputs)
{
	Vect2 vReturn;

	string _strCoordX = _strCoordInputs;

	// removes spaces
	string::iterator end_pos = remove(_strCoordX.begin(), _strCoordX.end(), ' ');
	_strCoordX.erase(end_pos, _strCoordX.end());
	

	std::string delimiter = ",";
	string token;
	size_t pos = 0;

	string _strCoordY;

	while ((pos = _strCoordX.find(delimiter)) != string::npos)
	{
		_strCoordY = _strCoordX.substr(0, pos);

		_strCoordX.erase(0, pos + delimiter.length());
	}



	vReturn.x = stoi(_strCoordX);
	vReturn.y = stoi(_strCoordY);

	return vReturn;
}

//string PlayerToString(Player _player)
//{
//	switch (_player)
//	{
//	case Blank:
//	{
//		return "Blank";
//		break;
//	}
//	case X:
//	{
//		return "X";
//		break;
//	}
//	case O:
//	{
//		return "O";
//		break;
//	}
//	case null:
//	{
//		return "null";
//		break;
//	}
//	default:
//	{
//		return " An error has occured ";
//	}
//	}
//	return " An error has occured ";
//}
