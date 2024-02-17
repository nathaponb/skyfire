all:
	g++ -I include -L lib -o main src/main.cpp src/core/engine.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

run:
	./main.exe