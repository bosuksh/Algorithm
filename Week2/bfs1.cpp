#include<stdio.h>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int box[1001][1001];
int dx[] = {-1, 0 ,1, 0};
int dy[] = {0,-1,0,1};

int main() {
    int i, j, day = 0;
    int m,n;
    bool tmt = false, tmtfull = true;
    queue< pair<int,int> > q;

    scanf("%d %d",&n,&m);
    for(i = 0; i< m; i++) {
        for(j = 0; j< n; j++) {
            scanf("%d",&box[i][j]);
            if(box[i][j] == 1) {
                tmt = true;
                q.push({i,j});
            }
            else if(box[i][j] == 0) {
                tmtfull = false;
            }
        }
    }
    if(tmtfull)
        printf("0\n");

    else  {
        while(!q.empty()) {
            int size = q.size();            
            for(int j = 0; j<size;j++) {
                int x = q.front(). first;
                int y = q.front(). second;
                q.pop();

                for(i = 0; i< 4;i++) {
                    if(y+dy[i] <0 || y+dy[i]>=n || x+dx[i] <0 || x+dx[i]>=m)
                        continue;
                    
                    if(box[x+dx[i]][y+dy[i]] == 0) {
                        box[x+dx[i]][y+dy[i]] = 1;
                        q.push({x+dx[i],y+dy[i]});
                    }
                }

            }

            day++;
        }

        for(int i= 0; i<m; i++) {
            for( int j =0 ;j< n; j++) {
                if(box[i][j] == 0) {
                    printf("-1\n");
                    return 0;
                }
            }   
        }

        printf("%d\n",day-1);
    }
    return 0;
}
