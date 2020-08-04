#include <math.h>
#include "fx_s1615_double.h"

#define PI 3.14159265359
#define INV_PI (1 / PI)

fx_s1615 fx_sine(fx_s1615 a) {
    double fa = fx_s1615_int_to_double(a);
    fa *= PI / 180;
    return fx_s1615_double_to_int((sin((fa))));
}

fx_s1615 fx_sqrt(fx_s1615 a) {
    double fxa = fx_s1615_int_to_double(a);
    return fx_s1615_double_to_int(fx_s1615_int_to_double(sqrt(fxa)));
}

fx_s1615 fx_power(fx_s1615 a, double n) {
    double fa = fx_s1615_int_to_double(a);
    return fx_s1615_double_to_int(fx_s1615_int_to_double((pow(fa, n))));
}