#include<stdio.h>
int m,n;
int map[9][9];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cnt;

void virus(int i, int j) {
    int newi,newj;

    for(int k = 0; k< 4; k++) {
        newi = i+dx[k];
        newj = j+dy[k];

        if(newi < 0 || newj < 0 || newi >=m || newj >=n)
            continue;
        
        if(map[newi][newj] == 0) {
            map[newi][newj] = 2;
            virus(newi,newj);
        }
    }
}
void wall(int m,int n) {
    map
}
int main() {
    scanf("%d %d",&m,&n);

    for(int i = 0; i<m; i++) {
        for(int j =0 ; j< n; j++) {
            scanf("%d",&map[i][j]);
        }
    }
    
    for(int i1 = 0; i1<m*n-2; i1++) {
        for(int i2 = i1+1; i2<m*n-1;i2++){
            for(int i3 = i2+1; i3<m*n;i3++) {
                map[i1/n][i1%n] = 1;
                map[i2/n][i2%n] = 1;
                map[i3/n][i3%n] = 1;


            }
        } 
    }
    
    printf("\n");
    for(int i = 0; i< m ; i++) {
        for(int j = 0; j< n; j++) {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
