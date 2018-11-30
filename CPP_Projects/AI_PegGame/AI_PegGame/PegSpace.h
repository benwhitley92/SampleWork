// PegSpace.h: Defines a Peg Space in a Peg Jump game board
#pragma once

#include <iostream>
#include <vector>
using namespace std;

class CPegSpace
{
public:
	CPegSpace(int spaceNum, bool isOcc);
	void Init();

	int GetSpaceNumber() { return spaceNumber; }
	int GetNumberOfValidMoves() { return numberOfValidMoves; }
	void AddPossibleMove(CPegSpace* jump, CPegSpace* land);
	void SetOccupied(bool isOccupied) { isOccupied = isOccupied; }
	void Print() { cout << "Space #: " << spaceNumber << endl << "Occupied: " << isOccupied << endl; }
	void Reset();
	bool IsOccupied() { return isOccupied; }
	vector<CPegSpace*> GetValidJumpSpaces() { return validJumpSpaces; }
	vector<CPegSpace*> GetValidLandSpaces() { return validLandSpaces; }

private:
	vector<CPegSpace*> possibleJumpSpaces;
	vector<CPegSpace*> possibleLandSpaces;
	vector<CPegSpace*> validJumpSpaces;
	vector<CPegSpace*> validLandSpaces;

	int spaceNumber, numberOfPossibleMoves, numberOfValidMoves;
	bool isOccupied;
};