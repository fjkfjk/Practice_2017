// BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
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
			else if (delNode->left != nullptr && delNode->right != nullptr)    //�д�ɾ���ڵ��������ӽڵ㣬ɾ��ʱ�ҵ��ýڵ���������е���С�ڵ㣬���������������ڵ㣬�øýڵ���Ϊɾ���ڵ������ڵ㡣�������ܱ��ֶ���������Ĳ�������
			{
				TreeNode* node = findMin(delNode->right);
				delNode->value = node->value;             //���ԣ�����ֻ��Ҫ���½ڵ��ֵ�����ɾ���ڵ��ֵ���ɣ�������ȥ�ƻ��ڵ�ṹ��
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
		return new TreeNode(root->value, clone(root->left), clone(root->right));  //���
	}

	void AVLTree::insert(const int& x)
	{
		
	}
}