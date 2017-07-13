#include <SDL2/SDL_thread.h>
#include "common.h"
#include "font_rom.h"

// thread function prototypes
int keyboard_thread( void* memory[] );
int videoCard_thread( void* memory[] );

int videoCard_thread(void* memory[] ) {

	// Event handler
	SDL_Event e;

	// Accessing each byte in vram
	int x, y;

	// VRAM
	BYTE vram[480][640];

	BYTE cursor_x_pos;
	BYTE cursor_y_pos;
	BYTE x_start;
	BYTE x_stop;
	BYTE y_start;
	BYTE y_stop;

	// Initialize vram
	for (y = 0; y < SCREEN_HEIGHT; y++) {
		for (x = 0; x < SCREEN_WIDTH; x ++) {
			vram[y][x] = 0;
		}
	}

	BYTE byte_to_write[14][8];

	// for (y = 0; y < 14; y++) {
	// 	for (x = 0; x < 8; x ++) {
	// 		vram[y][x] = s[y%17][x%8];
	// 	}
	// }

	// for (y = 0; y < 14; y++) {
	// 	for (x = 8; x < 16; x ++) {
	// 		vram[y][x] = s[y%14][x%8];
	// 	}
	// }


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

			// Interrupt for text mode print has been sent.
			if (*((BYTE*)memory + 0xFFFE) == 0x02) { 

				printf("I AM IN VIDEO\n");
				// Get char byte from code page
				memcpy(byte_to_write, codePage[0x00], sizeof(byte_to_write));

				// // Get X and Y pos for the cursor
				cursor_x_pos = *((BYTE*)memory + 0xFFFD) + 1;
				cursor_y_pos = *((BYTE*)memory + 0xFFFC) + 1;

				// Calculate where this char starts on stops on VRAM
				x_stop = cursor_x_pos * 8;
				x_start = ( (x_stop - 8) < 0 ) ? 0 : (x_stop - 8);
				y_stop = cursor_y_pos * 14;
				y_start = ( (y_stop - 14) < 0 ) ? 0 : (y_stop - 14);

				// DEBUG
				printf("cursor_x_pos: %x\n", cursor_x_pos);
				printf("cursor_y_pos: %x\n", cursor_y_pos);
				printf("x_stop: %x\n", x_stop);
				printf("x_start: %x\n", x_start);
				printf("y_stop: %x\n", y_stop);
				printf("y_start: %x\n", y_start);

				// // Draw
				for (y = y_start; y < y_stop; y++) {
					for (x = x_start; x < x_stop; x++) {
						vram[y][x] = byte_to_write[y%14][x%8];
					}
				}

				// Interrupt done
				*((BYTE*)memory + 0xFFFE) = 0x00;
			}

			// Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear( gRenderer );

			for (y = 0; y < SCREEN_HEIGHT; y++) {
				for (x = 0; x < SCREEN_WIDTH; x++) {

					// Render red pixel
					SDL_Rect pixel = { x, y, 1, 1};
					int z = vram[y][x];

					SDL_SetRenderDrawColor( gRenderer, z, z, z, 255);		
					SDL_RenderFillRect( gRenderer, &pixel );
				}
			}

			// Update screen
			SDL_RenderPresent( gRenderer );
		}

	// Free resources and close SDL
	close_sdl();
		
	}
}

int keyboard_thread( void* memory[] ) {
		
	// Get key input
	while (!quit) {

		// Do nothing until the correct signal is passed.
		while (*((BYTE*)memory + 0xFFFE) != 0x01) { if (quit) goto stop; }

		// Read keyboard input
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		if ( currentKeyStates[ SDL_SCANCODE_A ]) {

			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x61;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_B ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x62;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_C ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x63;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_D ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x64;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_E ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x65;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_F ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x66;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_G ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x67;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_H ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x68;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_I ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x69;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_J ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x6A;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_K ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x6B;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_L ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x6C;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_M ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x6D;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_N ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x6E;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_O ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x6F;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_P ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x70;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Q ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x71;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_R ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x72;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_S ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x73;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_T ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x74;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_U ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x75;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_V ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x76;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_W ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x77;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_X ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x78;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Y ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x79;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Z ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + 0xFFFF) = 0x7A;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + 0xFFFE) = 0x00;
		}
		usleep(150000);	
	}
	
	// It stops here..
	stop: return 0;
}