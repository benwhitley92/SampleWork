// PegGameTree.h: Defines a tree which holds all possible game moves
#pragma once

class CPegBoard;
class CNode;

class CPegGameTree
{
public:
	CPegGameTree();
	~CPegGameTree();

	void Insert(CNode* parent, CNode* child);
	void Populate(CNode* currentNode);

	CNode* head;
	int size, onePegLeft, onePegInCorner;
};