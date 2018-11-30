#include "PegBoard.h"
#include "PegSpace.h"

// Constructor
CPegBoard::CPegBoard()
{
	rowIsAdded = false;

	CPegSpace* one = new CPegSpace(1, false);
	CPegSpace* two = new CPegSpace(2, true);
	CPegSpace* three = new CPegSpace(3, true);
	CPegSpace* four = new CPegSpace(4, true);
	CPegSpace* five = new CPegSpace(5, true);
	CPegSpace* six = new CPegSpace(6, true);
	CPegSpace* seven = new CPegSpace(7, true);
	CPegSpace* eight = new CPegSpace(8, true);
	CPegSpace* nine = new CPegSpace(9, true);
	CPegSpace* ten = new CPegSpace(10, true);
	CPegSpace* eleven = new CPegSpace(11, true);
	CPegSpace* twelve = new CPegSpace(12, true);
	CPegSpace* thirteen = new CPegSpace(13, true);
	CPegSpace* fourteen = new CPegSpace(14, true);
	CPegSpace* fifteen = new CPegSpace(15, true);

	for(int i = 1; i <= 15; i++)
	{
		switch(i)
		{
		case 1:
			one->AddPossibleMove(two, four);
			one->AddPossibleMove(three, six);
			pegs.push_back(one);
			break;

		case 2:
			two->AddPossibleMove(four, seven);
			two->AddPossibleMove(five, nine);
			pegs.push_back(two);
			break;

		case 3:
			three->AddPossibleMove(five, eight);
			three->AddPossibleMove(six, ten);
			pegs.push_back(three);
			break;

		case 4:
			four->AddPossibleMove(two, one);
			four->AddPossibleMove(five, six);
			four->AddPossibleMove(seven, eleven);
			four->AddPossibleMove(eight, thirteen);
			pegs.push_back(four);
			break;

		case 5:
			five->AddPossibleMove(eight, twelve);
			five->AddPossibleMove(nine, fourteen);
			pegs.push_back(five);
			break;

		case 6:
			six->AddPossibleMove(three, one);
			six->AddPossibleMove(five, four);
			six->AddPossibleMove(nine, thirteen);
			six->AddPossibleMove(ten, fifteen);
			pegs.push_back(six);
			break;

		case 7:
			seven->AddPossibleMove(four, two);
			seven->AddPossibleMove(eight, nine);
			pegs.push_back(seven);
			break;

		case 8:
			eight->AddPossibleMove(five, three);
			eight->AddPossibleMove(nine, ten);
			pegs.push_back(eight);
			break;

		case 9:
			nine->AddPossibleMove(five, two);
			nine->AddPossibleMove(eight, seven);
			pegs.push_back(nine);
			break;

		case 10:
			ten->AddPossibleMove(six, three);
			ten->AddPossibleMove(nine, eight);
			pegs.push_back(ten);
			break;

		case 11:
			eleven->AddPossibleMove(seven, four);
			eleven->AddPossibleMove(twelve, thirteen);
			pegs.push_back(eleven);
			break;

		case 12:
			twelve->AddPossibleMove(eight, five);
			twelve->AddPossibleMove(thirteen, fourteen);
			pegs.push_back(twelve);
			break;

		case 13:
			thirteen->AddPossibleMove(eight, four);
			thirteen->AddPossibleMove(nine, six);
			thirteen->AddPossibleMove(twelve, eleven);
			thirteen->AddPossibleMove(fourteen, fifteen);
			pegs.push_back(thirteen);
			break;

		case 14:
			fourteen->AddPossibleMove(nine, five);
			fourteen->AddPossibleMove(thirteen, twelve);
			pegs.push_back(fourteen);
			break;

		case 15:
			fifteen->AddPossibleMove(ten, six);
			fifteen->AddPossibleMove(fourteen, thirteen);
			pegs.push_back(fifteen);
			break;

		default:
			break;
		}
	}

	numberOfValidMoves = 0;

	Init();
}

void CPegBoard::Init()
{
	for(unsigned int i = 0; i < pegs.size(); i++)
	{
		pegs[i]->Init();
		numberOfValidMoves += pegs[i]->GetNumberOfValidMoves();
	}
}

// Returns the number of pegs occupied
int CPegBoard::NumberOfPegsLeft()
{
	int numberOfPegsLeft = 0;

	for(unsigned int i = 0; i < pegs.size(); i++)
	{
		if(pegs[i]->IsOccupied())
			numberOfPegsLeft++;
	}

	return numberOfPegsLeft;
}

int CPegBoard::GetLastPegNumber()
{
	for(unsigned int i = 0; i < pegs.size(); i++)
	{
		if(pegs[i]->IsOccupied())
			return pegs[i]->GetSpaceNumber();
	}
	return -1;
}

// Do the next possible move
void CPegBoard::DoValidMove(int offset)
{
	vector<CPegSpace*> validJumpSpaces;
	vector<CPegSpace*> validLandSpaces;
	int moveNumber = 0;
	if(offset < numberOfValidMoves)
	{
		for(unsigned int i = 0; i < pegs.size(); i++)
		{
			for(int j = 0; j < pegs[i]->GetNumberOfValidMoves(); j++)
			{
				if(moveNumber == offset)
				{
					validJumpSpaces = pegs[i]->GetValidJumpSpaces();
					validLandSpaces = pegs[i]->GetValidLandSpaces();

					pegs[i]->SetOccupied(false);
					pegs[validJumpSpaces[j]->GetSpaceNumber() - 1]->SetOccupied(false);
					pegs[validLandSpaces[j]->GetSpaceNumber() - 1]->SetOccupied(true);

					return;
				}

				else
					moveNumber++;
			}
		}
	}
}

// Add a row of 6 to the bottom of the board
void CPegBoard::AddRow()
{
	rowIsAdded = true;

	CPegSpace* sixteen = new CPegSpace(16, true);
	CPegSpace* seventeen = new CPegSpace(17, true);
	CPegSpace* eighteen = new CPegSpace(18, true);
	CPegSpace* nineteen = new CPegSpace(19, true);
	CPegSpace* twenty = new CPegSpace(20, true);
	CPegSpace* twentyone = new CPegSpace(21, true);

	for(int i = 7; i <= 21; i++)
	{
		switch(i)
		{
		case 7:
			pegs[6]->AddPossibleMove(pegs[10], sixteen);
			pegs[6]->AddPossibleMove(pegs[11], eighteen);
			break;

		case 8:
			pegs[7]->AddPossibleMove(pegs[11], seventeen);
			pegs[7]->AddPossibleMove(pegs[12], nineteen);
			break;

		case 9:
			pegs[8]->AddPossibleMove(pegs[12], eighteen);
			pegs[8]->AddPossibleMove(pegs[13], twenty);
			break;

		case 10:
			pegs[9]->AddPossibleMove(pegs[13], nineteen);
			pegs[9]->AddPossibleMove(pegs[14], twentyone);
			break;

		case 16:
			sixteen->AddPossibleMove(pegs[10], pegs[6]);
			sixteen->AddPossibleMove(seventeen, eighteen);
			pegs.push_back(sixteen);
			break;

		case 17:
			seventeen->AddPossibleMove(pegs[11], pegs[7]);
			seventeen->AddPossibleMove(eighteen, nineteen);
			pegs.push_back(seventeen);
			break;

		case 18:
			eighteen->AddPossibleMove(pegs[11], pegs[6]);
			eighteen->AddPossibleMove(pegs[12], pegs[8]);
			eighteen->AddPossibleMove(seventeen, sixteen);
			eighteen->AddPossibleMove(nineteen, twenty);
			pegs.push_back(eighteen);
			break;

		case 19:
			nineteen->AddPossibleMove(pegs[12], pegs[7]);
			nineteen->AddPossibleMove(pegs[13], pegs[9]);
			nineteen->AddPossibleMove(eighteen, seventeen);
			nineteen->AddPossibleMove(twenty, twentyone);
			pegs.push_back(nineteen);
			break;

		case 20:
			twenty->AddPossibleMove(pegs[13], pegs[8]);
			twenty->AddPossibleMove(nineteen, eighteen);
			pegs.push_back(twenty);
			break;

		case 21:
			twentyone->AddPossibleMove(pegs[14], pegs[9]);
			twentyone->AddPossibleMove(nineteen, eighteen);
			pegs.push_back(twentyone);
			break;

		default:
			break;
		}
	}
}

// Prints the information of each peg space
void CPegBoard::Print()
{
	for(unsigned int i = 0; i < pegs.size(); i++)
		pegs[i]->Print();
}

// Recomputes the valid moves and number of valid moves
void CPegBoard::Reset()
{
	numberOfValidMoves = 0;

	for(unsigned int i = 0; i < pegs.size(); i++)
		pegs[i]->Reset();

	Init();
}