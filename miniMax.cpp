

#include "miniMax.h"



CMiniMax::CMiniMax(Player _mGrid[3][3], Player _pPlayerTurn)
{
	int m_iNodeHeuristic = 9999;

	int m_iAlpha = -9999;
	int m_iBeta = 9999;

	// Copping the array
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_pGrid[i][j] = _mGrid[i][j];
		}
	}

	// Makes all the nodes
	if (checkGameOver() == None)
	{
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

					CNode* cNewNode = new CNode(m_pGrid, _pPlayerTurn, vNewTurn, m_iAlpha, m_iBeta, NULL);

					m_pChildNodes.push_back(cNewNode);


					if (m_pPlayerTurn == X)
					{
						m_iNodeHeuristic = max(m_iNodeHeuristic, cNewNode->GetHeuristic());

						m_iAlpha = max(m_iAlpha, m_iNodeHeuristic);

						if (m_iAlpha >= m_iBeta)
						{
							return;
						}
					}
					// Min
					else
					{
						m_iNodeHeuristic = min(m_iNodeHeuristic, cNewNode->GetHeuristic());

						m_iBeta = min(m_iBeta, m_iNodeHeuristic);

						if (m_iAlpha >= m_iBeta)
						{
							return;
						}
					}
				}
			}
		}
	}
}





CMiniMax::~CMiniMax()
{
	for (int i = 0; i < static_cast<int>(m_pChildNodes.size()); i++)
	{
		delete m_pChildNodes[i];
	}
}



Vect2 CMiniMax::GetBestMove()
{
	CNode* BestNode = m_pChildNodes[0];

	// Gets heuristic from child nodes
	for (int i = 0; i < static_cast<int>(m_pChildNodes.size()); i++)
	{
		if (m_pChildNodes[i]->GetHeuristic() > BestNode->GetHeuristic())
		{
			BestNode = m_pChildNodes[i];
		}
	}

	return BestNode->GetTurnPosition();
}



Winner CMiniMax::checkGameOver()
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
				// No Winner
				return None;
			}
		}
	}


	// Returns Tie
	return Tie;
}
