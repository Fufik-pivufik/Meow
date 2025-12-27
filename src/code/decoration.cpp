#include "../decorations.h"
#include <iostream>
#include <string>

std::array<std::string, 3> meow::kitten = {
    "  |\\__/,|   (`\\   |",
    "_.|o o  |_   ) )  |",
    "-(((---(((--------|",

};

std::string conc(const char& src, size_t times)
{
  std::string result = "";
  for (size_t i = 0; i < times; i++)
    result += src;

  return result;
}

size_t digits(size_t num)
{
  size_t result = 0;
  while (num > 0)
  {
    result++;
    num /= 10;
  }

  return result;
}

std::array<std::string, 5> meow::head(std::string filename, size_t lines,
                                      size_t words, size_t bytes)
{
  std::array<std::string, 5> result;
  result[0] = " " + conc('_', 60) + " ";
  result[1] = "|_File:_\e[38;2;190;255;210m" + filename + "\e[0m" +
              conc('_', 53 - filename.length()) + "|";
  result[2] = "|\e[38;2;110;200;200mLines: " + std::to_string(lines) + "\e[0m" +
              conc(' ', 54 - kitten[0].length() - digits(lines)) + kitten[0];
  result[3] = "|\e[38;2;200;200;110mWords: " + std::to_string(words) +
              +"\e[0m" + conc(' ', 54 - kitten[1].length() - digits(words)) +
              kitten[1];
  result[4] = "|\e[38;2;200;110;200mBytes: " + std::to_string(bytes) +
              +"\e[0m" + conc('-', 54 - kitten[2].length() - digits(bytes)) +
              kitten[2];

  return result;
}

std::vector<std::string> meow::text(std::vector<std::string> src)
{
  std::vector<std::string> result;

  result.push_back("|" + conc('=', 60) + "|");
  for (std::string line : src)
  {
    std::string res_line = "";
    for (size_t i = 0; i < line.length(); i++)
    {
      res_line += line[i];
      if (res_line.length() == 60)
      {
        result.push_back("|\e[38;2;180;180;180m" + res_line + "\e[0m|");
        res_line = "";
      }
    }
    res_line += conc(' ', 60 - res_line.length()) + "\e[0m|";
    result.push_back("|\e[38;2;180;180;180m" + res_line);
  }
  result.push_back("|" + conc('_', 60) + "|");
  return result;
}

std::vector<std::string> meow::help()
{
  std::vector<std::string> result;
  result.push_back(" __\e[38;2;255;180;255mmeow\e[0m__" + conc('_', 45) +
                   "_\e[38;2;255;100;100mHelp\e[0m__ ");
  result.push_back("| \e[38;2;200;100;200mHint\e[0m: call "
                   "\e[38;2;180;255;180mmeow\e[0m for find out "
                   "information about file! " +
                   conc(' ', 6) + "|");
  result.push_back("|" + conc(' ', 60) + "|");
  result.push_back("| For example: \e[38;2;180;255;180mmeow\e[0m file.txt" +
                   conc(' ', 33) + "|");
  result.push_back("|" + conc(' ', 60) + "|");
  result.push_back("| You could use flag -s for view file's containment!" +
                   conc(' ', 9) + "|");
  result.push_back("|      \e[38;2;180;255;180mmeow\e[0m file.txt -s" +
                   conc(' ', 38) + "|");
  result.push_back("|" + conc(' ', 61 - kitten[0].length()) + kitten[0]);
  result.push_back("|" + conc(' ', 61 - kitten[1].length()) + kitten[1]);
  result.push_back("|" + conc('-', 61 - kitten[2].length()) + kitten[2]);

  return result;
}
