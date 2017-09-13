#ifndef _COMMON_H
#define _COMMON_H

// Define boolean data type
typedef enum bool {
	false, true
} bool;

// Main loop flag
bool quit = false;

// Data types
typedef signed	 char	   SBYTE;	// signed	 8-bits	
typedef unsigned char 	   BYTE;	// unsisgned 8-bits
typedef short unsigned int WORD;	// unsigned  16-bits

// Screen dimensions constants
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

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

// Function prototypes
WORD byte_to_word(BYTE, BYTE);

WORD byte_to_word(BYTE a, BYTE b) {
	WORD ret_val;
	ret_val= 0x0000 | (WORD)a;
	ret_val <<= 8;
	ret_val |= (WORD)b;
	return ret_val;
}

void word_to_bytes(WORD, BYTE*, BYTE*);

void word_to_bytes(WORD w, BYTE *hi, BYTE *low) {
	*low = w;
	w >>= 8;
	*hi = w;
}

#endif
