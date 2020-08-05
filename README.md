# battle_c_1

첫 번째 프로젝트 : fx_s1615  
Sign bit를 포함한 fixed point number의 arithmetic 구현  
<br>

## Role

| 이름 | 학번 | 역할 |
| ---- | ---- | ---- |
| 고예준 | 201820742 | README 파일 작성 |
| 김지원 | 201720771 | Fixed point arithmetic 구현 |
| 조시호 | 201520659 | README 파일 작성 |
| 최형택 | 201620989 | README 파일 교정 |
<br>

## What is Fixed Point sXXYY?

sXXYY는 2진수로 실수를 표현하는 방법 중 하나다. (1 + XX + YY)개의 비트로 실수를 표현하며 1개 비트는 부호, XX개 비트는 정수부,  YY개 비트는 소수부를 표현한다.  
우리가 구현할 s1615의 경우 32비트를 사용하며 각 비트별로 갖는 의미는 다음과 같다.

| Sign Bit | 정수부 (XX) | 소수부 (YY) |
| ---- | ---- | ---- |
| 0 : 양수, 1 : 음수 | 16 bits | 15 bits |
<br>

### Example

+15000.75라는 수가 있을 때, s1615 고정소수점은 0001 1101 0100 1100 0110 0000 0000 0000<sub>2</sub> 로 표현된다.

```
sign bit: 0 = positive 
정수부:  0011 1010 1001 1000(2) = 15000(10)   
소수부:  0.1100 0000 0000 000(2) = 0.75(10)
```

| Sign Bit | 정수부 (16 bits) | 소수부(15 bits) |
| --- | --- | --- |
| 0 | 0011 1010 1001 1000 | 110 0000 0000 0000 |
| (양수) | 15000 | 1/2 + 1/4 =  0.75 |
<br>

## Fixed Point vs Floating Point
고정 소수점 방식과 다르게, 부동 소수점 방식은 많은 시스템에서 실수를 표현할 때 사용된다 (e.g. `float foo = 3.141592`).  
동일 비트수를 사용할 때 부동 소수점 방식으로 더욱 넓은 범위를 표현할 수 있는 이점이 있기 때문이다.
하지만 부동 소수점만의 표현 방식 때문에 실수를 100% 정확하게 표현할 수 없다는 단점이 있기도 하다.  
이 오차가 누적될 경우 실제로 문제가 되는 경우도 있기 때문에 개발자는 항상 유의해서 코드를 작성해야 한다.  
<br>

## How to Convert Fixed Point Binary to Decimal
s1615를 10진수로 표현하는 방법은 간단하다.   
부호비트를 제외한 31비트 2진수를 10진수로 나타낸 수를 2<sup>YY</sup>로 나눠주면 된다.    

```
0011101010011000110000000000000(2) = 491544576(10)   
491544576 / 2^15 = 15000.75
```  
<br>


## Fixed Point Arithmetic Library

### Macros
* `P2_15 32768.0`

    15자리를 shifting하기 위해 필요한 2<sup>15</sup>를 정의

* `FX_S1615_INT_TO_DOUBLE(a)`

    fx_s1615로 표현한 숫자를 double로 형변환하는 macro

* `FX_S1615_DOUBLE_TO_INT(a)`

    double로 표현한 숫자를 fx_s1615로 형변환하는 macro
<br>
<br>


* `FX_S1615_ADD(a, b)`

    fx_s1615로 표현된 두 값을 더해주는 macro

* `FX_S1615_SUB(a, b)`

    fx_s1615로 표현된 두 값을 빼는 macro

* `FX_S1615_MUL(a, b)`

    fx_s1615로 표현된 두 값을 곱해주는 macro

* `FX_S1615_DIV(a, b)`

    fx_s1615로 표현된 두 값을 나눠주는 macro  
<br>

### Functions
* `fx_s1615 sine_fx_s1615_int(fx_s1615 a)`

    fx_s1615로 표현된 값의 sin 을 구해주는 함수

* `fx_s1615 sqrt_fx_s1615_int(fx_s1615 a)`

    fx_s1615로 표현된 값의 제곱근을 구해주는 함수

* `fx_s1615 power_fx_s1615_int(fx_s1615 a, double n)`

    fx_s1615로 표현된 값의 n승을 구해주는 함수



