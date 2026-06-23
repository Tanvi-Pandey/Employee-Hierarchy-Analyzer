#include "EmployeeTree.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

void EmployeeTree::inorder(Employee* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->id << " ";
    inorder(root->right);
}

void EmployeeTree::preorder(Employee* root) {
    if (root == nullptr)
        return;

    std::cout << root->id << " ";
    preorder(root->left);
    preorder(root->right);
}

void EmployeeTree::postorder(Employee* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    std::cout << root->id << " ";
}

int EmployeeTree::height(Employee* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

int EmployeeTree::countEmployees(Employee* root) {
    if (root == nullptr)
        return 0;

    return 1 +
           countEmployees(root->left) +
           countEmployees(root->right);
}

int EmployeeTree::countManagers(Employee* root) {
    if (root == nullptr)
        return 0;

    int current = 0;

    if (root->left != nullptr || root->right != nullptr)
        current = 1;

    return current +
           countManagers(root->left) +
           countManagers(root->right);
}

std::vector<Record> EmployeeTree::readRecords(const std::string& filename) {

    std::ifstream file(filename);

    std::vector<Record> records;

    if (!file.is_open()) {
        std::cerr << "Could not open file\n";
        return records;
    }

    char search1, search2;
    file >> search1 >> search2;

    Record temp;

    while (file >> temp.manager
                >> temp.leftEmployee
                >> temp.rightEmployee) {

        records.push_back(temp);
    }

    file.close();

    return records;}

    Employee* EmployeeTree::buildHierarchy(const std::vector<Record>& records) {

    std::unordered_map<char, Employee*> employees;
    std::unordered_set<char> children;

    for (const auto& record : records) {

        if (employees.find(record.manager) == employees.end())
            employees[record.manager] = new Employee(record.manager);

        Employee* manager = employees[record.manager];

        if (record.leftEmployee != 'X') {

            if (employees.find(record.leftEmployee) == employees.end())
                employees[record.leftEmployee] =
                    new Employee(record.leftEmployee);

            manager->left = employees[record.leftEmployee];

            children.insert(record.leftEmployee);
        }

        if (record.rightEmployee != 'X') {

            if (employees.find(record.rightEmployee) == employees.end())
                employees[record.rightEmployee] =
                    new Employee(record.rightEmployee);

            manager->right = employees[record.rightEmployee];

            children.insert(record.rightEmployee);
        }
    }

    for (const auto& pair : employees) {

        if (children.find(pair.first) == children.end()) {
            return pair.second;
        }
    }

    return nullptr;
}
