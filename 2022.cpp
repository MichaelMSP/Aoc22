// 2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "days.h"

int main()
{
  auto solution = Days::selectSolution();
    auto [answerA, answerB] = solution();
    std::cout << answerA << " " << answerB << std::endl;

    return 0;
}
