	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN

	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler 
Reset_Handler
	LDR R0, = DST
	MOV R1,#4
Outerloop
	MOV R2,R0
	MOV R4, R2
	MOV R3, R1
	ADD R2, #4
Innerloop
	LDR R5,[R2]
	LDR R6,[R4]
	CMP R5,R6
	MOVLO R4,R2
	ADD R2,R2,#4
	SUBS R3,R3,#1
	BNE Innerloop
	LDR R5,[R4]
	LDR R6,[R0]
	STR R5,[R0]
	STR R6,[R4]
	ADD R0,R0,#4
	SUBS R1,R1,#1
	BNE Outerloop
STOP
	B STOP
	AREA mydata, DATA, READWRITE
DST DCD 0x5,0x3,0x4,0x2,0x1
	END