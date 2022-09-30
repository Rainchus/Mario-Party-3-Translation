//DMA method (makes use of expansion pak)
.headersize 0x7FFFF400
.org 0x8000C2C0
NOP

//Payload related information
.definelabel PAYLOAD_START_ROM, 0x2000000
.definelabel PAYLOAD_START_RAM, 0x80400000
.definelabel MP3_MOD_ROM, PAYLOAD_START_ROM + 0x1000
.definelabel MP3_MOD_RAM, PAYLOAD_START_RAM + 0x1000
.definelabel PAYLOAD_SIZE, 0x20000 //fix to adjust automatically later

//hook main game loop, DMA our code/data, jump to the game loop that was moved to expansion pak memory
.org 0x8000E7B8 //ROM 0xF3B8
PAYLOAD_START:
//F3B8, 0x8000E7B8
ADDIU sp, sp, -0x18
SW ra, 0x0010 (sp)
LUI a0, hi(PAYLOAD_START_ROM)
ADDIU a0, a0, lo(PAYLOAD_START_ROM)
LUI a1, hi(PAYLOAD_START_RAM)
ADDIU a1, a1, lo(PAYLOAD_START_RAM)
LUI a2, hi(PAYLOAD_SIZE)
JAL unknownDMAFunc
ADDIU a2, a2, lo(PAYLOAD_SIZE)

    J mainLoopStart
    NOP

LW ra, 0x0010 (sp)
JR RA
ADDIU sp, sp, 0x18

customDataAndCode:
//copied main game loop
.headersize 0x7E400000
.org 0x80400000
    mainLoopStart:
    JAL cBootFunction
    NOP
    mainLoop:
    JAL SleepVProcess
    NOP
    JAL GetRandomByte
    NOP
    JAL 0x8000BA30
    NOP
    JAL 0x80014A3C
    ADDIU a0, r0, 2
    LUI a0, 0x800D
    ADDIU a0, a0, 0xCF38
    JAL 0x8001B0B4
    ADDIU a1, r0, 2
    J mainLoop
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

END: