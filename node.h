


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
	CNode(Player _mGrid[3][3], Player _pPlayerTurn, Vect2 _vturnPosition, int _iAlpha, int _iBeta, CNode* _pParent);
	~CNode();

	int GetHeuristic();
	Vect2 GetTurnPosition();
	
private:

	char PlayerEnumToChar(Player _pEnum);

	Winner checkGameOver();


	int m_iNodeHeuristic;
	int m_iAlpha;
	int m_iBeta;

	Player m_pGrid[3][3];
	
	Player m_pPlayerTurn;
	Vect2 m_vturnPosition;

	CNode* m_pParent;
	vector<CNode*> m_pChildNodes;


};