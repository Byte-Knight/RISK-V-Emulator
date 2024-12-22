#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/* Sign extends the given field to a 32-bit integer where field is
 * interpreted an n-bit integer. */
int sign_extend_number(unsigned int field, unsigned int n) {
  return (int)field << (32 - n) >> (32 - n);
  /* YOUR CODE HERE */
  return 0;
}

/* Unpacks the 32-bit machine code instruction given into the correct
 * type within the instruction struct */
Instruction parse_instruction(uint32_t instruction_bits) {
  /* YOUR CODE HERE */
  Instruction instruction;
  // add x8, x0, x0     hex : 00000433  binary = 0000 0000 0000 0000 0000 01000
  // Opcode: 0110011 (0x33) Get the Opcode by &ing 0x1111111, bottom 7 bits
  instruction.opcode = instruction_bits & ((1U << 7) - 1);

  // Shift right to move to pointer to interpret next fields in instruction.
  instruction_bits >>= 7;

  switch (instruction.opcode) {
  // R-Type
  case 0x33:
    // instruction: 0000 0000 0000 0000 0000 destination : 01000
    instruction.rtype.rd = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;

    // instruction: 0000 0000 0000 0000 0 func3 : 000
    instruction.rtype.funct3 = instruction_bits & ((1U << 3) - 1);
    instruction_bits >>= 3;

    // instruction: 0000 0000 0000  src1: 00000
    instruction.rtype.rs1 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;

    // instruction: 0000 000        src2: 00000
    instruction.rtype.rs2 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;

    // funct7: 0000 000
    instruction.rtype.funct7 = instruction_bits & ((1U << 7) - 1);
    break;

  // case for I-type 
  case 0x03:
  case 0x13:
  case 0x73:
    // instructions rd added
    instruction.itype.rd = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction funct3 added
    instruction.itype.funct3 = instruction_bits & ((1U << 3) - 1);
    instruction_bits >>= 3;
    // instruction rs1 added
    instruction.itype.rs1 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction imm added
    instruction.itype.imm = instruction_bits & ((1U << 12) - 1);
    // added every component of itype
    break;
  
  // case of S-type
  case 0x23:
    // instruction imm 7-11 added
    instruction.stype.imm5 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction funct3 12-14 added
    instruction.stype.funct3 = instruction_bits & ((1U << 3) - 1);
    instruction_bits >>= 3;
    // instruction rs1 15-19 added
    instruction.stype.rs1 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction rs2 20-24 added
    instruction.stype.rs2 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction imm 25-31 added
    instruction.stype.imm7 = instruction_bits & ((1U << 7) - 1);
    // added every component of stype
    break;

  // case of SB-type
  case 0x63:
    // instruction imm[4:1|11] 7-11 added
    instruction.sbtype.imm5 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction funct3 12-14 added
    instruction.sbtype.funct3 = instruction_bits & ((1U << 3) - 1);
    instruction_bits >>= 3;
    // instruction rs1 15-19 added 
    instruction.sbtype.rs1 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction rs2 20-24 added
    instruction.sbtype.rs2 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction imm[12|10:5] 25-31 added
    instruction.sbtype.imm7 = instruction_bits & ((1U << 7) - 1);
    // added every component of sb type
    break;

  // case of U type
  case 0x37:
    // instruction rd 7-11 added
    instruction.utype.rd = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction imm[31:12] 12-31 added
    instruction.utype.imm = instruction_bits & ((1U << 20) - 1);
    // added every component of U type
    break;

  // case of UJ type
  case 0x6f:
    // instruction rd 7-11 added
    instruction.ujtype.rd = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;
    // instruction imm[20|10:1|11|19:12] 12-31 added
    instruction.ujtype.imm = instruction_bits & ((1U << 20) - 1);
    // added every component of UJ type
    break;
  
  // SLT case
  case 0x2A:
    // instruction: 0000 0000 0000 0000 0000 destination : 01000
    instruction.rtype.rd = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;

    // instruction: 0000 0000 0000 0000 0 func3 : 000
    instruction.rtype.funct3 = instruction_bits & ((1U << 3) - 1);
    instruction_bits >>= 3;

    // instruction: 0000 0000 0000  src1: 00000
    instruction.rtype.rs1 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;

    // instruction: 0000 000        src2: 00000
    instruction.rtype.rs2 = instruction_bits & ((1U << 5) - 1);
    instruction_bits >>= 5;

    // funct7: 0000 000
    instruction.rtype.funct7 = instruction_bits & ((1U << 7) - 1);
    break;

  default:
    exit(EXIT_FAILURE);
  }
  return instruction;
}

/* Return the number of bytes (from the current PC) to the branch label using
 * the given branch instruction */
int get_branch_offset(Instruction instruction) {
  int temp = 0x00000000;
  temp |= ((instruction.sbtype.imm5 & 0x00000001) << 11);
  temp |= (((instruction.sbtype.imm5 >> 1) & ((1U << 4) - 1)) << 1);
  temp |= ((instruction.sbtype.imm7 << 5) & ((1U << 6) - 1) << 5);
  temp |= (((instruction.sbtype.imm7 >> 6) & 0x00000001) << 12);
  return (sign_extend_number(temp, 12));
  /* YOUR CODE HERE */
  return 0;
}

/* Returns the number of bytes (from the current PC) to the jump label using the
 * given jump instruction */
int get_jump_offset(Instruction instruction) {
  int temp = 0x00000000;
  temp |= ((instruction.ujtype.imm & ((1U << 8) - 1)) << 11);
  temp |= (((instruction.ujtype.imm >> 8) & 0x00000001) << 10);
  temp |= (((instruction.ujtype.imm >> 9) & ((1U << 10) - 1)) << 1);
  temp |= (((instruction.ujtype.imm >> 19) & 0x00000001) << 19);
  return sign_extend_number(temp, 20);
  /* YOUR CODE HERE */
}

int get_store_offset(Instruction instruction) {
  /* YOUR CODE HERE */
  int temp = 0x00000000;
  temp |= instruction.stype.imm5 & 0x0000001f;
  temp |= (instruction.stype.imm7 << 5) & 0x00000fe0;
  return (sign_extend_number(temp, 12));
}

void handle_invalid_instruction(Instruction instruction) {
  printf("Invalid Instruction: 0x%08x\n", instruction.bits);
}

void handle_invalid_read(Address address) {
  printf("Bad Read. Address: 0x%08x\n", address);
  exit(-1);
}

void handle_invalid_write(Address address) {
  printf("Bad Write. Address: 0x%08x\n", address);
  exit(-1);
}
