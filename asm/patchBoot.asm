//DMA method (makes use of expansion pak)
.headersize 0x7FFFF400
.org 0x8000C2C0
NOP

//Payload related information
.definelabel PAYLOAD_START_ROM, 0x2000000
.definelabel PAYLOAD_START_RAM, 0x80400000
.definelabel MP3_MOD_ROM, PAYLOAD_START_ROM + 0x1000
.definelabel MP3_MOD_RAM, PAYLOAD_START_RAM + 0x1000

.definelabel PAYLOAD_SIZE, 0xFFF0

PAYLOAD_START:
.headersize 0x7FFFF400
.org 0x8000C2C8
LUI a0, hi(PAYLOAD_START_ROM)
ADDIU a0, a0, lo(PAYLOAD_START_ROM)
LUI a1, hi(PAYLOAD_START_RAM)
ADDIU a1, a1, lo(PAYLOAD_START_RAM)
JAL unknownDMAFunc
ORI a2, r0, (PAYLOAD_SIZE)
J originalCode
NOP


//.headersize 0x7F86E000 // Set the displacement between ROM and RAM addresses (0xB92000)
.headersize (PAYLOAD_START_RAM - PAYLOAD_START_ROM)
.org 0x80400000 //ct1.asm max size of 0x1000, otherwise will overwrite ct1.o
originalCode:
//restore code overwritten by dma hook
LUI a0, 0x800D
ADDIU a0, a0, 0xE1A0
ADDU a1, r0, r0
LUI a2, 0x800D
ADDIU a2, a2, 0x0E50
JAL 0x80072590
ADDIU a3, r0, 0x0008

BEQZ v0, jump1
NOP
J 0x8000C2E8
NOP

jump1:
J 0x8000C2F0
NOP


getCustomMessageID: //a1 holds message ID
ADDIU sp, sp, -0x28
SW ra, 0x0024 (sp)

LUI t0, 0x8000
AND t1, t0, a1
BEQ t1, t0, isPointer
NOP

LI t0, textGroups
SRL t1, a1, 8 //knock bottom 8 bits off
SLL t2, t1, 2 //multiply by 2
ADDU t3, t2, t0 //now points to a char* []
LW t4, 0x0000 (t3) //load said char* []
ANDI t1, a1, 0x00FF //clear register except bottom 8 bits
SLL t2, t1, 2 //multiply by 4
ADDU t4, t4, t2
LW t5, 0x0000 (t4)
LI t6, defaultString
BNEZL t5, newMessage //new message not found, default to original string
ADDU a1, t5, r0 //new pointer to message

isPointer: //here temporarily for testing

newMessage:
J 0x8005B444
NOP





//data
messageID:
.word 0

stringBuffer:
.fill 0x100, 0

.headersize MP3_MOD_RAM - MP3_MOD_ROM
.org MP3_MOD_RAM
.align 8
.importobj "obj/strings.o"