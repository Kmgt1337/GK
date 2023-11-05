all:
	g++ -I Lib/SDL2/include -L Lib/SDL2/lib -o Bin/main Src/Lab3.cpp Lib/*.hpp Lib/*.cpp -lmingw32 -lSDL2main -lSDL2