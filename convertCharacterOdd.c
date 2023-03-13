#include<stdio.h>
#include<string.h>

int main(){
    char name[100];
    scanf("%s", name); // input: "Nguyen Van A"
    // strupr(name); // output: "NGUYEN VAN A"
    // printf("%s", name); // output: "NGUYEN VAN A"

    // scanf("%s", name); // input: "Nguyen Van A"
    // strlwr(name); // output: "nguyen van a"
    // printf("%s", name); // output: "nguyen van a"
    
    name[0] = toupper(name[0]); // output: "nguyen van a"
    for (int i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
    printf("%s", name); // output: "Nguyen van a"

    // tUNg -> Tung
}