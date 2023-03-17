#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[100], s2[100], s3[100], temp[100];
    gets(s1);
    gets(s2);
    strcpy(s3, s2);
    strrev(s3);
    char *p = strstr(s1, s2);   
    while (p != NULL) {
        strcpy(temp, p + strlen(s2));
        *p = '\0';
        strcat(s1, s3);
        strcat(s1, temp);
        p = strstr(s1, s2);
    }
    puts(s1);
    return 0;
}
