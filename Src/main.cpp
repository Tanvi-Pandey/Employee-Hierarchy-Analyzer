#include "EmployeeTree.h"

int main() {

    Employee* J = new Employee('J');
    Employee* F = new Employee('F');
    Employee* N = new Employee('N');
    Employee* L = new Employee('L');
    Employee* P = new Employee('P');
    Employee* T = new Employee('T');

    J->left = F;
    J->right = N;

    N->left = L;
    N->right = P;

    P->right = T;

    EmployeeTree tree;

    std::cout << "Inorder: ";
    tree.inorder(J);

    std::cout << "\nPreorder: ";
    tree.preorder(J);

    std::cout << "\nPostorder: ";
    tree.postorder(J);

    std::cout << std::endl;

    return 0;
}