#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

#include "days.h"

namespace Day1
{

auto ReadInput(std::string filename) -> std::optional<std::vector<int>>
{
  std::ifstream input(filename);
  std::string line;
  std::vector<int> totals;
  int sum = 0;
  while (std::getline(input, line))
  {
    if (line.empty())
    {
      totals.emplace_back(sum);
      sum = 0;
    }
    else
    {
      sum += stoi(line);
    }
  }

  if (totals.size() > 1)
  {
    std::sort(totals.begin(), totals.end(), std::greater<int>());
    return totals;
  }
  else
  {
    return std::nullopt;
  }
}

auto SumTopResults(std::vector<int> totals, int numberResults) -> int
{
  int sum = std::accumulate(totals.begin(), (totals.begin() + numberResults), 0);

  return sum;
}

} // namespace Day1

auto Days::solution1() -> Answers
{
  auto totals = Day1::ReadInput("day1_input.txt");


  if (!totals)
    std::cerr << "Failed to parse day 1 input." << std::endl;

  auto sol1 = Day1::SumTopResults(*totals, 1);
  auto sol2 = Day1::SumTopResults(*totals, 3);

  return {std::to_string(sol1), std::to_string(sol2)};
}
