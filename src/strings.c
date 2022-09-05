#include "../include/mp3.h"

#define IMAGE_PAD "\x1A\x1A\x1A\x1A"

char defaultString[] = "test";

s32 argsTemp[8];

char group4D_index0[] = "Test replacement message 4D00\xC2";
char group4D_index1[] = "Test replacement message 4D01\xC2"
char group5A_index0[] = "Test replacement message\xC2";

char* group00[200] = {0};
char* group01[200] = {0};
char* group02[200] = {0};
char* group03[200] = {0};
char* group04[200] = {0};
char* group05[200] = {0};
char* group06[200] = {0};
char* group07[200] = {0};
char* group08[200] = {0};
char* group09[200] = {0};
char* group0A[200] = {0};
char* group0B[200] = {0};
char* group0C[200] = {0};
char* group0D[200] = {0};
char* group0E[200] = {0};
char* group0F[200] = {0};
char* group10[200] = {0};
char* group11[200] = {0};
char* group12[200] = {0};
char* group13[200] = {0};
char* group14[200] = {0};
char* group15[200] = {0};
char* group16[200] = {0};
char* group17[200] = {0};
char* group18[200] = {0};
char* group19[200] = {0};
char* group1A[200] = {0};
char* group1B[200] = {0};
char* group1C[200] = {0};
char* group1D[200] = {0};
char* group1E[200] = {0};
char* group1F[200] = {0};
char* group20[200] = {0};
char* group21[200] = {0};
char* group22[200] = {0};
char* group23[200] = {0};
char* group24[200] = {0};
char* group25[200] = {0};
char* group26[200] = {0};
char* group27[200] = {0};
char* group28[200] = {0};
char* group29[200] = {0};
char* group2A[200] = {0};
char* group2B[200] = {0};
char* group2C[200] = {0};
char* group2D[200] = {0};
char* group2E[200] = {0};
char* group2F[200] = {0};
char* group30[200] = {0};
char* group31[200] = {0};
char* group32[200] = {0};
char* group33[200] = {0};
char* group34[200] = {0};
char* group35[200] = {0};
char* group36[200] = {0};
char* group37[200] = {0};
char* group38[200] = {0};
char* group39[200] = {0};
char* group3A[200] = {0};
char* group3B[200] = {0};
char* group3C[200] = {0};
char* group3D[200] = {0};
char* group3E[200] = {0};
char* group3F[200] = {0};
char* group40[200] = {0};
char* group41[200] = {0};
char* group42[200] = {0};
char* group43[200] = {0};
char* group44[200] = {0};
char* group45[200] = {0};
char* group46[200] = {0};
char* group47[200] = {0};
char* group48[200] = {0};
char* group49[200] = {0};
char* group4A[200] = {0};
char* group4B[200] = {0};
char* group4C[200] = {0};
char* group4D[200] = {group4D_index0, group4D_index1};
char* group4E[200] = {0};
char* group4F[200] = {0};
char* group50[200] = {0};
char* group51[200] = {0};
char* group52[200] = {0};
char* group53[200] = {0};
char* group54[200] = {0};
char* group55[200] = {0};
char* group56[200] = {0};
char* group57[200] = {0};
char* group58[200] = {0};
char* group59[200] = {0};
char* group5A[200] = {group5A_index0};
char* group5B[200] = {0};
char* group5C[200] = {0};
char* group5D[200] = {0};
char* group5E[200] = {0};
char* group5F[200] = {0};
char* group60[200] = {0};
char* group61[200] = {0};
char* group62[200] = {0};
char* group63[200] = {0};

//crashes at 80108424

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

void* messageLoadHook(s32 stringID) {
    u8 stringGroup = (stringID & 0x0000FF00) >> 8;
    u8 stringIndex = stringID & 0x000000FF;
    char** group = textGroups[stringGroup];
    char* string = group[stringIndex];
    // s32 strlength = mp3strlen(string);
    // void* mallocStringInstance = MallocPerm(strlength);
    // mp3bcopy(string, mallocStringInstance, strlength);
    // return mallocStringInstance;
    return string;
}

