static void taishan_fixups(void)
{
unsigned long sysclk = 33000000;
ibm440gx_fixup_clocks(sysclk, 6 * 1843200, 25000000);
ibm4xx_sdram_fixup_memsize();
dt_fixup_mac_address_by_alias("ethernet0", bd.bi_enetaddr);
dt_fixup_mac_address_by_alias("ethernet1", bd.bi_enet1addr);
ibm4xx_fixup_ebc_ranges("/plb/opb/ebc");
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
platform_ops.fixups = taishan_fixups;
fdt_init(_dtb_start);
serial_console_init();
}
