#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#pragma warning(disable:4996)

char A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char a[27][27];

//GENERAREA MATRICEI PENTRU CODAREA CIFRULUI

void generateMatrix() {
    int i, j;
    for (i = 1; i <= 26; i++) {
        for (j = 1; j <= 26; j++) {
            a[i][j] = A[((i + j) - 2) % 26];
            //            printf("%c ", a[i][j]);
        }
        //        printf(" %i \n",i);
    }
}

//FUNCTIA DE CRIPTARE

void Criptare(char code[200], char key[200])
{
    int i;
    for (i = 0; i <= strlen(code) - 1; i++)
    {
        code[i] = a[26 - ('Z' - code[i])][26 - ('Z' - key[i])]; //INLOCUIREA CODULUI PRIMIT CU CORESPONDENTA DIN MATRICE IN FUNCTIE DE FORMULA

    }

}

//FUNCTIA DE DECRIPTARE

void Decriptare(char code[200], char key[200]) {
    int i;
    for (i = 0; i <= strlen(code) - 1; i++)
    {
        int j, u;
        for (j = 1; j <= 26; j++)
            if (a[1][j] == key[i]) {
                u = j; // SE GASESTE COLOANA PE CARE SE AFLA LITERA DIN CHEIE
                break;
            }
        // SE CAUTA CORESPONDENTA CODULUI CRIPTAT DE PE COLOANA LITEREI DIN CHEIE
        for (j = 1; j <= 26; j++)
            if (a[j][u] == code[i]) {
                code[i] = a[j][1]; // SE SALVEAZA IN COD 
                break;
            }
    }

}



int main() {
    generateMatrix();
    char code[200], key[200];
    printf("Introdu cheia LITERE MARI ALE ALFABETULUI FARA SPATIU: ");
    scanf("%s", key);
    printf("Introdu codul LITERE MARI ALE ALFABETULUI FARA SPATIU: ");
    scanf("%s", code);
    while (strlen(key) <= strlen(code)) {
        char aux[200];
        strcpy(aux, key);
        strcat(key, aux);
    }
    Criptare(code, key);
    int i;
    printf("\n **CODUL CRIPTAT**: \n");
    for (i = 0; i <= strlen(code) - 1; i++)
        printf("%c", code[i]);
    Decriptare(code, key);
    printf("\n **CODUL DECRIPTAT**: \n");
    for (i = 0; i <= strlen(code) - 1; i++)
        printf("%c", code[i]);

}