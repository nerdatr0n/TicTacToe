//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : game.h
// Description : Headerr for class for dealing with the game
// Author      : David Haverland
// Mail        : david.hav8466@mediadesign.school.nz
//

#pragma once



enum Player
{
	Blank,
	X,
	O,
	null
};

enum Winner
{
	None,
	X_Winner,
	O_Winner,
	Tie
};

struct Vect2
{
	int x;
	int y;
};


//string PlayerToString(Player _player);
Vect2 StringToVector(std::string _strCoordInputs);

class CBoard
{

public:
	CBoard();
	~CBoard();



	void ResetBoard();
	bool GetEnded();
	Winner GetWinner();

	Player GetSpace(Vect2 _vPoint);
	bool HaveTurn(Vect2 _vPoint);
	
	void DisplayBoard();

	Player GetTurn();

	char PlayerEnumToChar(Player _pEnum);
	char WinnerEnumToChar(Winner _pEnum);

	void CopyBoard(Player _pBoard[3][3]);

private: 

	

	Player m_pGrid[3][3];
	Winner m_pWinner;
	Player m_pCurrentPlayer;


};