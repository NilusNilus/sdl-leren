
srcs := $(shell find src/ -name "*.c")
objs := $(addprefix bin/, $(srcs:.c=.o))

target = bin/out.exe
cc = gcc
cflags = -Wall
lflags = -lmingw32 -lSDL2.dll

.PHONY: all
all: $(target)
	@./$<

$(target): $(objs)
	$(cc) $^ -o $@ -Ldependencies/lib $(lflags)

bin/%.o: %.c
	@mkdir -p $(@D)
	$(cc) -c $< -o $@ -Isrc/ -Idependencies/include $(cflags)


.PHONY: clean
clean:
	@rm -fr $(target) bin/src