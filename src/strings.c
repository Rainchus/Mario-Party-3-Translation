#include "../include/mp3.h"
#include "asciiTable.c"

void crash_screen_init(void);

#ifndef AUTO_CONVERSION
#define AUTO_CONVERSION
#endif

#define END_GROUP (char*)-1
#define SKIP (char*)-2
#define IMAGE_PAD "\x1A\x1A\x1A\x1A"

char defaultString[] = "test";

char* group00[] = {END_GROUP};
char* group01[] = {END_GROUP};
char* group02[] = {END_GROUP};
char* group03[] = {END_GROUP};
char* group04[] = {END_GROUP};
char* group05[] = {END_GROUP};
char* group06[] = {END_GROUP};
char* group07[] = {END_GROUP};
char* group08[] = {END_GROUP};
char* group09[] = {END_GROUP};
char* group0A[] = {END_GROUP};
char* group0B[] = {END_GROUP};
char* group0C[] = {END_GROUP};
char* group0D[] = {END_GROUP};
char* group0E[] = {END_GROUP};
char* group0F[] = {END_GROUP};
char* group10[] = {END_GROUP};
char* group11[] = {END_GROUP};
char* group12[] = {END_GROUP};
char* group13[] = {END_GROUP};
char* group14[] = {END_GROUP};
char* group15[] = {END_GROUP};
char* group16[] = {END_GROUP};
char* group17[] = {END_GROUP};
char* group18[] = {END_GROUP};
char* group19[] = {END_GROUP};
char* group1A[] = {END_GROUP};
char* group1B[] = {END_GROUP};
char* group1C[] = {END_GROUP};
char* group1D[] = {END_GROUP};
char* group1E[] = {END_GROUP};
char* group1F[] = {END_GROUP};
char* group20[] = {END_GROUP};
char* group21[] = {END_GROUP};
char* group22[] = {END_GROUP};
char* group23[] = {END_GROUP};
char* group24[] = {END_GROUP};
char* group25[] = {END_GROUP};
char* group26[] = {END_GROUP};
char* group27[] = {END_GROUP};
char* group28[] = {END_GROUP};
char* group29[] = {END_GROUP};
char* group2A[] = {END_GROUP};
char* group2B[] = {END_GROUP};
char* group2C[] = {END_GROUP};
char* group2D[] = {END_GROUP};
char* group2E[] = {END_GROUP};
char* group2F[] = {END_GROUP};
char* group30[] = {END_GROUP};
char* group31[] = {END_GROUP};
char* group32[] = {END_GROUP};
char* group33[] = {END_GROUP};
char* group34[] = {END_GROUP};
char* group35[] = {END_GROUP};
char* group36[] = {END_GROUP};
char* group37[] = {END_GROUP};
char* group38[] = {END_GROUP};
char* group39[] = {END_GROUP};
char* group3A[] = {END_GROUP};
char* group3B[] = {END_GROUP};
char* group3C[] = {END_GROUP};
char* group3D[] = {END_GROUP};
char* group3E[] = {END_GROUP};
char* group3F[] = {END_GROUP};
char* group40[] = {END_GROUP};
char* group41[] = {END_GROUP};
char* group42[] = {END_GROUP};
char* group43[] = {END_GROUP};

s32 vinewithmetest[] = {
0x0B1A1A1A, 0x1A1A1A1A, 0x1A1A1A19, 0x050F1116,
0x19190A1A, 0x1A1A1A1A, 0x1A1A1A1A, 0x1A19194A,
0x756D7020, 0x66726F6D, 0x2076696E, 0x6520746F,
0x2076696E, 0x6520696E, 0x19190A1A, 0x1A1A1A1A,
0x1A1A1A1A, 0x1A191961, 0x20726163, 0x65207468,
0x726F7567, 0x68207468, 0x65205069, 0x72616E68,
0x6119190A, 0x1A1A1A1A, 0x1A1A1A1A, 0x1A1A1919,
0x506C616E, 0x7420666F, 0x72657374, 0x85191900,
};

char* group44[] = {
/* 0x00 */ SKIP,
/* 0x01 */ SKIP,
/* 0x02 */ SKIP,
/* 0x03 */ SKIP,
/* 0x04 */ SKIP,
/* 0x05 */ SKIP,
/* 0x06 */ SKIP,
/* 0x07 */ SKIP,
/* 0x08 */ SKIP,
/* 0x09 */ SKIP,
/* 0x0A */ SKIP,
/* 0x0B */ SKIP,
/* 0x0C */ SKIP,
/* 0x0D */ SKIP,
/* 0x0E */ SKIP,
/* 0x0F */ SKIP,
/* 0x10 */ SKIP,
/* 0x11 */ SKIP,
/* 0x12 */ SKIP,
/* 0x13 */ SKIP,
/* 0x14 */ SKIP,
/* 0x15 */ SKIP,
/* 0x16 */ SKIP,
/* 0x17 */ SKIP,
/* 0x18 */ SKIP,
/* 0x19 */ SKIP,
/* 0x1A */ SKIP,
/* 0x1B */ SKIP,
/* 0x1C */ SKIP,
/* 0x1D */ SKIP,
/* 0x1E */ SKIP,
/* 0x1F */ SKIP,
/* 0x20 */ SKIP,
/* 0x21 */ SKIP,
/* 0x22 */ SKIP,
/* 0x23 */ SKIP,
/* 0x24 */ SKIP,
/* 0x25 */ SKIP,
/* 0x26 */ SKIP,
/* 0x27 */ SKIP,
/* 0x28 */ SKIP,
/* 0x29 */ SKIP,
/* 0x2A */ SKIP,
/* 0x2B */ SKIP,
/* 0x2C */ SKIP,
/* 0x2D */ SKIP,
/* 0x2E */ SKIP,
/* 0x2F */ SKIP,
/* 0x30 */ SKIP,
/* 0x31 */ vinewithmetest,
/* 0x32 */ END_GROUP
};

char* group45[] = {END_GROUP};
char* group46[] = {END_GROUP};
char* group47[] = {END_GROUP};
char* group48[] = {END_GROUP};
char* group49[] = {END_GROUP};
char* group4A[] = {END_GROUP};
char* group4B[] = {END_GROUP};
char* group4C[] = {END_GROUP};
char* group4D[] = {"Test4D 00", "Test4D 01", "Test4D 02", END_GROUP};
char* group4E[] = {END_GROUP};
char* group4F[] = {END_GROUP};
char* group50[] = {END_GROUP};
char* group51[] = {END_GROUP};
char* group52[] = {END_GROUP};
char* group53[] = {END_GROUP};
char* group54[] = {END_GROUP};
char* group55[] = {END_GROUP};
char* group56[] = {END_GROUP};
char* group57[] = {END_GROUP};
char* group58[] = {END_GROUP};
char* group59[] = {END_GROUP};
char* group5A[] = {END_GROUP};
char* group5B[] = {END_GROUP};
char* group5C[] = {END_GROUP};
char* group5D[] = {END_GROUP};
char* group5E[] = {END_GROUP};
char* group5F[] = {END_GROUP};
char* group60[] = {END_GROUP};
char* group61[] = {END_GROUP};
char* group62[] = {END_GROUP};
char* group63[] = {END_GROUP};

char** textGroups[] = {
    group00,group01,group02,group03,group04,
    group05,group06,group07,group08,group09,
    group0A,group0B,group0C,group0D,group0E,
    group0F,group10,group11,group12,group13,
    group14,group15,group16,group17,group18,
    group19,group1A,group1B,group1C,group1D,
    group1E,group1F,group20,group21,group22,
    group23,group24,group25,group26,group27,
    group28,group29,group2A,group2B,group2C,
    group2D,group2E,group2F,group30,group31,
    group32,group33,group34,group35,group36,
    group37,group38,group39,group3A,group3B,
    group3C,group3D,group3E,group3F,group40,
    group41,group42,group43,group44,group45,
    group46,group47,group48,group49,group4A,
    group4B,group4C,group4D,group4E,group4F,
    group50,group51,group52,group53,group54,
    group55,group56,group57,group58,group59,
    group5A,group5B,group5C,group5D,group5E,
    group5F,group60,group61,group62,group63,
};

char* convertAsciiToMp3(char* asciiString) {
    #ifndef AUTO_CONVERSION
        for (int i = 0; asciiString[i] != 0; i++) {
            u8 asciiCharacter = asciiString[i];
            asciiString[i] = asciiLUT[asciiCharacter];
        }
        return asciiString;
    #else
        return NULL;
    #endif

}

void cBootFunction(void) {
    #ifndef AUTO_CONVERSION
        for (s32 i = 0; i < sizeof(textGroups) / sizeof(textGroups[0]); i++) { //for loop for all groups
        int j = 0;
            if (textGroups[i][j] != END_GROUP) {
                for (int j = 0; textGroups[i][j] != NULL; j++) {
                    if (textGroups[i][j] == END_GROUP) {
                        break;
                    }
                    textGroups[i][j] = convertAsciiToMp3(textGroups[i][j]);
                }
            }
        }
    #endif
    crash_screen_init();
}

s32 getGroupSize(char** group) {
    s32 i;

    for (i = 0; group[i] != END_GROUP; i++) {}
    return i;
}
