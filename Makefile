SRCS := test.c fx_s1615_double.c fx_1615_longlong.c
OBJS := $(SRCS:.c=.o)
CFLAGS := -c -Wall -lm
PG := 
DEFINE := 

test : $(OBJS)
	$(CC) -o $@ $^ -lm $(PG)

# default rule
.c.o : 
	$(CC) $(CFLAGS) $(DEFINE) $<

# dummy target - no dependency 
clean :
	-rm $(OBJS)
	-rm test

# dummy target - no dependency 
dep :
	gccmakedep ${SRCS}
