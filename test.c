#include <stdio.h>
#include "fx_s1615_double.h"
#include <time.h>
#include <limits.h>

int main() {

    clock_t start = clock();

    for(int i = 0 ; i < INT_MAX ; i++) {
        double a = 20.0, b = 30.0;
        fx_s1615 fxa = FX_S1615_DOUBLE_TO_INT(a), fxb = FX_S1615_DOUBLE_TO_INT(b);
#ifndef TEST
        printf("%f %d %f %d\n", a, fxa, b, fxb);
#endif
        fx_s1615 fxc = FX_S1615_DIV(fxa, fxb);
#ifndef TEST
        printf("%d %f\n", fxc, FX_S1615_INT_TO_DOUBLE(fxc));
#endif  
        double d = 50.0;
        fx_s1615 fxd = FX_S1615_DOUBLE_TO_INT(d);
#ifndef TEST
        printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxd), FX_S1615_INT_TO_DOUBLE(sqrt_fx_s1615_int(fxd)));
#endif
        double e = 3.0;
        fx_s1615 fxe = FX_S1615_DOUBLE_TO_INT(e);
#ifndef TEST
        printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxe), FX_S1615_INT_TO_DOUBLE(power_fx_s1615_int(fxe, 4)));
#endif
        double f = 30.0;
        fx_s1615 fxf = FX_S1615_DOUBLE_TO_INT(f);
#ifndef TEST
        printf("%f %f\n", FX_S1615_INT_TO_DOUBLE(fxf), FX_S1615_INT_TO_DOUBLE(sine_fx_s1615_int(fxf)));    
#endif
    }

    clock_t end = clock();

    printf("Total run time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;

}
