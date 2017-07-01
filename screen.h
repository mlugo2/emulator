#include <SDL2/SDL.h>

// define bool
typedef enum { false, true } bool;

// Screen dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Starts up SDL and creates window
bool init_screen();

// Shuts down SDL
void close_sdl();

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

// The window renderer
SDL_Renderer* gRenderer = NULL;


// The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

bool init_screen() {

	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {

		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		// Create window
		gWindow = SDL_CreateWindow("Sunflower", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		if (gWindow == NULL) {
			printf("Window could not created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {

			// Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED);
			if ( gRenderer == NULL ) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else {
				// Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00);
			}
		}
	}



	return success;
}

void close_sdl() {
	// Deallocate surface
	SDL_FreeSurface( gXOut );

	// Destroy window
	SDL_DestroyWindow( gWindow );

	// Quit SDL subsystem
	SDL_Quit();
}