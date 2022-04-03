#include "sprite.hpp"

namespace sprite
{
  void 
  print()
  {
    std::mt19937 mersenne(static_cast<unsigned>(time(NULL)));
    for(const auto &el:sprite::tree)
    {
      for(const auto ch:el)
      {
        if ( mersenne() % 8 != 1 )
        {
          std::cout << color_map[ch](ch);
        }
        else
        {
          std::cout << color_map['*'](ch);
        }
      }
      std::cout << std::endl;
    }

  }

}
