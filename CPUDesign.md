Introduction:
	This CPU uses a bus based design, with each register only interacting with the bus. In practice, this means any operation must put data on the bus or take data off the bus.

Registers:
	General Purpose:
		A, B, C
	PC - Program Counter, increments every clock cycle
	FLAGS - ABCDEFGHIJKLMNOP
	A - Overflow, set if an addition operation has an overflow
	B - Zero bit, set if an addition operation results in zero


OPCODES:

LDA
	Loads the value on the bus into the A register
LDB
	Loads the value on the bus into the B register
LDC
	Loads the value on the bus into the C register
LDPC
	Loads the value on the bus into the PC register
LDPNZ
	Loads the value on the bus into the PC register only if the 'zero' bit in FLAGS is 1
LDF
	Loads the value on the bus into the FLAGS register
PUSH
	Puts the value found at [%A] onto the bus
PUSH Imm16 
	Puts the value Imm16 onto the bus
ADD
	Adds Register A to Register B and stores into Register A (%A=%A+%B)
LOADM
	Writes the current value on the bus into the memory address stored in Register A
LOADVM
	Writes the current value on the bus into the video memory address stored in Register A

PUSH 0
LDA

PUSH 'A'
LOADVM
	


