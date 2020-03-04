#include "BinaryTree.h"
#include "raylib.h"


BinaryTree::BinaryTree()
{
	//Set the root to null
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


void BinaryTree::insert(int a_Value) 
{
	//If the tree is empty, the value is inserted at the root
	if (m_pRoot == nullptr) {
		m_pRoot->setData = a_Value;
	}
	//Set the current node to thr root
	TreeNode* current;
	current = m_pRoot;
	//while the current node is not null
	while (m_pRoot != nullptr) 
	{
		//If the value to be inserted is less than the value on the current node
		if (a_Value < current->getData) {
			//Set the current node to the left child and continue
			current = current->getLeft;
		}

		//If the value to be inserted is greater than the current node
		if (a_Value > current->getData) {
			//Set the current node to the right child and continue
			current = current->getRight;
		}

		//If the value to be inserted is the same as the value in the current node
		if (a_Value = m_pRoot->getData) {
			//Exit
			break;
		}
	}
}

void BinaryTree::remove(int a_Value) 
{

}

TreeNode* BinaryTree::find(int a_Value) 
{
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected) 
{
	//Draw the root node
	draw(m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent) 
{

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
