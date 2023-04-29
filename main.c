#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char matriz[3][3];

void init_matriz(void);
void mostrar_velha(void);
void getPlayerJogada(void);
void getMoveComputador(void);
char verificaVencedor(void);


int main(void) {
    char done;
    init_matriz();
    do {
        mostrar_velha();
        getPlayerJogada();
        done = verificaVencedor();
        if(done != ' ') break;
        getMoveComputador();
        done = verificaVencedor();
    } while(done == ' ');
    if(done == 'X') printf("\033[41m Humano tolo kkkk me ganhou!\n\033[0m");
    else printf("\033[41m Eu ganhei kkkkkk\n \033[0m");
    return 0;
}
void init_matriz(void) {
    int i, j;
    for(i = 0; i < 3; i++)
        for(j= 0; j < 3; j++) matriz[i][j] = ' ';
}

void mostrar_velha(void) {
    int i;
    for(i = 0; i < 3; ++i) {
        printf(" %c | %c | %c", matriz[i][0], matriz[i][1], matriz[i][2]);
        if(i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

void getPlayerJogada(void) {
    int x, y;
    printf("Digite as coordenadas para o X: ");
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if(matriz[x][y] != ' ') {
        printf("Essa posicao esta preenchida.\n");
        getPlayerJogada();
    } else {
        matriz[x][y] = 'X';
    } 
}

void getMoveComputador(void) {
     int i, j, k;
    srand(time(NULL));
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) 
            if(matriz[i][j] == ' ') break;
        if(matriz[i][j] == ' ') break;
    }
    if(i*j == 9) {
        printf("\033[41m empate.\n");
        exit(0);
    } else {
        k = 1;
        do {
            i  = rand() % 3;
            j  = rand() % 3;
            if(i < 3 && j < 3){
                if(matriz[i][j] == ' ') {
                    matriz[i][j] = 'O';
                    k--;
                    break;
                }
            }
        } while(k);
    }
}

char verificaVencedor(void) {
    int i;
    for(i = 0; i<3;i++) 
        if(matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) return matriz[0][i];
    for(i = 0; i < 3; i++) 
        if(matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) return matriz[i][0];
    
    if((matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]) 
    || (matriz[0][2] == matriz[1][1] && matriz[2][0] == matriz[0][2])) return matriz[1][1];
    
    return ' ';
}