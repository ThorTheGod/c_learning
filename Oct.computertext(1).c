#include<stdio.h>
int main(){
    int x;//x表示工资
    float M,r;//M表示利息，r表示利率
    scanf("%d",&x);
    switch(x<=5000?1:0){//用判断符解决题目只能用switch的要求
        case 1:
            r = 0;
            break;
        case 0:
            switch(x<=8000?1:0){
                case 1:
                r = 0.03;
                break;
                case 0:
                    switch(x<=17000?1:0){
                        case 1:
                        r = 0.10;
                        break;
                        case 0:
                            switch(x<=30000?1:0){
                                case 1:
                                r = 0.20;
                                break;
                                case 0:
                                r = 0.25;}}}}
    M = r*x;
    printf("%f",M);
    return 0;
}
