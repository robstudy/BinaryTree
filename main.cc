#include <limits>
#include "BinaryTree.cc"

int main() {
	std::cout << "Integer Binary Tree!" << std::endl;
	std::cout << "Instruction!\n" << "Press the following number commands:\n" 
		<< "1. Insert\n" << "2. Print\n" << "3. Search\n" 
		<< "4. Remove\n" << "5. Max\n" << "6. Min\n" << "7. Quit\n";
		
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
			bt.insert(data);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			break;
			case '2':
			bt.print();
			break;
			case '3':
			std::cin >> data;
			if(bt.search(data)) std::cout << data << " in tree!\n";
			else std::cout << data << " not in tree.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			break;
			case '4':
			
			break;
			case '5':
			std::cout << "The max element is: " << bt.Max() << std::endl;
			break;
			case '6':
			std::cout << "The minimum element is: " << bt.Min() << std::endl;
			break;
			case '7':
			exit(EXIT_SUCCESS);
			default:
			break;
		}
	}
	return 0;
}
