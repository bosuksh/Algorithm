#include<stdio.h>
#include<string.h>

char str[1000000];
char bomb[36];

int main() {
    scanf("%s",str);
    scanf("%s",bomb);

    for(int i = 0; i<strlen(str)-strlen(bomb);i++) {
       if(str[i] == bomb[0]) {
           
       }
    }
}
