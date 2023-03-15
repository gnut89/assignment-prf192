#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int allUpper(char s[]) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            return 0;
        }
    }
    return 1;
}

int firstLower(char s[]) {
    if (!islower(s[0])) {
        return 0;
    }
    for (int i = 1; i < strlen(s); i++) {
        if (!isupper(s[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
	char s[100];
    gets(s);
    if (allUpper(s)) {
        for (int i = 0; i < strlen(s); i++) {
            s[i] = tolower(s[i]);
        }
    } else if (firstLower(s)) {
        s[0] = toupper(s[0]);
        for (int i = 1; i < strlen(s); i++) {
            s[i] = tolower(s[i]);
        }
    }
    printf("%s", s);
    return 0;
}