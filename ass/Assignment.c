#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

void chucNang1(){
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
    printf("Trung binh cac so trong mang la: %.3lf\n", (double)sum/n);
    int max = a[0], index = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > max){
            max = a[i];
            index = i;
        }
    }
    printf("So lon nhat mang la %d o vi tri: %d\n", max, index);
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
    char s[100];
    printf("Nhap chuoi: ");
    scanf("%s", s);
    if (doiXung(s) == 1){
        printf("Chuoi doi xung\n");
    } else {
        printf("\nChuoi khong co doi xung\n");
    }
    
    int count = 0;
    for (int i = 0; i < strlen(s); i++){
        if (isdigit(s[i])){
            count++;
        }
    }
    printf("So luong cac ky tu la so trong chuoi la: %d\n", count);
}


void chucNang3() {
    FILE *fptr1, *fptr2;
    int max = -1e9, temp = 0, check = 0;
    char c;
    fptr1 = fopen("a.txt", "r");
    if (fptr1 == NULL) {
        printf("Khong the mo tep a.txt\n");
        return;
    }
    while (c = fgetc(fptr1)) {
        if (isdigit(c)) {
            temp = temp * 10 + (c - '0');
        } else if (c == '\n' || isspace(c) || c == EOF) {
            if (temp > max) {
                max = temp;
            }
            temp = 0;
        } else {
            check = 1;
            break;
        }
        if (c == EOF)
            break;
    }
    fclose(fptr1);
    if (check == 1) {
        printf("Tep khong hoan toan la so\n");
    } else {
        fptr2 = fopen("b.txt", "w");
        printf("Da ghi so lon nhat vao file b.txt\n");
        fprintf(fptr2, "%d", max);
        fclose(fptr2);
    }
}



int main(){
    int choice;
    do {
        printf("\nMoi ban chon:\n");
        printf("1. Nhap 1 mang, tinh trung binh cac so trong mang\n");
        printf("Tim vi tri cua so lon nhat trong mang\n");
        printf("2. Nhap 1 chuoi, in ra chuoi co doi xung hay khong\n");
        printf("So luong cac ky tu la so trong chuoi\n");
        printf("3. Nhap ten tap .txt va doc noi dung\n");
        printf("Neu tep hoan toan la so, tim so lon nhat va viet tep .txt\n");
        printf("4. Thoat\n\n");
        scanf("%d", &choice);
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