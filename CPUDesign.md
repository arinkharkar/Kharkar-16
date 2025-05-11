Introduction:
	This CPU uses a bus based design, with each register only interacting with the bus. In practice, this means any operation must put data on the bus or take data off the bus.

Registers:
	General Purpose:
		A, B*
	* The B resister can only store the value from the A register, thus, all operations go through the A register and if needed, are stored into the B register
	Result - Stores the result of ADD
	PC - Program Counter, increments every clock cycle
	FLAGS - ABCDEFGHIJKLMNOP
	A - Overflow, set if an addition operation has an overflow
	B - Zero bit, set if an addition operation results in zero


OPCODES:
Key:
	Imm - A constant 16 bit integer
	Addr - A 16 bit wide pointer
	Reg - Either the A or B register (The rest are reserved and cannot be used for general purpose)

LDAI Imm:
	RegA = Imm
	RegPC++

LDAM Addr:
	RegA = Memory[Addr]
	RegPC++

LDAB:
	RegA = RegB
	RegPC++

LDARES:
	RegA = RegResult
	RegPC++

LDAFLAG:
	RegA = RegFlag


LDBA:
	RegB = RegA
	RegPC++

ADD:
	RegResult = RegA + RegB

	if (RegResult == 0)
		RegFlags.Zero = 1
	else 
		RegFlags.Zero = 0
	
	if (RegA + RegB > UINT16_MAX)
		RegFlags.Overflow = 1
	else
		RegFlags.Overflow = 0
	
	RegPC++
	
LDPCA:
	RegPC = RegA
	
LDPCI Imm:
	RegPC = Imm

LDPCNZA:
	if (RegFlags.Zero == 1)
		RegPC = RegA
	else
		RegPC++
	
LDPCNZB:
	if (RegFlags.Zero == 1)
		RegPC = RegA
	else
		RegPC++

LDPCNZI Imm:
	if (RegFlags.Zero == 1)
		RegPC = Imm
	else
		RegPC++

LDM
