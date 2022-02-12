static void sam440ep_fixups(void)
{
unsigned long sysclk = 66666666;
ibm440ep_fixup_clocks(sysclk, 11059200, 25000000);
ibm4xx_sdram_fixup_memsize();
ibm4xx_quiesce_eth((u32 *)0xef600e00, (u32 *)0xef600f00);
dt_fixup_mac_addresses(&bd.bi_enetaddr, &bd.bi_enet1addr);
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
platform_ops.fixups = sam440ep_fixups;
platform_ops.exit = ibm44x_dbcr_reset;
fdt_init(_dtb_start);
serial_console_init();
}
