static void __init ts72xx_map_io(void)
{
ep93xx_map_io();
iotable_init(ts72xx_io_desc, ARRAY_SIZE(ts72xx_io_desc));
}
static void ts72xx_nand_hwcontrol(struct mtd_info *mtd,
int cmd, unsigned int ctrl)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (ctrl & NAND_CTRL_CHANGE) {
void __iomem *addr = chip->IO_ADDR_R;
unsigned char bits;
addr += (1 << TS72XX_NAND_CONTROL_ADDR_LINE);
bits = __raw_readb(addr) & ~0x07;
bits |= (ctrl & NAND_NCE) << 2;
bits |= (ctrl & NAND_CLE);
bits |= (ctrl & NAND_ALE) >> 2;
__raw_writeb(bits, addr);
}
if (cmd != NAND_CMD_NONE)
__raw_writeb(cmd, chip->IO_ADDR_W);
}
static int ts72xx_nand_device_ready(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
void __iomem *addr = chip->IO_ADDR_R;
addr += (1 << TS72XX_NAND_BUSY_ADDR_LINE);
return !!(__raw_readb(addr) & 0x20);
}
static void __init ts72xx_register_flash(void)
{
if (board_is_ts7200()) {
ep93xx_register_flash(2, EP93XX_CS6_PHYS_BASE, SZ_16M);
} else {
resource_size_t start;
if (is_ts9420_installed())
start = EP93XX_CS7_PHYS_BASE;
else
start = EP93XX_CS6_PHYS_BASE;
ts72xx_nand_resource[0].start = start;
ts72xx_nand_resource[0].end = start + SZ_16M - 1;
platform_device_register(&ts72xx_nand_flash);
}
}
static void __init ts72xx_init_machine(void)
{
ep93xx_init_devices();
ts72xx_register_flash();
platform_device_register(&ts72xx_rtc_device);
platform_device_register(&ts72xx_wdt_device);
ep93xx_register_eth(&ts72xx_eth_data, 1);
#if IS_ENABLED(CONFIG_FPGA_MGR_TS73XX)
if (board_is_ts7300())
platform_device_register(&ts73xx_fpga_device);
#endif
}
