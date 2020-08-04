#include <stdio.h>
#include "fx_s1615_double.h"

int main() {

    double a = 60.0, b = 30.0;
    fx_s1615 fxa = double_to_fx_s1615(a), fxb = double_to_fx_s1615(b);
    printf("%f %d %f %d\n", a, fxa, b, fxb);
    fx_s1615 fxc = fx_div(fxa, fxb);
    printf("%d %f\n", fxc, fx_s1615_to_double(fxc));
    
    double d = 81.0;
    fx_s1615 fxd = double_to_fx_s1615(d);
    printf("%f %f\n", fx_s1615_to_double(fxd), fx_s1615_to_double(fx_sqrt(fxd)));

    double e = 3.0;
    fx_s1615 fxe = double_to_fx_s1615(e);
    printf("%f %f\n", fx_s1615_to_double(fxe), fx_s1615_to_double(fx_power(fxe, 3)));

    double f = 45.0;
    fx_s1615 fxf = double_to_fx_s1615(f);
    printf("%f %f\n", fx_s1615_to_double(fxf), fx_s1615_to_double(fx_sine(fxf)));
    return 0;

}