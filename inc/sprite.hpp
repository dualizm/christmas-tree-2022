#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <functional>
#include <unordered_map>
#include "lpct.hpp"

namespace sprite
{
  
  static std::vector<std::string> 
  tree 
  {
    "                     z                     ",
    "                    zrr                    ",
    "                 zzzzrrrrr                 ",
    "                   zz#rr                   ",
    "                   z###r                   ",
    "                 ##########                ",
    "                ##()########               ",
    "              ################             ",
    "            ####################           ",
    "              #########()#####             ",
    "           #####()################         ",
    "         ###########################       ",
    "            #######()######()#####         ",
    "        ##############################     ",
    "           ######################          ",
    "       ######()##############()########    ",
    "         ###########################       ",
    "                 |  /   |                  ",
    "                 |   \\\\ |                  ",
    "                 |   \\  |                  ",
    "_________________|______|__________________",
  };

  using lc = lpct::colors;
  static std::unordered_map<char, std::function<std::string(const char)>> 
  color_map
  {
    {'r', [](const char) {return lpct::get_colorstr<std::string>(lc::red, "r"); }},
    {'z', [](const char) {return lpct::get_colorstr<std::string>(lc::red, "z"); }},
    {'#', [](const char) {return lpct::get_colorstr<std::string>(lc::green, "#"); }},
    {'|', [](const char) {return lpct::get_colorstr<std::string>(lc::bright_yellow, "|"); }},
    {'\\',[](const char) {return lpct::get_colorstr<std::string>(lc::bright_yellow, "\\"); }},
    {'/', [](const char) {return lpct::get_colorstr<std::string>(lc::bright_yellow, "/"); }},
    {'(', [](const char) {return lpct::get_colorstr<std::string>(lc::magenta, "("); }},
    {')', [](const char) {return lpct::get_colorstr<std::string>(lc::magenta, ")"); }},
    {'*', [](const char ch) 
      {
        if (ch == '#')
        {
          if (rand() % 6 != 1 )
          {
            return lpct::get_colorstr<std::string>(lc::green, "#");
          }
          else
          {
            return lpct::get_colorstr<std::string>(lc::white, "#");
          }
        }
        else if (ch == ')')
        {
          return lpct::get_colorstr<std::string>(lc::magenta, ")");
        }
        else if (ch == '(')
        {
          return lpct::get_colorstr<std::string>(lc::magenta, "(");
        }
        else
        {
          return lpct::get_colorstr<std::string>(lc::white, "*");
        }
      }
    },
    {'_', [](const char) {return lpct::get_colorstr<std::string>(lc::white, "_"); }},
    {' ', [](const char) {return lpct::get_colorstr<std::string>(lc::white, " "); }},
  };

  void 
  print();
}

#endif // _SPRITE_HPP_
