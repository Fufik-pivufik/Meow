#include "../conifg.hpp"
#include <cstdlib>
#include <fstream>
#include <nlohmann/json_fwd.hpp>
#include <filesystem>

namespace fs = std::filesystem;
using json = nlohmann::json;

std::string config_default = R"({
  "filename": "190;255;210",
  "lines":    "110;200;200",
  "words":    "200;200;110",
  "bytes":    "200;110;200",
  "text":     "180;180;180",
  "width": 60
})";

namespace meow
{
  void Config::read_conf()  {
    
    std::string config_path = std::string(std::getenv("HOME")) + "/.config";
    std::string path_Meow_conf = config_path + "/" + "Meow" + "/" + "config.json";

    std::ifstream fconf(path_Meow_conf);
    
    if (fconf.is_open()) {
      json dconf = json::parse(fconf);
      this->col_fname = dconf["filename"];
      this->col_lines = dconf["lines"];
      this->col_words = dconf["words"];
      this->col_bytes = dconf["bytes"];
      this->col_text = dconf["text"];
      this->width = dconf["width"];
    } else {
      fs::create_directory(config_path + "/" + "Meow");
      std::ofstream fconf_(path_Meow_conf);
      fconf_ << config_default << std::endl;
      fconf_.close();
    }
  }
}
