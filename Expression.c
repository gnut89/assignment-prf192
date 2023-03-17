#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int s1 = a + (b * c);
    int s2 = a * (b + c);
    int s3 = a * b * c;
    int s4 = (a + b) * c;
    int s5 = a + b + c;
    int max = s1;
    if (s2 > max) max = s2;
    if (s3 > max) max = s3;
    if (s4 > max) max = s4;
    if (s5 > max) max = s5;
    printf("%d", max);
    return 0;    
}