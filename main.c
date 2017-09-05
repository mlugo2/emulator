#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "screen.h"
#include "cpu.h"
#include "risc_cpu.h"
#include "peripherals.h"

/*
	Author: Marco Lugo

	Contributors: Kristina Garcia

	Summary:
	--------
	
		This is the Sunflower computer system.  This is a simulation of a
	complete computing system, including: cpu, memory, I/O, and display--
	and anything else I can think of duck tapping on to this thing 

	Description:
	------------

		The Sunflower computer system has a stack micro-architecture.

*/

// Function prototypes
void load_ram(BYTE []);

int main(int argc, char const *argv[])
{
	printf("Hello world!\n");
	
	// main memory
	BYTE ram[0xffff] = {

		iconst, 0x23,		// Set color of pixel
		gstore, 0xff, 0xf9,

		iconst, 0x00,		// set pixel position to (0,0)
		iconst, 0x00,	
		iconst, 0x00,
		iconst, 0x00,
		gstore, 0xff, 0xfd,
		gstore, 0xff, 0xfc,
		gstore, 0xff, 0xfb,
		gstore, 0xff, 0xfa,

		iconst, 0x03,		// call graphics inturrupt
		gstore, 0xff, 0xfe,

		iconst, 0x55,		// Set color of pixel
		gstore, 0xff, 0xf9,

		iconst, 0x01,		// set pixel position to (0,0)
		gstore, 0xff, 0xfc,

		iconst, 0x03,		// call graphics inturrupt
		gstore, 0xff, 0xfe,


		halt
	};


	WORD start = 0x0000;

	// Run the threads
	void* data = ram;
	SDL_Thread* threadID = SDL_CreateThread( keyboard_thread, "Simple", data);
	SDL_Thread* screenID = SDL_CreateThread( videoCard_thread, "Screen", data);
	SDL_Thread* clockID = SDL_CreateThread( clock_thread, "Clock", data);

	// Da CPU
	cpu(ram, start);

	// Remove timer in case the call back was not called
	SDL_WaitThread( screenID, NULL);
	SDL_WaitThread( threadID, NULL);
	SDL_WaitThread( clockID, NULL);

	return 0;
}

void load_ram(BYTE ram[]) {
	// Open a file and load all the bytes into ram
}