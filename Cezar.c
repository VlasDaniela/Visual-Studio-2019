#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <ctype.h>
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
            printf("%c", v[i]);
        }

    }
    else {
        for (i = 0; i <= strlen(v) - 1; i++)
            if (v[i] + key >= 'a' && v[i] + key <= 'z') v[i] = v[i] + key;
            else {
                v[i] = v[i] - (26 - key);
            }

        for (i = 0; i <= strlen(v) - 1; i++)
            printf("%c", v[i]);

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
            printf("%c", v[i]);
        }

    }
    else {
        for (i = 0; i <= strlen(v) - 1; i++)
            if (v[i] - key >= 'a' && v[i] - key <= 'z') v[i] = v[i] - key;
            else {
                v[i] = v[i] + (26 - key);
            }

        for (i = 0; i <= strlen(v) - 1; i++)
            printf("%c", v[i]);

    }

}

int main() {
    char v[1000];
    gets(v);
    int key;
    scanf("%i", &key);
    cryptmes(&v, key);
    //    decryptmes(&v,key);

    return 0;
}