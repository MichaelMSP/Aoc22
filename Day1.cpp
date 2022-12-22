#ifndef DAY1
#define DAY1

#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

static class Day1
{
  auto static ReadInput(std::string filename) -> std::optional<std::vector<int>>
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
  };

  auto static SumTopResults(std::vector<int> totals, int numberResults) -> int
  {
    int sum = std::accumulate(totals.begin(), (totals.begin() + numberResults), 0);

    return sum;
  };

  public:
  auto static Main() -> void
  {
    auto totals = ReadInput("day1_input.txt");


    if (!totals)
      std::cerr << "Failed to parse day 1 input." << std::endl;

    auto sol1 = SumTopResults(*totals, 1);
    auto sol2 = SumTopResults(*totals, 3);

    std::cout << "Part 1: " << sol1 << " and part 2: " << sol2 << std::endl;
  };
};
#endif