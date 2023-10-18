#include "YCbCr.hpp"

YCbCr RGB_to_YCbCr(int xx, int yy, Uint8 R, Uint8 G, Uint8 B)
{
    SDL_Color color_rgb;
    YCbCr color_ycbcr;
    int Y, Cb, Cr;

    color_rgb = getPixel(xx, yy);

    Y = (0.299 * static_cast<float>(color_rgb.r)) + (0.587 * static_cast<float>(color_rgb.g)) + (0.114 * (float)color_rgb.b);
    Cb = 128 - (0.168736 * static_cast<float>(color_rgb.r)) - (0.331264* static_cast<float>(color_rgb.g)) + (0.5 * static_cast<float>(color_rgb.b));
    Cr= 128 + (0.5 * static_cast<float>(color_rgb.r)) - (0.418688 * static_cast<float>(color_rgb.g)) - (0.081312 * static_cast<float>(color_rgb.b));

    Y = (Y + 256) % 256;
    Cb = (Cb + 256) % 256;
    Cr = (Cr + 256) % 256;

    color_ycbcr.Y = Y;
    color_ycbcr.Cb = Cb;
    color_ycbcr.Cr = Cr;

    return color_ycbcr;
}