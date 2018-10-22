#include<stdio.h>
int main(){
    int row,col;
    int a,b;
    int c[3][3];
    int d[3][3];
    printf("please input 3X3 numbers:\n");
    for(row=0; row<=2; row++) {
        for(col=0; col<=2; col++) {
            scanf("%d",&c[row][col]);//输入数据给c数组
            d[col][row]=c[row][col];//将数组横坐标和竖坐标转换存进d数组
        }
    }
    for(row=0; row<=2; row++) {
        for(col=0; col<=2; col++) {
            printf("%d\t",c[row][col]);//先输出矩阵c作参照
        }
        printf("\n");
    }
    printf("\n");
    for(col=0; col<=2; col++) {
        for(row=0; row<=2; row++) {
            printf("%d\t",d[col][row]);//输出转置矩阵d，对比效果
        }
        printf("\n");
    }
}
