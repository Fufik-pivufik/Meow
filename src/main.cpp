#include <iostream>
#include <vector>

#include "decorations.h"
#include "file.h"
#include "text.h"

int main(int argc, char* argv[])
{
  bool display = 0;

  std::vector<char> keys;
  std::vector<std::string> files;
  for (int i = 1; i < argc; i++)
  {
    if (std::isalnum(argv[i][0]) || argv[i][0] == '.')
      files.push_back(argv[i]);
    else if (argv[i][0] == '-')
      keys.push_back(argv[i][1]);
    else
      std::cout << "Unknown argument: " << argv[i] << std::endl;
  }

  //
  // std::cout << "\nKeys" << std::endl;
  // for (char key : keys)
  //   std::cout << "| " << key << std::endl;
  //
  // std::cout << "\nFiles" << std::endl;
  // for (std::string file : files)
  //   std::cout << "| " << file << std::endl;

  for (char key : keys)
  {
    switch (key)
    {
    default:
      std::cout << "Unknown key: -" << key << std::endl;
      break;
    case 's':
      display = true;
      break;
    case 'h':

      std::vector<std::string> helptext = meow::help();
      for (std::string line : helptext)
      {
        std::cout << line << std::endl;
      }
      return 0;
    }
  }

  if (argc < 2 || files.size() == 0)
  {
    std::cout << "Oh! Maybe you forgot write a filename!\n\n| Like this: meow "
                 "text.txt\nAnd without file I'll just sleep "
                 "Z-z-z...\n\e[38;2;180;180;180m(for more information use $ "
                 "meow -h)\e[0m"
              << std::endl;
    return 0;
  }

  for (std::string file : files)
  {
    size_t words, lines, bytes;
    try
    {
      std::vector<std::string> text = meow::readfile(file, lines, words, bytes);
      std::array<std::string, 5> parsed = meow::head(file, lines, words, bytes);
      for (int i = 0; i < 5; i++)
        std::cout << parsed[i] << std::endl;

      if (display)
      {
        std::vector<std::string> src = meow::text(text);
        for (std::string line : src)
          std::cout << line << std::endl;
      }
    }
    catch (int errnum)
    {
      switch (errnum)
      {
      default:
        std::cout << "unknown error" << std::endl;
      }
    }
  }

  return 0;
}
