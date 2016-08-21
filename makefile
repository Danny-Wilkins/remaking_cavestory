cavestory: src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp
	g++ -std=c++11 -g -Wall -o cavestory src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp -lSDL2  -lSDL2_image -I header

