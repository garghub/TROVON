static void platform_fixups(void)
{
if ((epapr_magic != EPAPR_EMAGIC)
&& (epapr_magic != EPAPR_SMAGIC))
fatal("r6 contained 0x%08x instead of ePAPR magic number\n",
epapr_magic);
if (ima_size < (unsigned long)_end)
printf("WARNING: Image loaded outside IMA!"
" (_end=%p, ima_size=0x%lx)\n", _end, ima_size);
if (ima_size < fdt_addr)
printf("WARNING: Device tree address is outside IMA!"
"(fdt_addr=0x%lx, ima_size=0x%lx)\n", fdt_addr,
ima_size);
if (ima_size < fdt_addr + fdt_totalsize((void *)fdt_addr))
printf("WARNING: Device tree extends outside IMA!"
" (fdt_addr=0x%lx, size=0x%x, ima_size=0x%lx\n",
fdt_addr, fdt_totalsize((void *)fdt_addr), ima_size);
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
epapr_magic = r6;
ima_size = r7;
fdt_addr = r3;
simple_alloc_init(_end, ima_size - (unsigned long)_end, 32, 64);
fdt_init((void *)fdt_addr);
serial_console_init();
platform_ops.fixups = platform_fixups;
}
