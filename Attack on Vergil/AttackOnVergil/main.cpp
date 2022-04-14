#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include "Game_Base.h"
using namespace std;




bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout<<"SDL error"<<endl<<SDL_GetError();
	}

	else
	{
	    //create window
	     gWindow = SDL_CreateWindow( "Attack on V", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            cout<<"Cant open"<<endl<<SDL_GetError();
            success = false;
        }
        else
        {

                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );

        }

	}
	return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gMainMenu );
    gMainMenu = NULL;
    SDL_FreeSurface(gBackGround);
    gBackGround = NULL;

    gCurrentImage =NULL;
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}



SDL_Surface* loadSurface( string path )
{
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
       cout<<"Unable to load image  SDL Error: "<<endl<< path.c_str()<<SDL_GetError() ;
    }

    else
    {
        //Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			cout<< "Unable to optimize image %s! SDL Error: %s\n"<<endl <<path.c_str() <<SDL_GetError();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}



//Loads menu
bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gMainMenu = loadSurface( "Images/Background/Main Menu.png");
    gBackGround = loadSurface("Images/Background/Background.png");


    return success;
}


int main( int argc, char* args[] )
{



    if(!init())
    {
        cout<<"Error"<<endl;
    }

    else
    {

        if(!loadMedia())
        {
            cout<<"Error to load Media";
        }

        else
        {
            gCurrentImage = gMainMenu;

           //Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event MouseClick;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &MouseClick ) != 0 )
				{
					//User requests quit
					if(MouseClick.type == SDL_QUIT)
                    {
                        quit = true;
                    }
					else if( MouseClick.type == SDL_MOUSEBUTTONDOWN )
					{
                       if(MouseClick.button.button == SDL_BUTTON_LEFT)
                       {
                           gCurrentImage = gMainMenu;
                       }

                       else if(MouseClick.button.button == SDL_BUTTON_RIGHT)
                       {
                           gCurrentImage = gBackGround;
                       }
					}
				}

				//Apply the PNG image
				SDL_BlitSurface( gCurrentImage, NULL, gScreenSurface, NULL );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );

			}
        }


    }


    close();
    return 0;
}


