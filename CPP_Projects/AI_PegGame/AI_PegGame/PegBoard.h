// PegBoard.h: Defines a peg board for the jump game
#pragma once

class CPegSpace;

#include <vector>
using namespace std;

class CPegBoard
{
public:
	CPegBoard();
	void Init();

	int GetNumberOfValidMoves() { return numberOfValidMoves; }
	int NumberOfPegsLeft();
	int GetLastPegNumber();
	void DoValidMove(int offset);
	void AddRow();
	void Print();
	void Reset();
	bool isDone() { return (numberOfValidMoves > 0 ? true : false); }

	bool rowIsAdded;

private:
	vector<CPegSpace*> pegs;
	int numberOfValidMoves;
};