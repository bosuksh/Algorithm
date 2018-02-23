#include<stdio.h>

int n,m,k;
int max = 0;

int main() {
    int newn,newm;
    scanf("%d %d %d",&n,&m,&k);
    
    for(int i = 0; i<=k;i++) {
        newn = n-i;
        newm = m-(k-i);

        if(newn/2 >= newm)  {
           max = max>newm?max:newm; 
        }
        else {
            max = max>(newn/2)?max:(newn/2);
        }
    }
    printf("%d\n",max);   
    return 0;
}
