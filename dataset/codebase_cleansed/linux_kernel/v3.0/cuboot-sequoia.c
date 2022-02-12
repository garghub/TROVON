static void sequoia_fixups(void)
{
unsigned long sysclk = 33333333;
ibm440ep_fixup_clocks(sysclk, 11059200, 50000000);
ibm4xx_fixup_ebc_ranges("/plb/opb/ebc");
ibm4xx_denali_fixup_memsize();
dt_fixup_mac_address_by_alias("ethernet0", bd.bi_enetaddr);
dt_fixup_mac_address_by_alias("ethernet1", bd.bi_enet1addr);
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
platform_ops.fixups = sequoia_fixups;
platform_ops.exit = ibm44x_dbcr_reset;
fdt_init(_dtb_start);
serial_console_init();
}
