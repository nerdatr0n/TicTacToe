//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : main.cpp
// Description : Main file
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

#include "display.h"
#include "board.h"
#include "errorCheck.h"

using namespace std;


void PlayerVsPlayer(CBoard _board)
{
	string strCoordInputs;

	Vect2 GridPosition;

	_board.ResetBoard();


	while (_board.GetWinner() == null)
	{
		DisplayHeader();
		_board.DisplayBoard();
		cout << endl << "	Current Turn: " << _board.PlayerEnumToChar(_board.GetTurn()) << endl;
		cout << "	Please input your turn seperated by a ','" << endl;

		// Gets and clears the input
		cin.clear();
		//cin.ignore(9999999, '\n');
		getline(cin, strCoordInputs);



		DisplayHeader();
		while (!CheckStringCoords(strCoordInputs))
		{
			DisplayHeader();
			_board.DisplayBoard();
			cout << endl << "	Current Turn: " << _board.PlayerEnumToChar(_board.GetTurn()) << endl;
			cout << "	Please input your turn seperated by a ',' - ERROR Please enter a valid input" << endl;

			cin.clear();
			//cin.ignore(9999999, '\n');
			getline(cin, strCoordInputs);


		}

		GridPosition = StringToVector(strCoordInputs);


		_board.HaveTurn(GridPosition);
	}

	DisplayHeader();
	_board.DisplayBoard();
	cout << endl << "	The winner is " << _board.PlayerEnumToChar(_board.GetWinner()) << endl;
	cout << endl << "	Press enter to continue " << endl;



	cin.clear();
	//cin.ignore(9999999, '\n');
	getline(cin, strCoordInputs);
}

void PlayerVsAiEasy(CBoard _board)
{

}

void PlayerVsAiHard(CBoard _board)
{

}



void MainMenu(CBoard _board)
{
	bool bErrorThrown = false;

	while (true)
	{
		if (!bErrorThrown)
		{
			DisplayMainMenu();
		}
		else
		{
			DisplayMenuError();
		}

		bErrorThrown = false;


		// Inputs
		string iInput;
		cin.clear();
		//cin.ignore(9999999, '\n');
		getline(cin, iInput);


		// For Player Vs Player
		if (iInput == "1")
		{
			PlayerVsPlayer(_board);
		}

		// For player Vs Ai
		else if (iInput == "2")
		{
			PlayerVsAiEasy(_board);
		}
		else if (iInput == "3")
		{
			PlayerVsAiHard(_board);
		}


		//Exit function
		else if (iInput == "4")
		{
			exit(0);
		}


		// recalls this function 
		else
		{
			bErrorThrown = true;

			// Clears the input
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
}


int main()
{
	// Set the consloe to white mode
	system("color f0");

	CBoard board;

	MainMenu(board);
	
	cout << endl << "	An Error has occured and I have no idea why -  I am just a console" << endl;


	// Keeps the window open while testing
	int iTemp = 0;
	cin >> iTemp;
	return 0;
}
