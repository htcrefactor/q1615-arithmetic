#include <stdio.h>
#include "fx_s1615_double.h"

int main() {

    double a = 60.0, b = 30.0;
    fx_s1615 fxa = fx_s1615_double_to_int(a), fxb = fx_s1615_double_to_int(b);
    printf("%f %d %f %d\n", a, fxa, b, fxb);
    fx_s1615 fxc = fx_div(fxa, fxb);
    printf("%d %f\n", fxc, fx_s1615_int_to_double(fxc));
    
    double d = 81.0;
    fx_s1615 fxd = fx_s1615_double_to_int(d);
    printf("%f %d\n", fx_s1615_int_to_double(fxd), fx_sqrt(fxd));

    double e = 3.0;
    fx_s1615 fxe = fx_s1615_double_to_int(e);
    printf("%f %d\n", fx_s1615_int_to_double(fxe), fx_power(fxe, 3));

    double f = 90.0;
    fx_s1615 fxf = fx_s1615_double_to_int(f);
    printf("%f %f\n", fx_s1615_int_to_double(fxf), fx_s1615_int_to_double(fx_sine(fxf)));
    return 0;

}