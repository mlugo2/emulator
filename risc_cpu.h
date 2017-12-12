#include "common.h"

void risc_cpu(DWORD [], DWORD);

void risc_cpu(DWORD mem[], DWORD pc) {

	DWORD reg[0x20];
	DWORD instruction;
	DWORD temp32, hi, lo;
	QWORD temp64;

	BYTE opcode, rsReg, rtReg, rdReg,
		 shft, funct;

	WORD imm16;

	DWORD target26;

	// Initialization
	reg[0x00] = 0;			// reg0 should always be zero

	// Start the decoding
	while (1) {

		// Stop the cpu while the interupt is handled
		while (mem[MEM_INT] != 0x00) { if (quit) goto end; }
		
		printf("PC: %x\n", pc);
		printf("reg[4]: %x\n", reg[4]);
		printf("-----------\n\n");

		// Fetch
		instruction = mem[pc++];
		opcode = get_opcode(instruction);
		rsReg  = get_rs(instruction);
		rtReg  = get_rt(instruction);
		rdReg  = get_rd(instruction);
		shft   = get_sa(instruction);
		funct  = get_funct(instruction);
		imm16  = get_imm16(instruction);
		target26 = get_target26(instruction);

		// Decode
		switch(opcode) {

			/*****************************************
			 *	Arithmetic and Logical Instructions	 *
			 *****************************************/

			case 0x01:	// add
				break;
			case 0x02:	// addu
				reg[rdReg] = reg[rsReg] + reg[rtReg];
				break;
			case 0x03:	// addi
				break;
			case 0x04:	// addiu
				reg[rtReg] = reg[rsReg] + ((DWORD)imm16);
				break;
			case 0x05:	// and
				reg[rdReg] = reg[rsReg] & reg[rtReg];
				break;
			case 0x06:	// andi
				reg[rdReg] = reg[rsReg] & (((DWORD)imm16) << 16);
				break;
			case 0x07:	// div
				break;
			case 0x08:	// divu
				lo = reg[rsReg]/reg[rtReg];
				hi = reg[rsReg]%reg[rtReg];
				break;
			case 0x09:	// mult
				break;
			case 0x0A:	// multu
				temp64 = reg[rsReg] * reg[rtReg];
				lo = (DWORD) temp64;
				hi = (DWORD)(temp64 >>= 31);
				break;
			case 0x0B:	// nor
				reg[rdReg] = ~(reg[rsReg] | reg[rtReg]);
				break;
			case 0x0C:	// or
				reg[rdReg] = reg[rsReg] | reg[rtReg];
				break;
			case 0x0D:	// ori
				reg[rdReg] = reg[rsReg] & (((DWORD)imm16) << 16);
				break;
			case 0x0E:	// sll
				reg[rdReg] = reg[rtReg] << reg[shft];
				break;
			case 0x0F:	// sllv
				reg[rdReg] = reg[rtReg] << reg[rsReg];
				break;
			case 0x10:	// sra
				break;
			case 0x11:	// srav
				break;
			case 0x12:	// srl
				reg[rdReg] = reg[rtReg] >> reg[shft];
				break;
			case 0x13:	// srlv
				reg[rdReg] = reg[rtReg] >> reg[rsReg];
				break;
			case 0x14:	// sub
				break;
			case 0x15:	// subu
				reg[rdReg] = reg[rsReg] - reg[rtReg];
				break;
			case 0x16:	// xor
				reg[rdReg] = reg[rsReg] ^ reg[rtReg];
				break;
			case 0x17:	// xori
				reg[rdReg] = reg[rsReg] ^ (((DWORD)imm16) << 16);
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
				reg[rdReg] = ( reg[rsReg] < reg[rtReg] ) ? 1:0;
				break;
			case 0x1C:	// slti
				break;
			case 0x1D:	// sltiu
				reg[rdReg] = (reg[rsReg] < (((DWORD)imm16) << 16)) ? 1:0;
				break;

			/*****************************************
			 *	Branch Instructions					 *
			 *****************************************/

			case 0x1E:	// beq
				if ( reg[rsReg] == reg[rtReg] )
					pc += (imm16 << 2); 
				break;
			case 0x1F:	// bgtz
				if ( reg[rsReg] > 0 )
					pc += (imm16 << 2);
				break;
			case 0x20:	// blez
				break;
			case 0x21:	// bne
				if ( reg[rsReg] != reg[rtReg] )
					pc += imm16; 
				break;

			/*****************************************
			 *	Jump Instructions					 *
			 *****************************************/

			case 0x22:	// j
				pc = (target26 << 2);
				break;
			case 0x23:	// jal
				reg[31] = pc;
				pc = (target26 << 2);
				break;
			case 0x24:	// jalr
				reg[31] = reg[rdReg];
				pc = reg[rsReg];
				break;
			case 0x25:	// jr
				pc = reg[rsReg];
				break;

			/*****************************************
			 *	Load Instructions					 *
			 *****************************************/	
			case 0x26:	// lb
				break;
			case 0x27:	// lbu
				reg[rtReg] = mem[rsReg + imm16] & 0x000000FF;
				break;
			case 0x28:	// lh
				break;
			case 0x29:	// lhu
				reg[rtReg] = mem[rsReg + imm16] & 0x0000FFFF;
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
				mem[rsReg + imm16] = reg[rtReg];
				break;

			/*****************************************
			 *	Data Movement Instructions			 *
			 *****************************************/

			case 0x2E:	// mfhi
				reg[rdReg] = hi;
				break;
			case 0x2F:	// mflo
				reg[rdReg] = lo;
				break;
			case 0x30:	// mthi
				hi = reg[rsReg];
				break;
			case 0x31:	// mtlo
				lo = reg[rsReg];
				break;

			/*****************************************
			 *	Execption and Interrupt Instructions *
			 *****************************************/

			case 0x32:	// trap1 - inturrupt selection
				mem[MEM_INT] = reg[0x01];
				break;
			case 0x33:	// trap2 - xpos/x-hi
				mem[0xFFFD] = reg[0x01];
				break;
			case 0x34:	// trap3 - ypos/x-lo
				mem[0xFFFC] = reg[0x01];
				break;
			case 0x35:	// trap4 - char color font/y-hi
				mem[0xFFFB] = reg[0x01];
				break;
			case 0x36:	// trap5 - char color back/y-low
				mem[0xFFFA] = reg[0x01];
				break;
			case 0x37:	// trap6 - pixel color
				mem[0xFFF9] = reg[0x01];
				break;
			
			default:
				goto end;
				break;
		} // end of switch

		reg[0x00] = 0;		// reg0 should always be zero

	} // end of while
	end:	return;
}