#include "PegSpace.h"
#include "PegBoard.h"
#include "PegGameTree.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main()
{
	CPegBoard board;

	CNode* node = new CNode();
	node->board = board;

	CPegGameTree gameTreeSmall;
	CPegGameTree gameTreeLarge;

	gameTreeSmall.Insert(gameTreeSmall.head, node);
	gameTreeSmall.Populate(node);

	cout << "Games with one peg left: " << gameTreeSmall.onePegLeft << endl;
	cout << "Games with one peg left in corner: " << gameTreeSmall.onePegInCorner << endl;
	cout << "Size: " << gameTreeSmall.size << endl;
	board.AddRow();
	node->board = board;
	node->children.clear();
	
	gameTreeLarge.Insert(gameTreeLarge.head, node);
	gameTreeLarge.Populate(node);

	cout << "Games with one peg left: " << gameTreeLarge.onePegLeft << endl;
	cout << "Games with one peg left in corner: " << gameTreeLarge.onePegInCorner << endl;

	system("pause");
	return 0;
}