	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R10,#1
	MOV R0, #21
	MOV R1, #5
	LDR R5, = DST
UP
	MUL R2,R10,R0
	UDIV R3, R2, R1
	MLS R4, R1, R3, R2
	STR R2, [R5]
	CMP R4, #0
	
	BEQ STOP
	ADD R10, #1
	B UP
STOP
	B STOP
	AREA mydata,DATA,READWRITE
DST DCD 0
	END
	
	
	