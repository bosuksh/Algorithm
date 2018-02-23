#include<stdio.h>
//#include<queue>

int max= -1000000000;
int min= 1000000000;
int N;
int n[10];
int calc[9];
int sum,sub,mul,div;

void fact(int start) {

    if(start == N-1) {
        int res= n[0];

        for(int i = 0; i< N-1; i++) {
                if(calc[i] ==0)
                    res = res+ n[i+1];
                else if(calc[i] ==1)
                    res = res- n[i+1];
                else if(calc[i] ==2)
                    res = res* n[i+1];
                else
                    res = res/ n[i+1];
        }

        min = res<min?res:min;
        max = res>max?res:max;
        return;
    }
    for(int  i = start; i< N-1; i++) {
        int tmp = calc[start];
        calc[start] = calc[i];
        calc[i] = tmp;
        fact(start+1);
        tmp = calc[start];
        calc[start] = calc[i];
        calc[i] = tmp;
    }
}

int main() {
    int cnt = 0;

    scanf("%d",&N);

    for(int i = 0; i< N; i++) {
        scanf("%d",&n[i]);
    }
    scanf("%d",&sum);
    scanf("%d",&sub);
    scanf("%d",&mul);
    scanf("%d",&div);

    for(int i = 0; i< sum; i++) 
        calc[cnt++] = 0;
    for(int i = 0; i< sub; i++) 
        calc[cnt++] = 1;
    for(int i = 0; i< mul; i++) 
        calc[cnt++] = 2;
    for(int i = 0; i< div; i++) 
        calc[cnt++] = 3;

    fact(0);

    printf("%d\n",max);
    printf("%d\n",min);

    return 0;
}

