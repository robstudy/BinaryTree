#pragma once
#include <iostream>

template <class T>
struct Leaf {
	T data;
	Leaf *left;
	Leaf *right;
	Leaf(T d = NULL, Leaf *l = NULL, Leaf *r = NULL):
		data(d),
		left(l),
		right(r){}
};

template <class T>
class BinaryTree {
	public: 
		//constructor
		BinaryTree<T>();
		//destructor
		~BinaryTree<T>();
		//public functions
		void insert(T);
		void Remove(T);
		void print();
		bool search(T);
		//Max and Min
		T Max();
		T Min();
		//Size and Count Nodes
		int Size();
		int CountNodes();
	private:
	//Leaf struct and functions
	void deleteAllLeaves(Leaf<T> *&);
	void insertLeaf(Leaf<T> *&, T);
	void printLeaf(Leaf<T> *);
	Leaf<T>* MinNode(Leaf<T> *);
	Leaf<T>* RemoveLeaf(Leaf<T> *, T);
	bool searchLeaf(Leaf<T> *, T);
	int rCountNodes(Leaf<T> *);
	
	//root leaf and size
	Leaf<T> *root;
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
void BinaryTree<T>::deleteAllLeaves(Leaf<T> *&leaf){
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
void BinaryTree<T>::insertLeaf(Leaf<T> *&leaf, T data) {
	if(leaf == nullptr) {
		leaf = new Leaf<T>(data, NULL, NULL);
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
void BinaryTree<T>::printLeaf(Leaf<T> *leaf) {
	//Inorder-tree-walk
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
bool BinaryTree<T>::searchLeaf(Leaf<T> *leaf, T data) {
	if(!leaf) return false;
	if(leaf->data == data) return true;
	if(leaf->data < data) searchLeaf(leaf->right, data);
	else searchLeaf(leaf->left, data);
};

//Max and Min
template <class T>
T BinaryTree<T>::Max(){
	Leaf<T> *tmp = root;
	while(tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->data;
};

template <class T>
T BinaryTree<T>::Min() {
	Leaf<T> *tmp = root;
	while(tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->data;
};

template <class T>
Leaf<T>* BinaryTree<T>::MinNode(Leaf<T> *leaf) {
	if(leaf == NULL) return NULL;
	if(leaf->left != NULL) return MinNode(leaf->left);
	return leaf;
};

//Size and CountNodes/rCountNodes
template <class T>
int BinaryTree<T>::CountNodes() {
	return rCountNodes(root);
};

template <class T>
int BinaryTree<T>::rCountNodes(Leaf<T> *leaf){
	//Count number of nodes
	if(leaf == NULL) return 0; //empty
	else {
		int count = 1;
		count += rCountNodes(leaf->left);
		count += rCountNodes(leaf->right);
		return count; //total
	}
}; 

template <class T>
int BinaryTree<T>::Size() {
	return size;
};

//Remove and RemoveLeaf
template <class T>
void BinaryTree<T>::Remove(T data) {
	root = RemoveLeaf(root, data);
};

template <class T>
Leaf<T>* BinaryTree<T>::RemoveLeaf(Leaf<T> *leaf, T data) {
	if(leaf == NULL) {
		return NULL;
	}
	if (leaf->data > data) {
		leaf->left = RemoveLeaf(leaf->left,data);
	} else if (leaf->data < data) {
		leaf->right = RemoveLeaf(leaf->right, data);
	} else {
		//case 1: no children;
		if (leaf->left == NULL && leaf->right == NULL) {
			delete leaf;
			leaf = NULL;
			return leaf;
		}
		//case 2: 1 child (right)
		else  if (leaf->left == NULL) {
			Leaf<T> *tmp = leaf;
			leaf = leaf->right;
			delete(tmp);
		} 
		//case 3: 1 child (left)
		else if (leaf->right == NULL) {
			Leaf<T> *tmp = leaf;
			leaf = leaf->left;
			delete(tmp);
		}
		//case 4: 2 children
		else {
			Leaf<T>* tmp = MinNode(leaf->right);
			leaf->data = tmp->data;
			leaf->right = RemoveLeaf(leaf->right, tmp->data);
		}
	}
		
	return leaf;
};