#include "../conifg.hpp"
#include <cstdlib>
#include <fstream>
#include <nlohmann/json_fwd.hpp>
#include <filesystem>

namespace fs = std::filesystem;
using json = nlohmann::json;

std::string config_default = R"({
  "art":      true,
  "art-color": "255;255;255",
  
  // art must have height of 3
  "art-source": "", // only txt files with ASCII arts

  "filename": "190;255;210",
  "lines":    "110;200;200",
  "words":    "200;200;110",
  "bytes":    "200;110;200",
  "text":     "180;180;180",
  "borders":  "255;255;255",
  "width":    60,

  //borders
  "horizontal": "_",
  "vertical":   "|",
  "separator":  "-",

  //corners
  "top-left":  " ",
  "top-right": " ",
  "bot-right": "|",
  "bot-left":  "|"
})";

namespace meow
{
  void Config::read_conf()  {
    
    std::string config_path = std::string(std::getenv("HOME")) + "/.config";
    std::string path_Meow_conf = config_path + "/" + "Meow" + "/" + "config.json";

    std::ifstream fconf(path_Meow_conf);
    
    if (fconf.is_open()) {
      json dconf = json::parse(fconf);
      if (dconf["art"] != nullptr)
        this->art = dconf["art"];
      if (dconf["art-color"] != nullptr)
        this->art_col = dconf["art-color"];
      if (dconf["art-source"] != nullptr)
        this->art_src = dconf["art-source"];


      if (dconf["filename"] != nullptr)
        this->col_fname = dconf["filename"];
      if (dconf["lines"] != nullptr)
        this->col_lines = dconf["lines"];
      if (dconf["words"] != nullptr)
        this->col_words = dconf["words"];
      if (dconf["bytes"] != nullptr)
        this->col_bytes = dconf["bytes"];
      if (dconf["text"] != nullptr)
        this->col_text = dconf["text"];
      if (dconf["borders"] != nullptr)
        this->col_borders = dconf["borders"];
      if (dconf["width"] != nullptr)
        this->width = dconf["width"];

      if (dconf["horizontal"] != nullptr)
        this->horz_border = dconf["horizontal"];
      if (dconf["vertical"] != nullptr)
        this->vert_border = dconf["vertical"];
      if (dconf["separator"] != nullptr)
        this->horz_separator = dconf["separator"];
      
      if (dconf["top-left"] != nullptr)
        this->corners[0] = dconf["top-left"];
      if (dconf["top-right"] != nullptr)
        this->corners[1] = dconf["top-right"];
      if (dconf["bot-right"] != nullptr)
        this->corners[2] = dconf["bot-right"];
      if (dconf["bot-left"] != nullptr)
        this->corners[3] = dconf["bot-left"];
    } else {
      fs::create_directory(config_path + "/" + "Meow");
      std::ofstream fconf_(path_Meow_conf);
      fconf_ << config_default << std::endl;
      fconf_.close();
    }
  }
}
