#include "SDLManager.h"



SDLManager::SDLManager()
{
	//initialize SDL
	InitSDL();

	//init pointers to null
	m_window = nullptr;
	m_renderer = nullptr;
	keyboard = SDL_GetKeyboardState( NULL );

	//if SDL initializes, create window and renderer
	if ( InitSDL() )
	{
		m_window = CreateWindow( "Particle Demo", 100, 100, SCREEN_W, SCREEN_H );
		m_renderer = CreateRenderer( m_window );
	}
}

bool SDLManager::InitSDL()
{
	//initialize SDL
	if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

		return false;
	}

	return true;

}

SDL_Window* SDLManager::CreateWindow( char * _windowTitle, int _xPos, int _yPos, int _windowWidth, int _windowHeight )
{

		// try to create the window, log error and return nullptr if fail
		SDL_Window* window = SDL_CreateWindow( _windowTitle, _xPos, _yPos, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN );
		if ( window == nullptr )
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}

		// return pointer to newly created window
		return window;
	
}

SDL_Renderer* SDLManager::CreateRenderer( SDL_Window * _window )
{
	// try to create renderer, log error and return NULL if fails
	SDL_Renderer* renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if ( renderer == nullptr )
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	// return pointer to new renderer
	return renderer;
}

SDL_Renderer * SDLManager::GetRenderer()
{
	return m_renderer;
}

const Uint8 * SDLManager::GetKeyboard()
{
	return keyboard;
}

bool SDLManager::HandleEvents()
{
	while ( SDL_PollEvent( &e ) )
	{
		/* If a quit event has been sent */
		if ( e.type == SDL_QUIT )
		{
			/* Quit the application */
			return true;
		}
	}

	return false;
}

SDLManager::~SDLManager()
{
	SDL_Quit();
}
