#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            s1++;
        } else if (a[i] == 2) {
            s2++;
        } else if (a[i] == 3) {
            s3++;
        } else if (a[i] == 4) {
            s4++;
        }
    }
    int sum = s4;
    if (s3 >= s1) {
        sum += s3;
        s1 = 0;
    } else {
        sum += s3;
        s1 -= s3;
    }
    sum += s2 / 2;
    s2 = s2 % 2;
    if (s2 == 1) {
        if (s1 <= 2) {
            sum += 1;
            s1 = 0;
        } else {
            sum += 1;
            s1 -= 2;
        }
    }
    if (s1 % 4 == 0) {
        sum += s1 / 4;
    } else {
        sum += s1 / 4 + 1;
    }
    

    printf("%d", sum);
    return 0;
}