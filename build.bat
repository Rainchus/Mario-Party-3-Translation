mkdir obj
mips64-elf-gcc -Wall -O2 -mtune=vr4300 -march=vr4300 -mabi=32 -fomit-frame-pointer -G0 -c src/strings.c
mv strings.o obj/
armips asm/main.asm
n64crc "rom/mp3mod.z64"