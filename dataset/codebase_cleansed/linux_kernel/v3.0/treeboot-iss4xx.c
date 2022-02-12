static void iss_4xx_fixups(void)
{
ibm4xx_sdram_fixup_memsize();
}
void platform_init(void)
{
unsigned long end_of_ram = 0x08000000;
unsigned long avail_ram = end_of_ram - (unsigned long)_end;
u32 pir_reg;
simple_alloc_init(_end, avail_ram, 128, 64);
platform_ops.fixups = iss_4xx_fixups;
platform_ops.exit = ibm44x_dbcr_reset;
pir_reg = mfspr(SPRN_PIR);
fdt_set_boot_cpuid_phys(_dtb_start, pir_reg);
fdt_init(_dtb_start);
serial_console_init();
}
