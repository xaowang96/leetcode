DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj

#由于 .c文件在不同的文件下，那么匹配模式 要匹配不同文件下的%.c文件
SRC1 = $(wildcard $(DIR_SRC)/*.c)
SRC2 = $(wildcard ./*.c)
#输出中间文件在obj目录下
#OBJ1 = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir ${SRC1}))
#输出中间文件在源文件目录下
OBJ1 = $(patsubst %.c,%.o,${SRC1})
OBJ2 = $(patsubst %.c,%.o,${SRC2})

CC=gcc
CFLAGS = -g -Wall -c -I${DIR_INC}
LD=gcc

#LDFLAGS += -lpthread

TARGET=main

$(TARGET):$(OBJ1) $(OBJ2)
	$(LD) $^ $(LDFLAGS) -o $@ 

#编译src文件夹下的.c文件
#$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c		#目标文件在obj目录下
$(DIR_SRC)/%.o:$(DIR_SRC)/%.c		#目标文件在源文件目录下
	echo $(OBJ1)
	$(CC) $(CFLAGS) $^ -o $@ 
#编译当前路径下的.c文件
%.o:%.c
	echo $(OBJ2)
	$(CC) $(CFLAGS) $^ -o $@ 

.PHONY: clean #防止 外面有clean文件 阻止执行clean

clean:
	rm -f $(TARGET) $(OBJ1) $(OBJ2)


