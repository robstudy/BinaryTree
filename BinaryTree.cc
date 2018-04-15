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
	//Leaf struct and functions
	struct Leaf {
		T data;
		Leaf *left;
		Leaf *right;
	};
	void deleteAllLeaves(Leaf *leaf);
	void printLeaf(Leaf *leaf);
	
	//root leaf and size
	Leaf *root;
	int size;
	
};

template <class T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
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

template <class T>
void BinaryTree<T>::print(){
	printLeaf(root);
	std::cout << std::endl;
};

template <class T>
void BinaryTree<T>::printLeaf(Leaf *leaf) {
	if(leaf == NULL) return;
	printLeaf(leaf->left);
	printLeaf(leaf->right);
	std::cout << leaf->data << " ";
};