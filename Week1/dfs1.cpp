#include<stdio.h>
#include<algorithm>

int n,k; 
char arr[26][26];
int dfs[26][26]= {0, };   
int cnt[26*26];

void dfs1(int x,int y) {
    dfs[x][y] = k;
    arr[x][y] = '0';
    cnt[k]++;

    int new_idx_x, new_idx_y;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for(int i = 0; i< 4; i++) {
        new_idx_x = x+dx[i];
        new_idx_y = y+dy[i];

        if(new_idx_x >=0 && new_idx_x <n && new_idx_y >=0 && new_idx_y <n && arr[new_idx_x][new_idx_y] == '1') {
            dfs1(new_idx_x,new_idx_y);
        }
    }
}

int main() {

    k=0;
    scanf("%d",&n);

    for(int i= 0; i< n; i++) {
        scanf("%s",arr[i]);
    }

    for(int i = 0; i< n; i++) {
        for(int j = 0; j< n ; j++){
            if(arr[i][j] == '1' && dfs[i][j] == 0) {
                k++;
                dfs1(i,j);
            }
        }
    }
    std::sort(cnt+1,cnt+1+k);
    printf("%d\n",k);
    for(int i = 1; i<=k; i++) 
        printf("%d\n",cnt[i]);
    return 0;
}
