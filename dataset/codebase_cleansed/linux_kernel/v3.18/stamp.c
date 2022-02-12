void sl811_port_power(struct device *dev, int is_on)
{
gpio_request(CONFIG_USB_SL811_BFIN_GPIO_VBUS, "usb:SL811_VBUS");
gpio_direction_output(CONFIG_USB_SL811_BFIN_GPIO_VBUS, is_on);
}
static void bfin_plat_nand_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
writeb(cmd, this->IO_ADDR_W + (1 << BFIN_NAND_PLAT_CLE));
else
writeb(cmd, this->IO_ADDR_W + (1 << BFIN_NAND_PLAT_ALE));
}
static int bfin_plat_nand_dev_ready(struct mtd_info *mtd)
{
return gpio_get_value(BFIN_NAND_PLAT_READY);
}
static void bfin_plat_nand_init(void)
{
gpio_request(BFIN_NAND_PLAT_READY, "bfin_nand_plat");
gpio_direction_input(BFIN_NAND_PLAT_READY);
}
static void bfin_plat_nand_init(void) {}
static int bfin_mmc_spi_init(struct device *dev,
irqreturn_t (*detect_int)(int, void *), void *data)
{
return request_irq(MMC_SPI_CARD_DETECT_INT, detect_int,
IRQF_TRIGGER_FALLING, "mmc-spi-detect", data);
}
static void bfin_mmc_spi_exit(struct device *dev, void *data)
{
free_irq(MMC_SPI_CARD_DETECT_INT, data);
}
static inline void adf702x_mac_init(void)
{
eth_random_addr(adf7021_platform_data.mac_addr);
}
static inline void adf702x_mac_init(void) {}
static int ads7873_get_pendown_state(void)
{
return gpio_get_value(GPIO_PF6);
}
static int __init net2272_init(void)
{
#if IS_ENABLED(CONFIG_USB_NET2272)
int ret;
ret = gpio_request(GPIO_PF6, "net2272");
if (ret)
return ret;
gpio_direction_output(GPIO_PF6, 0);
mdelay(2);
gpio_set_value(GPIO_PF6, 1);
#endif
return 0;
}
static int __init stamp_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
bfin_plat_nand_init();
adf702x_mac_init();
platform_add_devices(stamp_devices, ARRAY_SIZE(stamp_devices));
i2c_register_board_info(0, bfin_i2c_board_info,
ARRAY_SIZE(bfin_i2c_board_info));
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
if (net2272_init())
pr_warning("unable to configure net2272; it probably won't work\n");
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(stamp_early_devices,
ARRAY_SIZE(stamp_early_devices));
}
void native_machine_restart(char *cmd)
{
if ((bfin_read_SYSCR() & 0x7) == 0x3)
bfin_reset_boot_spi_cs(P_DEFAULT_BOOT_SPI_CS);
}
int bfin_get_ether_addr(char *addr)
{
*(u32 *)(&(addr[0])) = bfin_read32(FLASH_MAC);
*(u16 *)(&(addr[4])) = bfin_read16(FLASH_MAC + 4);
return 0;
}
