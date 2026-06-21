#include "EmployeeTree.h"

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