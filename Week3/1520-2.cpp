#include<stdio.h>
#include<queue>
#include<utility>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[501][501] = {0,};
int chk[501][501] = {0,};
int cnt = 0;
int m,n;

void bfs(int i, int j) {
    int newi,newj;
    int a = 0;
    queue< pair<int,int> >q;
    q.push({i,j});

    while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();    
            for(int k = 0; k< 4 ; k++) {
                newi= i+dx[k];
                newj= j+dy[k];

                if(newi >= m || newi <0 || newj <0|| newj >=n || chk[newi][newj] == 1)
                    continue;

                if(map[newi][newj] < map[i][j]) {
                    q.push({newi,newj});
                    chk[newi][newj] =1;
                }

                if(newi == m-1 && newj == n-1)
                    cnt++;
            }
    }
}
int main() {

    scanf("%d %d",&m,&n);

    for(int i = 0; i< m; i++) {
        for(int j= 0; j< n; j++) {
            scanf("%d",&map[i][j]);
        }
    }

    bfs(0,0);
    printf("%d\n",cnt);
    return 0;

}

