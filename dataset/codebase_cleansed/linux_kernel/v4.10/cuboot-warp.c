static void warp_fixups(void)
{
ibm440ep_fixup_clocks(66000000, 11059200, 50000000);
ibm4xx_sdram_fixup_memsize();
ibm4xx_fixup_ebc_ranges("/plb/opb/ebc");
dt_fixup_mac_address_by_alias("ethernet0", bd.bi_enetaddr);
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
platform_ops.fixups = warp_fixups;
platform_ops.exit = ibm44x_dbcr_reset;
fdt_init(_dtb_start);
serial_console_init();
}
