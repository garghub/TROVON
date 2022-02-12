static void
ixdp425_flash_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
int offset = (int)this->priv;
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_NCE) {
gpio_line_set(IXDP425_NAND_NCE_PIN, IXP4XX_GPIO_LOW);
udelay(5);
} else
gpio_line_set(IXDP425_NAND_NCE_PIN, IXP4XX_GPIO_HIGH);
offset = (ctrl & NAND_CLE) ? IXDP425_NAND_CMD_BYTE : 0;
offset |= (ctrl & NAND_ALE) ? IXDP425_NAND_ADDR_BYTE : 0;
this->priv = (void *)offset;
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, this->IO_ADDR_W + offset);
}
static void __init ixdp425_init(void)
{
ixp4xx_sys_init();
ixdp425_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
ixdp425_flash_resource.end =
IXP4XX_EXP_BUS_BASE(0) + ixp4xx_exp_bus_size - 1;
#if defined(CONFIG_MTD_NAND_PLATFORM) || \
defined(CONFIG_MTD_NAND_PLATFORM_MODULE)
ixdp425_flash_nand_resource.start = IXP4XX_EXP_BUS_BASE(3),
ixdp425_flash_nand_resource.end = IXP4XX_EXP_BUS_BASE(3) + 0x10 - 1;
gpio_line_config(IXDP425_NAND_NCE_PIN, IXP4XX_GPIO_OUT);
*IXP4XX_EXP_CS3 = IXP4XX_EXP_BUS_CS_EN |
IXP4XX_EXP_BUS_STROBE_T(1) |
IXP4XX_EXP_BUS_CYCLES(0) |
IXP4XX_EXP_BUS_SIZE(0) |
IXP4XX_EXP_BUS_WR_EN |
IXP4XX_EXP_BUS_BYTE_EN;
#endif
if (cpu_is_ixp43x()) {
ixdp425_uart.num_resources = 1;
ixdp425_uart_data[1].flags = 0;
}
platform_add_devices(ixdp425_devices, ARRAY_SIZE(ixdp425_devices));
}
