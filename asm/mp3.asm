//data
.definelabel Player1Buttons,		0x800CCF7C
.definelabel Player1Pressedbuttons,	0x800C9520
.definelabel Player2Pressedbuttons,	0x800C9522
.definelabel Player3Pressedbuttons,	0x800C9524
.definelabel Player4Pressedbuttons,	0x800C9526
.definelabel inBoardPtr, 0x800CC3DC

//custom data
.definelabel globalTaunt, 0x800977D0
.definelabel canTauntDuringYourTurn, 0x800977D2
.definelabel PlayerPressedButtonsArray, 0x800C9520


//functions
.definelabel mp3bcopy, 0x8007B970
.definelabel MallocPerm, 0x80035864
.definelabel FreePerm, 0x80035888
.definelabel mp3strlen, 0x8007BD70
.definelabel ShowMessage, 0x800EC8EC
.definelabel GetCurrentPlayerIndex, 0x800F2130
.definelabel GetPlayerStruct, 0x800F213C
.definelabel unknownDMAFunc, 0x8004DB14
.definelabel PlaySound, 0x8004AA88
.definelabel SleepVProcess, 0x8004F074
.definelabel GetRandomByte, 0x8000B16C