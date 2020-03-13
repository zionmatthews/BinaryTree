#pragma once
class TreeNode
{
public:
	//Deconstructers
	TreeNode(int value) { m_value = value; }
	~TreeNode();

	//Returns left and right 
	bool hasLeft() { return (m_left != nullptr); }
	bool hasRight() { return (m_right != nullptr); }

	//Gets Data
	int getData() { return m_value; }

	//Gets left and right
	TreeNode* getLeft() { return m_left; }
	TreeNode* getRight() { return m_right; }

	//Sets the left, right and data of the node
	void setData(int value) { m_value = value;  }
	void setLeft(TreeNode* node) { m_left = node; }
	void setRight(TreeNode* node) { m_right = node; }

	// Draws the nods circle around the number
	void draw(int x, int y, bool selected = false);

private:
	//data this node stores
	int m_value;

	//this node's children
	TreeNode* m_left;
	TreeNode* m_right;
};
