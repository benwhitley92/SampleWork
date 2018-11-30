#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

// Tree state functions
void CBinarySearchTree::Insert(int data)
{
	TreeNode* temp = new TreeNode;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	TreeNode* parent;

	// Is it a new tree?
	if(size == 0)
	{
		root = temp;
		size++;
	}

	else
	{
		TreeNode* current;
		current = root;

		// Find the node's parent
		while(current)
		{
			parent = current;
			if(temp->data > current->data)
				current = current->right;

			else
				current = current->left;
		}

		if(temp->data < parent->data)
			parent->left = temp;

		else 
			parent->right = temp;

		size++;
	}
}

void CBinarySearchTree::Remove(int data)
{
	bool found = false;

	// Check if the tree is empty
	if(size == 0)
	{
		cout << "The tree is already empty!\n";
		return;
	}

	// Locate the element
	TreeNode* current;
	TreeNode* parent;
	current = root;

	while(current != NULL)
	{
		if(current->data == data)
		{
			found = true;
			break;
		}

		else
		{
			parent = current;
			if(data > current->data)
				current = current->right;

			else
				current = current->left;
		}
	}

	// Handle data not found
	if(!found)
	{
		cout << "Data not found!\n";
		return;
	}

	// 3 cases:
	//		1. We're removing a leaf node
	//		2. We're removing a node with a single child
	//		3. We're removing a node with two children
	
	// Single Child
	if((current->right == NULL && current->left != NULL) || (current->right != NULL && current->left == NULL))
	{
		if(current->left == NULL && current->right != NULL)
		{
			if(parent->left == current)
			{
				parent->left = current->right;
				delete current;
			}

			else
			{
				parent->right = current->right;
				delete current;
			}
		}

		else
		{
			if(parent->left == current)
			{
				parent->left = current->left;
				delete current;
			}

			else
			{
				parent->right = current->left;
				delete current;
			}
		}

		size--;
		return;
	}

	// Leaf Node
	if(current->left == NULL && current->right == NULL)
	{
		if(parent->left == current)
			parent->left = NULL;

		else 
			parent->right = NULL;

		delete current;

		size--;
		return;
	}

	// Two Children - replace with bottom-right node of left child
	if(current->left != NULL && current->right != NULL)
	{
		TreeNode* chkr;
		chkr = current->right;

		if((chkr->left == NULL) && (chkr->right == NULL))
		{
			current = chkr;
			delete chkr;
			current->right = NULL;
		}

		// Right has some children
		else
		{
			// If the node's right child has left children,
			// Move all the way down left and find the smallest
			if((current->right)->left != NULL)
			{
				TreeNode* lCurrent;
				TreeNode* lCurrentp;
				lCurrentp = current->right;
				lCurrent = (current->right)->left;

				while(lCurrent->left != NULL)
				{
					lCurrentp = lCurrent;
					lCurrent = lCurrent->left;
				}

				current->data = lCurrent->data;
				delete lCurrent;
				lCurrentp->left = NULL;
			}

			else
			{
				TreeNode* temp;
				temp = current->right;
				current->data = temp->data;
				current->right = temp->right;
				delete temp;
			}
		}

		size--;
		return;
	}
}
	
// Tree traversal functions
void CBinarySearchTree::PreOrder(TreeNode* p)
{
	if(p != NULL)
	{
		cout << " " << p->data << " ";

		if(p->left)
			PreOrder(p->left);

		if(p->right)
			PreOrder(p->right);
	}
}
void CBinarySearchTree::InOrder(TreeNode* p)
{
	if(p != NULL)
	{

		if(p->left)
			InOrder(p->left);

		cout << " " << p->data << " ";

		if(p-> right)
			InOrder(p->right);
	}
}
void CBinarySearchTree::PostOrder(TreeNode* p)
{
	if(p != NULL)
	{

		if(p->left)
			PostOrder(p->left);

		if(p-> right)
			PostOrder(p->right);

		cout << " " << p->data << " ";
	}
}

// Printing functions
void CBinarySearchTree::PrintPreOrder()
{
	PreOrder(root);
}

void CBinarySearchTree::PrintInOrder()
{
	InOrder(root);
}

void CBinarySearchTree::PrintPostOrder()
{
	PostOrder(root);
}

int main()
{
	CBinarySearchTree b;

	int ch, tmp, tmp1;

	while(1)
	{
		cout << "\n\n";
		cout << " Binary Search Tree Operations \n";
		cout << " 1. Insertion/Creation \n";
		cout << " 2. Pre-Order Traversal \n";
		cout << " 3. In-Order Traversal \n";
		cout << " 4. Post-Order Traversal \n";
		cout << " 5. Removal \n";
		cout << " 6. Exit \n";

		cout << " Enter your choice: ";
		cin >> ch;

		switch(ch)
		{
		case 1:
			cout << " Enter number to be entered: ";
			cin >> tmp;
			b.Insert(tmp);
			break;

		case 2:
			cout << " Pre-Order Traversal \n";
			cout << "---------------------\n";
			b.PrintPreOrder();
			break;

		case 3:
			cout << " In-Order Traversal \n";
			cout << "--------------------\n";
			b.PrintInOrder();
			break;

		case 4:
			cout << " Post-Order Traversal \n";
			cout << "----------------------\n";
			b.PrintPostOrder();
			break;

		case 5:
			cout << " Enter a number to be removed: ";
			cin >> tmp1;
			b.Remove(tmp1);
			break;

		case 6:
			cout << " Exiting \n";
			return 0;
		
		default:
			cout << "You entered a wrong choice.\n";
			break;
		}
	}
}