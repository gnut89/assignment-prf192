#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

void chucNang1(){
    printf("\n");
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
    }
    printf("Trung binh cong cac so trong mang la: %.3lf\n", (double)sum/n);
    int max = a[0], index = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > max){
            max = a[i];
            index = i;
        }
    }
    printf("So lon nhat mang la %d o vi tri: %d\n", max, index);
    printf("\n");
}

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
    printf("\n");
    char s[100];
    printf("Nhap chuoi: ");
    gets(s);
    char temp[100];
    strcpy(temp, s);
    strrev(temp);
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

int checkNumber(char c[]){
    int i;
    for (i = 0; i < strlen(c); i++) {
        if (!isdigit(c[i])) {
            return 0;
        }
    }
    return 1;
}

void chucNang3() {
    printf("\n");
    FILE *f1, *f2;
    int max = -1e9, check = 0;
    char filename[100] = "";
    char filename2[100] = "";

    printf("Nhap ten file: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    int x;
    char c[100];
    f1 = fopen(filename, "r");

    if (f1 != NULL) {
        while (fscanf(f1, "%s", c) != EOF) {
            if (checkNumber(c) == 0) {
                check = 1;
                break;
            } else {
                x = atoi(c);
                if (x > max) {
                    max = x;
                }
            }
        }
        fclose(f1);
    } else {
        printf("Khong mo duoc file\n");
        return;
    }

    if (check == 1) {
        printf("File khong hoan toan la so\n");
    } else {
        printf("Nhap ten file de ghi so lon nhat: ");
        scanf("%s", filename2);
        strcat(filename2, ".txt");
        f2 = fopen(filename2, "w");
        fprintf(f2, "%d", max);
        printf("Da ghi so lon nhat vao file %s\n", filename2);
        fclose(f2);
    }
    printf("\n");
}



int main(){
    int choice;
    do {
        printf("\n1. Nhap 1 mang, tinh trung binh cac so trong mang\n");
        printf("Tim vi tri cua so lon nhat trong mang\n");
        printf("2. Nhap 1 chuoi, in ra chuoi dao nguoc,\nin ra chuoi co doi xung hay khong\n");
        printf("So luong cac ky tu la so trong chuoi\n");
        printf("3. Nhap ten file .txt va doc noi dung\n");
        printf("Neu file hoan toan la so, tim so lon nhat va viet file .txt\n");
        printf("4. Thoat\n\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice){
            case 1:
                chucNang1();
                break;
            case 2:
                chucNang2();
                break;
            case 3:
                chucNang3();
                break;
            case 4:
                printf("Ban da chon thoat\n");
                break;
            default:
                printf("Ban da chon sai, moi ban chon lai\n");
                break;
        }
    } while (choice != 4);
    getch();
    return 0;
}