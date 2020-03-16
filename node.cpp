



#include "node.h"

CNode::CNode(Player _mGrid[3][3], Player _pPlayerTurn, Vect2 _vturnPosition, int _iAlpha, int _iBeta, CNode* _pParent)
{
	

	// Copping the array
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_pGrid[i][j] = _mGrid[i][j];
		}
	}
	
	// Copping the variables
	m_pPlayerTurn = _pPlayerTurn;
	m_vturnPosition = _vturnPosition;
	m_iAlpha = _iAlpha;
	m_iBeta = _iBeta;
	m_pParent = _pParent;


	// Has turn
	m_pGrid[m_vturnPosition.x][m_vturnPosition.y] = m_pPlayerTurn;





	// is leaf Node
	if (checkGameOver() != None)
	{
		// For ai win
		if (checkGameOver() == O_Winner)
		{
			m_iNodeHeuristic = 1;
		}
		// For player win
		else if (checkGameOver() == X_Winner)
		{
			m_iNodeHeuristic = -1;
		}
		// For tie
		else 
		{
			m_iNodeHeuristic = 0;
		}
	}
	else // Has leaf nodes
	{

		// What its going to make the next nodes
		Player NextTurn;
		if (m_pPlayerTurn == X)
		{
			NextTurn = O;

			// Sets the start heuristic
			m_iNodeHeuristic = -static_cast<int>(INFINITY);
		}
		else
		{
			NextTurn = X;
			// Sets the start heuristic
			m_iNodeHeuristic = static_cast<int>(INFINITY);
		}


		// Makes all the nodes
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
					vNewTurn.y = j;

					CNode* cNewNode = new CNode(m_pGrid, NextTurn, vNewTurn, m_iAlpha, m_iBeta, this);

					m_pChildNodes.push_back(cNewNode);



					// Gets all the heuristics
					// Max
					if (m_pPlayerTurn == X)
					{
						// Gets heuristic from child nodes
						if (cNewNode->GetHeuristic() > m_iNodeHeuristic)
						{
							m_iNodeHeuristic = cNewNode->GetHeuristic();
						}
					}
					// Min
					else
					{
						// Gets heuristic from child nodes
						if (cNewNode->GetHeuristic() < m_iNodeHeuristic)
						{
							m_iNodeHeuristic = cNewNode->GetHeuristic();
						}
					}

				}
			}
		}
	}



}

CNode::~CNode()
{

}

int CNode::GetHeuristic()
{
	return m_iNodeHeuristic;
}

Vect2 CNode::GetTurnPosition()
{
	return m_vturnPosition;
}



char CNode::PlayerEnumToChar(Player _pEnum)
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

Winner CNode::checkGameOver()
{

	// iterates through all columns and rows
	for (int i = 0; i < 3; ++i)
	{

		if ((m_pGrid[i][0] == X and m_pGrid[i][1] == X and m_pGrid[i][2] == X) or (m_pGrid[0][i] == X and m_pGrid[1][i] == X and m_pGrid[2][i] == X))
		{
			return X_Winner;
		}
		else if ((m_pGrid[i][0] == O and m_pGrid[i][1] == O and m_pGrid[i][2] == O) or (m_pGrid[0][i] == O and m_pGrid[1][i] == O and m_pGrid[2][i] == O))
		{
			return O_Winner;
		}
	}

	// Checks for Diagonals 
	if ((m_pGrid[0][2] == X and m_pGrid[1][1] == X and m_pGrid[2][0] == X) or (m_pGrid[0][0] == X and m_pGrid[1][1] == X and m_pGrid[2][2] == X))
	{
		return X_Winner;
	}
	else if ((m_pGrid[0][2] == O and m_pGrid[1][1] == O and m_pGrid[2][0] == O) or (m_pGrid[0][0] == O and m_pGrid[1][1] == O and m_pGrid[2][2] == O))
	{
		return O_Winner;
	}


	// Checks for no win
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (m_pGrid[i][j] == Blank)
			{
				return None;
			}
		}
	}


	// Returns Tie
	return Tie;
}

