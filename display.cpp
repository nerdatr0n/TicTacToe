//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : display.cpp
// Description : For functions that display text
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

#include "display.h"



using namespace std;


void DisplayMainMenu()
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << "	Tic Tac Toe: LightMode" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "	Please input a number below" << endl;
	cout << endl;
	cout << "	1. Human vs Human" << endl;
	cout << endl;
	cout << "	2. Human vs AI - easy" << endl;
	cout << endl;
	cout << "	3. Human vs AI - Impossable" << endl;
	cout << endl;
	cout << "	4. Quit game" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

}

void DisplayMenuError()
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << "	Tic Tac Toe: LightMode" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "	Please input a number below" << endl;
	cout << endl;
	cout << "	1. Human vs Human" << endl;
	cout << endl;
	cout << "	2. Human vs AI - easy" << endl;
	cout << endl;
	cout << "	3. Human vs AI - Impossable" << endl;
	cout << endl;
	cout << "	4. Quit game" << endl;
	cout << endl;
	cout << endl;
	cout << "  Error - Please enter a valid input" << endl;
	cout << endl;

}


void DisplayHeader()
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << "	Tic Tac Toe: LightMode" << endl;
	cout << endl;
	cout << endl;
}