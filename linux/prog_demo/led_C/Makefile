objs = start.o main.o

led_c.bin : $(objs)
	arm-linux-gnueabihf-ld -Tlink.lds    $^ -o led_c.elf
	arm-linux-gnueabihf-objcopy -O binary -S led_c.elf $@
	arm-linux-gnueabihf-objdump -D -m arm led_c.elf > led_c.dis

%.o : %.c
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<
%.o : %.s
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<

clean:
	del *.o
	del *.bin
	del *.elf
	del *.dis