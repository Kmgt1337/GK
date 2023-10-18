#include "CMYK.hpp"

void setCMYK(int xx, int yy, Uint8 c, Uint8 m, Uint8 y, Uint8 k)
{
    int C = c + k;
    int M = m + k;
    int Y = y + k;

    setPixel(xx, yy, 255 - C, 255 - M,  255 - Y);
}

CMYK getCMYK(int xx, int yy)
{
    CMYK result;
 
    result.c = 255 - getPixel(xx, yy).r;
    result.m = 255 - getPixel(xx, yy).g;
    result.y = 255 - getPixel(xx, yy).b;
    result.k = std::min(std::min(result.c, result.m), result.y);

    result.c -= result.k;
    result.m -= result.k;
    result.y -= result.k;
 
    return result;
}