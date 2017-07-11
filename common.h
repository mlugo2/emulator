#ifndef _COMMON_H
#define _COMMON_H
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

#endif
