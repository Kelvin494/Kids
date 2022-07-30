

#编译器指令
CROSS_COMPILE ?= arm-linux-gnueabihf-

CC			:= $(CROSS_COMPILE)gcc
LD			:= $(CROSS_COMPILE)ld
OBJCOPY		:= $(CROSS_COMPILE)objcopy
OBJDUMP		:= $(CROSS_COMPILE)objdump

#工程信息
PROJECT_NAME  ?= led_c

#文件树
#源文件夹#
SOURCE_DIRS :=  source \
				source/start \
				moudle/common \
				moudle/common/clk \
				moudle/common/delay
#文件路径#
ASMFILES_PATH		:= $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.s))
CFILES_PATH			:= $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.c))

#文件名称#
ASMFILES		:= $(notdir $(ASMFILES_PATH))
CFILES			:= $(notdir $(CFILES_PATH))

#生成中间文件#
OBJ_DIR	:= midobj
ASMOBJS		:= $(patsubst %, $(OBJ_DIR)/%, $(ASMFILES:.s=.o))
COBJS		:= $(patsubst %, $(OBJ_DIR)/%, $(CFILES:.c=.o))
MIDOBJS 	:= $(ASMOBJS) $(COBJS)

#最终生成
PRODUCE_DIR := produce
PROJECTPRODUCE := $(PRODUCE_DIR)/$(PROJECT_NAME)

#检索并替换为gcc命令#
#头文件#
INCLUDE_DIRS := moudle \
				moudle/sdk \
				moudle/common \
				moudle/common/clk \
				moudle/common/delay

INCLUDE		:= $(patsubst %, -I %, $(INCLUDE_DIRS))

VPATH :=$(SOURCE_DIRS)

#构建正文

$(PROJECTPRODUCE).bin : $(MIDOBJS)
	$(LD) -Tlink.lds -o $(PROJECTPRODUCE).elf $^
	$(OBJCOPY) -O binary -S $(PROJECTPRODUCE).elf $@

$(ASMOBJS) : $(OBJ_DIR)/%.o : %.s
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<
$(COBJS) : $(OBJ_DIR)/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<



#附属命令
.PHONY:clean print dump
dump:
	$(OBJDUMP) -D -m arm $(PROJECTPRODUCE).elf > $(PROJECTPRODUCE).dis

clean:
	del $(OBJ_DIR) /s /f /q
	del $(PRODUCE_DIR) /s /f /q
	del *.o /s
	del *.elf /s
	del *.bin /s
	del *.dis /s

print:
	@echo PROJECT_NAME : $(PROJECT_NAME)
	@echo -
	@echo INCLUDE DIRS : $(INCLUDE)
	@echo -
	@echo SOURCE_DIRS : $(SOURCE_DIRS)
	@echo -
	@echo ASMFILES_PATH : $(ASMFILES_PATH)
	@echo CFILES_PATH : $(CFILES_PATH)
	@echo ASMFILES : $(ASMFILES)
	@echo CFILES : $(CFILES)
	@echo -
	@echo OBJ_DIR : $(OBJ_DIR)
	@echo ASMOBJS : $(ASMOBJS)
	@echo COBJS : $(COBJS)
	@echo OBJS : $(MIDOBJS)
	@echo -
	@echo PRODUCE_DIR : $(PRODUCE_DIR)
	@echo PROJECTPRODUCE : $(PROJECTPRODUCE)

