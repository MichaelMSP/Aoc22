#ifndef DAY3
#define DAY3

#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

#include "HelperFunctions.cpp";

class Day3
{
  ///
  /// @brief Determine the priority of the given char.
  /// @param c The char to determine.
  /// @return The priority as an int.
  auto static Priority(char c) -> int
  {
    if (islower(c))
      return (int)c - 96;
    else
      return (int)c - 38;
  }

  /// @brief Finds the char that appears in both first and second half of the given string.
  /// @param contents The string to find the char in.
  /// @return The char if found, nullopt if not.
  auto static FindDuplicate(std::string contents) -> std::optional<char>
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



  public: 
  ///
  /// @brief The main entry point for this day.
  ///
  auto static Main() -> void
  {
    auto inputs = ReadInput("day3_input.txt");

    int sum = 0;
    for (std::string s : inputs)
    {
      auto c = FindDuplicate(s);
      if (c)
      {
        std::cout << "Got " << *c << " with priority " << Priority(*c) << std::endl;
        sum += Priority(*c);
      }
      else
      {
        std::cerr << "Failed to get priority for string " << s << std::endl;
      }
    }

    std::cout << "Day 3 Part 1: " << sum << std::endl;
    // std::cout << "Day 3 Part 2: " << sol2 << std::endl;
  };
};
#endif