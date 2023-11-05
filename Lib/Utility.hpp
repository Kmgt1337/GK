#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <exception>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/include/SDL2/SDL.h"

extern SDL_Window* window;
extern SDL_Surface* screen;

#define szerokosc 640
#define wysokosc 400

void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
SDL_Color getPixel (int x, int y);
void czyscEkran(Uint8 R, Uint8 G, Uint8 B);
void setPixelSurface(int x, int y, Uint8 R, Uint8 G, Uint8 B);
SDL_Color getPixel(int x, int y);
SDL_Color getPixelSurface(int x, int y, SDL_Surface *surface);
void ladujBMP(char const* nazwa, int x, int y);

#endif