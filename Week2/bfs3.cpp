#include<stdio.h>
#include<queue>
using namespace std;
int main() {
    int start, end;
    int visit[100001] = {0,};
    queue<int>q;
    int depth = 0;
    int i,v;
    scanf("%d %d",&start,&end);

    if(start == end)
        printf("0\n");
    else {
        q.push(start);
        visit[start] = 1;
        
        while(!q.empty()) {
            int size = q.size();

            for(i = 0; i< size; i++) {
                v = q.front();
                q.pop();

                if(v == end) {
                    printf("%d\n",depth);
                    return 0;
                }
                
                if(v-1 >= 0 && !visit[v-1]) {
                    q.push(v-1);
                    visit[v-1] = 1;
                }
                if(v+1 <= 100000 && !visit[v+1]) {
                    q.push(v+1);
                    visit[v+1] = 1;
                }
                if(2*v <= 100000 && !visit[2*v]) {
                    q.push(2*v);
                    visit[2*v]  =1;
                }
            }
            depth ++;
        }
    }
}
