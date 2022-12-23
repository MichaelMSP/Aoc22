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
    std::vector<std::deque<char>> existing_stacks = {{},{},{},{},{},{},{},{},{}};
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
      else if (line.empty() || line.starts_with(" 1"))
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
      size_t pos = 0;
      while((pos = line.find_first_of("[", pos)) != std::string::npos)
      {
        int idx = pos / 4;
        existing_stacks[idx].push_back(line[pos + 1]);
        pos++;
      }
    }

    return {existing_stacks, instructions};
  }

  // Specifically cannot pass by reference, or stacks is in the wrong starting
  // configuration for part 2.
  auto MoveCratesIndividually(std::vector<std::deque<char>> stacks, std::vector<Instruction>& instructions) -> std::string
  {
    // Loop all instructions. For each one, perform a move the number of times given.
    for (auto instr : instructions)
    {
      for (int num = 0; num < instr.quantity; num++)
      {
        stacks[instr.dest - 1].push_back(stacks[instr.src - 1].back());
        stacks[instr.src - 1].pop_back();
      }
    }

    std::string result;
    for(auto stack : stacks)
    {
      result.push_back(stack.back());
    }

    return result;
  }

  auto MoveCratesTogether(std::vector<std::deque<char>> stacks, std::vector<Instruction>& instructions) -> std::string
  {
    // Loop all instructions. For each one, perform a move the number of times given.
    for (auto instr : instructions)
    {
      std::deque<char> crane;
      for (int num = 0; num < instr.quantity; num++)
      {
        crane.push_back(stacks[instr.src - 1].back());
        stacks[instr.src - 1].pop_back();
      }

      for (int num = 0; num < instr.quantity; num++)
      {
        stacks[instr.dest - 1].push_back(crane.back());
        crane.pop_back();
      }
    }

    std::string result;
    for(auto stack : stacks)
    {
      result.push_back(stack.back());
    }

    return result;
  }

} // namespace Day5

///
/// @brief The main entry point for this day.
///
auto Days::solution5() -> Answers
{
  auto [existing_stacks, instructions] = Day5::ParseStacks("day5_input.txt");
  auto sol1 = Day5::MoveCratesIndividually(existing_stacks, instructions);
  auto sol2 = Day5::MoveCratesTogether(existing_stacks, instructions);

  return {sol1, sol2};
}