


#pragma once


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>

#include "board.h"

using namespace std;



class CNode
{
public:
	CNode(Player _mGrid[3][3], Player _pPlayerTurn, Vect2 _vturnPosition);
	~CNode();

	int GetHeuristic();
	Vect2 GetTurnPosition();
	
private:

	char PlayerEnumToChar(Player _pEnum);

	Player checkGameOver();

	int m_iNodeHeuristic;

	Player m_pGrid[3][3];
	
	Player m_pPlayerTurn;
	Vect2 m_vturnPosition;



	vector<CNode*> m_pChildNodes;


};