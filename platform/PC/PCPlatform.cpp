#include "Platform.h"

PCPlatform::PCPlatform()
{
}

void PCPlatform::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow("Flipdot", 100, 100, 640, 800, SDL_WINDOW_SHOWN);
	_driver = new SDLFlipdotDriver(_window, 2, 2);
}

void PCPlatform::done()
{
	SDL_DestroyWindow( _window );
	SDL_Quit();
}

IFlipdotDriver& PCPlatform::getFlipdotDriver()
{
	return *_driver;
}

uint32_t PCPlatform::getTicks()
{
	return SDL_GetTicks();
}

bool PCPlatform::doQuit()
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 )
	{
		if( e.type == SDL_QUIT ) {
			return true;
		}
	}

	return false;
}
