#include "../Lib/Utility.hpp"

#define tytul "GK2023 - Lab 1 - Gawlik Kamil"

void Funkcja1();
void Funkcja2();
void Funkcja3();
void Funkcja4();
void Funkcja5();
void Funkcja6();
void Funkcja7();
void Funkcja8();
void Funkcja9();

void Funkcja1() {

    for(int i = 0; i < 5000; i++)
    {
        int x = rand() % szerokosc;
        int y = rand() % wysokosc;
        Uint8 R = rand() % 255;
        Uint8 G = rand() % 255;
        Uint8 B = rand() % 255;

        setPixel(x, y, R, G, B);
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja2() {

    for(int y = 0; y < wysokosc; y++)
    {
        for(int x = 0; x < szerokosc; x++)
        {
            setPixel(x, y, 255 * (x * 1.0 / szerokosc), 0, 255 * (x * 1.0 / szerokosc));
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja3() {

    SDL_Color kolor;

    for(int y = 0; y < wysokosc / 2; y++)
    {
        for(int x = 0; x < szerokosc / 2; x++)
        {
            kolor = getPixel(x, y);

            setPixel(x + szerokosc / 2, y, kolor.r, kolor.r, kolor.r);
            setPixel(x, y + wysokosc / 2, kolor.g, kolor.g, kolor.g);
            setPixel(x + szerokosc / 2, y + wysokosc / 2, kolor.b, kolor.b, kolor.b);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja4() {

    SDL_Color kolor;

    int szary;
    int szary2;

    for(int y = 0; y < wysokosc / 2; y++)
    {
        for(int x = 0; x < szerokosc / 2; x++)
        {
            kolor = getPixel(x, y);

            szary = (kolor.r + kolor.g + kolor.b) / 3;
            szary2 = 0.299 * kolor.r + 0.587 * kolor.g + 0.114 * kolor.b;

            setPixel(x + szerokosc / 2, y, szary, szary, szary);
            //setPixel(x, y + wysokosc / 2, 0, szary, 0);
            setPixel(x + szerokosc / 2, y + wysokosc / 2, szary2, szary2, szary2);
        }
    }

    SDL_UpdateWindowSurface(window);
}

void Funkcja5() {

    //...

    SDL_UpdateWindowSurface(window);
}

void Funkcja6() {

    //...

    SDL_UpdateWindowSurface(window);
}

void Funkcja7() {

    //...

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