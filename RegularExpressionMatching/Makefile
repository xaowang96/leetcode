CC=gcc -Wall -c
LD=gcc

SRC1 = $(wildcard ./*.c)
OBJ1 = $(patsubst %.c,%.o,${SRC1})

TARGET ?= main

$(TARGET) : $(OBJ1)
	$(LD) $^ -o $@

%.o : %.c
	$(CC) $^ -o $@     

.PHONY: clean #防止 外面有clean文件 阻止执行clean

clean:
	rm -rf $(TARGET) $(OBJ1) $(OBJ2)
	 
