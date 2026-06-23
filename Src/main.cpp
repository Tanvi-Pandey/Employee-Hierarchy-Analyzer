#include "EmployeeTree.h"

#include <iostream>
#include <vector>

int main() {

    EmployeeTree tree;

    std::vector<Record> records =
        tree.readRecords("input/SampleInput.txt");

    Employee* ceo =
        tree.buildHierarchy(records);

    std::cout << "CEO: "
              << ceo->id
              << "\n\n";

    std::cout << "Inorder: ";
    tree.inorder(ceo);

    std::cout << "\nPreorder: ";
    tree.preorder(ceo);

    std::cout << "\nPostorder: ";
    tree.postorder(ceo);

    std::cout << "\n\nEmployees: "
              << tree.countEmployees(ceo);

    std::cout << "\nManagers: "
              << tree.countManagers(ceo);

    std::cout << "\nHeight: "
              << tree.height(ceo);

    std::cout << '\n';

    return 0;
}