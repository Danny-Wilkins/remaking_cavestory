#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"
#include "player.h"

namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000/FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING); //Initialize audio, keyboard, other things
	gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	player = Player(graphics, 100, 100);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while(true) //Checks for events such as keypresses
	{
		input.newFrame();

		if(SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.repeat == 0)
				{
					input.keyDownEvent(event);
				}
			}
			else if(event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}
			else if(event.type == SDL_QUIT)
			{
				return;
			}
		}
		if(input.keyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}
		else if(input.keyHeld(SDL_SCANCODE_LEFT) == true)
		{
			player.moveLeft();
		}
		else if(input.keyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			player.moveRight();
		}

		if(!input.keyHeld(SDL_SCANCODE_LEFT) && !input.keyHeld(SDL_SCANCODE_RIGHT))
		{
			player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME)); //Uses elapsed time or max FPS (50)

		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		draw(graphics);
	}
}

void Game::draw(Graphics& graphics)
{
	graphics.clear();

	player.draw(graphics);

	graphics.flip();
}

void Game::update(float elapsedTime)
{
	player.update(elapsedTime);
}