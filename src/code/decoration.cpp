#include "../decorations.h"
#include "../conifg.hpp"
#include <iostream>
#include <string>

std::array<std::string, 3> meow::kitten = {
    "|   |\\__/,|   (`\\   ",
    "| _.|o o  |_   ) )  ",
    "|--(((---(((--------",
};

std::string creset = "\e[0m";

std::string conc(const char& src, size_t times)
{
  std::string result = "";
  for (size_t i = 0; i < times; i++)
    result += src;

  return result;
}

std::string conc(const std::string& src, size_t times)
{
  std::string result = "";
  for (size_t i = 0; i < times; i++)
    result += src;

  return result;
}

size_t digits(size_t num)
{
  size_t result = 0;
  if (num == 0)
    return 1;
  while (num > 0)
  {
    result++;
    num /= 10;
  }

  return result;
}

std::array<std::string, 3> get_art(std::string path) {
  std::ifstream sfile(path);
  std::array<std::string, 3> result;
  if (sfile.is_open()) {
    for (int i = 0; i < 3; i++)
      std::getline(sfile, result[i]);
  }

  return result;
}


std::array<std::string, 6> meow::head(std::string filename, size_t lines,
                                      size_t words, size_t bytes, Config& conf)
{
  size_t wd = conf.get_width();
  std::string fpref = conf.get_fnpref();
  std::string fpost = conf.get_fnpost();
  
  if (!conf.is_art())
    kitten = {"", "", ""};

  if (conf.get_as() != "")
    kitten = get_art(conf.get_as());
  std::string kcol = "\e[38;2;" + conf.get_ca() + "m";


  std::array<std::string, 4> corns = conf.get_corns(); 
  std::string hb = conf.get_hb();
  std::string hs = "\e[38;2;" + conf.get_cbor() + "m" + conf.get_hs() + creset;
  std::string vb = "\e[38;2;" + conf.get_cbor() + "m" + conf.get_vb() + creset;


  std::array<std::string, 6> result;
  result[0] = "\e[38;2;" + conf.get_cbor() + "m" + corns[0] + conc(hb, wd) + corns[1] + creset;
  if (conf.get_fnpos() == 0)
    result[1] = vb +
              conc(hs, (wd - filename.length() - fpref.length() - fpost.length()) / 2 + (wd - filename.length() - fpref.length() - fpost.length()) % 2) + 
              + "\e[38;2;"+ conf.get_cfn() + "m" + fpref + filename + fpost + creset +
              conc(hs, (wd - 1 - filename.length() - fpref.length() - fpost.length()) / 2 + (wd - 1 - filename.length() - fpref.length() - fpost.length()) % 2) 
              + vb;
  if (conf.get_fnpos() == -1)
    result[1] = vb +
               + "\e[38;2;" + conf.get_cfn() + "m" + fpref + filename + fpost + creset +
              conc(hs, wd - filename.length() - fpref.length() - fpost.length()) 
              + vb;
  if (conf.get_fnpos() == 1)
    result[1] = vb +
              conc(hs,wd - filename.length() - fpref.length() - fpost.length()) +
              + "\e[38;2;" + conf.get_cfn() + "m" + fpref + filename + fpost + creset +
              vb;



  result[2] = vb + "\e[38;2;" + conf.get_cl() + "mLines: " + std::to_string(lines) + "\e[0m" +
              conc(' ', wd - 7 - kitten[0].length() - digits(lines)) + kcol + kitten[0] + creset + vb;
  result[3] = vb + "\e[38;2;" + conf.get_cw() + "mWords: " + std::to_string(words) +
              creset + conc(' ', wd - 7 - kitten[1].length() - digits(words)) + kcol +
              kitten[1] + creset + vb;
  result[4] = vb + "\e[38;2;" + conf.get_cb() + "mBytes: " + std::to_string(bytes) +
              creset + conc(" ", wd - 7 - kitten[2].length() - digits(bytes)) + kcol +
              kitten[2] + creset + vb;

  result[5] = "\e[38;2;" + conf.get_cbor() + "m" + corns[3] + conc(hb, wd) + corns[2] + creset;

  return result;
}

std::vector<std::string> meow::text(std::vector<std::string> src, Config& conf)
{
  size_t wd = conf.get_width();
  std::array<std::string, 4> corns = conf.get_corns(); 
  std::string hb = conf.get_hb();
  std::string hs = "\e[38;2;" + conf.get_cbor() + "m" + conf.get_hs() + creset;
  std::string vb = "\e[38;2;" + conf.get_cbor() + "m" + conf.get_vb() + creset;

  std::string ct = conf.get_ct();
  std::vector<std::string> result;

  result.push_back(vb + conc(hs, wd) + vb);
  for (std::string line : src)
  {
    std::string res_line = "";
    for (size_t i = 0; i < line.length(); i++)
    {
      if (line[i] == '\t')
        res_line += "    ";
      else
        res_line += line[i];

      if (res_line.length() == wd)
      {
        result.push_back(vb + "\e[38;2;" + ct + "m" + res_line + creset + vb);
        res_line = "";
      }
    }
    res_line += conc(' ', wd - res_line.length()) + creset + vb;
    result.push_back(vb + "\e[38;2;" + ct + "m" + res_line);
  }
  result.push_back("\e[38;2;" + conf.get_cbor() + "m" + corns[3] + conc(hb, wd) + corns[2] + creset);
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
