#pragma once

namespace DataStructure {

	struct TreeNode
	{
		int value;
		TreeNode* left;
		TreeNode* right;

		TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
		TreeNode(int val, TreeNode* l, TreeNode* r) : value(val), left(l), right(r) {}
	};

	class BinarySearchTree
	{
	public:
		BinarySearchTree();
		BinarySearchTree(TreeNode* root);
		virtual ~BinarySearchTree();
		BinarySearchTree(const BinarySearchTree& tree);
		BinarySearchTree& operator= (const BinarySearchTree& tree);

		TreeNode* contains(const int& x) const;

		int findMax() const;

		int findMin() const;

		virtual void insert(const int& x);

		virtual void remove(const int& x);

		TreeNode* find(const int& x) const;

		bool isEmpty() const;

		void makeEmpty(TreeNode*& root);

		virtual TreeNode* clone(TreeNode* root);

	protected:
		TreeNode* getRoot() {
			return mpRoot;
		}

	private:
		TreeNode* mpRoot;

		TreeNode* contains(const int x, TreeNode* root) const;
		TreeNode* findMax(TreeNode* root) const;
		TreeNode* findMin(TreeNode* root) const;
		TreeNode* find(const int x, TreeNode* root) const;
		TreeNode* insert(int x, TreeNode* root);
		void remove(int x, TreeNode* root);
	};

	class AVLTree : public BinarySearchTree
	{
	public:
		AVLTree() {}
		AVLTree(TreeNode* root) : BinarySearchTree(root) {}

		virtual ~AVLTree() {
			BinarySearchTree::~BinarySearchTree();
		}

		virtual void insert(const int& x) override;
		virtual void remove(const int& x) override;

	private:
		TreeNode* insert(const int& x, TreeNode* root);
	};


	class RBTree : AVLTree
	{


	};




}