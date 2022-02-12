static void bfin_plat_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd_to_nand(mtd);
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
}
static void bfin_plat_nand_init(void)
{
}
static int __init acvilon_init(void)
{
int ret;
printk(KERN_INFO "%s(): registering device resources\n", __func__);
bfin_plat_nand_init();
ret =
platform_add_devices(acvilon_devices, ARRAY_SIZE(acvilon_devices));
if (ret < 0)
return ret;
i2c_register_board_info(0, acvilon_i2c_devs,
ARRAY_SIZE(acvilon_i2c_devs));
bfin_write_FIO0_FLAG_C(1 << 14);
msleep(5);
bfin_write_FIO0_FLAG_S(1 << 14);
spi_register_board_info(bfin_spi_board_info,
ARRAY_SIZE(bfin_spi_board_info));
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(acvilon_early_devices,
ARRAY_SIZE(acvilon_early_devices));
}
