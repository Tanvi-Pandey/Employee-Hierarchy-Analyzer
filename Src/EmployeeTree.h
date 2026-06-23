#ifndef EMPLOYEE_TREE_H
#define EMPLOYEE_TREE_H

#include <iostream>
#include <vector>
#include <string>

struct Employee {
    char id;
    Employee* left;
    Employee* right;

    Employee(char value)
        : id(value), left(nullptr), right(nullptr) {}
};

struct Record {
    char manager;
    char leftEmployee;
    char rightEmployee;
};

class EmployeeTree {
public:
    void inorder(Employee* root);
    void preorder(Employee* root);
    void postorder(Employee* root);

    int height(Employee* root);
    int countEmployees(Employee* root);
    int countManagers(Employee* root);

    std::vector<Record> readRecords(const std::string& filename);

    Employee* buildHierarchy(const std::vector<Record>& records);

    Employee* search(Employee* root, char employeeId);

    Employee* findParent(Employee* root, char employeeId);

    char getTeammate(Employee* root, char employeeId);

    bool isBST(Employee* root);

    bool isBSTUtil(Employee* root,
                char minValue,
                char maxValue);
};

#endif