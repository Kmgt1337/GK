#ifndef YCBCR_HPP
#define YCBCR_HPP

#include "Utility.hpp"

class YCbCr
{
public:
    Uint8 Y;
    Uint8 Cb;
    Uint8 Cr;
};

YCbCr RGB_to_YCbCr(int xx, int yy, Uint8 R, Uint8 G, Uint8 B);

#endif