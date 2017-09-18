#include "common.h"

void risc_cpu(BYTE [], BYTE, WORD);

void risc_cpu(BYTE mem[], BYTE sp, WORD start) {

	// The setup
	BYTE reg[0x20];		// 8-bit wide registers
	BYTE hi, lo;
	BYTE opcode;
	WORD pc;

	BYTE a;				// temp variables
	BYTE b;

	// Initialization
	reg[0x00] = 0;		// reg0 should always be zero
	pc = start;

	// Start the decoding
	while (1) {

		// Stop the cpu while the interupt is handled
		while (mem[MEM_INT] != 0x00) { if (quit) goto end; }
		
		// Fetch
		opcode = mem[pc++];

		//printf("opcode: %x\n", opcode);

		// Decode
		switch(opcode) {

			/*****************************************
			 *	Arithmetic and Logical Instructions	 *
			 *****************************************/

			case 0x01:	// add
				
				break;
			case 0x02:	// addu
				reg[mem[pc++]] = reg[mem[pc++]] + reg[mem[pc++]]; pc++;
				break;
			case 0x03:	// addi
				
				break;
			case 0x04:	// addiu
				reg[mem[pc++]] = reg[mem[pc++]] + mem[pc++]; pc++;
				break;
			case 0x05:	// and
				reg[mem[pc++]] = reg[mem[pc++]] & reg[mem[pc++]]; pc++;
				break;
			case 0x06:	// andi
				reg[mem[pc++]] = reg[mem[pc++]] & mem[pc++]; pc++;
				break;
			case 0x07:	// div
				break;
			case 0x08:	// divu
				a = reg[mem[pc++]];
				b = reg[mem[pc++]];
				lo = a / b;
				hi = a % b;
				pc+=2;
				break;
			case 0x09:	// mult
				break;
			case 0x0A:	// multu
				lo = reg[mem[pc++]] * reg[mem[pc++]]; pc++; pc++;
				break;
			case 0x0B:	// nor
				reg[mem[pc++]] = ~(reg[mem[pc++]] | reg[mem[pc++]]); pc++;
				break;
			case 0x0C:	// or
				reg[mem[pc++]] = reg[mem[pc++]] | reg[mem[pc++]]; pc++;
				break;
			case 0x0D:	// ori
				reg[mem[pc++]] = reg[mem[pc++]] | mem[pc++]; pc++;
				break;
			case 0x0E:	// sll
				reg[mem[pc++]] = reg[mem[pc++]] << mem[pc++]; pc++;
				break;
			case 0x0F:	// sllv
				reg[mem[pc++]] = reg[mem[pc++]] << reg[mem[pc++]]; pc++;
				break;
			case 0x10:	// sra
				break;
			case 0x11:	// srav
				break;
			case 0x12:	// srl
				reg[mem[pc++]] = reg[mem[pc++]] >> mem[pc++]; pc++;
				break;
			case 0x13:	// srlv
				reg[mem[pc++]] = reg[mem[pc++]] >> reg[mem[pc++]]; pc++;
				break;
			case 0x14:	// sub
				break;
			case 0x15:	// subu
				reg[mem[pc++]] = reg[mem[pc++]] - reg[mem[pc++]]; pc++;
				break;
			case 0x16:	// xor
				reg[mem[pc++]] = reg[mem[pc++]] ^ reg[mem[pc++]]; pc++;
				break;
			case 0x17:	// xori
				reg[mem[pc++]] = reg[mem[pc++]] ^ mem[pc++]; pc++;
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
				reg[mem[pc++]] = ( reg[mem[pc++]] < reg[mem[pc++]] ) ? 1:0;
				pc++;
				break;
			case 0x1C:	// slti
				break;
			case 0x1D:	// sltiu
				reg[mem[pc++]] = ( reg[mem[pc++]] < mem[pc++] ) ? 1:0;
				pc++;
				break;

			/*****************************************
			 *	Branch Instructions					 *
			 *****************************************/

			case 0x1E:	// beq
				pc = ( reg[mem[pc++]] == reg[mem[pc++]] ) ? 
				(byte_to_word(mem[pc++], mem[pc++])):pc;
				break;
			case 0x1F:	// bgtz
				pc = ( reg[mem[pc++]] > reg[mem[pc++]] ) ? 
				(byte_to_word(mem[pc++], mem[pc++])):pc;
				break;
			case 0x20:	// blez
				pc = ( reg[mem[pc++]] <= reg[mem[pc++]] ) ? 
				(byte_to_word(mem[pc++], mem[pc++])):pc;
				break;
			case 0x21:	// bne
				pc = ( reg[mem[pc++]] != reg[mem[pc++]] ) ? 
				(byte_to_word(mem[pc++], mem[pc++])):pc;
				break;

			/*****************************************
			 *	Jump Instructions					 *
			 *****************************************/

			case 0x22:	// j
				pc = byte_to_word(mem[pc++], mem[pc++]);
				pc+=2;
				break;
			case 0x23:	// jal
				word_to_bytes(pc, &a, &b);
				reg[30] = lo;
				reg[31] = hi;
				pc = byte_to_word(mem[pc++], mem[pc++]);
				pc+=2;
				break;
			case 0x24:	// jalr
				word_to_bytes(pc, &a, &b);
				reg[30] = lo;
				reg[31] = hi;
				pc = byte_to_word(reg[mem[pc++]], reg[mem[pc++]]);
				pc+=2;
				break;
			case 0x25:	// jr
				pc = byte_to_word(reg[mem[pc++]], reg[mem[pc++]]);
				pc+=2;
				break;

			/*****************************************
			 *	Load Instructions					 *
			 *****************************************/	
			case 0x26:	// lb
				reg[mem[pc++]] = mem[byte_to_word(mem[pc++], mem[pc++])];
				pc++;
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
				a = reg[mem[pc++]];
				mem[byte_to_word(mem[pc++], mem[pc++])] = a;
				pc++;
				break;
			case 0x2C:	// sh
				break;
			case 0x2D:	// sw
				break;

			/*****************************************
			 *	Data Movement Instructions			 *
			 *****************************************/

			case 0x2E:	// mfhi
				reg[mem[pc++]] = hi; pc+=3;
				break;
			case 0x2F:	// mflo
				reg[mem[pc++]] = lo; pc+=3;
				break;
			case 0x30:	// mthi
				hi = reg[mem[pc++]]; pc+=3;
				break;
			case 0x31:	// mtlo
				lo = reg[mem[pc++]]; pc+=3;
				break;

			/*****************************************
			 *	Execption and Interrupt Instructions *
			 *****************************************/

			case 0x32:	// trap1 - inturrupt selection
				a = reg[0x01];
				mem[0xFFFE] = a;
				pc+=4;
				break;
			case 0x33:	// trap2 - xpos/x-hi
				a = reg[0x01];
				mem[0xFFFD] = a;
				pc+=4;
				break;
			case 0x34:	// trap3 - ypos/x-lo
				a = reg[0x01];
				mem[0xFFFC] = a;
				pc+=4;
				break;
			case 0x35:	// trap4 - char color/y-hi
				a = reg[0x01];
				mem[0xFFFB] = a;
				pc+=4;
				break;
			case 0x36:	// trap5 - char back/y-low
				a = reg[0x01];
				mem[0xFFFA] = a;
				pc+=4;
				break;
			case 0x37:	// trap6 - pixel color
				a = reg[0x01];
				mem[0xFFF9] = a;
				pc+=4;
				break;
			
			default:
				goto end;
				break;
		} // end of switch

		reg[0x00] = 0;		// reg0 should always be zero

	} // end of while
	end:	return;
}