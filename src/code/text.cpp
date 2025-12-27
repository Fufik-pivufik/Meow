#include "../text.h"

size_t meow::count_words(std::string line)
{
  size_t result = 0;
  for (int i = 0; i < line.length(); i++)
  {
    if (std::isalnum(line[i]))
    {
      result++;
      while (std::isalnum(line[i]) && i < line.length())
        i++;
    }
  }

  return result;
}
