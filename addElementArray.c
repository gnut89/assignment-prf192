#include<stdio.h>
#include<conio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n + 1];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int num, k;
    scanf("%d %d", &num, &k);
    for (i = n; i >= k + 1; i--) {
        a[i] = a[i - 1];
    }
    a[k] = num;
    for ( i = 0; i < n + 1; i++) {
        printf("%d ", a[i]);
    }
    getch();
    return 0;
}
