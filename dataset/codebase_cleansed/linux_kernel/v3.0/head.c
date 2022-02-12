void __init reserve_ebda_region(void)
{
unsigned int lowmem, ebda_addr;
if (paravirt_enabled())
return;
lowmem = *(unsigned short *)__va(BIOS_LOWMEM_KILOBYTES);
lowmem <<= 10;
ebda_addr = get_bios_ebda();
if ((lowmem - ebda_addr) <= 0x10000)
lowmem = ebda_addr;
if ((ebda_addr == 0) && (lowmem >= 0x9f000))
lowmem = 0x9f000;
if ((lowmem == 0) || (lowmem >= 0x100000))
lowmem = 0x9f000;
memblock_x86_reserve_range(lowmem, 0x100000, "* BIOS reserved");
}
