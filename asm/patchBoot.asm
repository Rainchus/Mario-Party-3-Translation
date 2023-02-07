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
ADDIU t7, r0, 0xFFFF
LI t6, defaultString
BNEL t5, t7, newMessage //new message not found, default to original string
ADDU a1, t5, r0 //new pointer to message

isPointer: //here temporarily for testing

newMessage:
J 0x8005B444
NOP

crash_screen_sleep: //takes arg a0, ms to sleep
ADDIU sp, sp, -0x20
ORI v0, r0, 0xB71B
MULT a0, v0
DADDU a0, r0, r0
DADDU a1, r0, r0
SW ra, 0x0018 (sp)
SW s1, 0x0014 (sp)
SW s0, 0x0010 (sp)
MFHI s0
MFLO s1
JAL osSetTime
NOP
crashScreenLoop:
JAL osGetTime
NOP
DADDU a0, v0, r0
DADDU a1, v1, r0
SLTU v0, a0, s0
BNEZ v0, crashScreenLoop
NOP
BNE s0, a0, exitCrashFunc
SLTU v0, a1, s1
BNEZ v0, crashScreenLoop
NOP
exitCrashFunc:
LW ra, 0x0018 (sp)
LW s1, 0x0014 (sp)
LW s0, 0x0010 (sp)
JR RA
ADDIU sp, sp, 0x20

osViRepeatLine:
ADDIU          SP, SP, -0x18
SW             S0, 0x0010 (SP)
SW             RA, 0x0014 (SP)
JAL            0x80080940 //__osDisableInt
ADDU           S0, A0, R0
ANDI           S0, S0, 0x00FF
BEQZ           S0, label1
ADDU           A0, V0, R0
LUI            V1, 0x800A
LW             V1, 0x4104 (V1)
LHU            V0, 0x0000 (V1)
J              label0
ORI            V0, V0, 0x0040
label1:
LUI            V1, 0x800A
LW             V1, 0x4104(V1)
LHU            V0, 0x0000 (V1)
ANDI           V0, V0, 0xFFBF
label0:
JAL            0x800809B0 //__osRestoreInt
SH             V0, 0x0000 (V1)
LW             RA, 0x0014 (SP)
LW             S0, 0x0010 (SP)
JR             RA
ADDIU          SP, SP, 0x18

infiniteLoop:
NOP
J infiniteLoop
NOP


//data
messageID:
.word 0

stringBuffer:
.fill 0x100, 0

.headersize MP3_MOD_RAM - MP3_MOD_ROM
.org MP3_MOD_RAM
.align 8
.importobj "obj/crash_screen.o"
.importobj "obj/strings.o"


END: