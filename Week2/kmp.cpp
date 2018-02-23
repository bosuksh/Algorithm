#include<stdio.h>
#include<string.h>

int main() {
    char H[100001];
    char N[11];
    int cnt = 0;

    scanf("%s",H);
    scanf("%s",N);

    for(int i = 0; i<strlen(H);i++) {
        if(H[i] == N[0]) {
            if(strncmp(H+i,N,strlen(N))== 0) {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    
    return 0;
}   
