#ifndef CMYK_HPP
#define CMYK_HPP

#include "Utility.hpp"

class CMYK
{
public:
    Uint8 c;
    Uint8 m;
    Uint8 y;
    Uint8 k; 
};

void setCMYK(int xx, int yy, Uint8 c, Uint8 m, Uint8 y, Uint8 k);
CMYK getCMYK(int xx, int yy);

#endif