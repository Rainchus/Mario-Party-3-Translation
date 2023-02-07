#include "../include/mp3.h"
#include "asciiTable.c"

void crash_screen_init(void);

#ifndef AUTO_CONVERSION
#define AUTO_CONVERSION
#endif

#define NULL_STRING (char*)-1
#define IMAGE_PAD "\x1A\x1A\x1A\x1A"

char defaultString[] = "test";

char* group00[] = {NULL_STRING};
char* group01[] = {NULL_STRING};
char* group02[] = {NULL_STRING};
char* group03[] = {NULL_STRING};
char* group04[] = {NULL_STRING};
char* group05[] = {NULL_STRING};
char* group06[] = {NULL_STRING};
char* group07[] = {NULL_STRING};
char* group08[] = {NULL_STRING};
char* group09[] = {NULL_STRING};
char* group0A[] = {NULL_STRING};
char* group0B[] = {NULL_STRING};
char* group0C[] = {NULL_STRING};
char* group0D[] = {NULL_STRING};
char* group0E[] = {NULL_STRING};
char* group0F[] = {NULL_STRING};
char* group10[] = {NULL_STRING};
char* group11[] = {NULL_STRING};
char* group12[] = {NULL_STRING};
char* group13[] = {NULL_STRING};
char* group14[] = {NULL_STRING};
char* group15[] = {NULL_STRING};
char* group16[] = {NULL_STRING};
char* group17[] = {NULL_STRING};
char* group18[] = {NULL_STRING};
char* group19[] = {NULL_STRING};
char* group1A[] = {NULL_STRING};
char* group1B[] = {NULL_STRING};
char* group1C[] = {NULL_STRING};
char* group1D[] = {NULL_STRING};
char* group1E[] = {NULL_STRING};
char* group1F[] = {NULL_STRING};
char* group20[] = {NULL_STRING};
char* group21[] = {NULL_STRING};
char* group22[] = {NULL_STRING};
char* group23[] = {NULL_STRING};
char* group24[] = {NULL_STRING};
char* group25[] = {NULL_STRING};
char* group26[] = {NULL_STRING};
char* group27[] = {NULL_STRING};
char* group28[] = {NULL_STRING};
char* group29[] = {NULL_STRING};
char* group2A[] = {NULL_STRING};
char* group2B[] = {NULL_STRING};
char* group2C[] = {NULL_STRING};
char* group2D[] = {NULL_STRING};
char* group2E[] = {NULL_STRING};
char* group2F[] = {NULL_STRING};
char* group30[] = {NULL_STRING};
char* group31[] = {NULL_STRING};
char* group32[] = {NULL_STRING};
char* group33[] = {NULL_STRING};
char* group34[] = {NULL_STRING};
char* group35[] = {NULL_STRING};
char* group36[] = {NULL_STRING};
char* group37[] = {NULL_STRING};
char* group38[] = {NULL_STRING};
char* group39[] = {NULL_STRING};
char* group3A[] = {NULL_STRING};
char* group3B[] = {NULL_STRING};
char* group3C[] = {NULL_STRING};
char* group3D[] = {NULL_STRING};
char* group3E[] = {NULL_STRING};
char* group3F[] = {NULL_STRING};
char* group40[] = {NULL_STRING};
char* group41[] = {NULL_STRING};
char* group42[] = {NULL_STRING};
char* group43[] = {NULL_STRING};
char* group44[] = {NULL_STRING};
char* group45[] = {NULL_STRING};
char* group46[] = {NULL_STRING};
char* group47[] = {NULL_STRING};
char* group48[] = {NULL_STRING};
char* group49[] = {NULL_STRING};
char* group4A[] = {NULL_STRING};
char* group4B[] = {NULL_STRING};
char* group4C[] = {NULL_STRING};
char* group4D[] = {NULL_STRING};
char* group4E[] = {NULL_STRING};
char* group4F[] = {NULL_STRING};
char* group50[] = {NULL_STRING};
char* group51[] = {NULL_STRING};
char* group52[] = {NULL_STRING};
char* group53[] = {NULL_STRING};
char* group54[] = {NULL_STRING};
char* group55[] = {NULL_STRING};
char* group56[] = {NULL_STRING};
char* group57[] = {NULL_STRING};
char* group58[] = {NULL_STRING};
char* group59[] = {NULL_STRING};
char* group5A[] = {NULL_STRING};
char* group5B[] = {NULL_STRING};
char* group5C[] = {NULL_STRING};
char* group5D[] = {NULL_STRING};
char* group5E[] = {NULL_STRING};
char* group5F[] = {NULL_STRING};
char* group60[] = {NULL_STRING};
char* group61[] = {NULL_STRING};
char* group62[] = {NULL_STRING};
char* group63[] = {NULL_STRING};

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
            if (textGroups[i][j] != NULL_STRING) {
                for (int j = 0; textGroups[i][j] != NULL; j++) {
                    if (textGroups[i][j] == NULL_STRING) {
                        break;
                    }
                    textGroups[i][j] = convertAsciiToMp3(textGroups[i][j]);
                }
            }
        }
    #endif
    crash_screen_init();
}
