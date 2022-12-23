#ifndef HELPER_FUNCTIONS
#define HELPER_FUNCTIONS

#include <string>
#include <vector>
#include <fstream>


/// @brief Read the file into a vector of string.
/// @param filename The name of the file to read.
/// @return The vector of strings.
auto static ReadInput(std::string filename) -> std::vector<std::string>
{
    std::vector<std::string> inputs;
    std::ifstream input(filename);
    std::string line;
    while (std::getline(input, line))
    {
        inputs.emplace_back(line);
    }

    return inputs;
};

#endif