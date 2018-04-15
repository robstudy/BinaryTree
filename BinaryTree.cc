#include <iostream>

template <class T>
class BinaryTree {
	public: 
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
};