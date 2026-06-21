#ifndef EMPLOYEE_TREE_H
#define EMPLOYEE_TREE_H

#include <iostream>

struct Employee {
    char id;
    Employee* left;
    Employee* right;

    Employee(char value)
        : id(value), left(nullptr), right(nullptr) {}
};

class EmployeeTree {
public:
    void inorder(Employee* root);
    void preorder(Employee* root);
    void postorder(Employee* root);

    int height(Employee* root);
    int countManagers(Employee* root);
    int countEmployees(Employee* root);
};

#endif