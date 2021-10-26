#include <stdio.h>
#include <math.h>
int main(){
    double IntervalFrom, IntervalTo, step, error;
    int choise;
    printf("Tabulation of the function:\nChoose one:\n1. x<2.5 -> f(x)=cos(log(x^2))\n   2.5<=x<=3.5 -> f(x)=sec(x^4)\n   x>3.5 -> tg(sin(x))\n2. second\n");
    do{
    printf("Your choise: ");
    scanf("%d", &choise);
    if(choise==1 || choise==2) break;
        printf("Invalid choise\nTry again\n");
    }while(1);
    do{
    printf("Enter interval:\nFrom: ");
    scanf("%lf", &IntervalFrom);
    printf("To: ");
    scanf("%lf", &IntervalTo);
    if(IntervalFrom <= IntervalTo) break;
        printf("Invalid interval\nTry again\n");
    }while(1);
    printf("Enter step: ");
    scanf("%lf", &step);
    if(choise==2){
        printf("Enter error: ");
        scanf("%lf", &error);
    }
    double newnum = IntervalFrom;
    do{
        double out = 0, prev;
        if(choise == 1){
            if(newnum < 2.5){
                out = cos(log(pow(newnum,2)));
            }else if(newnum >= 2.5 && newnum <= 3.5){
                out = pow(1/cos(newnum),4);
            }else{
                out = tan(sin(newnum));
            }
        }else if(choise == 2){
            unsigned int counter = 0;
            double y;
            do{
                prev = y;
                y = (4*counter + 3);
                y = 1/y;
                y *= pow(newnum, 4*counter + 3);
                out += y;
                counter++;
            }while(fabs(y - prev) >= error);
        }
        printf("%lf\n", out);
        newnum += step;
    }while(newnum <= IntervalTo);
    return 0;
}