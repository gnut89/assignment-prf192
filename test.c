#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>


int doiXung(char c[]){
    int l = 0, r = strlen(c) - 1;
    while (l <= r){
        if (c[l] != c[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

void chucNang2(){
    char s[100];
    printf("Nhap chuoi: ");
    gets(s);
    char temp[100];
    strcpy(temp, s);
    strrev(temp);
    // getchar();
    printf("Chuoi dao nguoc la: %s\n", temp);
    

    if (doiXung(s) == 1){
        printf("Chuoi doi xung\n");
    } else {
        printf("Chuoi khong doi xung\n");
    }
    
    int count = 0;
    for (int i = 0; i < strlen(s); i++){
        if (isdigit(s[i])){
            count++;
        }
    }
    printf("So luong cac ky tu la so trong chuoi la: %d\n", count);
}

int main(){
    chucNang2();
    getch();
    return 0;
}