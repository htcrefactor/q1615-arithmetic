#include <stdio.h>
#include "fx_s1615_double.h"

int main() {

    double a = 20.0, b = 30.0;
    fx_s1615 fxa = FX_S1615_DOUBLE_TO_INT(a), fxb = FX_S1615_DOUBLE_TO_INT(b);
    printf("%f %d %f %d\n", a, fxa, b, fxb);
    fx_s1615 fxc = FX_S1615_DIV(fxa, fxb);
    printf("%d %f\n", fxc, FX_S1615_INT_TO_DOUBLE(fxc));
    
    double d = 50.0;
    fx_s1615 fxd = FX_S1615_DOUBLE_TO_INT(d);
    printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxd), FX_S1615_INT_TO_DOUBLE(sqrt_fx_s1615_int(fxd)));

    double e = 3.0;
    fx_s1615 fxe = FX_S1615_DOUBLE_TO_INT(e);
    printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxe), FX_S1615_INT_TO_DOUBLE(power_fx_s1615_int(fxe, 4)));

    double f = 30.0;
    fx_s1615 fxf = FX_S1615_DOUBLE_TO_INT(f);
    printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxf), FX_S1615_INT_TO_DOUBLE(sine_fx_s1615_int(fxf)));
    return 0;

}