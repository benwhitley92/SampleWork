#include "PegSpace.h"

// Constructor
CPegSpace::CPegSpace(int spaceNum, bool isOcc) :
		spaceNumber(spaceNum), isOccupied(isOcc)
{
	numberOfPossibleMoves = 0;
	numberOfValidMoves = 0;
}

// Sets up the valid jump positions
void CPegSpace::Init()
{
	for(int i = 0; i < numberOfPossibleMoves; i++)
	{
		// Valid move is defined as the jump space being occupied and the land space not
		if(possibleJumpSpaces[i]->IsOccupied() && !possibleLandSpaces[i]->IsOccupied())
		{
			validJumpSpaces.push_back(possibleJumpSpaces[i]);
			validLandSpaces.push_back(possibleLandSpaces[i]);
			numberOfValidMoves++;
		}
	}
}

// Adds a possible move (for construction)
void CPegSpace::AddPossibleMove(CPegSpace* jump, CPegSpace* land)
{
	possibleJumpSpaces.push_back(jump);
	possibleLandSpaces.push_back(land);
	numberOfPossibleMoves++;
}

// Recomputes the valid moves
void CPegSpace::Reset()
{
	numberOfValidMoves = 0;

	validJumpSpaces.clear();
	validLandSpaces.clear();
}