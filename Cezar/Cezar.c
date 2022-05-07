#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <ctype.h>
#pragma warning(disable:4996)
void cryptmes(char* v, int key) {
    int i;
    if (v[0] >= 'A' && v[0] <= 'Z') {
        for (i = 0; i <= strlen(v) - 1; i++)
            v[i] = tolower(v[i]);

        for (i = 0; i <= strlen(v) - 1; i++)
            if (v[i] + key >= 'a' && v[i] + key <= 'z') v[i] = v[i] + key;
            else {
                v[i] = v[i] - (26 - key);

            }
        for (i = 0; i <= strlen(v) - 1; i++)
        {
            v[i] = toupper(v[i]);
            //printf("%c", v[i]);
        }

    }
    else {
        for (i = 0; i <= strlen(v) - 1; i++)
            if (v[i] + key >= 'a' && v[i] + key <= 'z') v[i] = v[i] + key;
            else {
                v[i] = v[i] - (26 - key);
            }



    }

}
void decryptmes(char* v, int key) {
    int i;
    if (v[0] >= 'A' && v[0] <= 'Z') {
        for (i = 0; i <= strlen(v) - 1; i++)
            v[i] = tolower(v[i]);

        for (i = 0; i <= strlen(v) - 1; i++)
            if (v[i] - key >= 'a' && v[i] - key <= 'z') v[i] = v[i] - key;
            else {
                v[i] = v[i] + (26 - key);

            }
        for (i = 0; i <= strlen(v) - 1; i++)
        {
            v[i] = toupper(v[i]);
            //printf("%c", v[i]);
        }

    }
    else {
        for (i = 0; i <= strlen(v) - 1; i++)
            if (v[i] - key >= 'a' && v[i] - key <= 'z') v[i] = v[i] - key;
            else {
                v[i] = v[i] + (26 - key);
            }



    }

}
void cryptAnalysis(char* v, char* s) {
    char u[1000];
    int i;
    strcpy(u, s);
    for (i = 1; i <= 25; i++) {
        decryptmes(u, i);
        if (strcmp(u, v) == 0) {
            printf("Cheia este %i \n", i);
            break;
        }
        else strcpy(u, s);
    }


}

int main() {
    char v[1000], s[1000];
    printf("Citeste text: \n");
    gets(v);
    strcpy(s, v);
    int key;
    printf("Citeste key: \n");
    scanf("%i", &key);
    cryptmes(&s, key);
    printf("Mesaj criptat: ");
    printf("%s\n", s);
    cryptAnalysis(v, s);
    printf("Mesaj decriptat: ");
    decryptmes(&s,key);
    printf("%s\n",s);

    return 0;
}