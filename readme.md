Zion Matthews
:-
s198031
Assessment 4
BinaryTree

## I. Design

3. ### Object Information

 **File**: Binary.h
 
 Description: Header for the binary class.
 
 **Attributes**
 
      Name: BinaryTree()/~BinaryTree()
      Description: Deconstruters
      Type: Function
      
      Name: isEmpty
      Description: checks if the node is empty
      Type: bool
      
      Name: remove
      Description: removes a value from the node
      Type: function
      
      Name: find
      Description: a function that finds the value in the tree
      Type: function
      
      Name: removeParent
      Description: Removes the parent from the node
      Type: variable
      
      Name: draw
      Description: a function that draws the binary tree and the root of the node
      Type: function
      
      Name: findNode
      Description: A function that finds the node in the binary tree
      Type: function
      
      Name: m_pRoot
      Description: the root node of the tree
      Type: variable
      
  **File**: TreeNode.h
  
  Description: Header for TreeNode class
  
  **Attributes**
  
      Name: ~TreeNode
      Description: Deconstructor
      Type: func
      
      Name: hasleft/hasright
      Description: Returns left/ returns right
      Type: bool
      
      name: getdata
      Description: Gets data
      Type: int
      
      Name: getleft/getright
      Description: gets left and right
      Type: variable
      
      Name: setdata/setleft/setright
      Description: Sets the left, right and data of the node
      Type: function
      
      Name: draw
      Description: Draws the nods circle around the number
      Type: function
      
      name: m_value
      description: dtat this node stores
      Type: int
      
      name: m_left / m_right
      description: the node's children
      type: variable

## License

MIT License - Copyright (c) 2018 Academy of Interactive Entertainment

For more information, see the [license][lic] file.

Third party works are attributed under [thirdparty.md][3p].

[lic]:license.md
[3p]:thirdparty.md
[raylib]:https://github.com/raysan5/raylib
