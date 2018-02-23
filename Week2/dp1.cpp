#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
    int n;
    int arr[1001];
    int dp[1001];
    int dp2[1001];
    int res;

    scanf("%d",&n);

    for(int i = 0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    for(int i= 0; i< n ; i++) {
        dp[i] = 1;
        for(int j = 0; j< i; j++) {
          if(arr[i]>arr[j] && dp[j]+1 > dp[i])
              dp[i] = dp[j] +1;
        }
    }

    for(int i = n-1; i>=0; i--) {
        dp2[i] = 1;
        for(int j = n-1; j> i; j--) {
            if(arr[i] >arr[j] && dp2[j]+1 > dp2[i] ) {
               dp2[i] = dp2[j] +1;
            }
        }
    }
    
    for(int i = 0; i< n; i++) {
        res = max(res,dp[i]+dp2[i]-1);
    }
    
    printf("%d\n",res);
    return 0;
}
