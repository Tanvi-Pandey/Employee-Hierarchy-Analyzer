#include "EmployeeTree.h"

#include <iostream>
#include <vector>

int main() {

    EmployeeTree tree;

    std::vector<Record> records =
        tree.readRecords("input/SampleInput.txt");

    std::cout << "Employee Records\n";

    for (const auto& record : records) {
        std::cout
            << record.manager << " "
            << record.leftEmployee << " "
            << record.rightEmployee
            << '\n';
    }

    return 0;
}