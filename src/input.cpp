#include "input.h"

void Input:: newFrame()
{
	pressedKeys.clear();
	releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event& event)
{
	pressedKeys[event.key.keysym.scancode] = true;
	heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event& event)
{
	releasedKeys[event.key.keysym.scancode] = true;
	heldKeys[event.key.keysym.scancode] = false;
}

bool Input::keyPressed(SDL_Scancode key)
{
	return pressedKeys[key];
}

bool Input::keyReleased(SDL_Scancode key)
{
	return releasedKeys[key];
}

bool Input::keyHeld(SDL_Scancode key)
{
	return heldKeys[key];
}