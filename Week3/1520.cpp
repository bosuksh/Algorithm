#include<stdio.h>
#include<queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[501][501] = {0,};
int cnt = 0;
int m,n;
int dp[501][501];

int dfs(int i, int j) {
    int newi,newj;
    int a = 0;
    if(i == m-1 && j==n-1) {
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;

    for(int k = 0; k< 4 ; k++) {
        newi= i+dx[k];
        newj= j+dy[k];
        
        if(newi<0 || newj<0 || newi>=m || newj >=n)
            continue;

        if(map[newi][newj] < map[i][j]) 
           dp[i][j] += dfs(newi,newj);
    }
    return dp[i][j];

}
int main() {
    int res;
    scanf("%d %d",&m,&n);

    for(int i = 0; i< m; i++) {
        for(int j= 0; j< n; j++) {
            scanf("%d",&map[i][j]);
            dp[i][j] = -1;
        }
    }
    
    res = dfs(0,0);

    printf("%d\n",res);
    return 0;

}

