Introduction:

OPCODES:

LDA
	Loads the value on the bus into the A register
LDB
	Loads the value on the bus into the B register
LDC
	Loads the value on the bus into the C register
LDD
	Loads the value on the bus into the D register
LDPC
	Loads the value on the bus into the PC register
LDPCS
	Loads the value on the bus into the PC register only if the 'set' bit in FLAGS is 1
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
	


