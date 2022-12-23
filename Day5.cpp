#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <sstream>
#include <deque>

#include "HelperFunctions.cpp"
#include "days.h"

namespace Day5
{
  struct Instruction
  {
    int quantity;
    int src;
    int dest;
  };

  auto ParseStacks(std::string filename) -> std::tuple<std::vector<std::deque<char>>, std::vector<Instruction>>
  {
    std::vector<std::deque<char>> existing_stacks;
    std::vector<std::string> existing_stacks_txt;
    std::vector<Instruction> instructions;

    std::ifstream input(filename);
    std::string line;
    while (std::getline(input, line))
    {
      if (line.starts_with("move"))
      {
        std::stringstream read_inst(line);
        int quan, src, dest;
        std::string word;
        read_inst >> word >> quan >> word >> src >> word >> dest;
        instructions.emplace_back(quan, src, dest);
      }
      if (line.empty() || line.starts_with(" 1"))
      {
        // Do nothing.
      }
      else
      {
        existing_stacks_txt.push_back(line);
      }
    }

    std::ranges::reverse_view rv {existing_stacks_txt};
    for (auto line : rv)
    {

    }

    return {existing_stacks, instructions};
  }

} // namespace Day5

///
/// @brief The main entry point for this day.
///
auto Days::solution5() -> Answers
{
  auto [existing_stacks, instructions] = Day5::ParseStacks("day5_input.txt");

  auto sol1 = -1;
  auto sol2 = -1;

  return {std::to_string(sol1),std::to_string(sol2)};
}