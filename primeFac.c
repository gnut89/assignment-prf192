#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d", &n);
    int i = 2;
    printf("%d = ", n);
    while (n > 1){
        if (n % i == 0){
            printf("%d ", i);
            n /= i;
            if (n > 1) printf(" * ");
        }
        else i++;
    }
    return 0;
}