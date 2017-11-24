#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "screen.h"
#include "risc_cpu.h"
#include "peripherals.h"

/*
	Author: Marco Lugo

	Contributors: Kristina Garcia

	Summary:
	--------
	
		This is the Sunflower computer system.  This is a simulation of a
	complete computing system, including: cpu, memory, I/O, and display--
	and anything else I can think of duck tapping on to this thing.

	Description:
	------------

		The Sunflower computer system has a risc architecture.

*/

int main(int argc, char const *argv[])
{
	// main memory 1MB
	// DWORD *mem;
	// mem = malloc(sizeof(DWORD)*0x3FFFFFFF);
	// memset(mem, 0, sizeof(DWORD)*0x3FFFFFFF);

	DWORD mem[0xFFFF] = {
		/* Set font color */
		0x10010008,		// addiu $1, 0x08
		0xD4000000,		// trap4 color font

		/* Set background color */
		0x1001000F,		// addiu $1, 0x0F
		0xD8000000,		// trap5 background color

		/* Set cursor X and Y pos to 0 */
		0x10010000,		// addiu $1, 0x00
		0xCC000000,		// trap2 X pos
		0xD0000000,		// trap3 Y pos

		/* Get char from user */
		0x10010001,		// addiu $1, 0x01
		0xC8000000,		// trap1 interrupt selection

		/* Print char */
		0x10010002,		// addiu $1, 0x02
		0xC8000000,		// trap1 interrupt selection
	};

	DWORD start = 0;

	// Run the threads
	void* data = mem;
	SDL_Thread* keyID = SDL_CreateThread( keyboard_thread, "Key", data);
	SDL_Thread* screenID = SDL_CreateThread( videoCard_thread, "Screen", data);
	SDL_Thread* clockID = SDL_CreateThread( clock_thread, "Clock", data);

	// The CPU
	risc_cpu(mem, start);

	// Remove timer in case the call back was not called
	SDL_WaitThread( screenID, NULL);
	SDL_WaitThread( keyID, NULL);
	SDL_WaitThread( clockID, NULL);

	return 0;
}
