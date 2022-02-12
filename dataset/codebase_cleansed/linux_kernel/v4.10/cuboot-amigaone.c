static void platform_fixups(void)
{
dt_fixup_memory(bd.bi_memstart, bd.bi_memsize);
dt_fixup_cpu_clocks(bd.bi_intfreq, bd.bi_busfreq / 4, bd.bi_busfreq);
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
fdt_init(_dtb_start);
serial_console_init();
platform_ops.fixups = platform_fixups;
}
