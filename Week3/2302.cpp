#include<stdio.h>

int main() {
    int seat,num,seatnum[42];
    int dp[42] = {0,},cnt = 0,totalcnt= 1,cnt2= 0;

    scanf("%d",&seat);
    scanf("%d",&num);


    for(int i = 0; i<num; i++) {
        scanf("%d",&seatnum[i]);
    }
    seatnum[num] = seat+1;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i<= seat; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    if(num == 0) {
        totalcnt = dp[seat];
    }
    else {
        for(int i = num; i>0 ; i--)  {
            totalcnt *= dp[seatnum[i]-seatnum[i-1]-1];
        } 
        totalcnt *= dp[seatnum[0]-1];
    } 
    printf("%d\n",totalcnt);

    return 0;
}
