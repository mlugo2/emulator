#include <stdio.h>
#include <SDL2/SDL.h>

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

// Data types for the cpu
typedef char BYTE;			// 8-bits
typedef short int WORD;		// 16-bits

// Screen dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


/*
	For testing purposes. 
	Erase once done.
*/
#define iadd 0x01
#define isub 0x02
#define imul 0x03
#define ilt  0x04
#define ieq  0x05
#define br   0x06
#define brt  0x07
#define brf  0x08
#define iconst 0x09
#define load 0x0a
#define gload 0x0b
#define store 0x0c
#define gstore 0x0d
#define print 0x0e
#define pop  0x0f
#define call 0x10
#define ret  0x11
#define halt 0x12

// Function prototypes
void cpu(BYTE [], WORD);
void load_ram(BYTE []);
void display();

int main(int argc, char const *argv[])
{
	printf("Hello world!\n");
	
	// main memory
	BYTE ram[0xffff] = {
		iconst, 1,			// 0
		ret,
		call, 0x00,0x00, 0x00,	// 3
		print,
		halt
	};
	WORD start = 0x0003;

	cpu(ram, start);

	return 0;
}

void cpu(BYTE ram[], WORD start) {
	// Initialize the stack
	BYTE stack[0xff];
	BYTE sp = 0xff;
	BYTE fp = 0x00;
	WORD pc = start;
	BYTE nargs;
	BYTE rvalue;

	BYTE opcode;

	// Start the decoding
	while (1) {

		// Local temp variables
		BYTE v, a, b;
		WORD addr;

		opcode = ram[pc++];

		switch(opcode) {
			case 0x01:	// iadd
				b = stack[sp--];
				a = stack[sp];
				stack[sp] = a + b;
				break;

			case 0x02:	// isub
				b = stack[sp--];
				a = stack[sp];
				stack[sp] = a - b;
				break;

			case 0x03:	// imul
				b = stack[sp--];
				a = stack[sp];
				stack[sp] = a * b;
				break;

			case 0x04:	// ilt
				b = stack[sp--];
				a = stack[sp];
				stack[sp] = (a < b) ? 1 : 0;
				break;

			case 0x05:	// ieq
				b = stack[sp--];
				a = stack[sp];
				stack[sp] = (a == b) ? 1 : 0;
				break;

			case 0x06:	// br
				a = ram[pc++];
				b = ram[pc];
				addr = 0x0000 | (WORD)a;
				addr <<= 8;
				addr |= (WORD)b;
				pc = addr;
				break;

			case 0x07:	// brt
				if (stack[sp] == 1) {
					a = ram[pc++];
					b = ram[pc];
					addr = 0x0000 | (WORD)a;
					addr <<= 8;
					addr |= (WORD)b;
					pc = addr;
				}
				sp--;
				break;

			case 0x08:	// brf
				if (stack[sp] == 0) {
					a = ram[pc++];
					b = ram[pc];
					addr = 0x0000 | (WORD)a;
					addr <<= 8;
					addr |= (WORD)b;
					pc = addr;
				}
				sp--;
				break;

			case 0x09:	// iconst
				v = ram[pc++];
				stack[++sp] = v;
				break;

			case 0x0a:	// load
				v = ram[pc++];
				stack[++sp] = stack[fp+v];
				break;

			case 0x0b:	// global load
				a = ram[pc++];	// hi byte
				b = ram[pc++];	// low byte
				addr = 0x0000 | (WORD)a;
				addr <<= 8;
				addr |= (WORD)b;
				v = ram[addr];
				stack[++sp] = v;
				
				break;

			case 0x0c:	// store
				v = ram[pc++];
				stack[fp+v] = stack[sp--];
				break;

			case 0x0d:	// global store
				v = stack[sp--];
				a = ram[pc++];	// hi byte
				b = ram[pc++];	// low byte
				addr = 0x0000 | (WORD)a;
				addr <<= 8;
				addr |= (WORD)b;
				ram[addr] = v;
				
				break;

			case 0x0e:	// print tos
				v = stack[sp--];
				printf("%x\n", v);
				break;

			case 0x0f:	// pop
				sp--;
				break;

			case 0x10:	// call
				a = ram[pc++];	// hi byte
				b = ram[pc++];	// low byte
				addr = 0x0000 | (WORD)a;
				addr <<= 8;
				addr |= (WORD)b;
				a = pc;
				b = pc >> 8;
				nargs = ram[pc++];
				stack[++sp] = nargs;
				stack[++sp] = fp;
				stack[++sp] = a;
				stack[++sp] = b;
				fp = sp;
				pc = addr;
				break;

			case 0x11:	// ret
				rvalue = stack[sp--];
				sp = fp;
				a = stack[sp--];
				b = stack[sp--];
				pc = 0x0000 | (WORD)a;
				pc <<= 8;
				pc |= (WORD)b;
				fp = stack[sp--];
				nargs = stack[sp--];
				sp -= nargs;
				stack[++sp] = rvalue;
				break;

			case 0x12:	// halt
				goto stop;
				break;
		}

	} // end of while

	stop: return;
}

void load_ram(BYTE ram[]) {
	// Open a file and load all the bytes into ram
}
