#ifndef __MRR_THREADED_BINARY_TREE__
#define __MRR_THREADED_BINARY_TREE__

//===========================================================================
// Author: Matt Renaud
// The following is an implementation of a threaded binary tree.
//===========================================================================

#include <stdio.h>
#include <string.h>

//===========================================================================
// ThreadedBinaryTreeNode Class.
//===========================================================================
template <typename T>
class ThreadedBinaryTreeNode
{
public:
  T datum_;
  ThreadedBinaryTreeNode * left_;
  ThreadedBinaryTreeNode * right_;
  bool isSet_;
  bool isThreadedLeft;
  bool isThreadedRight;
  ThreadedBinaryTreeNode * tLeft_;
  ThreadedBinaryTreeNode * tRight_;
};


//===========================================================================
// ThreadedBinaryTree Class.
//===========================================================================
template <typename T>
class ThreadedBinaryTree
{
  typedef ThreadedBinaryTreeNode<T> Node;
  Node * root_;

public:
  BinaryTree()
    : root_(new Node())
  { }

  Node * insert(Node * node, Node * parent, T val)
  {
    if(!root_->isSet_)
    {
      root_ = new Node(val);
      return root_;
    }
    if(node == nullptr)
    {
      Node * newnode = new Node(val);
      if(val < parent->datum_)
      {
	parent->left_ = newnode;
	return newnode;
      }
      else
      {
	parent->right_ = newnode;
	return newnode;
      }
    }
    else if(val < node->datum_)
      insert(node->left_, node, val);
    else
      insert(node->right_, node, val);

  } // insert()

  Node * insert(T val)
  {
    return insert(root_, nullptr, val);
  }

  bool isElement(Node * node, T val)
  {
    if(node == nullptr)
      return false;
    if(node->datum_ == val)
      return true;
    else if(val < node->datum_)
      return isElement(node->left_, val);
    else
      return isElement(node->right_, val);
  } // isElement()

  void print(std::string s = "")
  {
    print(root_, s);
  }

  void print(Node * n, std::string s = "")
  {
    if(n == NULL)
      return;
    print(n->left_, s + "l");
    std::cout << s << " - " << (n->datum_) << std::endl;
    print(n->right_, s + "r");
  } // print()

  T min()
  {
    Node * cur = root_;

    while(cur->left_ != nullptr)
      cur = cur->left_;

    return cur->datum_;
  }

  T max()
  {
    Node * cur = root_;

    while(cur->right_ != nullptr)
      cur = cur->right_;

    return cur->datum_;
  }

  unsigned depth(Node * cur)
  {

    if(cur == nullptr)
      return 0;

    return 1 + std::max(depth(cur->left_), depth(cur->right_));
  }

  unsigned depth()
  {
    return depth(root_);
  }
};
};



#endif // __MRR_THREADED_BINARY_TREE__
