#ifndef _COMMON_H
#define _COMMON_H

// Define boolean data type
typedef enum bool {
	false, true
} bool;

// Main loop flag
bool quit = false;

// Data types for the cpu
typedef unsigned char BYTE;			// 8-bits
typedef short unsigned int WORD;	// 16-bits

// Screen dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Definitions for memory map
#define MEM_ASCII 	0xFFFF
#define MEM_INT		0xFFFE
#define MEM_XPOS	0xFFFD
#define MEM_YPOS	0xFFFC
#define MEM_CNTM	0xFFFB
#define MEM_COUNT	0xFFFA
#define MEM_CTCON	0xFFF9

#endif
