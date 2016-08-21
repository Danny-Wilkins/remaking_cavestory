#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 
								0, &window, &renderer); //Width x Height, win, ren
	SDL_SetWindowTitle(window, "CaveStory"); //Creates game window
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(window); //Closes window
}

SDL_Surface* Graphics::loadImage(const std::string& filePath)
{
	if(spriteSheets.count(filePath) == 0)
	{
		spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}

	return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destinationRect)
{
	SDL_RenderCopy(renderer, texture, sourceRect, destinationRect);
}

void Graphics::flip()
{
	SDL_RenderPresent(renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return renderer;
}