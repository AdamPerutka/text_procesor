#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

int main(int argc, char *argv[]){
    char string[MAX];
    char novystring[MAX];
    char skusobnystring[MAX];
    char nonoptionArgument[20];
    char ach[MAX];

    int j = 0;
    int pocetSpinacov = 0;
    int pocetDvojbdk = 3;
    int dlzkastringu = 0;
    int k = 0;




    int opt;
    char *optstring = ":dpulr:R:";
    int pocetZopakovani = 0;


    for (int ok = 1; ok < argc; ok++) { //vypocitanie kolko spinacov sa nachadza v cmd
        if (argv[ok][0] == '-') {
            pocetSpinacov += 1;
        }
    }
    int nonOptionArgumentOdIX; //Index pre argv[nonopt...] odkial zacina non option argument

    while ((opt = getopt(argc, argv, optstring)) != -1) {



    switch (opt) {
/// od 65 po 90 su velke pismena !!
/// od 97 po 122 su male pismena !!
        /// vstupne operacie (mozu sa kombinovat)
        case 'd': {
            skusobnystring[0]='d';
            break;
        }
        case 'p': {
            skusobnystring[1]='p';
            break;
        }
        case 'u': {
            skusobnystring[2]='u';
            break;
        }
        case 'l': {
            skusobnystring[3]='l';
            break;
        }
            /// nahrádzanie slov (nemôžu sa kombinovať)
        case 'r': {
            skusobnystring[4] = 'r';
            break;
        }
        case 'R': {

            skusobnystring[5] = 'R';
            break;
        }
        default:
        {
            if(opt=='?'){
                return 1;
            }
            if(opt==':'){
                return 2;
            }
        return 1;
        }
    }

    }
//    printf("\npocet: %d\n",pocetSpinacov);
  //  while( fgets (string, MAX, fp) != NULL ){
   while(strcmp( fgets (string, MAX, stdin),"\n") != 0 ) {

        for (int i = 0; i < MAX; i++) {
            dlzkastringu++;
            if (string[i] == '\n') {
                break;
            }
        }

if(skusobnystring[0] == 'd'){
    int dp = 0;
    int D = 0;
    int z = 0;

    if (argc > 2) {
        if (argv[2][1] == 'p' || argv[1][1] == 'p') {

            memmove(novystring, string, dlzkastringu);
            dp = 1;
        }
    }


    // neplatny argument

    //

    if (pocetSpinacov + 1 < argc && argv[2][0] != '-' ||
        pocetSpinacov + 1 < argc && argv[1][0] != '-') {
        //    printf("2");
        return 1;
    }

    // printf("halo:::");

    if(dp == 0) {
        for (z = 0; string[z] != '\n'; z++) {

            if (ispunct(string[z]) == 0) {

                novystring[D] = string[z];

                D++;

            }
        }
        string[D] = '\n';
        novystring[D] = '\n';
        memmove(string, novystring, D);
    }
}
if(skusobnystring[1] == 'p'){
    int j = 0;
    int dp = 0;
    int i = 0;
    int pocitanie = 0;
    int nachadzaSa = 0;
    // to do - -d -p argumet == return 1

    //




    for (int p = 1; p < argc; p++) {

       if(skusobnystring[0] == 'd') {
                    nachadzaSa = 1;

                }

        if (pocetSpinacov > 2 && argv[p][1] == 'p' && nachadzaSa == 1 && p < 2) {

            if (argv[p + 1][1] != 'd') {
                //  printf("return");
                return 1;
            }


        }
        if (pocetSpinacov > 2 && argv[p][1] == 'p' && nachadzaSa == 1 && p > 2) {

            if (argv[p - 1][1] != 'd') {
//                                printf("return2");
                return 1;
            }
        }

    }
    if (argc > 2) {
        if (argv[2][1] == 'd' || argv[1][1] == 'd') {
            memmove(novystring, string, dlzkastringu);
            dp = 1;
        }
    }

    if (pocetSpinacov + 1 < argc && argv[2][0] != '-' ||
        pocetSpinacov + 1 < argc && argv[1][0] != '-') {
        return 1;
    }
    if(dp == 0){
        for (i = 0; string[i] != '\n'; i++) {
            if (isdigit(string[i]) == 0) {
                novystring[j] = string[i];
                j++;

            }
        }
        string[j]='\n';
        novystring[j] = '\n';
        memmove(string, novystring, i);
    }
}
if(skusobnystring[2] == 'u') {
    int j = 0;
    int i = 0;
    int zastav = 0;

    if (argc == 2) {
        int pocet = 0;
        int k = 0;
        for (int k = 0; string[k] != '\n'; k++) {
            //  printf("%c",string[k]);
            if (ispunct(string[k]) == 0 && isdigit(string[k]) == 0) {
                char zvacsit = toupper(string[k]);
                novystring[pocet] = zvacsit;
                pocet++;
            }

        }

        novystring[pocet] = '\n';
        zastav = 1;
    }

    if(zastav == 0) {
        for (i = 0; string[i] != '\n'; i++) {
            char zmensit = toupper(string[i]);
            novystring[j] = zmensit;
            j++;
        }

        novystring[j] = '\n';
        memmove(string, novystring, i);
    }
//                novystring[j + 1] = '\n';
//                printf("%s", novystring);}
}
if(skusobnystring[3] == 'l') {
    int zastav = 0;
    int j = 0;
    int i = 0;
    if (argc == 2) {
        int j = 0;
        for (int k = 0; string[k] != '\n'; k++) {
            if (ispunct(string[k]) == 0 && isdigit(string[k]) == 0) {
                char zmensit = tolower(string[k]);
                novystring[j] = zmensit;
                j++;
            }

        }
        novystring[j] = '\n';
        zastav = 1;
    }
    if(zastav == 0) {
        for (i = 0; string[i] != '\n'; i++) {
            char zmensit = tolower(string[i]);
            novystring[j] = zmensit;
            j++;
        }
        novystring[j] = '\n';
        memmove(string, novystring, i);
    }
}
if(skusobnystring[4] == 'r'){

    // vyhladanie non optionov
    if(optind < argc){
        int nonoption = 0;
        for(int i=optind;i<argc;i++){
           printf("nonoption: %s\n",argv[i]);
//                strcpy(nonoptionArgument,argv[i]);
//                memmove(nonoptionArgument, argv[i], /**/strlen(argv[i]));

        }
    }

    char povinnyArgument[20];
    /// isalnum 1 = male pismeno
    /// 2 = velke pismeno
    /// 4 = cislo/znak
    int L = 1;

    // NAJDENIE POVINNEHO ARGUMENTU !
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'r')
            {
//                strcpy(povinnyArgument,argv[i+1]);
            memmove(povinnyArgument, argv[i + 1], strlen(argv[i+1]));
            L = i;

//            povinnyArgument[strlen(argv[i+1])] = '\n';
            i+=2;

        }
        printf("%s",povinnyArgument);
    }
    int i = 0;
    int arg = 0;
    novystring[i] = '\n';
    memmove(string, novystring, i);


        }
if(skusobnystring[5] == 'R'){
    char povinnyArgument[MAX];
    /// isalnum 1 = male pismeno
    /// 2 = velke pismeno
    /// 4 = cislo/znak


    // NAJDENIE POVINNEHO ARGUMENTU !
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'r') {
            memmove(povinnyArgument, argv[i + 1], strlen(argv[i]));
            i++;
//                            povinnyArgument[1] = argv[i+1];
//                            printf("argc: %d i: %d",argc-1,i);
            if ((argc - 1) > i) {

                nonOptionArgumentOdIX = i + 2;
            }
        }
    }

    int r = 0;
    int i = 0;
    for (i = 0; string[i] != '\n'; i++) {
        r = 0;
        if ((isalnum(string[i])) != 0) {
            //    printf("pvR: %c", povinnyArgument[i]);
            string[i] = povinnyArgument[r];
            r++;

        }
//                        if((isalnum(string[i])) == 0){
//                            novystring[r] = ' ';
//                            r++;
//                        }
    }
    memmove(novystring, povinnyArgument, i);
    novystring[r] = '\n';

    break;

        break;
}


        if (argc == 1) {
            int j = 0;
            int k = 0;


            for (k = 0; string[k] != '\n'; k++) {
                if (ispunct(string[k]) == 0 && isdigit(string[k]) == 0) {
                    novystring[j] = string[k];
                    j++;

                }
            }
            novystring[j] = '\n';
        }
//VYPISOVANIE STRINGU KONECNEHO



        for (int ke = 0; novystring[ke] != '\n'; ke++)
        {
            printf("%c", novystring[ke]);
        }
        printf("\n");

    }

    return 0;
}
