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

```
Maximum : 0111 1111 1111 1111 1111 1111 1111 1111 (2) =  65535.999969482421875 (10)
Minimum : 1111 1111 1111 1111 1111 1111 1111 1111 (2) = -65535.999969482421875 (10)
Resolution : 0000 0000 0000 0000 0000 0000 0000 0001 (2) = 0.000030517578125 (10)
```


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


## Makefile

1. define : 코드의 재사용성을 증가시키기 위해 반복되는 내용을 정의한다.
```
SRCS := test.c fx_s1615_double.c
OBJS := $(SRCS:.c=.o)
CC := gcc	# pre-defined macro can be redefined!
#CFLAGS = -c -Wall -g
CFLAGS = -c -DTEST -Wall 
```
<br>
<br>


2. 실행 파일 생성  
* $@ : 현재의 target 파일명 
* $^ : 현재 모든 의존 파일들의 명단
* -lm : <math.h> library 추가      
![image](/uploads/39a775cf74f8403d3fbf97ef7b7212f2/image.png)

``` 
test : $(OBJS)
	$(CC) -o $@ $^ -lm
```
<br>
<br>


3. 확장자 규칙 적용 : 일일히 목적 파일들을 gcc로 컴파일하지 않아도 된다. 
* $< : 의존 파일 중 첫번째 파일명   
```
# default rule
.c.o : 
	$(CC) $(CFLAGS) $< -lm
```

<br>
<br>


4. make clean :  .o파일과 실행파일을 지워준다.
```
# dummy target - no dependency 
clean : 
	-rm $(OBJS)
	-rm test
```

<br>
<br>


5. make dep : SRCS에 정의된 파일들이 의존하는 파일을 찾아준다. 
```
# dummy target - no dependency 
dep :
	gccmakedep ${SRCS}  # dependency check
```

## gcc -O flag
### -O 옵션별 세부 사항
`[-Olevel]`
- O0 : 최적화를 수행하지 않음 (Default)
- O, -O1 : 코드 크기와 실행 시간을 줄이는 최적화만 수행
- O2 : 메모리 공간과 속도를 희생하지 않는 범위 내의 모든 최적화를 수행
- O3 : -O2 최적화에 인라인 함수와 레지스터에 대한 최적화를 추가로 수행
- Os : -O2 최적화 기능을 사용하지만, 코드 크기를 증가하는 최적화는 제외

### 최적화 성능 비교
for문을 통하여 2,147,483,648(INT_MAX)번의 연산을 반복하는 코드를 작성하고 -O0과 -O2 옵션을 주어 컴파일 한 뒤 실행시간을 측정하였다.

#### 결과
![O2-optimization-result](O2-optimization-result.png)

최적화를 하지 않았을 때 for문을 수행하는데 약 5분의 시간이 걸렸으나 -O2 옵션으로 최적화하였을 때 for문을 수행했는가 싶을 정도로 실행시간이 줄어들었음을 확인할 수 있었다.

#### 원인 분석
실제로 코드가 어떻게 최적화 되었는지 확인하기 위해 gcc -S 옵션을 통해 컴파일된 어셈블리 코드를 분석해 보았다.
```
pi@raspberrypi:~/battle_c_1 $ gcc -S -DTEST -lm test.c
pi@raspberrypi:~/battle_c_1 $ gcc -S -O2 -DTEST -lm test.c -o test_optimization.s
```

복잡한 어셈블리 코드를 전부 해석하지 않고 for문의 시작 시간과 끝난 시간을 알기 위해 호출했던 clock 함수의 위치를 알 수 있다면 그 사이에 수행되는 어셈블리 코드를 통해 최적화 여부를 알 수 있을 것이다.   
실제로 어셈블리 코드는 아직 link 되어있지 않기 때문에 clock 함수의 시그니처가 그대로 남아있었다.

![O2-optimization-assembly](O2-optimization-assembly.png)
test.s는 main 라벨에서 처음 clock 함수를 호출한다. 이후 L2 라벨로 이동한뒤 C코드에서 for문에 해당하는 L3 라벨로 이동하고 70줄 가량의 어셈블리 코드를 실행하고 나서야 clock 함수를 호출한다. 라벨을 이동하는 것을 제외하면 C코드와 로직상 다른점이 없다.   
그런데 test_optimization.s는 main 라벨에서 첫 clock 함수를 호출하고 하나의 mov 명령을 수행하자마자 다시 clock 함수를 호출한다. 최적화의 영향인지 for문이 그대로 사라져버렸다.   
실제로 for문 내부에서 실행되는 코드들은 그 안에서만 연산될 뿐 for문 밖의 코드에 영향을 주지 못한다. 외부 변수에 연산의 결과를 저장하거나 출력하는 코드가 없기 때문이다.   
-O2 옵션을 주어 컴파일 하였을 때 컴파일러가 이를 확인하고 어셈블리 코드에 포함시키지 않아 극단적인 성능 차이를 보여준 것으로 보인다.
