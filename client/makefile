Path:=./build/
Path2:=./source/
PathH:=./header/
target:=process_pool

Srcs:=$(wildcard $(Path2)*.c) # ./source/ .c

Objs:=$(Srcs:$(Path2)%.c=$(Path)%.o) # ./build/ .o

Bins:=$(Srcs:$(paht2)%.c=%) 

total:$(target) ./Client_c/client

$(target):$(Objs)
	gcc $(Objs) -o $(target) -I $(PathH) 
	
all:$(Bins)
$(Path)%.o:$(Path2)%.c # % 通配上一条依赖规则
	gcc -c $^ -o $@ -I $(PathH)

./Client_c/client:
	gcc ./Client_c/client.c  -o ./Client_c/client -I $(PathH)

.PHONY:rebuild clean
rebuild:clean total

clean:
	rm $(Objs) $(target) ./Client_c/client