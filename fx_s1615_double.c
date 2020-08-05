#include <math.h>
#include "fx_s1615_double.h"

#define PI 3.14159265359
#define INV_PI (1 / PI)

fx_s1615 sine_fx_s1615_int(fx_s1615 a) {
    double fa = FX_S1615_INT_TO_DOUBLE(a);
    fa *= PI / 180;
    return FX_S1615_DOUBLE_TO_INT(sin((fa)));
}

fx_s1615 sqrt_fx_s1615_int(fx_s1615 a) {
    double fxa = FX_S1615_INT_TO_DOUBLE(a);
    return FX_S1615_DOUBLE_TO_INT(sqrt(fxa));
}

fx_s1615 power_fx_s1615_int(fx_s1615 a, double n) {
    double fa = FX_S1615_INT_TO_DOUBLE(a);
    return FX_S1615_DOUBLE_TO_INT(pow(fa, n));
}