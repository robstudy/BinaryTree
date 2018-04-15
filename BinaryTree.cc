#include <iostream>

template <class T>
class BinaryTree {
	public: 
		//constructor
		BinaryTree<T>();
		//destructor
		~BinaryTree<T>();
		void insert(T);
		void remove(T);
		bool search(T);
		void print();
	private:
	struct Leaf {
		T data;
		Leaf *left;
		Leaf *right;
	};
	Leaf *root;
	void deleteAllLeaves(Leaf *leaf);
	int size;
};

template <class T>
BinaryTree<T>::BinaryTree() {
	size = 0;
};

template <class T>
BinaryTree<T>::~BinaryTree() {
	deleteAllLeaves(root);
};
template <class T>
void BinaryTree<T>::deleteAllLeaves(Leaf *leaf){
	if(leaf == NULL) return;
	deleteAllLeaves(leaf->left);
	deleteAllLeaves(leaf->right);
	delete leaf;
};