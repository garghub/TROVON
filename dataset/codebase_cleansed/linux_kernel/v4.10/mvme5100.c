void platform_init(unsigned long r3, unsigned long r4, unsigned long r5)
{
u32 heapsize;
heapsize = 0x8000000 - (u32)_end;
simple_alloc_init(_end, heapsize, 32, 64);
fdt_init(_dtb_start);
serial_console_init();
}
