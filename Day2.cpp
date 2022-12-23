#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <tuple>

#include "days.h"

namespace Day2
{

enum choice
{
  Rock = 1,
  Paper = 2,
  Scissors = 3
};

auto DetermineChoice(char c)
{
  if (c == 'A' || c == 'X')
  {
    return Rock;
  }
  else if (c == 'B' || c == 'Y')
  {
    return Paper;
  }
  else if (c == 'C' || c == 'Z')
  {
    return Scissors;
  }
  else
  {
    std::cerr << "Failed to parse choice." << std::endl;
    return Rock;
  }
}

auto ReadInput(std::string filename) -> std::vector<std::tuple<choice, choice>>
{
  std::vector<std::tuple<choice, choice>> inputs;
  std::ifstream input(filename);
  std::string line;
  while (std::getline(input, line))
  {
    inputs.emplace_back(std::tuple<choice, choice>(DetermineChoice(line[0]), DetermineChoice(line[2])));
  }

  return inputs;
}

auto Score(choice first, choice second) -> int
{
  int result;
  if (first == second)
  {
    result = 3;
  }
  else if (first == second - 1 || second + 2 == first)
  {
    result = 6;
  }
  else
  {
    result = 0;
  }

  return (int)second + result;
}

auto CompareChoice(int score, const std::tuple<choice, choice> &input) -> int
{
  return score + Score(std::get<0>(input), std::get<1>(input));
}

auto LoosingMove(choice c) -> choice
{
  if (c == Rock) return Scissors;
  else if (c == Paper) return Rock;
  else return Paper;
}

auto WinningMove(choice c) -> choice
{
  if (c == Rock) return Paper;
  else if (c == Paper) return Scissors;
  else return Rock;
}

auto RequiredScore(choice first, choice second) -> int
{
  int result;
  int newChoice;
  if (second == Rock) // Now, rock (X) is lose
  {
    newChoice = LoosingMove(first);
    result = 0;
  }
  else if (second == Paper) // Now, Paper (Y) is draw
  {
    newChoice = first;
    result = 3;
  }
  else if (second == Scissors) // Now, Scissors (Z) is a win
  {
    newChoice = WinningMove(first);
    result = 6;
  }

  return (int)newChoice + result;
}

auto DetermineEnding(int score, const std::tuple<choice, choice>& input) -> int
{
  return score + RequiredScore(std::get<0>(input), std::get<1>(input));
}

auto FindScore(std::vector<std::tuple<choice, choice>> inputs) -> int
{
  int sum = std::accumulate(inputs.begin(), inputs.end(), 0, CompareChoice);

  return sum;
}

auto FindScore2(std::vector<std::tuple<choice, choice>> inputs) -> int
{
  int sum = std::accumulate(inputs.begin(), inputs.end(), 0, DetermineEnding);

  return sum;
}
} // namespace Day2

auto Days::solution2() -> Answers
{
  auto choices = Day2::ReadInput("day2_input.txt");

  auto sol1 = Day2::FindScore(choices);
  auto sol2 = Day2::FindScore2(choices);

  return {std::to_string(sol1), std::to_string(sol2)};
}
