#include<stdio.h>

int main() {
    int n;
    int dp[16],t,p;

    for(int i = 0; i<16; i++) 
        dp[i] = 0;

    scanf("%d",&n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d",&t,&p);

        if(dp[i] >dp[i+1])
            dp[i+1] = dp[i];    // i일의 값이 i+1번째 최대수익보다 크면 i+1번째 수익을 그대로 가져온다
        if(dp[i+t]<dp[i]+p)        // i+t일의 원래 수익과 i일에서 t일 후 수익중 최대 값을 선택한다. 
            dp[i+t] = dp[i]+p;
    } 

    printf("%d\n",dp[n]);
}
