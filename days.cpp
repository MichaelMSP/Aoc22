#include "days.h"

#include <iostream>
#include <string>
#include <unordered_map>

const std::unordered_map<int, std::function<Days::Answers()>> solutionForChoice {
    {1, Days::solution1},
    {2, Days::solution2},
    {3, Days::solution3},
    {4, Days::solution4},
    {5, Days::solution5},
    // {6, Days::solution6},
    // {7, Days::solution7},
    // {8, Days::solution8}
};

auto Days::selectSolution() -> std::function<Answers()> {
    int choice = 0;
    std::string toNewLine;
    while (!solutionForChoice.contains(choice)) {
        std::cout << "Choose a solution (1-" << MAX << "):" << std::endl;
        std::cin >> choice;
        std::cin.clear(); // Clear and ignore until newline in case of non-integral input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return solutionForChoice.at(choice);
}