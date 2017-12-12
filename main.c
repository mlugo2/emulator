#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "screen.h"
#include "risc_cpu.h"
#include "peripherals.h"

/*
	Author: Marco Lugo

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

	DWORD mem[0xFFFF] = {
		/* Set font color */
/*00*/	0x10010008,		// addiu $1, $0, 0x08
/*01*/	0xD4000000,		// trap4 color font

		/* Set background color */
/*02*/	0x1001000F,		// addiu $1, $0, 0x0F
/*03*/	0xD8000000,		// trap5 background color

		/* Store where to jump back to */
/*04*/	0x10060008,		// addiu $6, $0, 0x09

		/* Store max X pos in $3 */
/*05*/	0x10030028,		// addiu $3, $0, 0x0F

		/* Store X pos in $4 */
/*06*/	0x10040000,		// addiu $4, $0, 0x00

		/* Store Y pos in $5 */
/*07*/	0x10050000,		// addiu $5, $0, 0x00

		/* Set cursor X pos */
/*08*/	0x08040800,		// addu $1, $0, $4
/*09*/	0xCC000000,		// trap2 X pos

		/* Set cursor Y pos */
/*0A*/	0x08050800,		// addu $1, $0, $5
/*0B*/	0xD0000000,		// trap3 Y pos

		/* Get char from user */
/*0C*/	0x10010001,		// addiu $1, $0, 0x01
/*0D*/	0xC8000000,		// trap1 interrupt selection

		/* Print char */
/*0E*/	0x10010002,		// addiu $1, $0, 0x02
/*0F*/	0xC8000000,		// trap1 interrupt selection

		/* Inc X pos */
/*10*/	0x10840001,		// addiu $4, $4, 0x01

		/* Check X pos */
/*11*/	0x84640002,		// if $4 != $3 branch
						
/*12*/	0x10040000,		// X pos == max X pos
						// set x Pos to 0

		/* Inc Y pos */
/*13*/	0x10A50001,		// addiu $5, $0, 0x01

/*14*/	0x94C00000,		// branch here, jump to continue typing
	
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
