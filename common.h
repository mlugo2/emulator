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

// #define SCREEN_WIDTH 320
// #define SCREEN_HEIGHT 240

// Definitions for memory map
#define MEM_ASCII 	0xFFFF
#define MEM_INT		0xFFFE
#define MEM_XPOS	0xFFFD	// Also HI XPOS for graphics
#define MEM_YPOS	0xFFFC	// Also LOW XPOS for graphics
#define MEM_CHCOL	0xFFFB	// Also HI YPOS for graphics
#define MEM_BACOL	0xFFFA	// Also LOW YPOS for graphics
#define MEM_PICOL	0xFFF9
#define MEM_CNTM	0xFFF8
#define MEM_COUNT	0xFFF7
#define MEM_CTCON	0xFFF6

#endif
