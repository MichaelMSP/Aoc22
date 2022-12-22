#ifndef DAY2
#define DAY2

#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <tuple>

class Day2
{
  enum choice
  {
    Rock = 1,
    Paper = 2,
    Scissors = 3
  };

  auto static DetermineChoice(char c)
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
  }

  auto static ReadInput(std::string filename) -> std::vector<std::tuple<choice, choice>>
  {
    std::vector<std::tuple<choice, choice>> inputs;
    std::ifstream input(filename);
    std::string line;
    while (std::getline(input, line))
    {
      inputs.emplace_back(std::tuple<choice, choice>(DetermineChoice(line[0]), DetermineChoice(line[2])));
    }

    return inputs;
  };

  auto static Score(choice first, choice second) -> int
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

  auto static CompareChoice(int score, const std::tuple<choice, choice> &input) -> int
  {
    return score + Score(std::get<0>(input), std::get<1>(input));
  }

  auto static LoosingMove(choice c) -> choice
  {
    if (c == Rock) return Scissors;
    else if (c == Paper) return Rock;
    else return Paper;
  }

  auto static WinningMove(choice c) -> choice
  {
    if (c == Rock) return Paper;
    else if (c == Paper) return Scissors;
    else return Rock;
  }

  auto static RequiredScore(choice first, choice second) -> int
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

  auto static DetermineEnding(int score, const std::tuple<choice, choice>& input) -> int
  {
    return score + RequiredScore(std::get<0>(input), std::get<1>(input));
  }

  auto static FindScore(std::vector<std::tuple<choice, choice>> inputs) -> int
  {
    int sum = std::accumulate(inputs.begin(), inputs.end(), 0, CompareChoice);

    return sum;
  };

  auto static FindScore2(std::vector<std::tuple<choice, choice>> inputs) -> int
  {
    int sum = std::accumulate(inputs.begin(), inputs.end(), 0, DetermineEnding);

    return sum;
  };

  public: 
  auto static Main() -> void
  {
    auto choices = ReadInput("day2_input.txt");

    auto sol1 = FindScore(choices);
    auto sol2 = FindScore2(choices);

    std::cout << "Day 2 Part 1: " << sol1 << std::endl;
    std::cout << "Day 2 Part 2: " << sol2 << std::endl;
  };
};
#endif