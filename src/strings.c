#include "../include/mp3.h"
#include "asciiTable.c"

#define NULL_STRING (char*)-1
#define IMAGE_PAD "\x1A\x1A\x1A\x1A"

char defaultString[] = "test";

char group2_index1[] = "Test";
char group15_index0[] = "Benvenuto! Questo Ascensore Stella\nva ai\x0F\x05 Tabelloni di gioco\x16\x19!\xFF\x0BIo sono\x0F\x05 Dadì\x16\x19. Da ora in avanti\nsarò io la tua guida\xFF\x0B";
char group15_index1[] = "\x0BVuoi tornare al\x0F\x05 cortile del Castello\x16\x19?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group15_index2[] = "OK! \x97 ora di scegliere le\nimpostazioni di gioco.\xFF";
char group15_index3[] = "In quanti giocheranno stavolta?\xFF\x0B";
char group15_index4[] = "\x0B\x05\x0F 1 Giocatore\x16\x19 e\n\x03\x0F 3 Personaggi COM\x16\x19";
char group15_index5[] = "\x0B\x05\x0F 2 Giocatori\x16\x19 e\n\x03\x0F 2 Personaggi COM\x16\x19";
char group15_index6[] = "\x0B\x05\x0F 3 Giocatori\x16\x19 e\n\x03\x0F 1 Personaggio COM\x16\x19";
char group15_index7[] = "\x0B\x05\x0F 4 Giocatori\x16\x19";
char group15_index8[] = "\x0BScegli quali Personaggi\nverranno usati dai Giocatori.";
char group15_index9[] = "\x0BScegli quali\x05\x0F 3 Personaggi\x16\x19 verranno\nusati dal\x03\x0F Computer\x16\x19\xFF\x0b";
char group15_index10[] = "\x0BScegli quali\x05\x0F 2 Personaggi\x16\x19 verranno\nusati dal\x03\x0F Computer\x16\x19\xFF\x0B";
char group15_index11[] = "\x0BScegli quale\x05\x0F Personaggio\x16\x19 verrà\nutilizzato dal\x03\x0F Computer\x16\x19\xFF\x0B";
char group15_index12[] = "\x0B\x03\x0FMario\x16\x0F --\x16\x19 Il nostro eroe usa il\n\x05\x0F Fungo D'Oro\x16\x19 per correre.";
char group15_index13[] = "\x0B\x03\x0FLuigi\x16\x0F \x3D\x3D\x16\x19 Quest'uomo dai molti talenti\nama usare\x05\x0F Schelechiavi\x16\x19.";
char group15_index14[] = "\x0B\x03\x0FPeach\x16\x0F \x3D\x3D\x16\x19 \x97 furba, quindi attenti a\nquando ha il\x05\x0F Baule Saccheggio\x16\x19!";
char group15_index15[] = "\x0B\x03\x0FYoshi\x16\x0F \x3D\x3D\x16\x19\x05\x0F Teletrasportarsi\x16\x19 è il suo\nmetodo per pedinare gli altri!";
char group15_index16[] = "\x0B\x03\x0FWario\x16\x0F \x3D\x3D\x16\x19 L'ineluttabile duellante ama\nlanciare il\x05\x0F Guanto di Sfida\x16\x19!";
char group15_index17[] = "\x0B\x03\x0F Donkey Kong\x16\x0F \x3D\x3D\x16\x19 Più forte di tutti,\ngli piace il\x05\x0F Fungo Inverso\x16\x19!";
char group15_index18[] = "\x0B\x03\x0F Daisy\x16\x0F \x3D\x3D\x16\x19 Molto maschiaccio, lei è\nfan del \x05\x0F Cellulare Acquisti\x16\x19!";
char group15_index19[] = "\x0B\x03\x0FWaluigi\x16\x0F \x3D\x3D\x16\x19 Attento, o questo furfante\nuserà un\x05\x0F Fungo Velenoso\x16\x19 su di te!";
char group15_index20[] = "\x0B Come vuoi impostare il livello di\ndifficoltà dei personaggi COM?\xFF";
char group15_index21[] = "\x0BImposta tutti i personaggi\nCOM allo stesso livello.";
char group15_index22[] = "\x0BImposta il livello dei\npersonaggi COM distintamente.";
char group15_index23[] = "\x0BImposta il livello di difficoltà\ndei personaggi COM.";
char group15_index24[] = "\x0BImposta il livello di difficoltà\nper \x11.";
char group15_index25[] = "\x0BVuoi utilizzare dei vantaggi?";
char group15_index26[] = "\x0B Decidi con quante stelle\ni personaggi inizieranno il gioco";
char group15_index27[] = "\x0BTutti i personaggi inizieranno\ncon\x03\x0F 0 \x16\x19Stelle.";
char group15_index28[] = "\x0BSeleziona il numero di \x07\x0FStelle di\nvantaggio\x16\x19 per \x11.";
char group15_index29[] = "\x0BScegli quale Tabellone vuoi giocare.\xFF";
char group15_index30[] = "\x0B\x05\x0F Falde Gelate\x16\x19\x03\x0F    Difficoltà\x7B \x3B\x16\x19\nPupazzi gelidi\ne pinguini vivaci\x85";
char group15_index31[] = "\x0B\x05\x0F Fondale Kalamako\x16\x19\x03\x0F    Difficoltà\x7B \x3B\x16\x19\nTesori sommersi\ne creature fantastiche\x85";
char group15_index32[] = "\x0B\x05\x0F Deserto Spinoso\x16\x19\x03\x0F    Difficoltà\x7B \x3B\x3B\x16\x19\nSabbie mobili\ne sole cocente\x85";
char group15_index33[] = "\x0B\x05\x0F Bosco Boscoso\x16\x19\x03\x0F    Difficoltà\x7B \x3B\x3B\x16\x19\nFlora floreale\ne creature coccolose\x85";
char group15_index34[] = "\x0B\x05\x0F Caverna Spettrale\x16\x19\x03\x0F    Difficoltà\x7B \x3B\x3B\x3B\x16\x19\nGemme lucenti\ne viscidi insetti\x85";
char group15_index35[] = "\x0B\x05\x0F Isola Di Waluigi\x16\x19\x03\x0F    Difficoltà\x7B \x3B\x3B\x3B\x16\x19\nTrappole perfide\ne arnesi astuti\x85";
char group15_index36[] = "\x0BScegli il numero di turni.\xFF";
char group15_index37[] = "\x0B\x05\x0F Leggero\x16\x19\nLa partita finirà dopo\x05\x0F 20 turni\x16\x19.";
char group15_index38[] = "\x0B\x05\x0F Standard\x16\x19\nLa partita finirà dopo\x05\x0F 35 turni\x16\x19.";
char group15_index39[] = "\x0B\x05\x0F Completo\x16\x19\nLa partita finirà dopo\x05\x0F 50 turni\x16\x19.";
char group15_index40[] = "\x0B\x05\x0FPersonalizzato\x16\x19\nDecidi tu il numero di turni.";
char group15_index41[] = "\x0BScegli il\n\x19numero di turni.\x19\x19";
char group15_index42[] = "\x0BVuoi assegnare\x05\x0F Bonus\x16\x19?\xFF";
char group15_index43[] = "\x0BI\x05\x0F Bonus\x16\x19 saranno annunciati\nalla fine della partita.";
char group15_index44[] = "\x0BNon assegnare\x05\x0F Bonus\x16\x19.";
char group15_index45[] = "\x0BVanno bene queste impostazioni?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group15_index46[] = "\x0BReimpostare tutto?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group15_index47[] = "\x0BSiete pronti per la partita?\nAllora andiamo!\xFF";
char group15_index48[] = "\x0B\x16\x02Scegli un pacchetto Minigiochi\x19.\xFF";
char group15_index49[] = "\x0B\x05\x0FPacchetto Normale\x16\x19\nTutti i Minigiochi possono uscire.";
char group15_index50[] = "\x0B\x05\x0FPacchetto Facile\x16\x19\nSolo Minigiochi più facili.";
char group18_index12[] = "Siete tutti qui!\nBenvenuti nelle leggendarie\x0F\x05 Falde Gelate\x16\x19!\x19\xFF\x0BIn questo territorio freddo e nevoso,\ngareggerete per diventare la Superstar.\x19\xFF\x0BOra, prima di iniziare, dobbiamo\ndeterminare l'ordine dei turni.\x19\xFF";
char group18_index13[] = "Siete tutti qui!\nBenvenuti nel leggendario\x0F\x05 Fondale Kalamako\x16\x19!\x19\xFF\x0BIn questo profondo fondale marino buio,\ngareggerete per diventare la Superstar.\x19\xFF\x0BOra, prima di iniziare, dobbiamo\ndeterminare l'ordine dei turni.\x19\xFF";
char group18_index14[] = "Siete tutti qui!\nBenvenuti nel leggendario\x0F\x05 Deserto Spinoso\x16\x19!\x19\xFF\x0BIn questa terra del sole cocente,\ngareggerete per diventare la Superstar.\x19\xFF\x0BOra, prima di iniziare, dobbiamo\ndeterminare l'ordine dei turni.\x19\xFF";
char group18_index15[] = "Siete tutti qui!\nBenvenuti nel leggendario\x0F\x05 Bosco Boscoso\x16\x19!\x19\xFF\x0BNel bel mezzo di questa grande foresta,\ngareggerete per diventare la Superstar.\x19\xFF\x0BOra, prima di iniziare, dobbiamo\ndeterminare l'ordine dei turni.\x19\xFF";
char group18_index16[] = "Siete tutti qui!\nBenvenuti nella leggendaria\x0F\x05 Caverna Spettrale\x16\x19!\x19\xFF\x0BIn questa fantastica caverna rocciosa,\ngareggerete per diventare la Superstar.\x19\xFF\x0BOra, prima di iniziare, dobbiamo\ndeterminare l'ordine dei turni.\x19\xFF";
char group18_index17[] = "Siete tutti qui!\nBenvenuti nella leggendaria\x0F\x05 Isola di Waluigi\x16\x19!\x19\xFF\x0BIn questa isola piena di trappole malvagie,\ngareggerete per diventare la Superstar.\x19\xFF\x0BOra, prima di iniziare, dobbiamo\ndeterminare l'ordine dei turni.\x19\xFF";
char group18_index18[] = "\x0BL'ordine dei turni è deciso.\n\x1APrima parte\x1A\x11\x19\xFF";
char group18_index19[] = "\x0B\x1A Dopo tocca a\x1A\x11\x19\xFF";
char group18_index20[] = "\x0B\x1A A seguire tocca a\x1A\x11\x19\xFF";
char group18_index21[] = "\x0B\x1A Infine tocca a\x1A\x11\x19\xFF";
char group18_index22[] = "\x0B Ed infine, ecco un regalo per tutti.\nVi darò\x07\x0F 10 Gettoni\x16\x19 a testa.\nNon sprecatele.\x19\xFF";
char group18_index23[] = "\x0B Buona fortuna, e cercate di\ndiventare Superstars!\nChe la gara abbia inizio!\x19\xFF";
char group4D_index0[] = "Al centro del vasto universo,\nnacque una stella alquanto luminosa";
//char group4D_index0[] = "Test message.";
char group4D_index1[] = "Test replacement message 4D01\xC2";
char group4D_index2[] = "Era una stella che nasce solo una volta\nogni mille anni, la Stella Millenaria";
char group4D_index4[] = "Si dice che chiunque entri in possesso\ndella stella mistica era destinato\na diventare la Superstar dell'universo";
char group4D_index6[] = "Tuttavia, siccome la Stella Millenaria\nnon era che neonata...";
char group4D_index8[] = "Cadde dal cielo stellato.";
char group4D_index10[] = "Allora, Mario e i suoi amici\nerano tutti a rilassarsi felicemente,";
char group4D_index12[] = "quando......";
char group4D_index14[] = "All'improvviso, la Stella Millenaria\narrivò precipitando...";
char group4D_index16[] = "Poco dopo, Mario e i suoi amici iniziarono\na battersi su chi doveva tenere\nla Stella Millenaria.";
char group4D_index18[] = "Vedendo ciò, Lakitu arrivò in volo,\ndondolando una scatola dalla sua canna";
char group4D_index20[] = "Proprio così! Potrebbero giocare a \n\xC0Mario Party\xC1 per stabilire chi fosse\nla più grande Superstar!";
char group4D_index22[] = "Improvvisamente, la Stella Millenaria\ndiede un bagliore accecante!";
char group4D_index24[] = "E con quella lampata, Mario e i suoi amici\nfurono trasportati\nall'interno della scatola!";
char group4D_index26[] = "\xC0Salve! Sono la Stella Millenaria!\xC1";
char group4D_index28[] = "Dovrai superare la mia prova per\ndimostrarti degno di possedermi";
char group4D_index33[] = "Seguimi!";
char group2A_index0[] = "Seleziona un file";
char group2A_index1[] = "Copia un file";
char group2A_index2[] = "Seleziona il file che vuoi copiare";
char group2A_index3[] = "Non puoi copiare un file se non ci\nsono file o sono tutti utilizzati";
char group2A_index4[] = "Per copiare un file, eliminare\n un file esistente";
char group2A_index5[] = "Dove vuoi copiare\x0F\x05 File \x16\x19\x05\x0F\x11\x16\x19\x05\x0F\x16\x19?";
char group2A_index6[] = "Copia completata";
char group2A_index7[] = "Elimina un file";
char group2A_index8[] = "Seleziona il file che vuoi eliminare";
char group2A_index9[] = "Vuoi eliminare\x0F\x05 File \x16\x19\x05\x0F\x11\x16\x19\xC3\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group2A_index10[] = "Vuoi veramente eliminare questo file?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group2A_index11[] = "Il\x0F\x05 File \x16\x19\x05\x0F\x11\x16\x19\x05\x0F \x16\x19 \xD5 stato eliminato!";
char group2A_index12[] = "Seleziona modalità di gioco";
char group2A_index13[] = "Questa modalità per un giocatore ti\npermette di goderti a pieno la storia";
char group2A_index14[] = "Questa modalità ti permette di\ngiocare qualunque tabellone";
char group2A_index15[] = "Continuare la partita?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group2A_index16[] = "Iniziare una nuova partita?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group2A_index17[] = "Inserisci il tuo nome";
char group2A_index18[] = "Non puoi copiare un file che è\nal momento utilizzato";
char group2A_index19[] = "Non ci sono file";
char group2A_index20[] = "Creazione file in corso...";
char group2A_index21[] = "Salvataggio...";
char group2A_index22[] = "Copia in corso...";
char group2A_index23[] = "Eliminazione...";
char group2A_index24[] = "Questo file ha dati salvati per una\npartita in svolgimento.\x19\xFF";
char group2A_index25[] = "Vuoi cancellare anche questi dati\xC3\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group31_index0[] = "Ha, ha, ha,\nsono la \x07\x0FStella Millenaria\x16\x19!\x19\xFF";
char group31_index1[] = "Usa il Control Stick per scegliere\nla tua destinazione, e premi \xFD!\xFF";
char group31_index2[] = "Usa il Control Stick per scegliere\nla tua destinazione, e premi \xFD!\xFF";
char group31_index3[] = "Questo Ascensore Stella va\nai \x05\x0FTabelloni\x16\x19!";
char group31_index4[] = "Questo Ascensore Stella va\nalle \x05\x0FMappe Duello\x16\x19!";
char group31_index5[] = "Questo Ascensore Stella va\nalla \x05\x0FSala Minigiochi\x16\x19!";
char group31_index6[] = "Questo\x05\x0F Cannone\x16\x19 ti sparerà al\ntabellone a cui si stà giocando!";
char group31_index7[] = "Questo è il\x05\x0F Castello di Peach\x16\x19.\nQuì puoi cambiare le impostazioni di gioco";
char group31_index8[] = "Quì puoi vedere i\n\x05\x0Frisultati \x16\x19Superstar!";
char group31_index9[] = "Vuoi ascoltare il regolamento dei\n\x05\x0FTabelloni\x16\x19? \x1A\x1A>Sì\x1A\x1A<>No<";
char group31_index10[] = "Vuoi ascoltare il regolamento delle\n\x05\x0F Mappe Duello\x16\x19? \x1A\x1A>Sì\x1A\x1A<>No<";
char group31_index11[] = "Uhm... Sembra ci siano ancora\ndati salvati.\x19\xFF";
char group31_index12[] = "Vuoi rigiocare questo Tabellone?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group31_index13[] = "Vuoi ricominciare questa partita?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group31_index14[] = "Se salverai ora\x05\x0F sovrascriverai\x16\x19\nquesto file...\x19\xFF";
char group31_index15[] = "Se vuoi conservare questi dati,\ncontinua a giocare e\x05\x0F NON SALVARE\x16\x19!\x19\xFF";
char group31_index16[] = "I tuoi dati saranno cancellati!\n\x1A\x1A>Va Bene\x1A\x1A\x1A\x1A<>No<";
char group31_index19[] = "Se vuoi riprendere la partita\nscegli il\x05\x0F cannone\x16\x19!\x19\xFF";
char group31_index17[] = "...Questo cos'è? Sembra che sia ancora\n\x03\x0Fin costruzione\x16\x19.\x19\xFF";
char group31_index18[] = "Hai 2 file salvati. A quale vuoi\ngiocare?\x00\x00\x00\x00\x04\x0B\n\x00\x00\x00\x1D\x0B";
char group31_index20[] = "Busto in Pietra di\n\x07\x0F\x12\x16\x19, un \x11.";
char group31_index21[] = "Uh? Vuoi veramente uscire?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group31_index22[] = "Allora ciao! A presto!\x19\xFF";
char group31_index23[] = "Benissimo! Allora andiamo!\x19\xFF";
char group31_index24[] = "Non puoi arrivare al prossimo\n tabellone da quì!\x19\xFF";
char group31_index25[] = "Quando sei pronto a combattere\nselezionami!";
char group31_index26[] = "Oh, oh! Sembra che il busto di pietra di\n\x07\x0F\x11\x16\x19\x07\x0F\x16\x19 sia finito.\x19\xFF";
char group31_index27[] = "\x07\x0FStella Miracolo\x16\x19";
char group31_index28[] = "\x07\x0FUltra Stella\x16\x19";
char group31_index29[] = "\x07\x0FGrande Stella\x16\x19";
char group31_index33[] = "\x07\x0F\x5CStella scarsa\x5C\x16\x19";
char group31_index34[] = "\x07\x0F\x5CStella triste\x5C\x16\x19";
char group31_index35[] = "Se vuoi saperne di più sui\n\x07\x0FLivelli stellari\x16\x19, selezionami!";
char group31_index36[] = "Sono la\x07\x0F Stella Millenaria\x16\x19. Gioca\nal tabellone che preferisci!";
char group31_index37[] = "Uh? Il mio consiglio? Che ne\n diresti di \x05\x0F\x11\x16\x19?\x19\xFF";
char group31_index51[] = "Vuoi andare alla Sala Minigiochi?\n\x1A\x1A>Sì\x1A\x1A<>No<";
char group5A_index0[] = "Test replacement message\xC2";
char group5E_index0[] = "\x0B OK! Lasciate che vi mostri dove\n si trova la prima Stella!\x19\xFF";
char group5E_index1[] = "\x0B OK! La prossima stella\n si trova da questa parte!\x19\xFF";
char group5E_index2[] = "\x0B Ecco, è qui!\n Portate\x07\x0F 20 Gettoni\x16\x19 per ottenerla!\x19\xFF";
char group5E_index3[] = "\x0B Ecco, è qui!\n Portate\x07\x0F 20 Gettoni\x16\x19 per ottenerla!\n Presto! Sbrigatevi!\x19\xFF";
char group5E_index4[] = "\x0B Ecco, è qui!\n Portate\x07\x0F 20 Gettoni\x16\x19 per ottenerla!\n Non lasciatevela sfuggire!\x19\xFF";
char group5E_index5[] = "\x0B Ecco. è qui!\n Portate\x07\x0F 20 Gettoni\x16\x19 per ottenerla!\n Ha, ha, ha!\x19\xFF";
char group5E_index6[] = "\x0B Oh-Oh! La stella è finita laggiù\n Portate\x07\x0F 20 Gettoni\x16\x19 per ottenerla...\n ...semmai riuscirete ad arrivare là.\x19\xFF";
char group5E_index7[] = "\x0B Ahia! La stella è finita laggiù\n \x97 terribile!\n Nessuno riuscirà mai ad ottenerla!\x19\xFF";
char group5E_index8[] = "\x0B Wow! \x97 proprio da questa parte!\n\x07\x0F 20 Gettoni\x16\x19 per poter ottenerla!\nGrande! Lo adoro!\x19\xFF";
char group5E_index9[] = "\x0B Vi mostro dove si trova\n la prima stella che cercate.\xFF\x0B\x97 da questa parte!\nE...\x19\xFF\x0B...ce ne è un'altra di qua!\nMa una di queste è un miraggio.\nSai, un\x03\x0F falso\x16\x19! Fai Attenzione!\x19\xFF";
char group5E_index10[] = "\x0B Vi mostro dove si trova\n la prossima stella che cercate.\xFF\x0B\x97 da questa parte!\nE...\x19\xFF\x0B...ce ne è un'altra di qua!\nMa una di queste è un miraggio.\nSai, un\x03\x0F falso\x16\x19! Fai Attenzione!\x19\xFF";

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
char* group15[] = {group15_index0, group15_index1, group15_index2, group15_index3, group15_index4, group15_index5, group15_index6, group15_index7, group15_index8, group15_index9, group15_index10, group15_index11, group15_index12, group15_index13, group15_index14, group15_index15, group15_index16, group15_index17, group15_index18, group15_index19, group15_index20, group15_index21, group15_index22, group15_index23, group15_index24, group15_index25, group15_index26, group15_index27, group15_index28, group15_index29, group15_index30, group15_index31, group15_index32, group15_index33, group15_index34, group15_index35, group15_index36, group15_index37, group15_index38, group15_index39, group15_index40, group15_index41, group15_index42, group15_index43, group15_index44, group15_index45, group15_index46, group15_index47, group15_index48, group15_index49, group15_index50, NULL_STRING};
char* group16[] = {NULL_STRING};
char* group17[] = {NULL_STRING};
char* group18[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, group18_index12, group18_index13, group18_index14, group18_index15, group18_index16, group18_index17, group18_index18, group18_index19, group18_index20, group18_index21, group18_index22, group18_index23, NULL_STRING};
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
char* group2A[] = {group2A_index0, group2A_index1, group2A_index2, group2A_index3, group2A_index4, group2A_index5, group2A_index6, group2A_index7, group2A_index8, group2A_index9, group2A_index10, group2A_index11, group2A_index12, group2A_index13, group2A_index14, group2A_index15, group2A_index16, group2A_index17, group2A_index18, group2A_index19, group2A_index20, group2A_index21, group2A_index22, group2A_index23, group2A_index24, group2A_index25, NULL_STRING};
char* group2B[] = {NULL_STRING};
char* group2C[] = {NULL_STRING};
char* group2D[] = {NULL_STRING};
char* group2E[] = {NULL_STRING};
char* group2F[] = {NULL_STRING};
char* group30[] = {NULL_STRING};
char* group31[] = {group31_index0, group31_index1, group31_index2, group31_index3, group31_index4, group31_index5, group31_index6, group31_index7, group31_index8, group31_index9, group31_index10, group31_index11, group31_index12, group31_index13, group31_index14, group31_index15, group31_index16, group31_index17, group31_index18, group31_index19, group31_index20, group31_index21, group31_index22, group31_index23, group31_index24, group31_index25, group31_index26, group31_index27, group31_index28, group31_index29, 0, 0, 0, group31_index33, group31_index34, group31_index35, group31_index36, group31_index37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, group31_index51, NULL_STRING};
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
char* group4D[] = {group4D_index0, group4D_index1, group4D_index2, 0, group4D_index4, 0, group4D_index6, 0, group4D_index8, 0, group4D_index10, 0, group4D_index12, 0, group4D_index14, 0, group4D_index16, 0, group4D_index18, 0, group4D_index20, 0, group4D_index22, 0, group4D_index24, 0, group4D_index26, 0, group4D_index28, 0, 0, 0, 0, group4D_index33, NULL_STRING};
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
char* group5A[] = {group5A_index0, NULL_STRING};
char* group5B[] = {NULL_STRING};
char* group5C[] = {NULL_STRING};
char* group5D[] = {NULL_STRING};
char* group5E[] = {group5E_index0, group5E_index1, group5E_index2, group5E_index3, group5E_index4, group5E_index5, group5E_index6, group5E_index7, group5E_index8, group5E_index9, group5E_index10, NULL_STRING};
char* group5F[] = {NULL_STRING};
char* group60[] = {NULL_STRING};
char* group61[] = {NULL_STRING};
char* group62[] = {NULL_STRING};
char* group63[] = {NULL_STRING};

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

char* convertAsciiToMp3(char* asciiString) {
    for (int i = 0; asciiString[i] != 0; i++) {
        u8 asciiCharacter = asciiString[i];
        asciiString[i] = asciiLUT[asciiCharacter];
    }
    return asciiString;
}

void cBootFunction(void) {
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

