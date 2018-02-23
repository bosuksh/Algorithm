#include<stdio.h>
#define min(a, b)(a<b?a:b);
int main() {
    int x;
    int dp[1000001] ={0,};

    scanf("%d",&x);

    for(int i = 2; i<=x; i++) {
        if(i%3 == 0)  {
            dp[i]= min(dp[i/3],dp[i-1]);
            dp[i]++;
        }
        if(i%2 == 0) {
            dp[i] = min(dp[i/2],dp[i-1]);
            dp[i]++;
        }
        if(i%6 == 0) {
            dp[i]= min(dp[i/3],dp[i-1]);
            dp[i] = min(dp[i],dp[i/2]);
            dp[i]++;
        }
        if(i%2 != 0 && i%3 != 0)
            dp[i] = dp[i-1]+1;
    } 

    printf("%d\n",dp[x]);
    return 0;
}
