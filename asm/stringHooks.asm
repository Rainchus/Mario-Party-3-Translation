//.headersize 0x7FFFF400
//.org 0x8005B43C //hook "RefreshMsgWindow?" (a1 holds string ID)
//J refreshStringsHook
//NOP

.headersize 0x7FFFF400
.org 0x800364DC //hook minigame explanation title (a0 holds string ID)
J otherStringsHook
NOP