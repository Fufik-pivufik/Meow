#include "../file.h"
#include "../text.h"
#include <iostream>

std::vector<std::string> meow::readfile(std::string path, size_t& lines,
                                        size_t& words, size_t& bytes, size_t& maxlen)
{
  lines = bytes = words = maxlen = 0;
  std::ifstream src(path);
  if (!src.is_open())
    throw 100;

  std::vector<std::string> result;
  std::string line;
  while (std::getline(src, line))
  {
    lines++;
    result.push_back(line);
    words += meow::count_words(line);
    bytes += line.length() + 1;
    if (line.length() > maxlen)
      maxlen = line.length();
  }

  return result;
}
