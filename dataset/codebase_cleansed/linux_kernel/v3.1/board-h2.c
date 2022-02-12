static void h2_nand_cmd_ctl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
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
static int h2_nand_dev_ready(struct mtd_info *mtd)
{
return gpio_get_value(H2_NAND_RB_GPIO_PIN);
}
static void __init h2_init_smc91x(void)
{
if (gpio_request(0, "SMC91x irq") < 0) {
printk("Error requesting gpio 0 for smc91x irq\n");
return;
}
}
static int tps_setup(struct i2c_client *client, void *context)
{
tps65010_config_vregs1(TPS_LDO2_ENABLE | TPS_VLDO2_3_0V |
TPS_LDO1_ENABLE | TPS_VLDO1_3_0V);
return 0;
}
static void __init h2_init_irq(void)
{
omap1_init_common_hw();
omap1_init_irq();
}
static void __init h2_init(void)
{
h2_init_smc91x();
h2_nor_resource.end = h2_nor_resource.start = omap_cs3_phys();
h2_nor_resource.end += SZ_32M - 1;
h2_nand_resource.end = h2_nand_resource.start = OMAP_CS2B_PHYS;
h2_nand_resource.end += SZ_4K - 1;
if (gpio_request(H2_NAND_RB_GPIO_PIN, "NAND ready") < 0)
BUG();
gpio_direction_input(H2_NAND_RB_GPIO_PIN);
omap_cfg_reg(L3_1610_FLASH_CS2B_OE);
omap_cfg_reg(M8_1610_FLASH_CS2B_WE);
omap_cfg_reg(BALLOUT_V8_ARMIO3);
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
platform_add_devices(h2_devices, ARRAY_SIZE(h2_devices));
omap_board_config = h2_config;
omap_board_config_size = ARRAY_SIZE(h2_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, h2_i2c_board_info,
ARRAY_SIZE(h2_i2c_board_info));
omap1_usb_init(&h2_usb_config);
h2_mmc_init();
}
static void __init h2_map_io(void)
{
omap1_map_common_io();
}
