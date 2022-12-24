#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <fstream>
#include <map>
#include <sstream>

#include "HelperFunctions.cpp"
#include "days.h"

namespace Day7
{

auto AddSizeToParents(std::map<std::string, int>& dirSizes, std::string& currentDir, int& size)
{
  if (currentDir == "/") return;
  char div = '/';
  size_t pos = currentDir.find(div, 0);
  while (pos != std::string::npos)
  {
    std::string parent = currentDir.substr(0, pos);
    if (parent.empty())
      parent = "/";
    pos = currentDir.find(div, pos + 1);
    dirSizes[parent] += size;
  }
}

auto ParseInput(std::vector<std::string> input) -> std::map<std::string, int>
{
  std::map<std::string, int> dirSizes;
  std::string currentDir = "";

  for (auto line : input)
  {
    if (line.starts_with("$ cd"))
    {
      // We've moved. Update currentDir.
      auto idx = line.find_last_of(' ');
      std::string dirName = line.substr(++idx);
      if (dirName == "..")
      {
        auto rmidx = currentDir.find_last_of('/');
        std::string dirRemoved = currentDir.substr(++rmidx);
        currentDir.erase(currentDir.length() - dirRemoved.size() - 1);
      }
      else
      {
        if (dirName != "/")
          if (currentDir == "/")
            currentDir += dirName;
          else
            currentDir += "/" + dirName;
        else
          currentDir += dirName;
        dirSizes[currentDir] = 0;
      }
    }
    else if (line.starts_with("$ ls") || line.starts_with("dir"))
    {
      // Do nothing.
    }
    else
    {
      // Must be a file.
      std::stringstream ss(line);
      int size;
      ss >> size;
      dirSizes[currentDir] += size;
      AddSizeToParents(dirSizes, currentDir, size);
    }
  }

  return dirSizes;
}

auto SumLessThan(std::map<std::string, int> dirSizes, int lessThan) -> int
{
  int result = 0;
  for (auto m : dirSizes)
  {
    if (m.second < lessThan)
    {
      result += m.second;
    }
  }

  return result;
}

auto SmallestAboveLimit(std::map<std::string, int> dirSizes) -> int
{
  int total_space = 70'000'000;
  int needed = 30'000'000;
  int taken = dirSizes["/"];
  int to_remove = needed - (total_space - taken);

  int smallest = total_space;
  for (auto m : dirSizes)
  {
    if (m.second < smallest && m.second > to_remove)
    {
      smallest = m.second;
    }
  }

  return smallest;
}

} // namespace Day7

///
/// @brief The main entry point for this day.
///
auto Days::solution7() -> Answers
{
  auto input = ReadInput("day7_input.txt");;
  auto dirMap = Day7::ParseInput(input);

  auto sol1 = Day7::SumLessThan(dirMap, 100'000);
  auto sol2 = Day7::SmallestAboveLimit(dirMap);

  return {std::to_string(sol1), std::to_string(sol2)};
}