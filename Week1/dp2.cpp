#include<stdio.h>

int main() {
    int N;
    int arr[1001], dp[1001]= {1,};
    int i,j,idx = 1;
    int max, min;
    scanf("%d",&N);
    for(i = 1; i<=N; i++)
        scanf("%d",&arr[i]);

    for(i = 1; i<= N; i++) 
        dp[i] = 1;
    max= dp[1];
    //    max_val = arr[1];
    for(i = 1; i<= N; i++) {
        //        idx =1;
        //        dp[i] = dp[i-1];
        min = 0;
        for(j = 1; j <= i; j++) {
            if(arr[i] > arr[j]) {
                min = (min>dp[j]? min:dp[j]);
            }   
        }   
        dp[i] = min+1;

        if(max< dp[i])
            max = dp[i];
    }   

    printf("%d ",max);
    printf("\n");
    return 0;
}


