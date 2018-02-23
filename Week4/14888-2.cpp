#include<stdio.h>
#include<limits.h>

int num[11];
int add;
int sub;
int mul;
int div;
int N;
int min = INT_MAX;
int max = INT_MIN;

void dfs(int start, int res) {
    if(start == N-1) {
        max = res>max?res:max;
        min = res<min?res:min;
        return;
    }

    if(add) {
        add--;
        dfs(start+1,res+num[start+1]);
        add++;
    }
    if(sub) {
        sub--;
        dfs(start+1,res-num[start+1]);
        sub++;
    }
    if(mul) {
        mul--;
        dfs(start+1,res*num[start+1]);
        mul++;
    }
    if(div) {
        div--;
        dfs(start+1,res/num[start+1]);
        div++;
    }
}
int main() {
    scanf("%d",&N);

    for(int i = 0; i< N; i++) {
        scanf("%d",&num[i]);
    }

    scanf("%d %d %d %d",&add,&sub,&mul,&div);
    dfs(0,num[0]);
    printf("%d\n%d\n",max,min);
}

