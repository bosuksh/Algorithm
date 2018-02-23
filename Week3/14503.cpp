#include<stdio.h>
#include<stdlib.h>

enum direction {n,e,s,w};
int map[51][51];
int r,c;
typedef struct _point{
    int r;
    int c;
    direction d;
}point;
point p;


int main(){
    int cnt = 0;
    scanf("%d %d",&r,&c);
    scanf("%d %d %d",&p.r,&p.c,&p.d);
    getchar();
    for(int i= 0; i< r; i++) {
        for(int j= 0; j< c-1; j++) {
            scanf("%d ",&map[i][j]);
        }
        scanf("%d",&map[i][c-1]);
    }/*
        for(int i =0 ; i<r; i++) {
        for(int j = 0; j<c; j++) {
        printf("%d ",map[i][j]);
        }
        printf("\n");
        }*/
    /*
       if(map[p.r][p.c] == 0) {
       map[p.r][p.c] = 2;
       cnt++;
       }*/

    while(1) {
        if(map[p.r][p.c] == 0) {
            map[p.r][p.c] = 2;
            cnt++;
        }
        if(map[p.r-1][p.c] != 0 && map[p.r+1][p.c] != 0 && map[p.r][p.c-1] != 0 && map[p.r][p.c+1] != 0) {       //네 방향이 모두 빈공간이 아닐때

            if(p.d == n) {                   // 북쪽을 바라볼때
                if(map[p.r+1][p.c] == 1)   // 뒷쪽이 벽이면
                    break;
                else {                       // 뒤쪽이 청소가 되어있으면
                    p.r++;                   // 뒤로 한칸
                    continue;
                }
            }
            else if(p.d == e) {
                if(map[p.r][p.c-1] == 1)   // 뒷쪽이 벽이면
                    break;
                else {                       // 뒤쪽이 청소가 되어있으면
                    p.c--;                   // 뒤로 한칸
                    continue;
                }
            }
            else if(p.d == s) {
                if(map[p.r-1][p.c] == 1)   // 뒷쪽이 벽이면
                    break;
                else {                       // 뒤쪽이 청소가 되어있으면
                    p.r--;                   // 뒤로 한칸
                    continue;
                }
            }
            else if(p.d == w) {
                if(map[p.r][p.c+1] == 1)   // 뒷쪽이 벽이면
                    break;
                else {                       // 뒤쪽이 청소가 되어있으면
                    p.c++;                   // 뒤로 한칸
                    continue;
                }
            }

        }
        if(p.d== n) {      //북쪽을 바라볼때
            if(map[p.r][(p.c)-1] == 0 ){       // 왼쪽이 벽이 아닐때
                p.c--;
                p.d = w;
                map[p.r][p.c] = 2;
                cnt++;
            }
            else  {
                p.d = w;
            }
        }
        else if(p.d == e) {   //동쪽을 바라볼때
            if(map[(p.r)-1][p.c] == 0) {       //왼쪽이 벽이 아닐때
                p.r--;
                p.d = n;
                map[p.r][p.c] = 2;
                cnt++;
            }
            else {
                p.d = n;
            }
        }
        else if(p.d == s) {   //남쪽을 바라볼때
            if(map[p.r][(p.c)+1] == 0){        //왼쪽이 벽이 아닐때
                p.c++;
                p.d = e;
                map[p.r][p.c] = 2;
                cnt++;
            }
            else {
                p.d = e;
            }
        }
        else if(p.d == w) {   //서쪽을 바라볼때
            if(map[(p.r)+1][p.c] ==0) {        //왼쪽이 벽이 아닐때
                p.r++;
                p.d = s;
                map[p.r][p.c] = 2;
                cnt++;
            } 
            else {
                p.d = s;
            }
        }/*
        printf("\n\n");
        for(int i =0 ; i<r; i++) {
            for(int j = 0; j<c; j++) {
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
        printf("좌표의 위치는 %d %d\n",p.r,p.c);
        printf("direction is %d\n",p.d);
        getchar();
*/
    }/*
        for(int i =0 ; i<r; i++) {
        for(int j = 0; j<c; j++) {
        printf("%d ",map[i][j]);
        }
        printf("\n");
        }
        printf("좌표의 위치는 %d %d\n",p.r,p.c);
        printf("direction is %d\n",p.d);*/
    printf("%d\n",cnt);

    return 0;
}
