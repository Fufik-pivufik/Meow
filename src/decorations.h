#include <array>
#include <string>
#include <vector>

#pragma once

namespace meow
{

extern std::array<std::string, 3> kitten;

std::array<std::string, 5> head(std::string filename, size_t lines,
                                size_t words, size_t bytes);

std::vector<std::string> text(std::vector<std::string>);
std::vector<std::string> help();
}; // namespace meow
