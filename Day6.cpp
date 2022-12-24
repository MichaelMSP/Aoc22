#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <fstream>
#include <unordered_set>

#include "HelperFunctions.cpp"
#include "days.h"

namespace Day6
{

// Create a string using file buffers.
auto ReadInput(std::string filename) -> std::string
{
  std::ifstream input(filename);
  return std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
}

// Find the sequence of unique chars.
auto FindUniqueSequence(std::string input, int sequenceLength) -> int
{
  std::string::iterator itr;
  for (itr = input.begin(); itr < input.end() - sequenceLength; itr++) 
  {
    auto window = std::unordered_set<char>(itr, itr + sequenceLength);
    if (window.size() == sequenceLength)
    {
      return std::distance(input.begin(), itr) + sequenceLength;
    }
  }
}

} // namespace Day6

///
/// @brief The main entry point for this day.
///
auto Days::solution6() -> Answers
{
  auto input = Day6::ReadInput("Day6_input.txt");
  auto sol1 = Day6::FindUniqueSequence(input, 4);
  auto sol2 = Day6::FindUniqueSequence(input, 14);

  return {std::to_string(sol1), std::to_string(sol2)};
}