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
return gpio_get_value(H3_NAND_RB_GPIO_PIN);
}
static void __init h3_init_smc91x(void)
{
omap_cfg_reg(W15_1710_GPIO40);
if (gpio_request(40, "SMC91x irq") < 0) {
printk("Error requesting gpio 40 for smc91x irq\n");
return;
}
}
static void __init h3_init(void)
{
h3_init_smc91x();
nor_resource.end = nor_resource.start = omap_cs3_phys();
nor_resource.end += SZ_32M - 1;
nand_resource.end = nand_resource.start = OMAP_CS2B_PHYS;
nand_resource.end += SZ_4K - 1;
if (gpio_request(H3_NAND_RB_GPIO_PIN, "NAND ready") < 0)
BUG();
gpio_direction_input(H3_NAND_RB_GPIO_PIN);
omap_cfg_reg(V2_1710_GPIO10);
omap_cfg_reg(F18_1610_KBC0);
omap_cfg_reg(D20_1610_KBC1);
omap_cfg_reg(D19_1610_KBC2);
omap_cfg_reg(E18_1610_KBC3);
omap_cfg_reg(C21_1610_KBC4);
omap_cfg_reg(G18_1610_KBR0);
omap_cfg_reg(F19_1610_KBR1);
omap_cfg_reg(H14_1610_KBR2);
omap_cfg_reg(E20_1610_KBR3);
omap_cfg_reg(E19_1610_KBR4);
omap_cfg_reg(N19_1610_KBR5);
platform_add_devices(devices, ARRAY_SIZE(devices));
spi_register_board_info(h3_spi_board_info,
ARRAY_SIZE(h3_spi_board_info));
omap_board_config = h3_config;
omap_board_config_size = ARRAY_SIZE(h3_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, h3_i2c_board_info,
ARRAY_SIZE(h3_i2c_board_info));
omap1_usb_init(&h3_usb_config);
h3_mmc_init();
}
static void __init h3_init_irq(void)
{
omap1_init_common_hw();
omap1_init_irq();
}
static void __init h3_map_io(void)
{
omap1_map_common_io();
}
