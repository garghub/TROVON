void platform_init(unsigned long r3, unsigned long r4, unsigned long r5)
{
u32 heapsize = 16*1024*1024 - (u32)_end;
simple_alloc_init(_end, heapsize, 32, 64);
fdt_init(_dtb_start);
if (ug_probe())
console_ops.write = ug_console_write;
}
