#include "fx_s1615_double.h"
#include "fx_1615_longlong.h"

#define FX32_90    0x002D0000
#define FX32_180   0x00590000
#define FX32_360   0x00B40000


fx_s1615 sine_fx_s1615_longlong(fx_s1615 angle)
{
    int sign = 1;
    fx_s1615 ret0, diff;
    int idx;

    if (angle < 0)
    {
        sign = -1;
        angle *= -1; 
    }

    angle = angle % FX32_360; 
    if (angle >= FX32_180)
    {
        sign *= -1;
        angle -= FX32_180;
    }

    if (angle > FX32_90)
    {
        angle = FX32_180 - angle;
    }
    idx = angle >> 15;

    ret0 = fx_1516_SinTable[idx]; 
    diff = fx_1516_SinTable[idx + 1] - ret0;
    return ( sign * ( ret0 + ((diff * (angle & 0x7FFF)) >> 15) ));
}
