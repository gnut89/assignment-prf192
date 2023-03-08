#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    int n, i, pos, max = 0;
    double avg = 0;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
        avg += arr[i];  //trung binh = trung binh + arr[i]
        if (arr[i] > max) {    //neu arr[i] > max thi gan max = arr[i] va vi tri so lon nhat se la i 
            max = arr[i];
            pos = i;
            }
        }
    avg /= n; //cong thuc tinh tbcong
    printf("Trung binh cong cua mang la: %.2lf\n", avg);
    printf("So lon nhat trong mang la %d o vi tri: %d\n", max, pos);
}
void String2(){
    char str[1000], rev[1000]; //tao 2 chuoi: 1 chuoi de nhap, 1 chuoi de luu chuoi sau khi dao
    int i, len, count = 0;
    printf("Nhap vao 1 chuoi: ");
    gets(str); 
    len = strlen(str); //tinh do dai chuoi duoc tao
    int j = 0;
    for (i = len - 1; i >= 0; i--) //tao vong lap tu cuoi cho chuoi str[]
    {
        rev[j++] = str[i]; // gan chuoi dao nguoc vao chuoi rev[]
    }

    rev[j] = '\0'; //null duoc them vao cuoi chuoi de dam bao chuoi kthuc dung cach 

    printf("Chuoi dao nguoc la: %s\n", rev);
    
    for (i = 0; i < len/2; i++) {
        if (str[i] != str[len-i-1]) { // kiem tra xem chuoi co doi xung khong
            printf("Chuoi khong doi xung\n"); 
            break;
        }
    }
    if (i == len/2) { 
        printf("Chuoi doi xung\n");
    }
    for (i = 0; i < len; i++) { // dem so ky tu trong chuoi la so
        if (isdigit(str[i])) {
        count++; // neu la so thi tang bien count len 1
        }
    }
    printf("So ky tu trong chuoi la so: %d\n", count); // in ra so ky tu la so
}

int kiemtraso(char c[]){ // ham kiem tra xem chuoi co phai so khong
    int i; 
    for (i = 0; i < strlen(c); i++) {
        if (!isdigit(c[i])) { // kiem tra xem co phai la so khong
            return 0; // neu khong phai so thi tra ve 0
        }
    }
    return 1; // neu la so thi tra ve 1
}

void Lenh3(){
    FILE *f1, *f2; // tao 2 con tro file
    int kiemtra = 0; // tao 1 bien kiemtra de kiem tra xem file doc co toan la so khong
    char filevao[100] = ""; // tao 1 chuoi de luu ten file doc
    char filexuat[100] = ""; // tao 1 chuoi de luu ten file xuat
    printf("Nhap ten file muon doc: "); // nhap ten file de doc
    scanf("%s", filevao); 
    strcat(filevao, ".txt"); // noi them .txt vao cuoi ten file
    int tam;
    char c[100]; // tao 1 chuoi de luu cac so trong file
    f1 = fopen(filevao, "r");
    int max = -1e9;
    if (f1 == NULL) { // kiem tra file co ton tai khong
        printf("Khong the mo duoc file\n");
        return;
    } else {
        while (fscanf(f1, "%s", c) != EOF) { // doc tung so trong file
            if (kiemtraso(c) == 0) { // kiem tra xem co phai so khong
                kiemtra = 1; // neu khong phai so thi kiemtra = 1
                break; // dung vong lap
            } else {
                tam = atoi(c); // chuyen chuoi sang so
                if (tam > max) { // tim so lon nhat
                    max = tam; //   gan max = tam
                }
            }
        }
    }
    fclose(f1); 
    if (kiemtra == 0) // neu kiemtra = 0 thi file doc toan la so
    {
        printf("Nhap ten file de ghi so lon nhat: ");
        scanf("%s", filexuat);
        strcat(filexuat, ".txt"); // noi them .txt vao cuoi ten file
        f2 = fopen(filexuat, "w");
        fprintf(f2, "%d", max);
        printf("Da tim va ghi so lon nhat vao %s\n", filexuat);
        fclose(f2);
    } else // neu kiemtra = 1 thi file doc khong toan la so
    {
        printf("File da doc khong hoan toan la so\n");
    }
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
    return 0;
}
        	