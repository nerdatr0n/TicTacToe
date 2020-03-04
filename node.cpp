

#include "node.h"

CNode::CNode(Player _mGrid[3][3], Player _pPlayerTurn, Vect2 _vturnPosition)
{
	

	// Copping the array
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_pGrid[i][j] = _mGrid[i][j];
		}
	}

	m_pPlayerTurn = _pPlayerTurn;
	m_vturnPosition = _vturnPosition;


	// Has turn
	m_pGrid[m_vturnPosition.x][m_vturnPosition.y] = m_pPlayerTurn;


	// What its going to make the next nodes
	Player pNextTurn;
	if (m_pPlayerTurn == X)
	{
		pNextTurn = O;
	}
	else
	{
		pNextTurn = X;
	}



	// Checks to see if its an end node
	if (!checkGameOver())
	{
		// Checks for no win
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				// Only if its a blank space
				if (m_pGrid[i][j] == Blank)
				{
					// Coppies all 
					Vect2 vNewTurn;
					
					vNewTurn.x = i;
					vNewTurn.y = i;

					CNode cNewNode(m_pGrid, m_pPlayerTurn, m_vturnPosition);

					//m_pAdjcentNodes.push_back(cNewNode);

				}
			}
		}

		
	}
}

CNode::~CNode()
{

}



bool CNode::checkGameOver()
{

	// iterates through all columns and rows
	for (int i = 0; i < 3; ++i)
	{

		if ((m_pGrid[i][0] == X and m_pGrid[i][1] == X and m_pGrid[i][2] == X) or (m_pGrid[0][i] == X and m_pGrid[1][i] == X and m_pGrid[2][i] == X))
		{
			return true;
		}
		else if ((m_pGrid[i][0] == O and m_pGrid[i][1] == O and m_pGrid[i][2] == O) or (m_pGrid[0][i] == O and m_pGrid[1][i] == O and m_pGrid[2][i] == O))
		{
			return true;
		}
	}

	// Checks for Diagonals 
	if ((m_pGrid[0][2] == X and m_pGrid[1][1] == X and m_pGrid[2][0] == X) or (m_pGrid[0][0] == X and m_pGrid[1][1] == X and m_pGrid[2][2] == X))
	{
		return true;
	}
	else if ((m_pGrid[0][2] == O and m_pGrid[1][1] == O and m_pGrid[2][0] == O) or (m_pGrid[0][0] == O and m_pGrid[1][1] == O and m_pGrid[2][2] == O))
	{
		return true;
	}


	// Checks for no win
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (m_pGrid[i][j] == Blank)
			{
				return true;
			}
		}
	}


	// Returns no win
	return true;

}

