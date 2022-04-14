#ifndef GAME_BASE__H_
#define GAME_BASE_

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gMainMenu = NULL;

//Load Background
SDL_Surface* gBackGround = NULL;

//Current image
SDL_Surface* gCurrentImage = NULL;


#endif // GAME_BASE__H_


