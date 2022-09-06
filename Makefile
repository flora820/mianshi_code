srcfile = ./src/*.c
include = -I ./include
ObjFiles = $(patsubst %.c,%.o,$(srcfile))
target = test

${target}:$(ObjFiles)
	gcc -o ${target} ${include} $(ObjFiles)

%.o:%.c
	gcc -c $< -I ./include -o $@

#定义伪目标，防止有歧义，如果当前目录下有文件的名称和clean相同，则得到结果不理想
.PHONY:clean
clean:
	#-表示当这条命令报错时仍然继续执行，@表示规则命令不打印到屏幕上
	rm  ${ObjFiles} ${target} 


