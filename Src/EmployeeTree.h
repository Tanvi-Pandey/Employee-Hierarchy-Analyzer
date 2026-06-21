#ifndef EMPLOYEE_TREE_H
#define EMPLOYEE_TREE_H

struct Employee {
    char id;
    Employee* left;
    Employee* right;

    Employee(char value) : id(value), left(nullptr), right(nullptr) {}
};

#endif