Path:=./build/
Path2:=./source/
PathH:=./header/
target:=server

Srcs:=$(wildcard $(Path2)*.c) # ./source/ .c

Objs:=$(Srcs:$(Path2)%.c=$(Path)%.o) # ./build/ .o

Bins:=$(Srcs:$(paht2)%.c=%) 

$(target):$(Objs)
	gcc $(Objs) -o $(target) -I $(PathH) -lmysqlclient 
	
all:$(Bins)
$(Path)%.o:$(Path2)%.c # % 通配上一条依赖规则
	gcc -c $^ -o $@ -I $(PathH)

.PHONY:rebuild clean
rebuild:clean $(target)

clean:
	rm $(Objs) $(target)