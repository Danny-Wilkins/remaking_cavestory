#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>
#include <SDL2/SDL.h>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
	Graphics();

	~Graphics();

	//Loads image into spriteSheets map and if it doesn't exist and returns it
	SDL_Surface* loadImage(const std::string& filePath);

	//Draws texture to a certain part of screen
	void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destinationRect);

	//Renders everything to screen
	void flip();

	//Clears screen
	void clear();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif