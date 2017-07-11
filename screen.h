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

// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;


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

		// Create window
		gWindow = SDL_CreateWindow("Sunflower", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		if (gWindow == NULL) {
			printf("Window could not created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {

			// Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );

			// Fill the sureface white
			SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 0xFF, 0xFF, 0xFF) );

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