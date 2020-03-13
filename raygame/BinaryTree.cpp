#include "BinaryTree.h"
#include "raylib.h"
#include <stdio.h>


BinaryTree::BinaryTree()
{
	//Set the root to null
	m_pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const 
{
	//Return true if the root is null
	if (m_pRoot == nullptr) {
		return true;
	}
	return false;
}


void BinaryTree::insert(int a_nValue) 
{
	//If the tree is empty, the value is inserted at the root
	TreeNode*  NewNode = new TreeNode(a_nValue);

	if (isEmpty()) {
		m_pRoot = NewNode;
	}
	else {

		//Set the current node to thr root
		TreeNode* current;
		current = m_pRoot;
		TreeNode* parent;
		parent = current;
		//while the current node is not null
		while (current != nullptr)
		{
			//If the value to be inserted is less than the value on the current node
			if (a_nValue < current->getData()) {
				//Set the current node to the left child and continue
				parent = current;
				current = current->getLeft();
			}

			//If the value to be inserted is greater than the current node
			else if (a_nValue > current->getData()) {
				//Set the current node to the right child and continue
				parent = current;
				current = current->getRight();
			}

			//If the value to be inserted is the same as the value in the current node
			else if (a_nValue == current->getData()) {
				//Exit
				current = nullptr;
			}
		}//End of while

		//Get the parent of the current node(before it was set to null)
		if (a_nValue < parent->getData()) {
			parent->setLeft(NewNode);
		}
		else {
			parent->setRight(NewNode);
		}
	}
		
}

void BinaryTree::remove(int a_nValue) 
{
	//Find the value in the tree, obtaining a pointer to the node and its parent
	TreeNode* current;
	current = m_pRoot;
	TreeNode* parent;
	parent = current;

	TreeNode* RNode = nullptr;

	findNode(a_nValue, &current, &parent);
	//Return if node is not found
	TreeNode* Remove;
	Remove = find(a_nValue);
	if (current == nullptr) {
		return;
	}

	//If the current node has a right branch
	if (current->hasRight()) {
		//Find the minimum value in the right branch by iterating
		RNode = current->getRight();
		parent = current;
		while (RNode->hasLeft()) 
		{
			parent = RNode;
			RNode = RNode->getLeft();
		}
		current->setData(RNode->getData());
		//If we are deleting the parent's left node
		if (RNode == parent->getLeft()) {
			parent->setLeft(parent->getRight());
			delete RNode;
		}
		//If we are deleting the parents right node
		if (RNode == parent->getRight()) {
			parent->setRight(RNode->getLeft());
			delete RNode;
		}
	}
	//If the current has no right branch
	else if (!current->hasRight()) {
		//If we are deleting the parent's left child
		if (current == parent->getLeft()) {
			parent->setLeft(current->getLeft());
			delete current;
		}
		//If we are deleting the parent's right child
		if (current == parent->getRight()) {
			parent->setRight(current->getLeft());
			delete current;
		}
		//If we are deleting the root
		if (RNode == m_pRoot) {
			m_pRoot = current->getLeft();
			remove(current->getData());
		}
	}
}

TreeNode* BinaryTree::find(int a_nValue) 
{
	//Begin a search from the root node
	//Find the value in the tree, obtaining a pointer to the node and its parent
	TreeNode* current;
	TreeNode* parent;

	if (findNode(a_nValue,  (&current) , (&parent) )) {
		removeParent = parent;
		return current;
	}

	return nullptr;
}

void BinaryTree::draw(TreeNode* selected) 
{
	//Draw the root node
	draw(m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent) 
{//Set the current node to the root
	TreeNode* current;
	current = m_pRoot;
	TreeNode* parent;
	parent = current;

	//While the current node is not null
	while (current != nullptr) 
	{
		//If the search value equals the current node value
		if (a_nSearchValue < current->getData()) {
			//set the current node to the left child
			parent = current;
			current = current->getLeft();
		}
		//If the search value is less than the current node
		else if (a_nSearchValue > current->getData()) {
			//Set the current node to the right child
			parent = current;
			current = current->getRight();
		}
		else if (a_nSearchValue == current->getData()) {
			//Return the current node and its parent
			*ppOutNode = current;
			*ppOutParent = parent;			
			return true;
		}
	}
	return false;
}

void BinaryTree::draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected) 
{
	//Cut the horizontal spacing in half
	horizontalSpacing /= 2;

	if (pNode) {
		//Check for a left node
		if (pNode->hasLeft()) {
			//Draw a line to the left node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			draw(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Check for a right node
		if (pNode->hasRight()) {
			//Draw a line to the right node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draw the right node
			draw(pNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draw the current node
		pNode->draw(x, y, (selected == pNode));
	}
}
