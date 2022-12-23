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

auto ParseInput(const std::vector<std::string> &inputs) -> std::vector<std::pair<range, range>>
{
  std::vector<std::pair<range, range>> result;
  for (const auto &line : inputs)
  {
    std::stringstream input_line(line);
    int start1, end1, start2, end2;
    char separator;
    input_line >> start1 >> separator >> end1 >> separator >> start2 >> separator >> end2;

    std::pair p = {range(start1, end1), range(start2, end2)};

    result.push_back(p);
  }

  return result;
}

auto InclusiveCompare(int result, const std::pair<range, range>& input)
{
  if (input.first.start <= input.second.start && input.first.end >= input.second.end)
    result++;
  else if (input.second.start <= input.first.start && input.second.end >= input.first.end)
    result++;

  return result;
}

auto ExclusiveCompare(int result, const std::pair<range, range>& input)
{
  if (input.first.start <= input.second.end && input.first.start >= input.second.start) result++;
  else if (input.first.end >= input.second.start && input.first.end <= input.second.end) result++;
  else if (input.second.start >= input.first.end && input.second.start <= input.first.start) result++;
  else if (input.second.end >= input.first.start && input.second.end <= input.first.end) result++;
  return result;
}

} // namespace Day4

///
/// @brief The main entry point for this day.
///
auto Days::solution4() -> Answers
{
  auto inputs = ReadInput("day4_input.txt");
  auto spans = Day4::ParseInput(inputs);

  auto sol1 = std::accumulate(spans.begin(), spans.end(), 0, Day4::InclusiveCompare);
  auto sol2 = std::accumulate(spans.begin(), spans.end(), 0, Day4::ExclusiveCompare);

  return {std::to_string(sol1),std::to_string(sol2)};
}