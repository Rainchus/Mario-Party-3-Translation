.headersize 0x7FFFF400
.org 0x8005B43C //hook "RefreshMsgWindow?" (a1 holds string ID)
J getCustomMessageID
NOP