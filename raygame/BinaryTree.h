#pragma once
#include "TreeNode.h"
#include "raylib.h"
class BinaryTree
{
public:
	//Deconstructers
	BinaryTree();
	~BinaryTree();

	//Checks if the node is empty
	bool isEmpty() const;

	//Inserts a value into the node
	void insert(int a_nValue);

	//Removes a value from the node
	void remove(int a_nValue);

	//A function that finds the value in the tree
	TreeNode* find(int a_nValue);

	TreeNode* removeParent;
	
	//Draws the root of the node
	void draw(TreeNode* selected = nullptr);

private:
	//A function the finds the node in the binary tree
	bool findNode(int a_nSearchValue, TreeNode** pp0utNode, TreeNode** ppOutParent);

	//A function that draws the binary tree
	void draw(TreeNode* pNode, int x, int y, int  horizontalSpacing, TreeNode* selected = nullptr);

	//The root node of the tree
	TreeNode* m_pRoot;
};

