#include <iostream>

template <class T>
class BinaryTree {
	public: 
		//constructor
		BinaryTree<T>();
		//destructor
		~BinaryTree<T>();
		//public functions
		void insert(T);
		void remove(T);
		void print();
		bool search(T);
	private:
	//Leaf struct and functions
	struct Leaf {
		T data;
		Leaf *left;
		Leaf *right;
		Leaf(T d = NULL, Leaf *l = NULL, Leaf *r = NULL):
			data(d),
			left(l),
			right(r){}
	};
	void deleteAllLeaves(Leaf *&);
	void insertLeaf(Leaf *&, T);
	void printLeaf(Leaf *);
	bool searchLeaf(Leaf *, T);
	
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
void BinaryTree<T>::deleteAllLeaves(Leaf *&leaf){
	if(leaf == NULL) return;
	deleteAllLeaves(leaf->left);
	deleteAllLeaves(leaf->right);
	delete leaf;
};

template <class T>
void BinaryTree<T>::insert(T data){
	insertLeaf(root, data);
};

template <class T>
void BinaryTree<T>::insertLeaf(Leaf *&leaf, T data) {
	if(leaf == nullptr) {
		leaf = new Leaf(data, NULL, NULL);
		size++;
		return;
	}
	else if (leaf->data < data) insertLeaf(leaf->right, data);
	else insertLeaf(leaf->left, data);
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
	std::cout << leaf->data << " ";
	printLeaf(leaf->right);
};

template <class T>
bool BinaryTree<T>::search(T data) {
	searchLeaf(root, data);
};

template <class T>
bool BinaryTree<T>::searchLeaf(Leaf *leaf, T data) {
	if(!leaf) return false;
	if(leaf->data == data) return true;
	if(leaf->data < data) searchLeaf(leaf->right, data);
	else searchLeaf(leaf->left, data);
};