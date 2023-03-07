#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int show_menu() {
    int choice;
    printf("Menu:\n");
    printf("1. Tinh trung binh cong cua 1 mang va tim vi tri cua so lon nhat\n");
    printf("2. Dao nguoc 1 chuoi, kiem tra co doi xung khong, va dem cac ki tu so\n");
    printf("3. Doc 1 tep, tim so lon nhat neu no toan la so, va ghi 1 tep khac\n");
    printf("4. Thoat\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}
void Array1(){
    int n, i, pos = 0;
    float avg = 0, max = 0;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    float arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        avg += arr[i];  //trung binh = trung binh + arr[i]
        if (arr[i] > max) {    //neu arr[i] > max thi gan max = arr[i] va vi tri so lon nhat se la i 
            max = arr[i];
            pos = i;
            }
        }
    avg /= n; //cong thuc tinh tbcong
    printf("Trung binh cong cua mang la: %.2f\n", avg);
    printf("Vi tri cua so lon nhat trong mang la: %d\n", pos);
}
void String2(){
    char str[1000], reverse_str[1000]; //tao 2 chuoi: 1 chuoi de nhap, 1 chuoi de luu chuoi sau khi dao
    int i, len, numeric_count = 0;
    printf("Nhap vao 1 chuoi: ");
    gets(str); //nhap chuoi (gets() co the nhap chuoi co khoang trang
    len = strlen(str); //tinh do dai chuoi duoc tao
    int j = 0;
    for (i = len - 1; i >= 0; i--) //tao vong lap tu cuoi cho chuoi str[]
    {
        reverse_str[j++] = str[i]; 
    }

    reverse_str[j] = '\0'; //null duoc them vao cuoi chuoi de dam bao chuoi kthuc dung cach 

    printf("Chuoi dao nguoc la: %s\n", reverse_str);
    
    for (i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) {
            printf("Chuoi khong doi xung.\n");
                break;
        }
    }
    if (i == len/2) {
        printf("Chuoi doi xung.\n");
    }
    for (i = 0; i < len; i++) {
        if (isdigit(str[i])) {
        numeric_count++;
        }
    }
    printf("So ky tu trong chuoi la: %d\n", numeric_count);
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

void Lenh3(){
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


int main() {
    int choice;
    do {
        choice = show_menu();
        switch (choice) {
            case 1:
                Array1();
                break;
            case 2:
                String2();
                break;
            case 3:
                Lenh3();
                break;
            case 4:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Nhap sai, vui long nhap lai\n");
                break;
        }
    } while (choice != 4);
    getch();
    return 0;
}
        	