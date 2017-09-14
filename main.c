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

		The Sunflower computer system has a risc or stack micro-architecture.

*/

// Function prototypes
void load_ram(BYTE []);

int main(int argc, char const *argv[])
{
	printf("Hello world!\n");

	// main memory
	BYTE mem[0xffff] = {
		// Set x,y pos for cursor
		0x33, 0x00, 0x00, 0x00, 0x00,
		0x2b, 0x00, 26, 27, 0x00, 
		0x34, 0x00, 0x00, 0x00, 0x00,
		0x2b, 0x00, 26, 27, 0x00,

		// Set color for text
		0x35, 0x00, 0x00, 0x00, 0x00,
		0x04, 0x01, 0x00, 0x13, 0x00,
		0x2b, 0x01, 26, 27, 0x00,

		0x36, 0x00, 0x00, 0x00, 0x00,
		0x04, 0x01, 0x00, 0x2c, 0x00,
		0x2b, 0x01, 26, 27, 0x00,

		// Call keyboard interrupt
		0x32, 0x00, 0x00, 0x00, 0x00,
		0x04, 0x01, 0x00, 0x01, 0x00,
		0x2b, 0x01, 26, 27, 0x00,

		// print to screen
		0x32, 0x00, 0x00, 0x00, 0x00,
		0x04, 0x01, 0x00, 0x02, 0x00,
		0x2b, 0x01, 26, 27, 0x00,
		0xff
	};


	WORD start = 0x0000;

	// Run the threads
	void* data = mem;
	SDL_Thread* threadID = SDL_CreateThread( keyboard_thread, "Key", data);
	SDL_Thread* screenID = SDL_CreateThread( videoCard_thread, "Screen", data);
	SDL_Thread* clockID = SDL_CreateThread( clock_thread, "Clock", data);

	// Da CPU
	// cpu(mem, start);

	risc_cpu(mem, 0, start);

	// Remove timer in case the call back was not called
	SDL_WaitThread( screenID, NULL);
	SDL_WaitThread( threadID, NULL);
	SDL_WaitThread( clockID, NULL);

	return 0;
}

void load_ram(BYTE mem[]) {
	// Open a file and load all the bytes into mem
}