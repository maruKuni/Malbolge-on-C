CC:=clang
# CFLAGS+=-O3
CFLAGS+=-g
INCLUDE:=-Iinclude
SRCS:=$(wildcard src/*.c)
OBJS:=$(SRCS:src/%.c=obj/%.o)

.PHONY:all clean
all:bin/malbolge.exe
$(OBJS):obj/%.o:src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
bin/malbolge.exe:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	-rm obj/*.o
	-rm bin/*.exe