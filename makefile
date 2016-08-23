cavestory: src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp src/animated_sprite.cpp src/player.cpp
	g++ -std=c++11 -g -o cavestory src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp src/animated_sprite.cpp src/player.cpp -lSDL2  -lSDL2_image -I header

