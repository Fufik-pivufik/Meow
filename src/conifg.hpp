#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#pragma once

namespace meow
{
  class Config
  {
    std::string col_lines;
    std::string col_bytes;
    std::string col_words;
    std::string col_borders;
    std::string col_text;
    std::string col_fname;

    std::string vert_border;
    std::string horz_border;
    std::string horz_separator;

    std::array<std::string, 4> corners; // top-left, top-right, bottom-right, bottom-left

    bool art;
    std::string art_col;
    std::string art_src;


    size_t width;
    

    public:
      Config() // default configuration
      {
        col_fname = "190;255;210";
        col_lines = "110;200;200";
        col_words = "200;200;110";
        col_bytes = "200;110;200";
        col_borders = "255;255;255";
        col_text = "180;180;180";
        vert_border = "|";
        horz_border = "_";
        horz_separator = "-";
        corners = { " ", " ", "|", "|" };
        width = 60;
        art = true;
        art_col = "255;255;255";
        art_src = "";
      }

      std::string get_ca() const { return art_col; }
      std::string get_as() const { return art_src; }
      std::string get_cl() const  { return col_lines; }
      std::string get_cb() const  { return col_bytes; }
      std::string get_cw() const { return col_words; }
      std::string get_cbor() const { return col_borders; }
      std::string get_ct() const { return col_text; }
      std::string get_cfn() const { return col_fname; }
      size_t get_width() const { return width; }
      std::string get_vb() const { return vert_border; }
      std::string get_hb() const { return horz_border; }
      std::string get_hs() const { return horz_separator; }
      std::array<std::string, 4> get_corns() const { return corners; }
      bool is_art() const {return art;}


      void read_conf();
  };
}
