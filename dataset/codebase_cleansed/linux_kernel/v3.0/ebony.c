static void ebony_flashsel_fixup(void)
{
void *devp;
u32 reg[3] = {0x0, 0x0, 0x80000};
u8 *fpga;
u8 fpga_reg0 = 0x0;
devp = finddevice(EBONY_FPGA_PATH);
if (!devp)
fatal("Couldn't locate FPGA node %s\n\r", EBONY_FPGA_PATH);
if (getprop(devp, "virtual-reg", &fpga, sizeof(fpga)) != sizeof(fpga))
fatal("%s has missing or invalid virtual-reg property\n\r",
EBONY_FPGA_PATH);
fpga_reg0 = in_8(fpga);
devp = finddevice(EBONY_SMALL_FLASH_PATH);
if (!devp)
fatal("Couldn't locate small flash node %s\n\r",
EBONY_SMALL_FLASH_PATH);
if (getprop(devp, "reg", reg, sizeof(reg)) != sizeof(reg))
fatal("%s has reg property of unexpected size\n\r",
EBONY_SMALL_FLASH_PATH);
if (fpga_reg0 & EBONY_FPGA_FLASH_SEL)
reg[1] ^= 0x80000;
setprop(devp, "reg", reg, sizeof(reg));
}
static void ebony_fixups(void)
{
unsigned long sysclk = 33000000;
ibm440gp_fixup_clocks(sysclk, 6 * 1843200);
ibm4xx_sdram_fixup_memsize();
dt_fixup_mac_address_by_alias("ethernet0", ebony_mac0);
dt_fixup_mac_address_by_alias("ethernet1", ebony_mac1);
ibm4xx_fixup_ebc_ranges("/plb/opb/ebc");
ebony_flashsel_fixup();
}
void ebony_init(void *mac0, void *mac1)
{
platform_ops.fixups = ebony_fixups;
platform_ops.exit = ibm44x_dbcr_reset;
ebony_mac0 = mac0;
ebony_mac1 = mac1;
fdt_init(_dtb_start);
serial_console_init();
}
