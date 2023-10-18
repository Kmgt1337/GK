#include "../Lib/CMYK.hpp"
#include "../Lib/YCbCr.hpp"

#define tytul "GK2023 - Lab 2 - Gawlik Kamil"

void Funkcja1();
void Funkcja2();
void Funkcja3();
void test_CMYK();
void test_CMYK_czarny();
void RGB_to_YCbCr();

void Funkcja1()
{
    int R, G, B;
    int C, M, Y;
    int c, m, y, k;

    for(int yy = 0; yy < wysokosc / 2; yy++)
    {
        for(int xx = 0; xx < szerokosc / 2; xx++)
        {
            // pobranie wartosci RGB piksela
            R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;

            // przejscie z RGB na CMY
            C = 255 - R;
            M = 255 - G;
            Y = 255 - B;

            // znalezienie skladowej 'k' (czarny)
            k = std::min(std::min(C, M), Y);

            // przejscie z CMY do CMYK
            c = C - k;
            m = M - k;
            y = Y - k;

            // przejscie z CMYK do RGB
            C = c + k;
            M = m + k;
            Y = y + k;

            R = 255 - C;
            G = 255 - M;
            B = 255 - Y;

            setPixel(xx + szerokosc / 2, yy, R, G, B);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja2()
{
    int R, G, B;
    int C, M, Y;
    int c, m, y, k;

    for(int yy = 0; yy < wysokosc / 2; yy++)
    {
        for(int xx = 0; xx < szerokosc / 2; xx++)
        {
            //---------------------------------
            R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;

            C = 255 - R;
            M = 255 - G;
            Y = 255 - B;

            k = std::min(std::min(C, M), Y);

            c = C - k;
            m = M - k;
            y = 0;

            C = c + k;
            M = m + k;
            Y = y + k;

            R = 255 - C;
            G = 255 - M;
            B = 255 - Y;

            setPixel(xx + szerokosc / 2, yy, R, G, B);
            //---------------------------------

            //---------------------------------
            R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;

            C = 255 - R;
            M = 255 - G;
            Y = 255 - B;

            k = std::min(std::min(C, M), Y);

            c = 0;
            m = M - k;
            y = Y - k;

            C = c + k;
            M = m + k;
            Y = y + k;

            R = 255 - C;
            G = 255 - M;
            B = 255 - Y;

            setPixel(xx, yy + wysokosc / 2, R, G, B);
            //---------------------------------

            //---------------------------------
             R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;

            C = 255 - R;
            M = 255 - G;
            Y = 255 - B;

            k = std::min(std::min(C, M), Y);

            c = C - k;
            m = 0;
            y = Y - k;

            C = c + k;
            M = m + k;
            Y = y + k;

            R = 255 - C;
            G = 255 - M;
            B = 255 - Y;

            setPixel(xx + szerokosc / 2, yy + wysokosc / 2, R, G, B);
            //---------------------------------

        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja3()
{
    int R, G, B;
    int C, M, Y;
    int c, m, y, k;
    int czarny;

    for(int yy = 0; yy < wysokosc / 2; yy++)
    {
        for(int xx = 0; xx < szerokosc / 2; xx++)
        {
            //---------------------------------
            R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;

            C = 255 - R;
            M = 255 - G;
            Y = 255 - B;

            k = std::min(std::min(C, M), Y);
            czarny = 255 - k;
            setPixel(xx + szerokosc / 2, yy + wysokosc / 2, czarny, czarny, czarny);

            k = 0;

            c = C - k;
            m = M - k;
            y = Y - k;;

            C = c + k;
            M = m + k;
            Y = y + k;

            R = 255 - C;
            G = 255 - M;
            B = 255 - Y;

            setPixel(xx + szerokosc / 2, yy, R, G, B);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void test_CMYK()
{
    CMYK test;
    CMYK test2;
    Uint8 R, G, B;
 
    for(int yy = 0; yy < wysokosc / 2; yy++)
    {
        for(int xx = 0; xx < szerokosc / 2; xx++)
        {
            R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;
 
            test.c = 255 - R;
            test.m = 255 - G;
            test.y = 255 - B;
            test.k = std::min(std::min(test.c, test.m), test.y);

            test.c -= test.k;
            test.m -= test.k;
            test.y -= test.k;
 
            setCMYK(xx + szerokosc / 2, yy, test.c, test.m, test.y, test.k);
 
            test2 = getCMYK(xx, yy);
            setCMYK(xx, yy + wysokosc / 2, test2.c, test2.m, test2.y, test2.k);
        }
    }
 
    SDL_UpdateWindowSurface(window);
}

void test_CMYK_czarny()
{
    CMYK test;
    CMYK test2;
    Uint8 R, G, B;
 
    for(int yy = 0; yy < wysokosc / 2; yy++)
    {
        for(int xx = 0; xx < szerokosc / 2; xx++)
        {
            R = getPixel(xx, yy).r;
            G = getPixel(xx, yy).g;
            B = getPixel(xx, yy).b;
 
            test.c = 255 - R;
            test.m = 255 - G;
            test.y = 255 - B;
            test.k = 0;

            test.c -= test.k;
            test.m -= test.k;
            test.y -= test.k;
 
            setCMYK(xx + szerokosc / 2, yy, test.c, test.m, test.y, test.k);
 
            test2 = getCMYK(xx, yy);
            setCMYK(xx, yy + wysokosc / 2, test2.c, test2.m, test2.y, test2.k);
        }
    }
 
    SDL_UpdateWindowSurface(window); 
}

void RGB_to_YCbCr()
{
    SDL_Color color;
    YCbCr color_ycbcr;
    int Y=0, Cb=128, Cr=128;

    for(int yy = 0; yy < wysokosc / 2; yy++)
    {
        for(int xx = 0; xx < szerokosc / 2; xx++)
        {
            color = getPixel(xx, yy);

            color_ycbcr = RGB_to_YCbCr(xx, yy, color.r, color.g, color.b);

            setPixel(xx + szerokosc / 2, yy, color_ycbcr.Y, color_ycbcr.Y, color_ycbcr.Y);
            setPixel(xx, yy + wysokosc / 2, color_ycbcr.Cb, color_ycbcr.Cb, color_ycbcr.Cb);
            setPixel(xx + szerokosc / 2, yy + wysokosc / 2, color_ycbcr.Cr, color_ycbcr.Cr, color_ycbcr.Cr);
        }
    }

    SDL_UpdateWindowSurface(window);
}


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
    }

    window = SDL_CreateWindow(tytul, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szerokosc*2, wysokosc*2, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    screen = SDL_GetWindowSurface(window);
    if (screen == NULL) {
        fprintf(stderr, "SDL_GetWindowSurface Error: %s\n", SDL_GetError());
    return false;
    }
    SDL_UpdateWindowSurface(window);


    bool done = false;
    SDL_Event event;
    // główna pętla programu
    while (SDL_WaitEvent(&event)) {
        // sprawdzamy czy pojawiło się zdarzenie
        switch (event.type) {
            case SDL_QUIT:
                done = true;
                break;

            // sprawdzamy czy został wciśnięty klawisz
            case SDL_KEYDOWN: {
                // wychodzimy, gdy wciśnięto ESC
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    done = true;
                if (event.key.keysym.sym == SDLK_1)
                    Funkcja1();
                if (event.key.keysym.sym == SDLK_2)
                    Funkcja2();
                if (event.key.keysym.sym == SDLK_3)
                    Funkcja3();
                if (event.key.keysym.sym == SDLK_4)
                    test_CMYK();
                if (event.key.keysym.sym == SDLK_5)
                    test_CMYK_czarny();
                if (event.key.keysym.sym == SDLK_6)
                    RGB_to_YCbCr();
                // if (event.key.keysym.sym == SDLK_7)
                //     Funkcja7();
                // if (event.key.keysym.sym == SDLK_8)
                //     Funkcja8();
                // if (event.key.keysym.sym == SDLK_9)
                //     Funkcja9();
                if (event.key.keysym.sym == SDLK_a)
                    ladujBMP("Pictures/obrazek1.bmp", 0, 0);
                if (event.key.keysym.sym == SDLK_s)
                    ladujBMP("Pictures/obrazek2.bmp", 0, 0);
                if (event.key.keysym.sym == SDLK_d)
                    ladujBMP("Pictures/obrazek3.bmp", 0, 0);
                if (event.key.keysym.sym == SDLK_f)
                    ladujBMP("Pictures/obrazek4.bmp", 0, 0);
                if (event.key.keysym.sym == SDLK_g)
                    ladujBMP("Pictures/obrazek5.bmp", 0, 0);
                if (event.key.keysym.sym == SDLK_b)
                    czyscEkran(0, 0, 0);
                else
                    break;
               }
        }
        if (done) break;
    }

    if (screen) {
        SDL_FreeSurface(screen);
    }

    if (window) {
        SDL_DestroyWindow(window);
    }


    SDL_Quit();
    return 0;
}