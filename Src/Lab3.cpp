#include "../Lib/Utility.hpp"


#define tytul "GK2023 - Lab 3 - Gawlik Kamil"


void Funkcja1();
void Funkcja2();
void Funkcja3();
void Funkcja4();
void Funkcja5();
void Funkcja6();
void Funkcja7();
void Funkcja8();
void Funkcja9();
void zaktualizujTabliceBayera2();
void zaktualizujTabliceBayera2();

int tablicaBayera2[2][2] =
{
    {2, 4},
    {3, 1}
};
float zaktualizowanaTablicaBayera2[2][2];

int tablicaBayera4[4][4] =
{
    {6, 14, 8, 16},
    {10, 2, 12, 4},
    {7, 15, 5, 13},
    {11, 3, 9, 1}
};
float zaktualizowanaTablicaBayera4[4][4];

void zaktualizujTabliceBayera2()
{
    int zakres = 256;
    int rozmiar = 2;
    float podzial = zakres * 1.0 / (rozmiar * rozmiar);

    for(int y = 0; y < rozmiar; y++)
    {
        for(int x = 0; x < rozmiar; x++)
        {
            std::cout << y << " " << x << std::endl;
            zaktualizowanaTablicaBayera2[y][x] = (tablicaBayera2[y][x] * podzial) - podzial / 2;
        }
    }

    for(int y = 0; y < rozmiar; y++)
    {
        std::cout << std::endl;
        for(int x = 0; x < rozmiar; x++)
        {
            std::cout << tablicaBayera2[y][x] << " ";
        }
    }

    for(int y = 0; y < rozmiar; y++)
    {
        std::cout << std::endl;
        for(int x = 0; x < rozmiar; x++)
        {
            std::cout << zaktualizowanaTablicaBayera2[y][x] << " ";
        }
    }
}

void zaktualizujTabliceBayera4()
{
    int zakres = 256;
    int rozmiar = 4;
    float podzial = zakres * 1.0 / (rozmiar * rozmiar);

    for(int y = 0; y < rozmiar; y++)
    {
        for(int x = 0; x < rozmiar; x++)
        {
            std::cout << y << " " << x << std::endl;
            zaktualizowanaTablicaBayera4[y][x] = (tablicaBayera4[y][x] * podzial) - podzial / 2;
        }
    }

    for(int y = 0; y < rozmiar; y++)
    {
        std::cout << std::endl;
        for(int x = 0; x < rozmiar; x++)
        {
            std::cout << tablicaBayera4[y][x] << " ";
        }
    }

    for(int y = 0; y < rozmiar; y++)
    {
        std::cout << std::endl;
        for(int x = 0; x < rozmiar; x++)
        {
            std::cout << zaktualizowanaTablicaBayera4[y][x] << " ";
        }
    }
}

void Funkcja1() 
{

    SDL_Color kolor;
    Uint8 szary;
    Uint8 piksel;

    for(int y = 0; y < wysokosc; y++)
    {
        for(int x = 0; x < szerokosc; x++)
        {
            kolor = getPixel(x, y);
            szary = 0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b;
            setPixel(x, y, szary, szary, szary);

            if(szary > 127)
            {
                piksel = 255;
            }
            else
            {
                piksel = 0;
            }

            setPixel(x + szerokosc / 2, y, piksel, piksel, piksel);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja2() {

    int rozmiar = 2;
    zaktualizujTabliceBayera2();
    SDL_Color kolor;
    Uint8 szary;
    Uint8 piksel;
    Uint8 tablica;

    for(int y = 0; y < wysokosc / 2; y++)
    {
        for(int x = 0; x < szerokosc / 2; x++)
        {
            kolor = getPixel(x, y);
            szary = 0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b;
            setPixel(x, y, szary, szary, szary);

            tablica = zaktualizowanaTablicaBayera2[y % rozmiar][x % rozmiar];

            if(szary > tablica)
            {
                piksel = 255;
            }
            else
            {
                piksel = 0;
            }

            setPixel(x + szerokosc / 2, y, piksel, piksel, piksel);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja3() {

    int rozmiar = 4;
    zaktualizujTabliceBayera4();
    SDL_Color kolor;
    Uint8 szary;
    Uint8 piksel;
    Uint8 tablica;

    for(int y = 0; y < wysokosc / 2; y++)
    {
        for(int x = 0; x < szerokosc / 2; x++)
        {
            kolor = getPixel(x, y);
            szary = 0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b;
            setPixel(x, y, szary, szary, szary);

            tablica = zaktualizowanaTablicaBayera4[y % rozmiar][x % rozmiar];

            if(szary > tablica)
            {
                piksel = 255;
            }
            else
            {
                piksel = 0;
            }

            setPixel(x + szerokosc / 2, y, piksel, piksel, piksel);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja4() {

    SDL_Color kolor;
    int szary;
    Uint8 szaryOrg;
    Uint8 piksel;
    Uint8 przesuniecie = 1;
    float bledy[(szerokosc/2) + 2][wysokosc + 2];
    memset(bledy, 0, sizeof(bledy));
    int blad = 0;

    for(int y = 0; y < 200; y++)
    {
        for(int x = 0; x < 320; x++)
        {
            kolor = getPixel(x, y);
            szaryOrg = 0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b;
            szary = szaryOrg + bledy[x + przesuniecie][y];
            setPixel(x, y, szaryOrg, szaryOrg, szaryOrg);

            if(szary > 127)
            {
                piksel = 255;
                blad = szary - 255;
            }
            else
            {
                piksel = 0;
                blad = szary;
            }
            bledy[x + 1 + przesuniecie][y] += (blad*7.0/16.0);
            bledy[x - 1 + przesuniecie][y + 1] += (blad*3.0/16.0);
            bledy[x + przesuniecie][y + 1] += (blad*5.0/16.0);
            bledy[x + 1 + przesuniecie][y + 1] += (blad*1.0/16.0);

            setPixel(x + szerokosc / 2, y ,piksel, piksel, piksel);


            if(szary > 255) szary = 255;
            if(szary < 0) szary = 0;
            setPixel(x, y + wysokosc / 2, szary, szary, szary);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja5() {

    //...

    SDL_UpdateWindowSurface(window);
}

void Funkcja6() {

    int rozmiar = 4;
    zaktualizujTabliceBayera4();
    SDL_Color kolor;
    Uint8 tablica;
    Uint8 R, G, B;
    
    for(int y = 0; y < szerokosc; y++)
    {
        for(int x = 0; x < wysokosc; x++)
        {
            kolor = getPixel(x, y);
            tablica = zaktualizowanaTablicaBayera4[y % rozmiar][x % rozmiar];

            if(kolor.r > tablica)
            {
                R = 255;
            }
            else
            {
                R = 0;
            }

            if(kolor.g > tablica)
            {
                G = 255;
            }
            else
            {
                G = 0;
            }

            if(kolor.b > tablica)
            {
                B = 255;
            }
            else
            {
               B = 0;
            }

            setPixel(x + szerokosc / 2, y, R, G, B);
        }
    }
    SDL_UpdateWindowSurface(window);
}

void Funkcja7() {

    SDL_Color kolor;
    int szary;
    Uint8 szaryOrg;
    Uint8 red, green, blue;
    Uint8 piksel;
    Uint8 przesuniecie = 1;
    float bledy[(szerokosc/2) + 2][wysokosc + 2];
    memset(bledy, 0, sizeof(bledy));
    int blad = 0;
    Uint8 R, G, B;

    for(int y = 0; y < 200; y++)
    {
        for(int x = 0; x < 320; x++)
        {
            kolor = getPixel(x, y);
            red = kolor.r + bledy[x + przesuniecie][y];
            green = kolor.g + bledy[x + przesuniecie][y];
            blue = kolor.b + bledy[x + przesuniecie][y];
            setPixel(x, y, szaryOrg, szaryOrg, szaryOrg);

            if(kolor.r > red)
            {
                R = 255;
                blad = red - 255;
            }
            else
            {
                R = 0;
                blad = red;
            }

            if(kolor.g > green)
            {
                G = 255;
                blad = green - 255;
            }
            else
            {
                G = 0;
                blad = green;
            }

            if(kolor.b > blue)
            {
                B = 255;
                blad = blue - 255;
            }
            else
            {
               B = 0;
               blad = blue;
            }

            bledy[x + 1 + przesuniecie][y] += (blad*7.0/16.0);
            bledy[x - 1 + przesuniecie][y + 1] += (blad*3.0/16.0);
            bledy[x + przesuniecie][y + 1] += (blad*5.0/16.0);
            bledy[x + 1 + przesuniecie][y + 1] += (blad*1.0/16.0);

            setPixel(x + szerokosc / 2, y ,piksel, piksel, piksel);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja8() {

    //...

    SDL_UpdateWindowSurface(window);
}

void Funkcja9() {

    //...

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
                    Funkcja4();
                if (event.key.keysym.sym == SDLK_5)
                    Funkcja5();
                if (event.key.keysym.sym == SDLK_6)
                    Funkcja6();
                if (event.key.keysym.sym == SDLK_7)
                    Funkcja7();
                if (event.key.keysym.sym == SDLK_8)
                    Funkcja8();
                if (event.key.keysym.sym == SDLK_9)
                    Funkcja9();
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
                if (event.key.keysym.sym == SDLK_h)
                    ladujBMP("Pictures/obrazek6.bmp", 0, 0);
                if(event.key.keysym.sym == SDLK_k)
                    ladujBMP("Pictures/Franek.bmp", 0, 0);
                if(event.key.keysym.sym == SDLK_n)
                    ladujBMP("Pictures/Natalia.bmp", 0, 0);
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
