// BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <exception>
#include <cassert>

namespace DataStructure {

	BinarySearchTree::BinarySearchTree() : mpRoot(nullptr)
	{
	}

	BinarySearchTree::BinarySearchTree(TreeNode* root) : mpRoot(root) {}

	BinarySearchTree::~BinarySearchTree()
	{
		makeEmpty(mpRoot);
	}

	BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
	{
		this->mpRoot = clone(tree.mpRoot);
	}

	BinarySearchTree& BinarySearchTree::operator= (const BinarySearchTree& tree)
	{
		this->mpRoot = clone(tree.mpRoot);
		return *this;
	}
	TreeNode* BinarySearchTree::contains(const int& x) const
	{
		return contains(x, mpRoot);
	}

	TreeNode* BinarySearchTree::contains(const int x, TreeNode* root) const
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (x < root->value)
		{
			return contains(x, root->left);
		}

		if (x > root->value)
		{
			return contains(x, root->right);
		}

		return root;
	}

	int BinarySearchTree::findMax() const
	{
		if (mpRoot != nullptr)
			return findMax(mpRoot)->value;
		else
			throw new std::exception("tree is null!");
	}

	TreeNode* BinarySearchTree::findMax(TreeNode* root) const
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->right != nullptr)
		{
			return findMax(root->right);
		}
		else
		{
			return root;
		}
	}

	int BinarySearchTree::findMin() const
	{
		if (mpRoot != nullptr)
		{
			return findMin(mpRoot)->value;
		}
		else
		{
			throw new std::exception("tree is null!");
		}
	}

	TreeNode* BinarySearchTree::findMin(TreeNode* root) const
	{
		if (root != nullptr)
		{
			while (root->left != nullptr)
			{
				root = root->left;
			}
		}
		return root;
	}

	void BinarySearchTree::insert(const int& x)
	{
		insert(x, mpRoot);
	}

	TreeNode* BinarySearchTree::insert(int x, TreeNode* root)
	{
		if (root == nullptr)
		{
			root = new TreeNode(x);
			return root;
		}

		if (x < root->value)
		{
			return insert(x, root->left);
		}

		if (x > root->value)
		{
			return insert(x, root->right);
		}
	}


	TreeNode* BinarySearchTree::find(const int& x) const
	{
		return find(x, mpRoot);
	}

	TreeNode* BinarySearchTree::find(const int x, TreeNode* root) const
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (x < root->value)
		{
			return find(x, root->left);
		}
		if (x > root->value)
		{
			return find(x, root->right);
		}
		return root;
	}

	void BinarySearchTree::remove(const int& x)
	{
		remove(x, mpRoot);
	}

	void BinarySearchTree::remove(int x, TreeNode* root)
	{
		TreeNode* delNode = find(x);
		if (delNode != nullptr)
		{
			if (delNode->left == nullptr && delNode->right == nullptr)
			{
				delete delNode;
				delNode = nullptr;
			}
			else if (delNode->left != nullptr && delNode->right != nullptr)    //有待删除节点有两个子节点，删除时找到该节点的右子树中的最小节点，或者左子树的最大节点，用该节点作为删除节点的替代节点。这样才能保持二叉查找树的查找性质
			{
				TreeNode* node = findMin(delNode->right);
				delNode->value = node->value;             //明显，这里只需要用新节点的值代替待删除节点的值即可，而不必去破坏节点结构。
				delete node;
				node = nullptr;
			}
		}
	}

	bool BinarySearchTree::isEmpty() const
	{
		return mpRoot != nullptr;
	}

	void BinarySearchTree::makeEmpty(TreeNode*& root)
	{
		if (root != nullptr)
		{
			if (root->left != nullptr)
			{
				makeEmpty(root->left);
			}
			if (root->right != nullptr)
			{
				makeEmpty(root->right);
			}
			delete root;
			root = nullptr;
		}

	}

	TreeNode* BinarySearchTree::clone(TreeNode* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		return new TreeNode(root->value, clone(root->left), clone(root->right));  //巧妙！
	}

	void AVLTree::insert(const int& x)
	{
		
	}
}