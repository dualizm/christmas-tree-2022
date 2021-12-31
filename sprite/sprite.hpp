#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>
#include <random>
#include <functional>
#include <unordered_map>
#include "../color/color.hpp"

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

  static std::unordered_map<char, std::function<char(const char)>> 
  color_map
  {
    {'r', [](const char ch) { SetColor(ConsoleColor::Red, ConsoleColor::Black); return 'r'; }},
    {'z', [](const char ch) { SetColor(ConsoleColor::Red, ConsoleColor::Black); return 'z'; }},
    {'#', [](const char ch) { SetColor(ConsoleColor::Green, ConsoleColor::Black); return '#'; }},
    {'|', [](const char ch) { SetColor(ConsoleColor::Brown, ConsoleColor::Black);  return '|'; }},
    {'\\',[](const char ch) { SetColor(ConsoleColor::Brown, ConsoleColor::Black); return '\\'; }},
    {'/', [](const char ch) { SetColor(ConsoleColor::Brown, ConsoleColor::Black); return '/'; }},
    {'(', [](const char ch) { SetColor(ConsoleColor::Magenta, ConsoleColor::Black); return '('; }},
    {')', [](const char ch) { SetColor(ConsoleColor::Magenta, ConsoleColor::Black); return ')'; }},
    {'*', [](const char ch) 
      {
        if (ch == '#')
        {
          rand() % 6 != 1 ? (SetColor(ConsoleColor::Green, ConsoleColor::Black))
          : (SetColor(ConsoleColor::White, ConsoleColor::Black));
          return '#';
        }
        else if (ch == ')')
        {
          SetColor(ConsoleColor::Magenta, ConsoleColor::Black);
          return ')';
        }
        else if (ch == '(')
        {
          SetColor(ConsoleColor::Magenta, ConsoleColor::Black);
          return '(';
        }
        else
        {
          SetColor(ConsoleColor::White, ConsoleColor::Black); 
          return '*';
        }
      }
    },
    {'_', [](const char ch) { SetColor(ConsoleColor::White, ConsoleColor::Black); return '_'; }},
    {' ', [](const char ch) { SetColor(ConsoleColor::White, ConsoleColor::Black); return ' '; }},
  };

  void 
  print(std::vector<std::string> sprite);
}

#endif // _SPRITE_HPP_
