#include<stdio.h>
#include<queue>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int dx[8] = {-2,-1,-2,-1,1,2,1,2};
int dy[8] = {-1,-2,1,2,-2,-1,2,1};

int main() {
    int testcase;
    int cnt2 = 0;
    int tmp,tmp2= 0;

    scanf("%d",&testcase);
    tmp = testcase;
    while(tmp--) {
        int flag = 0; 
        int map[301][301]= {0,};
        int start_x,start_y;
        int end_x,end_y;
        int d;
        
        cnt2 =0;
        scanf("%d",&d);
        scanf("%d %d",&start_x,&start_y);
        scanf("%d %d",&end_x,&end_y);


        queue< pair<int, int> >q;
        q.push({start_x,start_y});
        
        if(start_x == end_x && start_y == end_y) {
            printf("0\n");
            continue;
       }


        while(!q.empty()) {
            int size = q.size();

            for(int i= 0; i< size; i++) {
                start_x = q.front().first;
                start_y = q.front().second;
                q.pop();

                for(int j = 0; j< 8; j++) {
                    int new_x= start_x+dx[j];
                    int new_y= start_y+dy[j];

                    if(new_x <0 || new_y<0 || new_x >= d || new_y >= d)
                        continue;
                    if(map[new_x][new_y] == 0) {
                        map[new_x][new_y] = 1;
                        q.push({new_x,new_y});
                    }
                    if(new_x == end_x && new_y == end_y && map[new_x][new_y] == 1){
                        flag =1;
                        break;
                    }
                }
                if (flag) break;
            }
            cnt2++;
            if (flag) break;

        }

        if(flag ==1){
            printf("%d\n", cnt2);
        }
        else 
            printf("0\n");
    }

    return 0;
}

