#include <stdio.h>
#include <unistd.h>
#include <SDL2/SDL_thread.h>
#include "common.h"
#include "screen.h"
#include "cpu.h"

/*
	Author: Marco Lugo

	Summary:
	--------
	
		This is the Sunflower computer system.  This is a simulation of a
	complete computing system, including: cpu, memory, I/O, and display--
	and anything else I can think of ducking tapping on to this thing :p

	Description:
	------------

		The Sunflower computer system has a stack architecture.

*/

// Function prototypes
void load_ram(BYTE []);

// thread function prototypes
int threadFunction( void* data[] );
int screenThread();

int main(int argc, char const *argv[])
{
	printf("Hello world!\n");
	
	// main memory
	BYTE ram[0xffff] = {
		iconst, 0xFF,
		gstore, 0xFF, 0xFE,
		halt
	};
	WORD start = 0x0000;

	// Run the thread
	void* data = ram;
	SDL_Thread* threadID = SDL_CreateThread( threadFunction, "Simple", data);
	SDL_Thread* screenID = SDL_CreateThread( screenThread, "Screen", data);

	cpu(ram, start);
	printf("DONE\n");

	// Remove timer in case the call back was not called
	SDL_WaitThread( screenID, NULL);
	SDL_WaitThread( threadID, NULL);

	
	return 0;
}



void load_ram(BYTE ram[]) {
	// Open a file and load all the bytes into ram
}

int screenThread(void* memory) {

	BYTE A[14][8] = {
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 0 ,255 ,255 ,255 ,255 ,0 ,0},
		{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
		{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
		{0, 255 ,255 ,255 ,255 ,255 ,255 ,0},
		{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
		{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
		{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
		{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
		{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	};

	BYTE** codePage[0xFF];

	codePage[0x61] = A;

	// Event handler
	SDL_Event e;

	// Accessing each byte in vram
	int x;
	int y;

	// VRAM
	int vram[480][640];

	// Initialize vram
	for (y = 0; y < SCREEN_HEIGHT; y++) {
		for (x = 0; x < SCREEN_WIDTH; x ++) {
			vram[y][x] = 0;
		}
	}

	BYTE s[14][8];

	memcpy(s, codePage[0x61], sizeof(s));

	for (y = 0; y < 14; y++) {
		for (x = 0; x < 8; x ++) {
			vram[y][x] = s[y][x];
		}
	}


	// Start up SDL and create window
	if ( !init_screen() ) {
		printf("Failed to Initialize!\n");
	}
	else {
		// While application is running
		while( !quit ) {

			// Handle events on queue
			while( SDL_PollEvent(&e) != 0) {
				// User requests quit
				if ( e.type == SDL_QUIT ){
					quit = true;
				}
			}

			// Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear( gRenderer );

			for (y = 0; y < SCREEN_HEIGHT; y++) {
				for (x = 0; x < SCREEN_WIDTH; x++) {

					// Render red pixel
					SDL_Rect fillpixel = { x, y, 1, 1};
					int z = vram[y][x];

					SDL_SetRenderDrawColor( gRenderer, z, z, z, z);		
					SDL_RenderFillRect( gRenderer, &fillpixel );
				}
			}

			// Update screen
			SDL_RenderPresent( gRenderer );
		}

		// Free resources and close SDL
	close_sdl();
		
	}
}

int threadFunction( void* data[] ) {
		
	// Get key input
	while (!quit) {

		// Do nothing until the correct signal is passed.
		while (*((BYTE*)data + 0xFFFE) != 0xFF) {
			if (quit)
				goto stop;
		}

		// Read keyboard input
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		if ( currentKeyStates[ SDL_SCANCODE_A ]) {

			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x61;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_B ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x62;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_C ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x63;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_D ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x64;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_E ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x65;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_F ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x66;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_G ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x67;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_H ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x68;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_I ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x69;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_J ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x6A;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_K ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x6B;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_L ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x6C;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_M ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x6D;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_N ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x6E;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_O ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x6F;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_P ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x70;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Q ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x71;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_R ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x72;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_S ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x73;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_T ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x74;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_U ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x75;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_V ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x76;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_W ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x77;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_X ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x78;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Y ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x79;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Z ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)data + 0xFFFF) = 0x7A;

			// Set SFR to allow CPU to continue
			*((BYTE*)data + 0xFFFE) = 0x00;
		}
		usleep(150000);	
	}
	
	stop: return 0;
}