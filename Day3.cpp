#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <ranges>

#include "HelperFunctions.cpp"
#include "days.h"

namespace Day3
{

///
/// @brief Determine the priority of the given char.
/// @param c The char to determine.
/// @return The priority as an int.
auto Priority(char c) -> int
{
  if (islower(c))
    return (int)c - 96;
  else
    return (int)c - 38;
}

/// @brief Finds the char that appears in both first and second half of the given string.
/// @param contents The string to find the char in.
/// @return The char if found, nullopt if not.
auto FindDuplicate(std::string contents) -> std::optional<char>
{
  std::string strFirst = contents.substr(0, contents.length()/2);
  std::string strSecond = contents.substr(contents.length()/2);
  std::unordered_set firstHalf = std::unordered_set(strFirst.begin(), strFirst.end());
  std::unordered_set secondHalf = std::unordered_set(strSecond.begin(), strSecond.end());
  for(char c : secondHalf)
  {
    if (firstHalf.contains(c))
    {
      return c;
    }
  }

  return std::nullopt;
}

auto FindPrioritySum(std::vector<std::string> inputs) -> int
{
  int sum = 0;
  for (std::string s : inputs)
  {
    auto c = FindDuplicate(s);
    if (c)
    {
      // std::cout << "Got " << *c << " with priority " << Priority(*c) << std::endl;
      sum += Priority(*c);
    }
    else
    {
      std::cerr << "Failed to get priority for string " << s << std::endl;
    }
  }

  return sum;
}

auto FindCommonItems(std::vector<std::string> inputs) -> int
{
  // This would be nice, but it is for C++23, not C++ 20.
  // for (const auto& chunk : inputs | std::views::chunk(3))
  // {
    // Perform operations on chunk[0], chunk[1] and chunk[2]
  // }

  int priority = 0;
  // Iterate through the vector in groups of three
  for (std::size_t i = 0; i < inputs.size(); i += 3) {
    std::unordered_set bag1 = std::unordered_set(inputs[i].begin(), inputs[i].end());
    std::unordered_set bag2 = std::unordered_set(inputs[i + 1].begin(), inputs[i + 1].end());
    std::unordered_set bag3 = std::unordered_set(inputs[i + 2].begin(), inputs[i + 2].end());

    std::vector<char> toRemove = std::vector<char>();
    for (char c : bag1)
    {
      if (bag2.count(c) == 0 || bag3.count(c) == 0) 
      {
        toRemove.push_back(c);
      }
    }

    for (char c : toRemove)
      bag1.erase(c);

    // There should now be only 1 element left in bag1.
    priority += Priority(*(bag1.begin()));
  }

  return priority;
}
} // namespace Day3

///
/// @brief The main entry point for this day.
///
auto Days::solution3() -> Answers
{
  auto inputs = ReadInput("day3_input.txt");

  int sum = Day3::FindPrioritySum(inputs);
  int sum2 = Day3::FindCommonItems(inputs);

  return {std::to_string(sum), std::to_string(sum2)};
};
