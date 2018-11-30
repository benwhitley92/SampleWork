// Binary Search Tree

#pragma once

#include <cstdlib>

class CBinarySearchTree
{
private:
	// Define each node of the tree
	struct TreeNode
	{
		TreeNode* left;
		TreeNode* right;
		int data;
	};

	// Define the root of the tree
	TreeNode* root;
	int size;

public:
	// Constructor
	CBinarySearchTree() { size = 0; }

	// Tree state functions
	void Insert(int);
	void Remove(int);
	
	// Tree traversal functions
	void PreOrder(TreeNode*);
	void InOrder(TreeNode*);
	void PostOrder(TreeNode*);

	// Printing functions
	void PrintPreOrder();
	void PrintInOrder();
	void PrintPostOrder();
};