#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int main(){
    char name[100];
    gets(name);
    name[0] = toupper(name[0]);
    for (int i = 1; i < strlen(name); i++) {
        if (name[i - 1] == ' ') {
            name[i] = toupper(name[i]);
        } else {
            name[i] = tolower(name[i]);
        }
    }
    printf("%s", name);
    getch();
    return 0;
}