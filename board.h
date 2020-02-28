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
	Player GetWinner();

	Player GetSpace(Vect2 _vPoint);
	bool HaveTurn(Vect2 _vPoint);
	
	void DisplayBoard();

	Player GetTurn();

	char PlayerEnumToChar(Player _pEnum);

private: 

	

	Player m_pGrid[3][3];
	Player m_pWinner;
	Player m_pCurrentPlayer;


};