#include "EmployeeTree.h"

#include <iostream>
#include <vector>

int main() {

    EmployeeTree tree;

    std::vector<Record> records =
        tree.readRecords("input/SampleInput.txt");

    Employee* ceo =
        tree.buildHierarchy(records);

    if (ceo == nullptr) {
        std::cout << "Failed to build hierarchy\n";
        return 1;
    }

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

    char target;

    std::cout << "\nEnter employee to search: ";
    std::cin >> target;

    Employee* found =
        tree.search(ceo, target);

    if (found != nullptr)
        std::cout << target
                  << " found in hierarchy\n";
    else
        std::cout << target
                  << " not found\n";

    char teammate =
        tree.getTeammate(ceo, target);

    if (teammate != 'X')
        std::cout << "Teammate: "
                  << teammate
                  << '\n';
    else
        std::cout << "No teammate found\n";

    return 0;
}