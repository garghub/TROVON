static void katmai_fixups(void)
{
unsigned long sysclk = 33333000;
ibm440spe_fixup_clocks(sysclk, 6 * 1843200, 0);
ibm440spe_fixup_memsize();
dt_fixup_mac_address(0, bd.bi_enetaddr);
ibm4xx_fixup_ebc_ranges("/plb/opb/ebc");
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
platform_ops.fixups = katmai_fixups;
fdt_init(_dtb_start);
serial_console_init();
}
