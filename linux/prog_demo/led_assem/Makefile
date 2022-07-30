led_assem.bin:led_assem.s
	arm-linux-gnueabihf-gcc -g -c               led_assem.s -o .\midpro\led_assem.o
	arm-linux-gnueabihf-ld -Ttext 0x87800000    .\midpro\led_assem.o -o .\midpro\led_assem.elf
	arm-linux-gnueabihf-objcopy -O binary -S -g .\midpro\led_assem.elf led_assem.bin
	arm-linux-gnueabihf-objdump -D .\midpro\led_assem.elf > led_assem.dis

clean:
	rm -rf \midpro *.bin *.dis