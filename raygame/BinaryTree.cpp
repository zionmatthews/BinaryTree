#include "BinaryTree.h"
#include "raylib.h"


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

	//Return if node is not found
	TreeNode* Remove;
	Remove = find(a_nValue);
	if (Remove == nullptr) {
		return;
	}

	while (current != nullptr) 
	{
		//Find the minimum value in the  right branch by iterating
		if (Remove->hasRight()) {
			current = Remove->getRight();
			parent = current;

			while (current->hasLeft()) 
			{
				parent = current;
				current = current->getLeft();
			}
			Remove = current;
		}
		else {
			if (parent->getLeft() == Remove) {
				parent->setLeft(current->getLeft());
			}

			else if (parent->getRight() == Remove) {
				parent->setRight(current->getRight());
			}

			else if (parent->getData() == a_nValue) {
				current->setLeft(m_pRoot);
			}
		}
	}
}

TreeNode* BinaryTree::find(int a_nValue) 
{
	//Begin a search from the root node
	//Find the value in the tree, obtaining a pointer to the node and its parent
	TreeNode* current;
	current = m_pRoot;
	TreeNode* parent;
	parent = nullptr;

	if (findNode(a_nValue, &current, &parent)) {
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
{
	//Set the current node to the root

	//While the current nod eis not null
	        //If the search value equals the current node value,
	              //Return the current node and its parent
	        //Otherwise
	      //If the search value is less than the current node
	                   //Set the current node to the left child
	          //Otherwise
	                    //Set the current node to the right child
	//End while
	//If the loop exists, then a match was not found, so return false
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
