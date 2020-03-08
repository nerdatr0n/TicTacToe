#pragma once
class miniMax
{
};




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
#include "node.h"


using namespace std;



class CMiniMax
{
public:
	CMiniMax(Player _mGrid[3][3], Player _pPlayerTurn);
	~CMiniMax();

	Vect2 GetBestMove();


private:

	Player checkGameOver();


	Player m_pGrid[3][3];

	Player m_pPlayerTurn;
	Vect2 m_vturnPosition;



	vector<CNode*> m_pChildNodes;


};