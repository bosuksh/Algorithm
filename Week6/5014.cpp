/*스타트 링크 BFS*/
#include<stdio.h>
#include<queue>

using namespace std;

int f,g,s,u,d;
int minval= 0;
int chk[1000001] = {0,};


int  main() {
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    queue <int>q;
    q.push(s);
    chk[s] = 1;
    

    while(!q.empty()) {

        int size = q.size();

        for(int i = 0; i< size; i++) {
            s = q.front(); 
            q.pop();

            int up =  s + u;
            int down = s - d;
            if(up == g || down == g) {
                chk[g] = 1;
                break;
            }
            if(chk[up] == 0 && up >=1 && up <= f) {
                chk[up] = 1;
                q.push(up);
            }
            if(chk[down] == 0 && down >=1 && down <= f) {
                chk[down] =1;
                q.push(down);
            }
        }
        minval ++;
        if(chk[g] == 1) {
            break;
        }
    }
    if(chk[g] == 1)
        printf("%d\n",minval);
    else
        printf("use the stairs\n");

    return 0;
}
