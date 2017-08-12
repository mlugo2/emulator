#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "screen.h"
#include "cpu.h"
#include "peripherals.h"

/*
	Author: Marco Lugo

	Summary:
	--------
	
		This is the Sunflower computer system.  This is a simulation of a
	complete computing system, including: cpu, memory, I/O, and display--
	and anything else I can think of duck tapping on to this thing 

	Description:
	------------

		The Sunflower computer system has a stack architecture.

*/

// Function prototypes
void load_ram(BYTE []);

int main(int argc, char const *argv[])
{
	printf("Hello world!\n");
	
	// main memory
	BYTE ram[0xffff] = {

		iconst, 0x37,		// Set color of char to white
		gstore, 0xff, 0xfb,
		iconst, 0x00,		// Set color of back to black
		gstore, 0xff, 0xfa,
		iconst,	0x00,		// initialize cursor xpos
		gstore, 0xff, 0xfd,

		iconst, 0x01,		// Get input from keyboard
		gstore, 0xff, 0xfe,
		iconst, 0x02,		// print to screen		
		gstore, 0xff, 0xfe,
		gload, 0xff, 0xfd,	// get current cursor xpos
		iconst, 0x01,		// inc by 1
		iadd,
		gstore, 0xff, 0xfd,	// set new xpos
		br, 0x00, 0x0f,
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
	printf("DONE!\n");

	// Remove timer in case the call back was not called
	SDL_WaitThread( screenID, NULL);
	SDL_WaitThread( threadID, NULL);
	SDL_WaitThread( clockID, NULL);

	return 0;
}

void load_ram(BYTE ram[]) {
	// Open a file and load all the bytes into ram
}