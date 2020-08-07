SRCS := test.c fx_s1615_double.c
OBJS := $(SRCS:.c=.o)
CC := gcc	# pre-defined macro can be redefined!
#CFLAGS = -c -Wall -g
CFLAGS = -c -DTEST -Wall 

test : $(OBJS)
	$(CC) -o $@ $^ -lm

# default rule
.c.o : 
	$(CC) $(CFLAGS) $< -lm

# dummy target - no dependency 
clean : 
	-rm $(OBJS)

# dummy target - no dependency 
dep :
	gccmakedep ${SRCS}


# DO NOT DELETE
test.o: test.c /usr/include/stdc-predef.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/arm-linux-gnueabihf/sys/cdefs.h \
 /usr/include/arm-linux-gnueabihf/bits/wordsize.h \
 /usr/include/arm-linux-gnueabihf/gnu/stubs.h \
 /usr/include/arm-linux-gnueabihf/gnu/stubs-hard.h \
 /usr/lib/gcc/arm-linux-gnueabihf/6/include/stddef.h \
 /usr/include/arm-linux-gnueabihf/bits/types.h \
 /usr/include/arm-linux-gnueabihf/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/arm-linux-gnueabihf/6/include/stdarg.h \
 /usr/include/arm-linux-gnueabihf/bits/stdio_lim.h \
 /usr/include/arm-linux-gnueabihf/bits/sys_errlist.h fx_s1615_double.h \
 /usr/include/time.h /usr/include/arm-linux-gnueabihf/bits/time.h \
 /usr/include/xlocale.h \
 /usr/lib/gcc/arm-linux-gnueabihf/6/include-fixed/limits.h \
 /usr/lib/gcc/arm-linux-gnueabihf/6/include-fixed/syslimits.h \
 /usr/include/limits.h /usr/include/arm-linux-gnueabihf/bits/posix1_lim.h \
 /usr/include/arm-linux-gnueabihf/bits/local_lim.h \
 /usr/include/linux/limits.h \
 /usr/include/arm-linux-gnueabihf/bits/posix2_lim.h
fx_s1615_double.o: fx_s1615_double.c /usr/include/stdc-predef.h \
 /usr/include/math.h /usr/include/features.h \
 /usr/include/arm-linux-gnueabihf/sys/cdefs.h \
 /usr/include/arm-linux-gnueabihf/bits/wordsize.h \
 /usr/include/arm-linux-gnueabihf/gnu/stubs.h \
 /usr/include/arm-linux-gnueabihf/gnu/stubs-hard.h \
 /usr/include/arm-linux-gnueabihf/bits/math-vector.h \
 /usr/include/arm-linux-gnueabihf/bits/libm-simd-decl-stubs.h \
 /usr/include/arm-linux-gnueabihf/bits/huge_val.h \
 /usr/include/arm-linux-gnueabihf/bits/huge_valf.h \
 /usr/include/arm-linux-gnueabihf/bits/huge_vall.h \
 /usr/include/arm-linux-gnueabihf/bits/inf.h \
 /usr/include/arm-linux-gnueabihf/bits/nan.h \
 /usr/include/arm-linux-gnueabihf/bits/mathdef.h \
 /usr/include/arm-linux-gnueabihf/bits/mathcalls.h fx_s1615_double.h
