static void __init u300_reserve(void)
{
#ifdef CONFIG_MACH_U300_SINGLE_RAM
#if ((CONFIG_MACH_U300_ACCESS_MEM_SIZE & 1) == 1) && \
CONFIG_MACH_U300_2MB_ALIGNMENT_FIX
memblock_reserve(PHYS_OFFSET, 0x00100000);
#endif
#endif
}
static void __init u300_init_machine(void)
{
u300_init_devices();
}
