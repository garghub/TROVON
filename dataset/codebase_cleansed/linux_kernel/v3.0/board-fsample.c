static void __init fsample_init_smc91x(void)
{
fpga_write(1, H2P2_DBG_FPGA_LAN_RESET);
mdelay(50);
fpga_write(fpga_read(H2P2_DBG_FPGA_LAN_RESET) & ~1,
H2P2_DBG_FPGA_LAN_RESET);
mdelay(50);
}
static void nand_cmd_ctl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
unsigned long mask;
if (cmd == NAND_CMD_NONE)
return;
mask = (ctrl & NAND_CLE) ? 0x02 : 0;
if (ctrl & NAND_ALE)
mask |= 0x04;
writeb(cmd, (unsigned long)this->IO_ADDR_W | mask);
}
static int nand_dev_ready(struct mtd_info *mtd)
{
return gpio_get_value(FSAMPLE_NAND_RB_GPIO_PIN);
}
static void __init omap_fsample_init(void)
{
fsample_init_smc91x();
if (gpio_request(FSAMPLE_NAND_RB_GPIO_PIN, "NAND ready") < 0)
BUG();
gpio_direction_input(FSAMPLE_NAND_RB_GPIO_PIN);
omap_cfg_reg(L3_1610_FLASH_CS2B_OE);
omap_cfg_reg(M8_1610_FLASH_CS2B_WE);
omap_cfg_reg(E2_7XX_KBR0);
omap_cfg_reg(J7_7XX_KBR1);
omap_cfg_reg(E1_7XX_KBR2);
omap_cfg_reg(F3_7XX_KBR3);
omap_cfg_reg(D2_7XX_KBR4);
omap_cfg_reg(C2_7XX_KBC0);
omap_cfg_reg(D3_7XX_KBC1);
omap_cfg_reg(E4_7XX_KBC2);
omap_cfg_reg(F4_7XX_KBC3);
omap_cfg_reg(E3_7XX_KBC4);
platform_add_devices(devices, ARRAY_SIZE(devices));
omap_board_config = fsample_config;
omap_board_config_size = ARRAY_SIZE(fsample_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
}
static void __init omap_fsample_init_irq(void)
{
omap1_init_common_hw();
omap_init_irq();
}
static void __init omap_fsample_map_io(void)
{
omap1_map_common_io();
iotable_init(omap_fsample_io_desc,
ARRAY_SIZE(omap_fsample_io_desc));
omap_writew(omap_readw(OMAP7XX_DSP_M_CTL) & ~1, OMAP7XX_DSP_M_CTL);
omap_writel(0x0000fff3, OMAP7XX_FLASH_CFG_0);
omap_writel(0x00000088, OMAP7XX_FLASH_ACFG_0);
omap_writel(0x0000fff3, OMAP7XX_FLASH_CFG_1);
omap_writel(0x00000000, OMAP7XX_FLASH_ACFG_1);
omap_writel(omap_readl(OMAP7XX_IO_CONF_9) & 0x1FFFFFFF, OMAP7XX_IO_CONF_9);
}
