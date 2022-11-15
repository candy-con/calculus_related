#include <stdio.h>
#include <math.h>
double f(double x, double a,double b,double c){
    double result = a*x*x + b*x + c;
    return result;
}
double g(double x, double a, double b){
    double result2 = 2*a*x + b;
    return result2;
}
double newton_square(double a,double b,double c,int shusoku, double start){
    double eps = 1E-6;
    double x = start;
    double prev_x = start;
    double new_x;
    for(int i=0;i<shusoku;i++){
        new_x = prev_x - (f(x,a,b,c)/g(x,a,b));
        x = new_x;
        if(fabs(new_x - prev_x) < eps){
            printf("loop=%d\n",i+1);
            break;
        }
        prev_x = new_x;
    }
    return new_x;
}
int main(){
    double a,b,c,start_val;
    int shusoku_val;
    double result;
    scanf("%lf%lf%lf%d%lf",&a,&b,&c,&shusoku_val,&start_val);
    result = newton_square(a,b,c,shusoku_val,start_val);
    printf("result:%lf\n",result);
    return 0;
}
