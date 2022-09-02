#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*cores*/
#define RED "\x1B[31m"
#define GRN "\x1b[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define R   "\x1B[0m"



/*prototipos*/
int dado();
void jogo();
void regras();
void tabuleiro(int posA, int posB);
void mostraVitoria(char nome[]);
char v(char player, int pos, int aux);

int main(void){
    /*variaveis*/
    int escolha;

    while(1){

        /*limpa a tela*/
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        

        /*UI*/    
        printf(YEL"___________                         .___                       \n");
        printf("\\_   _____/ ______ ____ _____     __| _/____    ______      ____  \n");
        printf(" |    __)_ /  ___// ___\\\\__  \\   / __ |\\__  \\  /  ___/    _/ __ \\ \n");
        printf(" |        \\\\___ \\\\  \\___ / __ \\_/ /_/ | / __ \\_\\___ \\     \\  ___/ \n");
        printf("/_______  /____  >\\___  >____  /\\____ |(____  /____  >     \\___  >\n");
        printf("        \\/     \\/     \\/     \\/      \\/     \\/     \\/          \\/ \n\n" R);

        printf(GRN"  ______ _________________   ____   _____/  |_  ____   ______\n");
        printf(" /  ___// __ \\_  __ \\____ \\_/ __ \\ /    \\   __\\/ __ \\ /  ___/\n");
        printf(" \\___ \\   ___/|  | \\/  |_> >  ___/|   |  \\  | \\  ___/ \\___ \\ \n");
        printf("/____  >\\___  >__|  |   __/ \\___  >___|  /__|  \\___  >____  >\n");
        printf("     \\/     \\/      |__|        \\/     \\/          \\/     \\/ \n"R);

        printf(YEL"\n\n-------------------------------------------------------------------\n\n"R);
        printf("["RED "1" R "] - Jogar\n");
        printf("["RED "2" R "] - Regras\n");
        printf("["RED "3" R "] - Encerrar\n\n");
        scanf("%d", &escolha);
        fflush(stdout);

        /*verifica input*/
        switch (escolha)
        {
        case 1:
            jogo();
            break;
        
        case 2:
            regras();
            break;
        
        case 3:
            return 0;

        default:
            printf("\nSelecione 1, 2 ou 3.\n\n");
            fflush(stdout);
            getchar();
            getchar();
        }
    }

    return 0;
}

void regras(){ 
    /*limpa a tela*/
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        /*UI*/    
        /*UI*/    
        printf(YEL"___________                         .___                       \n");
        printf("\\_   _____/ ______ ____ _____     __| _/____    ______      ____  \n");
        printf(" |    __)_ /  ___// ___\\\\__  \\   / __ |\\__  \\  /  ___/    _/ __ \\ \n");
        printf(" |        \\\\___ \\\\  \\___ / __ \\_/ /_/ | / __ \\_\\___ \\     \\  ___/ \n");
        printf("/_______  /____  >\\___  >____  /\\____ |(____  /____  >     \\___  >\n");
        printf("        \\/     \\/     \\/     \\/      \\/     \\/     \\/          \\/ \n\n" R);

        printf(GRN"  ______ _________________   ____   _____/  |_  ____   ______\n");
        printf(" /  ___// __ \\_  __ \\____ \\_/ __ \\ /    \\   __\\/ __ \\ /  ___/\n");
        printf(" \\___ \\   ___/|  | \\/  |_> >  ___/|   |  \\  | \\  ___/ \\___ \\ \n");
        printf("/____  >\\___  >__|  |   __/ \\___  >___|  /__|  \\___  >____  >\n");
        printf("     \\/     \\/      |__|        \\/     \\/          \\/     \\/ \n"R);

        printf(YEL"\n\n-------------------------------------------------------------------\n\n"R);
        printf("Ganha quem chegar primeiro na casa 100.\n");
        printf("A partida acontece entre dois jogadores, que tomam turnos aos dados.\n");
        printf("O dado representa o numero de casas que o jogador vai percorrer.\n");
        printf("Se o valor for \"6\" o dado é rolado novamente, e jogador anda a soma.\n"); 
        printf("Se o jogador cai em uma casa de início de escada, ele pode escala-la.\n");
        printf("Se o jogador cai em uma casa de cabeça de serpente, ele escorrega nela.\n");
        printf("\nPressione "YEL"ENTER"R " para voltar.\n");
        fflush(stdout);
        getchar();
        getchar();
}

void jogo(){
    /*variaveis*/
    int posA = 1, posB = 1;
    int turno = 1;
    int numeroSorteado;
    char nome1[50];
    char nome2[50];
    int jogadaAdicional;

    /*checaVitoria retorna 0 enquanto nenhuma posicao for igual a 100.*/
    int gameState = 0;

    /*limpa a tela*/
    #ifdef _WIN32
            system("cls");
    #else
            system("clear");
    #endif


    /*personalização*/
    /*UI*/    
        printf(YEL"___________                         .___                       \n");
        printf("\\_   _____/ ______ ____ _____     __| _/____    ______      ____  \n");
        printf(" |    __)_ /  ___// ___\\\\__  \\   / __ |\\__  \\  /  ___/    _/ __ \\ \n");
        printf(" |        \\\\___ \\\\  \\___ / __ \\_/ /_/ | / __ \\_\\___ \\     \\  ___/ \n");
        printf("/_______  /____  >\\___  >____  /\\____ |(____  /____  >     \\___  >\n");
        printf("        \\/     \\/     \\/     \\/      \\/     \\/     \\/          \\/ \n\n" R);

        printf(GRN"  ______ _________________   ____   _____/  |_  ____   ______\n");
        printf(" /  ___// __ \\_  __ \\____ \\_/ __ \\ /    \\   __\\/ __ \\ /  ___/\n");
        printf(" \\___ \\   ___/|  | \\/  |_> >  ___/|   |  \\  | \\  ___/ \\___ \\ \n");
        printf("/____  >\\___  >__|  |   __/ \\___  >___|  /__|  \\___  >____  >\n");
        printf("     \\/     \\/      |__|        \\/     \\/          \\/     \\/ \n"R);

        printf(YEL"\n\n-------------------------------------------------------------------\n\n"R);
    printf("\nInsira o nome do jogador 1: ");
    scanf("%s", nome1);
    fflush(stdin);
    printf("\nInsira o nome do jogador 2: ");
    scanf("%s", nome2);
    fflush(stdout);
    getchar();
    
    /*enquanto jogo nao acabar*/
    while(gameState == 0){
        /*limpa a tela*/
        
        #ifdef _WIN32
                system("cls");
        #else
                system("clear");
        #endif

        if(turno == 1){
            printf(RED"     ____.                        .___              ____ \n");
            printf("    |    | ____   _________     __| _/___________  /_   |\n");
            printf("    |    |/  _ \\ / ___\\__  \\   / __ |/  _ \\_  __ \\  |   |\n");
            printf("/\\__|    (  <_> ) /_/  > __ \\_/ /_/ (  <_> )  | \\/  |   |\n");
            printf("\\________|\\____/\\___  (______/\\_____|\\____/|__|     |___|\n");
            printf("               /_____/                                   \n"R);
            
            printf("\n%s: %d\n%s: %d\n",nome1, posA, nome2, posB);

            tabuleiro(posA, posB);
            printf("\nPressione "YEL"ENTER"R" para rolar o dado!");
            fflush(stdout);
            getchar();
            
            numeroSorteado = dado();
            if(numeroSorteado == 6){
                printf("\nVocê tirou "RED"6"R", role o dado novamente.\n");
                    printf("\nPressione "YEL"ENTER"R"!");
                    fflush(stdout);
                    getchar();
                jogadaAdicional = dado();
                numeroSorteado += jogadaAdicional;
            }
            printf("Você andou o total de "RED"%d"R" casas.\n", numeroSorteado);
            posA += numeroSorteado;
            
            if(posA == 100){
                gameState = 1;
                mostraVitoria(nome1);
            }
            else{
                turno++;
            }
        }

        else if(turno == 2){
            printf(RED"     ____.                        .___             ________  \n");
            printf("    |    | ____   _________     __| _/___________  \\_____  \\ \n");
            printf("    |    |/  _ \\ / ___\\__  \\   / __ |/  _ \\_  __ \\  /  ____/ \n");
            printf("/\\__|    (  <_> ) /_/  > __ \\_/ /_/ (  <_> )  | \\/ /       \\ \n");
            printf("\\________|\\____/\\___  (______/\\_____|\\____/|__|    \\_______ \\\n");
            printf("               /_____/                                     \\/\n"R);
            
            printf("\n%s: %d\n%s: %d\n",nome1, posA, nome2, posB);

            tabuleiro(posA, posB);
            printf("\nPressione "YEL"ENTER"R" para rolar o dado!");
            fflush(stdout);
            getchar();
            
            numeroSorteado = dado();
            if(numeroSorteado == 6){
                printf("\nVocê tirou "RED"6"R", role o dado novamente.\n");
                    printf("\nPressione "YEL"ENTER"R"!");
                    fflush(stdout);
                    getchar();  
                jogadaAdicional = dado();
                numeroSorteado += jogadaAdicional;
            }
            printf("Você andou o total de "RED"%d"R" casas.\n", numeroSorteado);
            posB += numeroSorteado;
            if(posB == 100){
                gameState = 2;
                mostraVitoria(nome2);
            }
            else{
                turno--;
            }
        }

        else{
            printf("ERRO!\n");
            fflush(stdout);
            getchar();
        }

        /*escadas, serpentes e casa maior que 100*/
        switch(posA){
            /*escadas*/
            case 3:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 24;
                break;
            case 7:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 34;
                break;
            case 12:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 31;
                break;
            case 44:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 64;
                break;
            case 41:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 79;
                break;
            case 51:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 90;
                break;
            case 74:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posA = 93;
                break;

            /* casa maior que 100 */
            case 101:
                printf(RED"\nVocê bateu na casa 100 e voltou uma casa!\n"R);
                posA = 99;
                break;
            case 102:
                printf(RED"\nVocê bateu na casa 100 e voltou duas casas!\n"R);
                posA = 98;
                break;
            case 103:
                printf(RED"\nVocê bateu na casa 100, voltou três casas e escorregou numa serpente :(\n"R);
                posA = 65;
                break;
            case 104:
                printf(RED"\nVocê bateu na casa 100 e voltou quatro casas!\n"R);
                posA = 96;
                break;
            case 105:
                printf(RED"\nVocê bateu na casa 100 e voltou cinco casas!\n"R);
                posA = 95;
                break;
            case 106:
                printf(RED"\nVocê bateu na casa 100 e voltou seis casas!\n"R);
                posA = 94;
                break;
            case 107:
                printf(RED"\nVocê bateu na casa 100 e voltou sete casas!\n"R);
                posA = 93;
                break;
            case 108:
                printf(RED"\nVocê bateu na casa 100 e voltou oito casas!\n"R);
                posA = 92;
                break;
            case 109:
                printf(RED"\nVocê bateu na casa 100 e voltou nove casas!\n"R);
                posA = 91;
                break;
            case 110:
                printf(RED"\nVocê bateu na casa 100 e voltou dez casas!\n"R);
                posA = 90;
                break;
            case 111:
                printf(RED"\nVocê bateu na casa 100 e voltou onze casas!\n"R);
                posA = 89;
                break;

            /*serpentes*/
            case 36:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posA = 5;
                break;
            case 53:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posA = 29;
                break;
            case 82:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posA = 58;
                break;
            case 97:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posA = 65;
                break;
        }

        switch(posB){
            /*escadas*/
            case 3:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 24;
                break;
            case 7:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 34;
                break;
            case 12:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 31;
                break;
            case 44:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 64;
                break;
            case 41:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 79;
                break;
            case 51:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 90;
                break;
            case 74:
                printf(GRN"\nVocê subiu uma escada!\n"R);
                posB = 93;
                break;

            /* casa maior que 100 */
            case 101:
                printf(RED"\nVocê bateu na casa 100 e voltou uma casa!\n"R);
                posB = 99;
                break;
            case 102:
                printf(RED"\nVocê bateu na casa 100 e voltou duas casas!\n"R);
                posB = 98;
                break;
            case 103:
                printf(RED"\nVocê bateu na casa 100, voltou três casas e escorregou numa serpente :(\n"R);
                posB = 65;
                break;
            case 104:
                printf(RED"\nVocê bateu na casa 100 e voltou quatro casas!\n"R);
                posB = 96;
                break;
            case 105:
                printf(RED"\nVocê bateu na casa 100 e voltou cinco casas!\n"R);
                posB = 95;
                break;
            case 106:
                printf(RED"\nVocê bateu na casa 100 e voltou seis casas!\n"R);
                posB = 94;
                break;
            case 107:
                printf(RED"\nVocê bateu na casa 100 e voltou sete casas!\n"R);
                posB = 93;
                break;
            case 108:
                printf(RED"\nVocê bateu na casa 100 e voltou oito casas!\n"R);
                posB = 92;
                break;
            case 109:
                printf(RED"\nVocê bateu na casa 100 e voltou nove casas!\n"R);
                posB = 91;
                break;
            case 110:
                printf(RED"\nVocê bateu na casa 100 e voltou dez casas!\n"R);
                posB = 90;
                break;
            case 111:
                printf(RED"\nVocê bateu na casa 100 e voltou onze casas!\n"R);
                posB = 89;
                break;

            /*serpentes*/
            case 36:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posB = 5;
                break;
            case 53:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posB = 29;
                break;
            case 82:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posB = 58;
                break;
            case 97:
                printf(RED"\nVocê escorregou numa serpente :(\n"R);
                posB = 65;
                break;
        }

        fflush(stdout);
        getchar();
    }
        
}

int dado(){
    int random;
    srand(time(NULL));
    random = (rand() % 6) + 1;
    
    switch (random){
            case 1:
                printf("\n");
                printf("   ________________\n");
                printf("  /   O           /|\n");
                printf(" /          O    / |\n");
                printf("/_______________/ o|\n");
                printf("|               |o |\n");
                printf("|               |  |\n");
                printf("|       O       | o/\n");
                printf("|               |o/\n");
                printf("|_______________|/\n");
                printf("\n");
                break;

            case 2:
                printf("\n");
                printf("   ________________\n");
                printf("  /   O   O   O   /|\n");
                printf(" /   O   O   O   / |\n");
                printf("/_______________/ o|\n");
                printf("|               |o |\n");
                printf("|   O           |  |\n");
                printf("|               | o/\n");
                printf("|          O    |o/\n");
                printf("|_______________|/\n");
                printf("\n");
                break;

            case 3:
                printf("\n");
                printf("   ________________\n");
                printf("  /           O   /|\n");
                printf(" /   O           / |\n");
                printf("/_______________/  |\n");
                printf("|               |  |\n");
                printf("|   O           | o|\n");
                printf("|       O       |  /\n");
                printf("|           O   | /\n");
                printf("|_______________|/\n");
                printf("\n");
                break;

            case 4:
                printf("\n");
                printf("   ________________\n");
                printf("  /               /|\n");
                printf(" /       O       / |\n");
                printf("/_______________/  |\n");
                printf("|               |o |\n");
                printf("|   O       O   |  |\n");
                printf("|               | o/\n");
                printf("|   O       O   | /\n");
                printf("|_______________|/\n");
                printf("\n");
                break;

            case 5:
                printf("\n");
                printf("   ________________\n");
                printf("  /               /|\n");
                printf(" /       O       / |\n");
                printf("/_______________/ o|\n");
                printf("|               |o |\n");
                printf("|  O         O  |  |\n");
                printf("|       O       | o/\n");
                printf("|  O         O  |o/\n");
                printf("|_______________|/\n");
                printf("\n");
                break;

            case 6:
                printf("\n");
                printf("   ________________\n");
                printf("  /   O      O    /|\n");
                printf(" /   O      O    / |\n");
                printf("/_______________/ o|\n");
                printf("|               |  |\n");
                printf("|   O       O   |  |\n");
                printf("|   O       O   |  /\n");
                printf("|   O       O   |o/\n");
                printf("|_______________|/\n");   
                printf("\n");  
                break;

        }
    return random;
}

void tabuleiro(int posA, int posB){
    printf("\n");
    printf(YEL" +------|------|------|------|------|------|------|------|------|------+\n");
    printf(" |"WHT"100"YEL"   |"WHT"99"YEL"    |"WHT"98"YEL"    |"WHT"97"YEL"    |"WHT"96"YEL"    |"WHT"95"YEL"    |"WHT"94"YEL"    |"WHT"93"YEL"  %c |"WHT"92"YEL"    |"WHT"91"YEL"    |\n", v('B', posB, 93));
    printf(" |      |%c %c   |%c %c   |    "GRN"^^"YEL"|%c %c   |%c %c   |%c %c   | /-/ %c|%c %c   |%c %c   |\n", v('A', posA, 99), v('B', posB, 99), v('A', posA, 98), v('B', posB, 98), v('A', posA, 96), v('B', posB, 96), v('A', posA, 95), v('B', posB, 95), v('A', posA, 94), v('B', posB, 94), v('A', posA, 93), v('A', posA, 92), v('B', posB, 92), v('A', posA, 91), v('B', posB, 91));
    printf(" |------|------|------|----"GRN"**"YEL"|------|------|------|/-/---|------|------|\n");
    printf(" |"WHT"81"YEL"    |"WHT"82"YEL"    |"WHT"83"YEL"    |"WHT"84"YEL"   "GRN"**"YEL""WHT"85"YEL"   %c|"WHT"86"YEL"    |"WHT"87"YEL"    /-/  "WHT"88"YEL"|"WHT"89"YEL"    |"WHT"90"YEL"   %c|\n", v('B', posB, 85), v('B', posB, 90));
    printf(" |%c %c   |   "GRN"^^"YEL" |%c %c   |%c %c   "GRN"**"YEL"   %c |%c %c   |%c %c  /-/  %c %c|%c %c   |%c |-| |\n", v('A', posA, 81), v('B', posB, 81), v('A', posA, 83), v('B', posB, 83), v('A', posA, 84), v('B', posB, 84), v('A', posA, 85), v('A', posA, 86), v('B', posB, 86), v('A', posA, 87), v('B', posB, 87), v('A', posA, 88), v('B', posB, 88), v('A', posA, 89), v('B', posB, 89), v('A', posA, 90));
    printf(" |------|---"GRN"**"YEL"-|------|------|"GRN"**"YEL"----|------|----/-/------|------|--|-|-|\n");
    printf(" |"WHT"80"YEL"    |"WHT"79"YEL"  "GRN"**"YEL"|"WHT"78"YEL"   %c|"WHT"77"YEL"    | "GRN"**"YEL"  %c|"WHT"75"YEL"    |"WHT"74"YEL" /-/|"WHT"73"YEL"    |"WHT"72"YEL"    |%c |-| |\n", v('B', posB, 78), v('B', posB, 76), v('B', posB, 71));
    printf(" |%c %c   |%c %c  "GRN"**"YEL"     %c|%c %c   | "GRN"**"YEL"  %c|%c %c   |%c %c   |%c %c   |%c %c   |%c |-| |\n", v('A', posA, 80), v('B', posB, 80), v('A', posA, 79), v('B', posB, 79), v('A', posA, 78), v('A', posA, 77), v('B', posB, 77), v('A', posA, 76), v('A', posA, 75), v('B', posB, 75), v('A', posA, 74), v('B', posB, 74), v('A', posA, 73), v('B', posB, 73), v('A', posA, 72), v('B', posB, 72), v('A', posA, 71));
    printf(" |------|--/-/-"GRN"**"YEL"-----|------|--"GRN"**"YEL"--|------|------|------|------|--|-|-|\n");
    printf(" |"WHT"61"YEL"    | /-/ %c|"GRN"**"YEL"  "WHT"63"YEL"|"WHT"64"YEL" %c %c|"WHT"65"YEL" "GRN"**"YEL" |"WHT"66"YEL"    |"WHT"67"YEL"    |"WHT"68"YEL"    |"WHT"69"YEL"    |%c |-| |\n", v('B', posB, 62), v('A', posA, 64), v('B', posB, 64), v('B', posB, 70));
    printf(" |%c %c   |/-/  %c|"GRN"**"YEL" %c %c|   |-|| %c %c  |%c %c   |%c %c   |%c %c   |%c %c   |%c |-| |\n", v('A', posA, 61), v('B', posB, 61), v('A', posA, 62), v('A', posA, 63), v('B', posB, 63), v('A', posA, 65), v('B', posB, 65), v('A', posA, 66), v('B', posB, 66), v('A', posA, 67), v('B', posB, 67), v('A', posA, 68), v('B', posB, 68), v('A', posA, 69), v('B', posB, 69),v('A', posA, 70));
    printf(" |------/-/----|--"GRN"**"YEL"--|---|-||------|------|------|------|------|--|-|-|\n");
    printf(" |"WHT"60"YEL"   /-/   "WHT"59"YEL"|"WHT"58"YEL" "GRN"**"YEL" |"WHT"57"YEL" |-||"WHT"56"YEL"    |"WHT"55"YEL"    |"WHT"54"YEL"    |"WHT"53"YEL"    |"WHT"52"YEL"    |"WHT"51"YEL"|-| |\n");
    printf(" |%c %c /-/ %c %c  | %c %c  |%c %c|-||%c %c   |%c %c   |%c %c   |    "GRN"^^"YEL"|%c %c   |      |\n", v('A', posA, 60),v('B', posB, 60),v('A', posA, 59),v('B', posB, 59),v('A', posA, 58),v('B', posB, 58),v('A', posA, 57),v('B', posB, 57),v('A', posA, 56),v('B', posB, 56),v('A', posA, 55),v('B', posB, 55),v('A', posA, 54),v('B', posB, 54),v('A', posA, 52),v('B', posB, 52));
    printf(" |---/-/|------|------|---|-||------|------|------|----"GRN"**"YEL"|------|------|\n");
    printf(" |"WHT"41"YEL"/-/ |"WHT"42"YEL"    |"WHT"43"YEL"    |"WHT"44"YEL" |-||"WHT"45"YEL"    |"WHT"46"YEL"    |"WHT"47"YEL"    |%c  "GRN"**"YEL" |"WHT"49"YEL"    |"WHT"50"YEL"    |\n",v('B',posB,48));
    printf(" |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c   "GRN"**"YEL"|%c %c   |%c %c   |\n",v('A', posA, 41), v('B', posB, 41), v('A', posA, 42), v('B', posB, 42),v('A', posA, 43), v('B', posB, 43),v('A', posA, 44),v('A', posA, 44), v('B', posB, 45),v('A', posA, 45), v('B', posB, 46), v('A', posA, 46),v('A', posA, 47), v('B', posB, 47),v('A', posA, 48), v('B', posB, 49),v('A', posA, 49), v('B', posB, 50), v('A', posA, 50));
    printf(" |------|------|------|------|------|------|------|---"GRN"**"YEL"-|------|------|\n");
    printf(" |"WHT"40"YEL"    |"WHT"39"YEL"    |"WHT"38"YEL"    |"WHT"37"YEL"    |"WHT"36"YEL"    |"WHT"35"YEL"    |"WHT"34"YEL" %c %c|"WHT"33"YEL"  "GRN"**"YEL"|"WHT"32"YEL"    |"WHT"31"YEL" %c %c|\n", v('A', posA, 34), v('B', posB, 34), v('A', posA, 31), v('B',posB,31));
    printf(" |%c %c   |%c %c   |%c %c   |%c %c   |  "GRN"^^"YEL"  |%c %c   |  |-| |%c %c  "GRN"**"YEL"  %c %c | /-/  |\n",v('A', posA, 40), v('B', posB, 40), v('A', posA, 39), v('B', posB, 39), v('A', posA, 38), v('B', posB, 38),v('A',posA,37),v('B', posB,37), v('A',posA,35),v('B', posB,35),v('A',posA,33),v('B', posB,33), v('A',posA,32),v('B', posB,32));
    printf(" |------|------|------|------|--"GRN"**"YEL"--|------|--|-|-|------"GRN"**"YEL"-----|/-/---|\n");
    printf(" |"WHT"21"YEL"    |"WHT"22"YEL"    |"WHT"23"YEL"    |"WHT"24"YEL" %c  |"WHT"25"YEL" "GRN"**"YEL" |"WHT"26"YEL"    |%c |-| |"WHT"28"YEL"    |"GRN"**"YEL"  "WHT"29"YEL"/-/  "WHT"30"YEL"|\n", v('B', posB, 24), v('B', posB, 27));
    printf(" |%c %c   |%c %c   |%c %c   |/-/%c  |%c %c"GRN"**"YEL" |%c %c   |%c |-| |%c %c   |%c %c  /-/%c %c  |\n", v('A', posA, 21), v('B', posB, 21), v('A', posA, 22), v('B', posB, 22),v('A', posA, 23), v('B', posB, 23),v('A', posA, 24),v('A', posA, 25), v('B', posB, 25),v('A', posA, 26), v('B', posB, 26), v('A', posA, 27),v('A', posA, 28), v('B', posB, 28),v('A', posA, 29), v('B', posB, 29),v('A', posA, 30), v('B', posB, 30));
    printf(" |------|------|------/-/----|--"GRN"**"YEL"--|------|--|-|-|------|----/-/------|\n");
    printf(" |"WHT"20"YEL"    |"WHT"19"YEL"    |%c    /-/"WHT"17"YEL"   |%c  "GRN"**"YEL" |"WHT"15"YEL"    |%c |-| |"WHT"13"YEL"    |"WHT"12"YEL" /-/|"WHT"11"YEL"    |\n",v('B', posB, 18), v('B', posB, 16), v('B', posB, 14));
    printf(" |%c %c   |%c %c   |%c   /-/%c %c   |%c "GRN"**"YEL"  |%c %c   |%c |-| |%c %c   |%c %c   |%c %c   |\n",v('A', posA, 20),v('B', posB, 20), v('A', posA, 19),v('B', posB, 19),v('A', posA, 18),v('A', posA, 17),v('B', posB, 17), v('A',posA,16), v('A',posA,15), v('B', posB,15), v('A', posA, 14), v('A', posA, 13), v('B', posB, 13), v('A', posA, 12), v('B', posB, 12), v('A', posA, 11), v('B', posB, 11));
    printf(" |------|------|---/-/|------|--"GRN"**"YEL"--|------|--|-|-|------|------|------|\n");
    printf(" |"WHT"1"YEL"     |"WHT"2"YEL"     |"WHT"3"YEL" /-/ |"WHT"4"YEL"     |"WHT"5"YEL"  "GRN"**"YEL" |"WHT"6"YEL"     |"WHT"7"YEL" |-| |"WHT"8"YEL"     |"WHT"9"YEL"     |"WHT"10"YEL"    |\n");
    printf(" |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |%c %c   |\n",v('A', posA, 1),v('B', posB, 1),v('A', posA, 2),v('B', posB, 2),v('A', posA, 3),v('B', posB, 3),v('A', posA, 4),v('B', posB, 4),v('A', posA, 5),v('B', posB, 5),v('A', posA, 6),v('B', posB, 6),v('A', posA, 7),v('B', posB, 7),v('A', posA, 8),v('B', posB, 8),v('A', posA, 9),v('B', posB, 9),v('A', posA, 10),v('B', posB, 10));
    printf(" |------|------|------|------|------|------|------|------|------|------|\n"R);
    printf("\n");
}

char v(char player, int pos, int aux){
    if(player == 'A'){
        if(pos == aux){
            return 'A';
        }
        else{
            return ' ';
        }
    }
    
    else if(player == 'B'){
        if(pos == aux){
            return 'B';
        }
        else{
            return ' ';
        }
    }   

    else{
        return '\0';
    }
}

void mostraVitoria(char nome[]){
    
        /*limpa a tela*/
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        /*UI*/    
        printf(YEL"___________                         .___                       \n");
        printf("\\_   _____/ ______ ____ _____     __| _/____    ______      ____  \n");
        printf(" |    __)_ /  ___// ___\\\\__  \\   / __ |\\__  \\  /  ___/    _/ __ \\ \n");
        printf(" |        \\\\___ \\\\  \\___ / __ \\_/ /_/ | / __ \\_\\___ \\     \\  ___/ \n");
        printf("/_______  /____  >\\___  >____  /\\____ |(____  /____  >     \\___  >\n");
        printf("        \\/     \\/     \\/     \\/      \\/     \\/     \\/          \\/ \n\n" R);

        printf(GRN"  ______ _________________   ____   _____/  |_  ____   ______\n");
        printf(" /  ___// __ \\_  __ \\____ \\_/ __ \\ /    \\   __\\/ __ \\ /  ___/\n");
        printf(" \\___ \\   ___/|  | \\/  |_> >  ___/|   |  \\  | \\  ___/ \\___ \\ \n");
        printf("/____  >\\___  >__|  |   __/ \\___  >___|  /__|  \\___  >____  >\n");
        printf("     \\/     \\/      |__|        \\/     \\/          \\/     \\/ \n"R);

        printf(YEL"\n\n-------------------------------------------------------------------\n\n"R);

        printf(RED"\t\t\t%s é o campeão!\n\n"R,nome);
        printf(YEL"\t\t\t .-=========-.\n");
        printf("\t\t\t \\'-=======-'/\n");
        printf("\t\t\t _|   .=.   |_\n");
        printf("\t\t\t((|  {{1}}  |))\n");
        printf("\t\t\t \\|   /|\\   |/\n");
        printf("\t\t\t    _`) (`_\n");
        printf("\t\t\t  _/_______\\_\n");
        printf("\t\t\t /___________\\\n"R);

        fflush(stdout);
        getchar();
}

