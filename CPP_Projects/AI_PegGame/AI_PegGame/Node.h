// Node.h: Defines a node in a tree
#pragma once

#include "PegBoard.h"
#include <vector>
using namespace std;

class CNode
{
public:
	CNode() {}

	CNode* parent;
	vector<CNode*> children;

	CPegBoard board;
};