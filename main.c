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
	and anything else I can think of ducking tapping on to this thing :p

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
		iconst, 0x01,
		gstore, 0xFF, 0xFE,
		iconst, 0x00,
		gstore, 0xFF, 0xFD,
		iconst, 0x00,
		gstore, 0xFF, 0xFC,
		iconst, 0x02,
		gstore, 0xFF, 0xFE,
		halt
	};
	WORD start = 0x0000;

	// Run the thread
	void* data = ram;
	SDL_Thread* threadID = SDL_CreateThread( keyboard_thread, "Simple", data);
	SDL_Thread* screenID = SDL_CreateThread( videoCard_thread, "Screen", data);

	cpu(ram, start);
	printf("DONE!\n");

	// Remove timer in case the call back was not called
	SDL_WaitThread( screenID, NULL);
	SDL_WaitThread( threadID, NULL);

	
	return 0;
}



void load_ram(BYTE ram[]) {
	// Open a file and load all the bytes into ram
}

