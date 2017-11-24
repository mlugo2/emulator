#ifndef _COMMON_H
#define _COMMON_H

// Define boolean data type
typedef enum bool {
	false, true
} bool;

// Main loop flag
bool quit = false;

// Data types
typedef unsigned char 	   		BYTE;	// unsigned  8-bits
typedef short unsigned int 		WORD;	// unsigned  16-bits
typedef unsigned long int  		DWORD;	// unsigned  32-bits
typedef unsigned long long      QWORD;	// unsigned  64-bits

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
void word_to_bytes(WORD, BYTE*, BYTE*);

BYTE get_opcode(DWORD);
BYTE get_rs(DWORD);
BYTE get_rt(DWORD);
BYTE get_rd(DWORD);
BYTE get_sa(DWORD);
BYTE get_funct(DWORD);
WORD get_imm16(DWORD);
DWORD get_target26(DWORD);

WORD byte_to_word(BYTE a, BYTE b) {
	WORD ret_val;
	ret_val= 0x0000 | (WORD)a;
	ret_val <<= 8;
	ret_val |= (WORD)b;
	return ret_val;
}

void word_to_bytes(WORD w, BYTE *hi, BYTE *low) {
	*low = w;
	w >>= 8;
	*hi = w;
}


BYTE get_opcode(DWORD instruction)
{
	// Shift down to last 6 bits
	instruction >>= 26;
	return (BYTE) instruction;
}

BYTE get_rs(DWORD instruction)
{
	instruction &= 0x3E00000;
	instruction >>= 21;
	return (BYTE) instruction;
}

BYTE get_rt(DWORD instruction)
{
	instruction &= 0x1F0000;
	instruction >>= 16;
	return (BYTE) instruction;
}

BYTE get_rd(DWORD instruction)
{
	instruction &= 0xF800;
	instruction >>= 11;
	return (BYTE) instruction;
}


BYTE get_sa(DWORD instruction)
{
	instruction &= 0x3E0;
	instruction >>=6;
	return (BYTE) instruction;
}

BYTE get_funct(DWORD instruction)
{
	instruction &= 0x1F;
	return (BYTE) instruction;
}

WORD get_imm16(DWORD instruction)
{
	instruction &= 0xFFFF;
	return (WORD) instruction;
}

DWORD get_target26(DWORD instruction)
{
	instruction &= 0x3FFFFFF;
	return instruction;
}

#endif
