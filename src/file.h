#include <fstream>
#include <string>
#include <vector>
#pragma once

namespace meow
{
std::vector<std::string> readfile(std::string path, size_t& line, size_t& words,
                                  size_t& bytes);
};
