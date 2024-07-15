# 避免同名文件产生编译冲突
.PHONY:process_copy

CC=gcc  # CC 存编译器版本
INCLUDE_PATH=../include
LIBRARY_PATH=../librart
INSTALL_PATH=/usr/bin/

# 编译选项 指定头文件位置 加入调试信息 严格编译 生成二进制文件
CFLAGS=-I$(INCLUDE_PATH) -g -Wall -c
# 预处理选项 汇编指令的优化选项
#CPPFLAGS=-o1 -o2 -o3
CPPFLAGS=
TARGET=copy

# 获取当前目录下所有.c文件 将.c文件变为.o文件
SRCFILE=$(wildcard *.c)
DESTFILE=$(patsubst %.c,%.o,$(SRCFILE))

# 主目标 将所有.o连接到一起
$(TARGET):$(DESTFILE)
	$(CC) $^ -o $@

# 功能目标 每一个.c对应生成.o
%.o:%.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(DESTFILE)
	rm -rf $(TARGET)


