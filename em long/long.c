#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void cau1() {
    int n, i, pos = 0, sum = 0;
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        printf("Phan Tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
            pos = i;
        }
    }
    double avg = (double)sum / n;
    printf("So trung binh cua mang la: %lf\n", avg);
    printf("So lon nhat: %d o vi tri: %d\n", max, pos + 1);
}


void cau2() {
    char str[100];
    printf("Nhap vao mang: ");
    gets(str);
    char temp[100];
    strcpy(temp, str);
    strrev(temp);
    puts(temp);
    if (strcmp(str, temp) == 0) {
        printf("Chuoi nay la chuoi doi xung.\n");
    } else {
        printf("Chuoi nay khong phai la chuoi doi xung.\n");
    }
    int i, count = 0;
    for (i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            count++;
        }
    }
    if (count == 0) {
        printf("Chuoi nay khong co so.\n");
    } else {
        printf("Chuoi nay co %d so.\n", count);
    }
}

void cau3() {
    FILE *f1, *f2;
    char fname[100], line[100];
    float num, max = -1e9;
    int is_numeric = 1;
    printf("Nhap ten file");
    scanf("%s", fname);
    f1 = fopen(fname, "r");
    if (f1 == NULL) {
        printf("Deo mo duoc file.\n");
        return;
    }
    while (fgets(line, 100, f1) != NULL) {
        if (sscanf(line, "%f", &num) != 1) {
            is_numeric = 0;
            break;
        }
        if (num > max) {
            max = num;
        }
    }
    fclose(f1);
    if (!is_numeric) {
        printf("File nay khong co so, doi file khac!.\n");
        return;
    }
    f2 = fopen("b.txt", "w");
    if (f2 == NULL) {
        printf("Khong the tao file.\n");
        return;
    }
    fprintf(f2, "%f", max);
    fclose(f2);
    printf("So lon nhat cua file a da viet vao b.txt.\n");
}

int main() {
    int choice;
    do {
        printf("Menu tien ich:\n");
        printf("1. Tinh trung binh cong va so lon nhat trong mang.\n");
        printf("2. dao nguoc chuoi, dem so ki tu.\n");
        printf("3. So lon nhat trong tep a.\n");
        printf("4. Cut ra ngoai.\n");
        printf("Chon nhanh len, thich thi lam sec, lom dom buoc: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                cau1();
                break;
            case 2:
                cau2();
                break;
            case 3:
                cau3();
                break;
            case 4:
                printf("Phan ra ngoai!");
                break;
            }
        }while(choice != 4);
    getch();
    return 0;
}