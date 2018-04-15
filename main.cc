#include <limits>
#include "BinaryTree.cc"

int main() {
	std::cout << "Integer Binary Tree!" << std::endl;
	std::cout << "Instruction!\n" << "Press the following number commands:\n" 
		<< "1. Insert\n" << "2. Print\n" << "3. Search\n" 
		<< "4. Remove\n" << "7. Quit\n";
		
	BinaryTree<int> bt;
	char input;
	int data;
	while(true) {
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		switch(input) {
			case '1':
			std::cin >> data;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			break;
			case '2':
			bt.print();
			break;
			case '3':
			
			break;
			case '4':
			
			break;
			
			case '7':
			exit(EXIT_SUCCESS);
			default:
			break;
		}
	}
	return 0;
}
