#ifndef _SDLMANAGER_
#define _SDLMANAGER_

#include <SDL.h>
#include <map>
#include <iostream>


class SDLManager
{
private:
	//intialize SDL
	bool InitSDL();

	//create window and renderer
	SDL_Window* CreateWindow( char* _windowTitle, int _xPos, int _yPos, int _windowWidth, int _windowHeight );
	SDL_Renderer* CreateRenderer( SDL_Window* _window );

	//mouse info?
	//button coords
	//draw menu
	//draw pause screen

	const Uint8* keyboard;
	SDL_Event e;

public:

	//screen variables
	const int SCREEN_W = 1900;
	const int SCREEN_H = 1000;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	SDL_Renderer* GetRenderer();

	const Uint8* GetKeyboard();

	bool HandleEvents();

	//handle input- keyboard input for #of particles, mouse for buttons

	//Update
	//Draw
	SDLManager();
	~SDLManager();
};

#endif