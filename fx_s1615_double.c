#include <math.h>
#include "fx_s1615_double.h"

#define PI 3.14159265359
#define INV_PI (1 / PI)

fx_s1615 fx_sine(fx_s1615 a) {
    double fa = fx_s1615_to_double(a);
    fa *= PI / 180;
    return double_to_fx_s1615((sin((fa))));
}

fx_s1615 fx_sqrt(fx_s1615 a) {
    double fxa = fx_s1615_to_double(a);
    return sqrt(fxa);
}

fx_s1615 fx_power(fx_s1615 a, double n) {
    double fa = fx_s1615_to_double(a);
    return pow(fa, n);
}