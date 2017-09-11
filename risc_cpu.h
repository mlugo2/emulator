#include "common.h"

void risc_cpu(BYTE [], BYTE, WORD, WORD);

void risc_cpu(BYTE mem[], BYTE sp, WORD start, WORD prog_len) {

	// The setup
	BYTE reg[0x20];		// 8-bit wide registers
	BYTE hi, lo;
	BYTE opcode;
	WORD pc;

	// Initialization
	reg[0x00] = 0;		// reg0 should always be zero
	pc = start;

	// Start the decoding
	while (pc < prog_len - 1) {
		
		// Fetch
		opcode = mem[pc++];

		// Decode
		switch(opcode) {

			/*****************************************
			 *	Arithmetic and Logical Instructions	 *
			 *****************************************/

			case 0x01:	// add
				
				break;
			case 0x02:	// addu
				reg[mem[pc]] = reg[mem[pc++]] + reg[mem[pc++]];
				break;
			case 0x03:	// addi
				
				break;
			case 0x04:	// addiu
				reg[mem[pc]] = reg[mem[pc++]] + mem[pc++];
				break;
			case 0x05:	// and
				reg[mem[pc]] = reg[mem[pc++]] & reg[mem[pc++]];
				break;
			case 0x06:	// andi
				reg[mem[pc]] = reg[mem[pc++]] & mem[pc++];
				break;
			case 0x07:	// div
				break;
			case 0x08:	// divu
				break;
			case 0x09:	// mult
				break;
			case 0x0A:	// multu
				break;
			case 0x0B:	// nor
				reg[mem[pc]] = ~(reg[mem[pc++]] | reg[mem[pc++]]);
				break;
			case 0x0C:	// or
				reg[mem[pc]] = reg[mem[pc++]] | reg[mem[pc++]];
				break;
			case 0x0D:	// ori
				reg[mem[pc]] = reg[mem[pc++]] | mem[pc++];
				break;
			case 0x0E:	// sll
				reg[mem[pc]] = reg[mem[pc++]] << mem[pc++];
				break;
			case 0x0F:	// sllv
				reg[mem[pc]] = reg[mem[pc++]] << reg[mem[pc++]];
				break;
			case 0x10:	// sra
				break;
			case 0x11:	// srav
				break;
			case 0x12:	// srl
				reg[mem[pc]] = reg[mem[pc++]] >> mem[pc++];
				break;
			case 0x13:	// srlv
				reg[mem[pc]] = reg[mem[pc++]] >> reg[mem[pc++]];
				break;
			case 0x14:	// sub
				break;
			case 0x15:	// subu
				reg[mem[pc]] = reg[mem[pc++]] - reg[mem[pc++]];
				break;
			case 0x16:	// xor
				reg[mem[pc]] = reg[mem[pc++]] ^ reg[mem[pc++]];
				break;
			case 0x17:	// xori
				reg[mem[pc]] = reg[mem[pc++]] ^ mem[pc++];
				break;

			/*****************************************
			 *	Constant-Manipulating Instructions	 *
			 *****************************************/

			case 0x18:	// lhi
				break;
			case 0x19:	// llo
				break;

			/*****************************************
			 *	Comparison Instructions				 *
			 *****************************************/

			case 0x1A:	// slt
				break;
			case 0x1B:	// sltu
				break;
			case 0x1C:	// slti
				break;
			case 0x1D:	// sltiu
				break;

			/*****************************************
			 *	Branch Instructions					 *
			 *****************************************/

			case 0x1E:	// beq
				break;
			case 0x1F:	// bgtz
				break;
			case 0x20:	// blez
				break;
			case 0x21:	// bne
				break;

			/*****************************************
			 *	Jump Instructions					 *
			 *****************************************/

			case 0x22:	// j
				break;
			case 0x23:	// jal
				break;
			case 0x24:	// jalr
				break;
			case 0x25:	// jr
				break;

			/*****************************************
			 *	Load Instructions					 *
			 *****************************************/	
			case 0x26:	// lb
				break;
			case 0x27:	// lbu
				break;
			case 0x28:	// lh
				break;
			case 0x29:	// lhu
				break;
			case 0x2A:	// lw
				break;

			/*****************************************
			 *	Store Instructions					 *
			 *****************************************/

			case 0x2B:	// sb
				break;
			case 0x2C:	// sh
				break;
			case 0x2D:	// sw
				break;

			/*****************************************
			 *	Data Movement Instructions			 *
			 *****************************************/

			case 0x2E:	// mfhi
				break;
			case 0x2F:	// mflo
				break;
			case 0x30:	// mthi
				break;
			case 0x31:	// mtlo
				break;

			/*****************************************
			 *	Execption and Interrupt Instructions *
			 *****************************************/

			case 0x32:	// tr1
				break;
			case 0x33:	// tr5
				break;
			case 0x34:	// tr10
				break;
			case 0x35:	// tr101
				break;
			case 0x36:	// tr102
				break;
			
			default:
				break;
		} // end of switch
	} // end of while

}