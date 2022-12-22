// 2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Day1.cpp"
#include "Day2.cpp"
#include "Day3.cpp"

int main()
{
  int day;
  std::cout << "Which day to you want to solve?" << std::endl;
  std::cin >> day;

  switch (day)
  {
  case 1:
    Day1::Main();
    break;
  case 2:
    Day2::Main();
    break;
  case 3:
    Day3::Main();
    break;
  default:
    std::cout << "Unrecognised day! Exiting." << std::endl;
    break;
  }
}
