#include <SDL2/SDL_thread.h>
#include "common.h"
#include "font_rom.h"

// thread function prototypes
int keyboard_thread( void* memory[] );
int videoCard_thread( void* memory[] );
int clock_thread( void* memory[] );

typedef struct color_values {
		int red;
		int green;
		int blue;
	} color;

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

	// fuction prototype
	color get_color(BYTE b);

	// Initialize vram
	for (y = 0; y < SCREEN_HEIGHT; y++) {
		for (x = 0; x < SCREEN_WIDTH; x ++) {
			vram[y][x] = 0;
		}
	}

	BYTE byte_to_write[14][8];

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
			if (*((BYTE*)memory + MEM_INT) == 0x02) { 

				// Get char byte from code page
				// TODO: actually pass the hex to codePage[]
				memcpy(byte_to_write, codePage[0x00], sizeof(byte_to_write));

				// // Get X and Y pos for the cursor
				cursor_x_pos = *((BYTE*)memory + MEM_XPOS) + 1;
				cursor_y_pos = *((BYTE*)memory + MEM_YPOS) + 1;

				// Calculate where this char starts and stops in VRAM
				x_stop = cursor_x_pos * 8;
				x_start = ( (x_stop - 8) < 0 ) ? 0 : (x_stop - 8);
				y_stop = cursor_y_pos * 14;
				y_start = ( (y_stop - 14) < 0 ) ? 0 : (y_stop - 14);

				// Fill vram given cursor location
				for (y = y_start; y < y_stop; y++) {
					for (x = x_start; x < x_stop; x++) {
						BYTE back_color = 10;
						BYTE front_color = 30;
						byte_to_write[y%14][x%8] = ( byte_to_write[y%14][x%8] == 0) ? (back_color) : (front_color);
						vram[y][x] = byte_to_write[y%14][x%8];
					}
				}

				// Interrupt done
				*((BYTE*)memory + MEM_INT) = 0x00;
			}

			// Interrupt for graphics mode
			// if (*((BYTE*)memory + MEM_INT) == 0x03) { 

			// 	// Get x position

			// 	// Get y position

			// 	// Get color of pixel

			// 	// Draw pixel at given location

			// 	// Interrupt done
			// 	*((BYTE*)memory + MEM_INT) = 0x00;
			// }

			// Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear( gRenderer );

			// Render to screen given vram
			for (y = 0; y < SCREEN_HEIGHT; y++) {
				for (x = 0; x < SCREEN_WIDTH; x++) {

					// Render pixel
					SDL_Rect pixel = { x, y, 1, 1};

					// Get color from palette
					color z = get_color( vram[y][x] );

					// Draw to the screen
					SDL_SetRenderDrawColor( gRenderer, z.red, z.green, z.blue, 255);
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

color get_color(BYTE b) {


	// Available colors
	color c0 = {0, 0, 0};
	color c1 = {0, 0, 1};
	color c2 = {120, 120, 120};
	color c3 = {248, 216, 248};
	color c4 = {0, 64, 88};
	color c5 = {0, 136, 136};
	color c6 = {0, 232, 216};
	color c7 = {0, 252, 252};
	color c8 = {0, 88, 0};
	color c9 = {0, 168, 68};
	color c10 = {88, 248, 152};
	color c11 = {184, 248, 216};
	color c12 = {0, 104, 0};
	color c13 = {0, 168, 0};
	color c14 = {88, 216, 84};
	color c15 = {184, 248, 184};
	color c16 = {0, 120, 0};
	color c17 = {0, 184, 0};
	color c18 = {184, 248, 24};
	color c19 = {216, 248, 120};
	color c20 = {80, 48, 0};
	color c21 = {172, 124, 0};
	color c22 = {248, 184, 0};
	color c23 = {248, 216, 120};
	color c24 = {136, 20, 0};
	color c25 = {228, 92, 16};
	color c26 = {252, 160, 68};
	color c27 = {252, 224, 168};
	color c28 = {168, 16, 0};
	color c29 = {248, 56, 0};
	color c30 = {248, 120, 88};
	color c31 = {240, 208, 176};
	color c32 = {168, 0, 32};
	color c33 = {228, 0, 88};
	color c34 = {248, 88, 152};
	color c35 = {248, 164, 192};
	color c36 = {148, 0, 132};
	color c37 = {216, 0, 204};
	color c38 = {248, 120, 248};
	color c39 = {248, 184, 248};
	color c40 = {68, 40, 188};
	color c41 = {104, 68, 252};
	color c42 = {152, 120, 248};
	color c43 = {216, 184, 248};
	color c44 = {0, 0, 188};
	color c45 = {0, 88, 248};
	color c46 = {104, 136, 252};
	color c47 = {184, 184, 248};
	color c48 = {0, 0, 252};
	color c49 = {0, 120, 248};
	color c50 = {60, 188, 252};
	color c51 = {164, 228, 252};
	color c52 = {124, 124, 124};
	color c53 = {188, 188, 188};
	color c54 = {248, 248, 248};
	color c55 = {252, 252, 252};

	color palette[] = {
		c0, c1, c2, c3, c4, c5, c6, c7,
		c8, c9, c10, c11, c12, c13, c14, c15,
		c16, c17, c18, c19, c20, c21, c22, c23,
		c24, c25, c26, c27, c28, c29, c30, c31,
		c32, c33, c34, c35, c36, c37, c38, c39,
		c40, c41, c42, c43, c44, c45, c46, c47,
		c48, c49, c50, c51, c52, c53, c54, c55
	};

	// Only allow 55 as max
	if (b > 55) b = 55;

	return palette[b];

}

int keyboard_thread( void* memory[] ) {
		
	// Get key input
	while (!quit) {

		// Do nothing until the correct signal is passed.
		while (*((BYTE*)memory + MEM_INT) != 0x01) { if (quit) goto stop; }

		// Read keyboard input
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		if ( currentKeyStates[ SDL_SCANCODE_A ]) {

			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x61;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_B ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x62;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_C ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x63;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_D ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x64;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_E ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x65;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_F ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x66;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_G ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x67;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_H ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x68;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_I ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x69;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_J ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x6A;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_K ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x6B;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_L ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x6C;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_M ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x6D;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_N ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x6E;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_O ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x6F;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_P ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x70;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Q ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x71;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_R ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x72;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_S ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x73;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_T ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x74;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_U ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x75;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_V ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x76;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_W ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x77;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_X ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x78;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Y ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x79;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		else if ( currentKeyStates[ SDL_SCANCODE_Z ]) {
			// Save appropriate ASCII code into memory 
			*((BYTE*)memory + MEM_ASCII) = 0x7A;

			// Set SFR to allow CPU to continue
			*((BYTE*)memory + MEM_INT) = 0x00;
		}
		// TODO change this to sdl_delay()
		usleep(150000);	
	}
	
	// It stops here..
	stop: return 0;
}


int clock_thread( void* memory[] ) {

	// Initialize var
	BYTE startTime = 0;

	// Initialize flags
	BYTE mode;
	BYTE start;
	BYTE stop;
	BYTE stat;
	BYTE enInt;

	BYTE COUNT = *((BYTE*)memory + MEM_COUNT);

	// Function
	bool tick(BYTE t);
	
end:	while( !quit ) {

		// First hurdle, is stop activated?
		// if it is, wait here
		while (stop) { stop  = (*((BYTE*)memory + MEM_CTCON	) >> 1) & 0x01; 
			if(quit) goto end;
		}
		
		// enInt = (*((BYTE*)memory + MEM_CTCON	) >> 4) & 0x01;

		// Stay here until start bit is set
		while (!start) { start = *((BYTE*)memory + MEM_CTCON	) & 0x01; 
			if(quit) goto end;
		}

		// Now get the mode
		mode  = *((BYTE*)memory + MEM_CTCON	) >> 7;

		// Initialize: COUNT = CNTM;
		*((BYTE*)memory + MEM_COUNT) = *((BYTE*)memory + MEM_CNTM);

		// Counter or Timer
		if (mode == 0) { 	// Counter mode

			// Set start to 0
			*((BYTE*)memory + MEM_CTCON	) &= 0xFE;
			start = 0;

			// Count down from COUNT
			while ( *((BYTE*)memory + MEM_COUNT) > 0 ) {

				// Decrease COUNT
				*((BYTE*)memory + MEM_COUNT) = ( tick( (BYTE) SDL_GetTicks() )) 
				? *((BYTE*)memory + MEM_COUNT) - 0x01 : *((BYTE*)memory + MEM_COUNT);
				if(quit) goto end;

				// Actual delay
				SDL_Delay(1);
			}

			// Finished, set CTCON[6]
			*((BYTE*)memory + MEM_COUNT) |= 0x40;
		}
		else {				// Timer mode
			// TODO
		}
		
		printf("Timer done\n");
	} // end of while
	
}

bool tick( BYTE t) {
	if (t % 2 == 0)
		return true;
	else
		return false;
}