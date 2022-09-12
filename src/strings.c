#include "../include/mp3.h"

#define IMAGE_PAD "\x1A\x1A\x1A\x1A"

char defaultString[] = "test";

s32 argsTemp[8];

char group15_index0[] = "Benvenuto\xC2 Questo Ascensore Stella\nva ai\x0F\x05 Tabelloni di gioco\x16\x19\xC2\xFF\x0BIo sono\x0F\x05 Dad\xE1\x16\x19\x85 Da ora in avanti\nsar\xE3 io la tua guida\xFF\x0B";
char group15_index1[] = "Vuoi tornare al\x0F\x05 cortile del Castello\x16\x19\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group15_index2[] = "OK\xC2 \x97 ora di scegliere le\nimpostazioni di gioco\x85\xFF";
char group15_index3[] = "In quanti giocheranno stavolta\xC3\xFF\x0B";
char group15_index4[] = "\x0B\x05\x0F 1 Giocatore\x16\x19 e\n\x03\x0F 3 Personaggi Computer\x16\x19";
char group15_index5[] = "\x0B\x05\x0F 2 Giocatori\x16\x19 e\n\x03\x0F 2 Personaggi Computer\x16\x19";
char group15_index6[] = "\x0B\x05\x0F 3 Giocatori\x16\x19 e\n\x03\x0F 1 Personaggio Computer\x16\x19";
char group15_index7[] = "\x0B\x05\x0F 4 Giocatori\x16\x19";
char group15_index8[] = "\x0BScegli quali Personaggi\nverranno usati dai Giocatori\x85";
char group15_index9[] = "\x0BScegli quali\x05\x0F 3 Personaggi\x16\x19 verranno\nusati dal\x03\x0F Computer\x16\x19\xFF\x0b";
char group15_index10[] = "\x0BScegli quali\x05\x0F 2 Personaggi\x16\x19 verranno\nusati dal\x03\x0F Computer\x16\x19\xFF\x0B";
char group15_index11[] = "\x0BScegli quale\x05\x0F Personaggio\x16\x19 verr\xD1\nutilizzato dal\x03\x0F Computer\x16\x19\xFF\x0B";
char group15_index12[] = "\x0B\x03\x0FMario\x16\x0F \x3D\x3D\x16\x19 Il nostro eroe usa il\n\x05\x0F Fungo D\x5COro\x16\x19 per correre\x85";
char group15_index13[] = "\x0B\x03\x0FLuigi\x16\x0F \x3D\x3D\x16\x19 Quest\x5Cuomo dai molti talenti\nama usare\x05\x0F Schelechiavi\x16\x19\x85";
char group15_index14[] = "\x0B\x03\x0FPeach\x16\x0F \x3D\x3D\x16\x19 \x97 furba\x82 quindi attenti a\nquando ha il\x05\x0F Baule Saccheggio\x16\x19\xC2";
char group15_index15[] = "\x0B\x03\x0FYoshi\x16\x0F \x3D\x3D\x16\x19\x05\x0F Teletrasportarsi\x16\x19 \xD5 il suo\nmetodo per pedinare gli altri\xC2";
char group15_index16[] = "\x0B\x03\x0FWario\x16\x0F \x3D\x3D\x16\x19 L\x5Cineluttabile duellante ama\nlanciare il\x05\x0F Guanto di Sfida\x16\x19\xC2";
char group15_index17[] = "\x0B\x03\x0F Donkey Kong\x16\x0F \x3D\x3D\x16\x19 Pi\xDD forte di tutti\x82\ngli piace il\x05\x0F Fungo Inverso\x16\x19\xC2";
char group15_index18[] = "\x0B\x03\x0F Daisy\x16\x0F \x3D\x3D\x16\x19 Molto maschiaccio\x82 lei \xD5\nfan del \x05\x0F Cellulare Acquisti\x16\x19\xC2";
char group15_index19[] = "\x0B\x03\x0FWaluigi\x16\x0F \x3D\x3D\x16\x19 Attento\x82 o questo furfante\nuser\xD1 un\x05\x0F Fungo Velenoso\x16\x19 su di te\xC2";
char group15_index20[] = "\x0B Come vuoi impostare il livello di\ndifficolt\xD1 dei personaggi computer\xC3\xFF";
char group15_index21[] = "\x0BImposta tutti i personaggi\ncomputer allo stesso livello\x85";
char group15_index22[] = "\x0BImposta il livello dei\npersonaggi computer distintamente\x85";
char group15_index23[] = "\x0BImposta il livello di difficolt\xD1\ndei personaggi computer\x85";
char group15_index24[] = "\x0BImposta il livello di difficolt\xD1\nper \x11\x85";
char group4D_index0[] = "Al centro del vasto universo\x82\nnacque una stella alquanto luminosa";
char group4D_index1[] = "Test replacement message 4D01\xC2";
char group4D_index2[] = "Era una stella che nasce solo una volta\nogni mille anni\x82 la Stella Millenaria";
char group4D_index4[] = "Si dice che chiunque entri in possesso\ndella stella mistica era destinato\na diventare la Superstar dell\x5c universo";
char group4D_index6[] = "Tuttavia\x82 siccome la Stella Millenaria\nnon era che neonata \x85\x85\x85";
char group4D_index8[] = "Cadde dal cielo stellato\x85";
char group4D_index10[] = "Allora\x82 Mario e i suoi amici\nerano tutti a rilassarsi felicemente\x82";
char group4D_index12[] = "quando\x85\x85\x85";
char group4D_index14[] = "All\x5Cimprovviso\x82 la Stella Millenaria\narriv\xE3 precipitando\x85\x85\x85";
char group4D_index16[] = "Poco dopo\x82 Mario e i suoi amici iniziarono\na battersi su chi doveva tenere\nla Stella Millenaria\x85";
char group4D_index18[] = "Vedendo ci\xE3\x82 Lakitu arriv\xE3 in volo\x82\ndondolando una scatola dalla sua canna";
char group4D_index20[] = "Proprio cos\xE1\xC2 Potrebbero giocare a \n\xC0Mario Party\xC1 per stabilire chi fosse\nla pi\xDD grande Superstar\xC2";
char group4D_index22[] = "Improvvisamente\x82 la Stella Millenaria\ndiede un bagliore accecante\xC2";
char group4D_index24[] = "E con quella lampata\x82 Mario e i suoi amici\nfurono trasportati\nall\x5Cinterno della scatola\xc2";
char group4D_index26[] = "\xC0Salve\xC2 Sono la Stella Millenaria\xC2\xC1";
char group4D_index28[] = "Dovrai superare la mia prova per\ndimostrarti degno di possedermi";
char group4D_index33[] = "Seguimi\xC2";
char group2A_index0[] = "Seleziona un file";
char group2A_index1[] = "Copia un file";
char group2A_index2[] = "Seleziona il file che vuoi copiare";
char group2A_index3[] = "Non puoi copiare un file se non ci\nsono file o sono tutti utilizzati";
char group2A_index4[] = "Per copiare un file\x82 eliminare\n un file esistente";
char group2A_index5[] = "Dove vuoi copiare\x0F\x05 File \x16\x19\x05\x0F\x11\x16\x19\x05\x0F\x16\x19\xC3";
char group2A_index6[] = "Copia completata";
char group2A_index7[] = "Elimina un file";
char group2A_index8[] = "Seleziona il file che vuoi eliminare";
char group2A_index9[] = "Vuoi eliminare\x0F\x05 File \x16\x19\x05\x0F\x11\x16\x19\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group2A_index10[] = "Vuoi veramente eliminare questo file\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group2A_index11[] = "Il\x0F\x05 File \x16\x19\x05\x0F\x11\x16\x19\x05\x0F \x16\x19 e\x5C stato eliminato\xC2";
char group2A_index12[] = "Seleziona modalit\xD1 di gioco";
char group2A_index13[] = "Questa modalit\xD1 per un giocatore ti\npermette di goderti a pieno la storia";
char group2A_index14[] = "Questa modalit\xD1 ti permette di\ngiocare qualunque tabellone";
char group2A_index15[] = "Continuare la partita\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group2A_index16[] = "Iniziare una nuova partita\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group2A_index17[] = "Inserisci il tuo nome";
char group2A_index18[] = "Non puoi copiare un file che \xD5\nal momento utilizzato";
char group2A_index19[] = "Non ci sono file";
char group2A_index20[] = "Creazione file in corso\x85\x85\x85";
char group2A_index21[] = "Salvataggio\x85\x85\x85";
char group2A_index22[] = "Copia in corso\x85\x85\x85";
char group2A_index23[] = "Eliminazione\x85\x85\x85";
char group2A_index24[] = "Questo file ha dati salvati per una\npartita in svolgimento\x85\x19\xFF";
char group2A_index25[] = "Vuoi cancellare anche questi dati\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group31_index0[] = "Ha\x82 ha\x82 ha\x82\nsono la \x07\x0FStella Millenaria\x16\x19\xC2\x19\xFF";
char group31_index1[] = "Usa il Control Stick per scegliere\nla tua destinazione\x82 e premi \x21\xC2\xFF";
char group31_index2[] = "Usa il Control Stick per scegliere\nla tua destinazione\x82 e premi \x21\xC2\xFF";
char group31_index3[] = "Questo Ascensore Stella v\xD1\nai \x05\x0FTabelloni\x16\x19\xC2";
char group31_index4[] = "Questo Ascensore Stella v\xD1\nalle \x05\x0FMappe Duello\x16\x19\xC2";
char group31_index5[] = "Questo Ascensore Stella v\xD1\nalla \x05\x0FSala Minigiochi\x16\x19\xC2";
char group31_index6[] = "Questo\x05\x0F Cannone\x16\x19 ti sparer\xD1 al\ntabellone a cui si st\xD1 giocando\xC2";
char group31_index7[] = "Questo \xD5 il\x05\x0F Castello di Peach\x16\x19\x85\nQu\xE1 puoi cambiare le impostazioni di gioco";
char group31_index8[] = "Qu\xE1 puoi vedere i\n\x05\x0Frisultati \x16\x19Superstar\xC2";
char group31_index9[] = "Vuoi ascoltare il regolamento dei\n\x05\x0FTabelloni\x16\x19\xC3 \x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group31_index10[] = "Vuoi ascoltare il regolamento delle\n\x05\x0F Mappe Duello\x16\x19\xC3 \x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group31_index11[] = "Uhm\x85\x85\x85 Sembra ci siano ancora\ndati salvati\x85\x19\xFF";
char group31_index12[] = "Vuoi rigiocare questo Tabellone\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group31_index13[] = "Vuoi ricominciare questa partita\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group31_index14[] = "Se salverai ora\x05\x0F sovrascriverai\x16\x19\nquesto file\x85\x85\x19\xFF";
char group31_index15[] = "Se vuoi conservare questi dati\x82\ncontinua a giocare e\x05\x0F NON SALVARE\x16\x19\x85\x85\x19\xFF";
char group31_index16[] = "I tuoi dati saranno cancellati\x85\xC3\n\x1A\x1A\x0CVa Bene\x1A\x1A\x1A\x1A\x0D\x0CNo\x0D";
char group31_index19[] = "Se vuoi riprendere la partita\nscegli il\x05\x0F cannone\x16\x19\xC2\x19\xFF";
char group31_index17[] = "\x85\x85\x85Questo cos\x5C\xD6\xC3 Sembra che sia ancora\n\x03\x0Fin costruzione\x16\x19\x85\x19\xFF";
char group31_index18[] = "Hai 2 file salvati\x85 A quale vuoi\ngiocare\xC3\x00\x00\x00\x00\x04\x0B\n\x00\x00\x00\x1D\x0B";
char group31_index20[] = "Busto in Pietra di\n\x07\x0F\x12\x16\x19\x82 un \x11\x85";
char group31_index21[] = "Uh\xC3 Vuoi veramente uscire\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
char group31_index22[] = "Allora ciao\xC2 A presto\xC2\x19\xFF";
char group31_index23[] = "Benissimo\xC2 Allora andiamo\xC2\x19\xFF";
char group31_index24[] = "Non puoi arrivare al prossimo\n tabellone da qui\xC5\xC2\x19\xFF";
char group31_index25[] = "Quando sei pronto a combattere\nselezionami\xC2";
char group31_index26[] = "Oh\x82 oh\xC2 Sembra che il busto di pietra di\n\x07\x0F\x11\x16\x19\x07\x0F\x16\x19 sia finito\x85\x19\xFF";
char group31_index27[] = "\x07\x0FStella Miracolo\x16\x19";
char group31_index28[] = "\x07\x0FUltra Stella\x16\x19";
char group31_index29[] = "\x07\x0FGrande Stella\x16\x19";
char group31_index33[] = "\x07\x0F\x5CStella scarsa\x5C\x16\x19";
char group31_index34[] = "\x07\x0F\x5CStella triste\x5C\x16\x19";
char group31_index35[] = "Se vuoi saperne di pi\xDD sui\n\x07\x0FLivelli stellari\x16\x19\x82 selezionami\xC2";
char group31_index36[] = "Sono la\x07\x0F Stella Millenaria\x16\x19\x85 Gioca\nal tabellone che preferisci\xC2";
char group31_index37[] = "Uh\xC3 Il mio consiglio\xC3 Che ne\n diresti di \x05\x0F\x11\x16\x19\xC3\x19\xFF";
char group31_index51[] = "Vuoi andare alla Sala Minigiochi\xC3\n\x1A\x1A\x0CSi\x1A\x1A\x0D\x0CNo\x0D";
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
char* group15[200] = {group15_index0, group15_index1, group15_index2, group15_index3, group15_index4, group15_index5, group15_index6, group15_index7, group15_index8, group15_index9, group15_index10, group15_index11, group15_index12, group15_index13, group15_index14, group15_index15, group15_index16, group15_index17, group15_index18, group15_index19, group15_index20, group15_index21, group15_index22, group15_index23, group15_index24};
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
char* group2A[200] = {group2A_index0, group2A_index1, group2A_index2, group2A_index3, group2A_index4, group2A_index5, group2A_index6, group2A_index7, group2A_index8, group2A_index9, group2A_index10, group2A_index11, group2A_index12, group2A_index13, group2A_index14, group2A_index15, group2A_index16, group2A_index17, group2A_index18, group2A_index19, group2A_index20, group2A_index21, group2A_index22, group2A_index23, group2A_index24, group2A_index25};
char* group2B[200] = {0};
char* group2C[200] = {0};
char* group2D[200] = {0};
char* group2E[200] = {0};
char* group2F[200] = {0};
char* group30[200] = {0};
char* group31[200] = {group31_index0, group31_index1, group31_index2, group31_index3, group31_index4, group31_index5, group31_index6, group31_index7, group31_index8, group31_index9, group31_index10, group31_index11, group31_index12, group31_index13, group31_index14, group31_index15, group31_index16, group31_index17, group31_index18, group31_index19, group31_index20, group31_index21, group31_index22, group31_index23, group31_index24, group31_index25, group31_index26, group31_index27, group31_index28, group31_index29, 0, 0, 0, group31_index33, group31_index34, group31_index35, group31_index36, group31_index37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, group31_index51};
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
char* group4D[200] = {group4D_index0, group4D_index1, group4D_index2, 0, group4D_index4, 0, group4D_index6, 0, group4D_index8, 0, group4D_index10, 0, group4D_index12, 0, group4D_index14, 0, group4D_index16, 0, group4D_index18, 0, group4D_index20, 0, group4D_index22, 0, group4D_index24, 0, group4D_index26, 0, group4D_index28, 0, 0, 0, 0, group4D_index33};
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

u8 asciiLUT[] = {
/* 0x00 */ 0x00, //
/* 0x01 */ 0x01, // ☺
/* 0x02 */ 0x02, // ☻
/* 0x03 */ 0x03, // ♥
/* 0x04 */ 0x04, // ♦
/* 0x05 */ 0x05, // ♣
/* 0x06 */ 0x06, // ♠
/* 0x07 */ 0x07, //
/* 0x08 */ 0x08, //
/* 0x09 */ 0x09, //
/* 0x0A */ 0x0A, // \n
/* 0x0B */ 0x0B, //
/* 0x0C */ 0x0C, //
/* 0x0D */ 0x0D, //
/* 0x0E */ 0x0E, //
/* 0x0F */ 0x0F, //
/* 0x10 */ 0x10, // ►
/* 0x11 */ 0x11, // ◄
/* 0x12 */ 0x12, // ↕
/* 0x13 */ 0x13, // ‼
/* 0x14 */ 0x14, // ¶
/* 0x15 */ 0x15, // §
/* 0x16 */ 0x16, // ▬
/* 0x17 */ 0x17, // ↨
/* 0x18 */ 0x18, // ↑
/* 0x19 */ 0x19, // ↓
/* 0x1A */ 0x1A, // →
/* 0x1B */ 0x1B, //
/* 0x1C */ 0x1C, // ∟
/* 0x1D */ 0x1D, // ↔
/* 0x1E */ 0x1E, // ▲
/* 0x1F */ 0x1F, // ▼
/* 0x20 */ 0x20, //
/* 0x21 */ 0xC2, // !
/* 0x22 */ 0x22, // "
/* 0x23 */ 0x23, // #
/* 0x24 */ 0x24, // $
/* 0x25 */ 0x25, // %
/* 0x26 */ 0x26, // &
/* 0x27 */ 0x27, // '
/* 0x28 */ 0x28, // (
/* 0x29 */ 0x29, // )
/* 0x2A */ 0x2A, // *
/* 0x2B */ 0x2B, // +
/* 0x2C */ 0x2C, // ,
/* 0x2D */ 0x2D, // -
/* 0x2E */ 0x85, // .
/* 0x2F */ 0x2F, // /
/* 0x30 */ 0x30, // 0
/* 0x31 */ 0x31, // 1
/* 0x32 */ 0x32, // 2
/* 0x33 */ 0x33, // 3
/* 0x34 */ 0x34, // 4
/* 0x35 */ 0x35, // 5
/* 0x36 */ 0x36, // 6
/* 0x37 */ 0x37, // 7
/* 0x38 */ 0x38, // 8
/* 0x39 */ 0x39, // 9
/* 0x3A */ 0x3A, // :
/* 0x3B */ 0x3B, // ;
/* 0x3C */ 0x3C, // <
/* 0x3D */ 0x3D, // =
/* 0x3E */ 0x3E, // >
/* 0x3F */ 0x3F, // ?
/* 0x40 */ 0x40, // @
/* 0x41 */ 0x41, // A
/* 0x42 */ 0x42, // B
/* 0x43 */ 0x43, // C
/* 0x44 */ 0x44, // D
/* 0x45 */ 0x45, // E
/* 0x46 */ 0x46, // F
/* 0x47 */ 0x47, // G
/* 0x48 */ 0x48, // H
/* 0x49 */ 0x49, // I
/* 0x4A */ 0x4A, // J
/* 0x4B */ 0x4B, // K
/* 0x4C */ 0x4C, // L
/* 0x4D */ 0x4D, // M
/* 0x4E */ 0x4E, // N
/* 0x4F */ 0x4F, // O
/* 0x50 */ 0x50, // P
/* 0x51 */ 0x51, // Q
/* 0x52 */ 0x52, // R
/* 0x53 */ 0x53, // S
/* 0x54 */ 0x54, // T
/* 0x55 */ 0x55, // U
/* 0x56 */ 0x56, // V
/* 0x57 */ 0x57, // W
/* 0x58 */ 0x58, // X
/* 0x59 */ 0x59, // Y
/* 0x5A */ 0x5A, // Z
/* 0x5B */ 0x5B, // [
/* 0x5C */ 0x5C, // "\"
/* 0x5D */ 0x5D, // ]
/* 0x5E */ 0x5E, // ^
/* 0x5F */ 0x5F, // _
/* 0x60 */ 0x60, // `
/* 0x61 */ 0x61, // a
/* 0x62 */ 0x62, // b
/* 0x63 */ 0x63, // c
/* 0x64 */ 0x64, // d
/* 0x65 */ 0x65, // e
/* 0x66 */ 0x66, // f
/* 0x67 */ 0x67, // g
/* 0x68 */ 0x68, // h
/* 0x69 */ 0x69, // i
/* 0x6A */ 0x6A, // j
/* 0x6B */ 0x6B, // k
/* 0x6C */ 0x6C, // l
/* 0x6D */ 0x6D, // m
/* 0x6E */ 0x6E, // n
/* 0x6F */ 0x6F, // o
/* 0x70 */ 0x70, // p
/* 0x71 */ 0x71, // q
/* 0x72 */ 0x72, // r
/* 0x73 */ 0x73, // s
/* 0x74 */ 0x74, // t
/* 0x75 */ 0x75, // u
/* 0x76 */ 0x76, // v
/* 0x77 */ 0x77, // w
/* 0x78 */ 0x78, // x
/* 0x79 */ 0x79, // y
/* 0x7A */ 0x7A, // z
/* 0x7B */ 0x7B, // {
/* 0x7C */ 0x7C, // |
/* 0x7D */ 0x7D, // }
/* 0x7E */ 0x7E, // ~
/* 0x7F */ 0x7F, //
/* 0x80 */ 0x80, // Ç
/* 0x81 */ 0x81, // ü
/* 0x82 */ 0x82, // é
/* 0x83 */ 0x83, // â
/* 0x84 */ 0x84, // ä
/* 0x85 */ 0x85, // à
/* 0x86 */ 0x86, // å
/* 0x87 */ 0x87, // ç
/* 0x88 */ 0x88, // ê
/* 0x89 */ 0x89, // ë
/* 0x8A */ 0x8A, // è
/* 0x8B */ 0x8B, // ï
/* 0x8C */ 0x8C, // î
/* 0x8D */ 0x8D, // ì
/* 0x8E */ 0x8E, // Ä
/* 0x8F */ 0x8F, // Å
/* 0x90 */ 0x90, // É
/* 0x91 */ 0x91, // æ
/* 0x92 */ 0x92, // Æ
/* 0x93 */ 0x93, // ô
/* 0x94 */ 0x94, // ö
/* 0x95 */ 0x95, // ò
/* 0x96 */ 0x96, // û
/* 0x97 */ 0x97, // ù
/* 0x98 */ 0x98, // ÿ
/* 0x99 */ 0x99, // Ö
/* 0x9A */ 0x9A, // Ü
/* 0x9B */ 0x9B, // ¢
/* 0x9C */ 0x9C, // £
/* 0x9D */ 0x9D, // ¥
/* 0x9E */ 0x9E, // ₧
/* 0x9F */ 0x9F, // ƒ
/* 0xA0 */ 0xA0, // á
/* 0xA1 */ 0xA1, // í
/* 0xA2 */ 0xA2, // ó
/* 0xA3 */ 0xA3, // ú
/* 0xA4 */ 0xA4, // ñ
/* 0xA5 */ 0xA5, // Ñ
/* 0xA6 */ 0xA6, // ª
/* 0xA7 */ 0xA7, // º
/* 0xA8 */ 0xA8, // ¿
/* 0xA9 */ 0xA9, // ⌐
/* 0xAA */ 0xAA, // ¬
/* 0xAB */ 0xAB, // ½
/* 0xAC */ 0xAC, // ¼
/* 0xAD */ 0xAD, // ¡
/* 0xAE */ 0xAE, // «
/* 0xAF */ 0xAF, // »
/* 0xB0 */ 0xB0, // ░
/* 0xB1 */ 0xB1, // ▒
/* 0xB2 */ 0xB2, // ▓
/* 0xB3 */ 0xB3, // │
/* 0xB4 */ 0xB4, // ┤
/* 0xB5 */ 0xB5, // ╡
/* 0xB6 */ 0xB6, // ╢
/* 0xB7 */ 0xB7, // ╖
/* 0xB8 */ 0xB8, // ╕
/* 0xB9 */ 0xB9, // ╣
/* 0xBA */ 0xBA, // ║
/* 0xBB */ 0xBB, // ╗
/* 0xBC */ 0xBC, // ╝
/* 0xBD */ 0xBD, // ╜
/* 0xBE */ 0xBE, // ╛
/* 0xBF */ 0xBF, // ┐
/* 0xC0 */ 0xC0, // └
/* 0xC1 */ 0xC1, // ┴
/* 0xC2 */ 0xC2, // ┬
/* 0xC3 */ 0xC3, // ├
/* 0xC4 */ 0xC4, // ─
/* 0xC5 */ 0xC5, // ┼
/* 0xC6 */ 0xC6, // ╞
/* 0xC7 */ 0xC7, // ╟
/* 0xC8 */ 0xC8, // ╚
/* 0xC9 */ 0xC9, // ╔
/* 0xCA */ 0xCA, // ╩
/* 0xCB */ 0xCB, // ╦
/* 0xCC */ 0xCC, // ╠
/* 0xCD */ 0xCD, // ═
/* 0xCE */ 0xCE, // ╬
/* 0xCF */ 0xCF, // ╧
/* 0xD0 */ 0xD0, // ╨
/* 0xD1 */ 0xD1, // ╤
/* 0xD2 */ 0xD2, // ╥
/* 0xD3 */ 0xD3, // ╙
/* 0xD4 */ 0xD4, // ╘
/* 0xD5 */ 0xD5, // ╒
/* 0xD6 */ 0xD6, // ╓
/* 0xD7 */ 0xD7, // ╫
/* 0xD8 */ 0xD8, // ╪
/* 0xD9 */ 0xD9, // ┘
/* 0xDA */ 0xDA, // ┌
/* 0xDB */ 0xDB, // █
/* 0xDC */ 0xDC, // ▄
/* 0xDD */ 0xDD, // ▌
/* 0xDE */ 0xDE, // ▐
/* 0xDF */ 0xDF, // ▀
/* 0xE0 */ 0xE0, // α
/* 0xE1 */ 0xE1, // ß
/* 0xE2 */ 0xE2, // Γ
/* 0xE3 */ 0xE3, // π
/* 0xE4 */ 0xE4, // Σ
/* 0xE5 */ 0xE5, // σ
/* 0xE6 */ 0xE6, // µ
/* 0xE7 */ 0xE7, // τ
/* 0xE8 */ 0xE8, // Φ
/* 0xE9 */ 0xE9, // Θ
/* 0xEA */ 0xEA, // Ω
/* 0xEB */ 0xEB, // δ
/* 0xEC */ 0xEC, // ∞
/* 0xED */ 0xED, // φ
/* 0xEE */ 0xEE, // ε
/* 0xEF */ 0xEF, // ∩
/* 0xF0 */ 0xF0, // ≡
/* 0xF1 */ 0xF1, // ±
/* 0xF2 */ 0xF2, // ≥
/* 0xF3 */ 0xF3, // ≤
/* 0xF4 */ 0xF4, // ⌠
/* 0xF5 */ 0xF5, // ⌡
/* 0xF6 */ 0xF6, // ÷
/* 0xF7 */ 0xF7, // ≈
/* 0xF8 */ 0xF8, // °
/* 0xF9 */ 0xF9, // ∙
/* 0xFA */ 0xFA, // ·
/* 0xFB */ 0xFB, // √
/* 0xFC */ 0xFC, // ⁿ
/* 0xFD */ 0xFD, // ²
/* 0xFE */ 0xFE, // ■
/* 0xFF */ 0xFF, //
};

char* convertAsciiToMp3(char* asciiString) {
    for (int i = 0; asciiString[i] != 0; i++) {
        u8 asciiCharacter = asciiString[i];
        asciiString[i] = asciiLUT[asciiCharacter];
    }
    return asciiString;
}

void cBootFunction(void) {
    for (s32 i = 0; i < sizeof(textGroups) / sizeof(textGroups[0]); i++) { //for loop for all groups
        for (s32 j = 0; j < sizeof(group00) / sizeof(char*); j++) {
            if (textGroups[i][j] != NULL) {
                textGroups[i][j] = convertAsciiToMp3(textGroups[i][j]);
            }
        }
    }
}

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

