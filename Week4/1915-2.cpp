#include<stdio.h>
#include<math.h>

int n,m;
char arr[1000][1000];
int dp[1000][1000] = {0,};

int main() {
    int tmp;
    int flag =1;
    int max =0;
    scanf("%d %d\n",&n,&m);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j< m; j++) {
            scanf("%c",&arr[i][j]);
        }
        getchar();
    }

    for(int i= 0; i< n; i++) {
        for(int j = 0; j< m; j++) {
            if(arr[i][j] == '1') {
                dp[i][j] = 1;
                max = 0;
            }
        }
    }
    for(int i = 0; i< n; i++) {
        for(int j = 0; j <m; j++) {
            if(arr[i][j]== '1') {
                if(i == 0)
                    dp[i][j] = 1;
                else if(j == 0) 
                    dp[i][j] = 1;
                else {
                    int min = dp[i-1][j];
                    if(dp[i][j-1] < min)
                        min = dp[i][j-1];
                    if(dp[i-1][j-1] < min)
                        min = dp[i-1][j-1];

                    dp[i][j]= min +1;
                }
                if(max < dp[i][j])
                    max = dp[i][j];
            }
        }
    }

    printf("%d\n",max*max); 
    return 0;

}
