#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <ranges>
#include <sstream>

#include "HelperFunctions.cpp"
#include "days.h"

namespace Day4
{

struct range {
  int start;
  int end;
  range (){}
  range(int s, int e) : start(s), end(e) {}
};

auto ParseInput(std::vector<std::string> &inputs) -> std::vector<std::pair<range, range>>
{
  std::vector<std::pair<range, range>> parsed;
  for (const auto &line : inputs)
  {
    std::stringstream input_line(line);
    int start1, end1, start2, end2;
    char separator;
    input_line >> start1 >> separator >> end1 >> separator >> start2 >> separator >> end2;

    parsed.emplace_back(range(start1, end1), range(start2, end2));
  }

  return parsed;
}

} // namespace Day4

///
/// @brief The main entry point for this day.
///
auto Days::solution4() -> Answers
{
  auto inputs = ReadInput("day4_input.txt");
  auto spans = Day4::ParseInput(inputs);

  

//   int sum = FindPrioritySum(inputs);
//   int sum2 = FindCommonItems(inputs);

//   std::cout << "Day 3 Part 1: " << sum << std::endl;
//   std::cout << "Day 3 Part 2: " << sum2 << std::endl;
  return {"",""};
}