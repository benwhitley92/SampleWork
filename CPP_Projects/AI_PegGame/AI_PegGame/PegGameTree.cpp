#include "PegGameTree.h"
#include "PegBoard.h"
#include "Node.h"

// Constructor
CPegGameTree::CPegGameTree()
{
	size = 0;
	onePegLeft = 0;
	onePegInCorner = 0;

	head = new CNode();
}

CPegGameTree::~CPegGameTree()
{
	delete head;
	head = NULL;
}

// Inserts a child node for the parent
void CPegGameTree::Insert(CNode* parent, CNode* child)
{
	if(size == 0)
	{
		head = parent;
		parent->parent = NULL;
	}

	else
	{
		child->parent = parent;
		parent->children.push_back(child);
	}

	size++;
}

void CPegGameTree::Populate(CNode* currentNode)
{
	CNode* tempNode;
	CPegBoard tempBoard;
	for(int i = 0; i < currentNode->board.GetNumberOfValidMoves(); i++)
	{
		tempBoard = currentNode->board;
		tempBoard.DoValidMove(i);
		tempBoard.Reset();
		tempNode->board = tempBoard;
		Insert(currentNode, tempNode);

		if(tempBoard.isDone())
		{
			if(tempBoard.NumberOfPegsLeft() == 1)
			{
				onePegLeft++;
				int pegNumber = tempBoard.GetLastPegNumber();
				if(!tempBoard.rowIsAdded)
				{
					if(pegNumber == 1 || pegNumber == 11 || pegNumber == 15)
						onePegInCorner++;
				}

				else
				{
					if(pegNumber == 1 || pegNumber == 16 || pegNumber == 21)
						onePegInCorner++;
				}
			}
		}

		Populate(tempNode);
	}
}