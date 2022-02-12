void __init omap_ads7846_init(int bus_num, int gpio_pendown, int gpio_debounce,
struct ads7846_platform_data *board_pdata)
{
struct spi_board_info *spi_bi = &ads7846_spi_board_info;
int err;
if (board_pdata && board_pdata->get_pendown_state) {
err = gpio_request_one(gpio_pendown, GPIOF_IN, "TSPenDown");
if (err) {
pr_err("Couldn't obtain gpio for TSPenDown: %d\n", err);
return;
}
gpio_export(gpio_pendown, 0);
if (gpio_debounce)
gpio_set_debounce(gpio_pendown, gpio_debounce);
}
ads7846_config.gpio_pendown = gpio_pendown;
spi_bi->bus_num = bus_num;
spi_bi->irq = OMAP_GPIO_IRQ(gpio_pendown);
if (board_pdata)
spi_bi->platform_data = board_pdata;
spi_register_board_info(&ads7846_spi_board_info, 1);
}
void __init omap_ads7846_init(int bus_num, int gpio_pendown, int gpio_debounce,
struct ads7846_platform_data *board_pdata)
{
}
void __init omap_nand_flash_init(int options, struct mtd_partition *parts,
int nr_parts)
{
u8 cs = 0;
u8 nandcs = GPMC_CS_NUM + 1;
while (cs < GPMC_CS_NUM) {
u32 ret = 0;
ret = gpmc_cs_read_reg(cs, GPMC_CS_CONFIG1);
if ((ret & 0xC00) == 0x800) {
printk(KERN_INFO "Found NAND on CS%d\n", cs);
if (nandcs > GPMC_CS_NUM)
nandcs = cs;
}
cs++;
}
if (nandcs > GPMC_CS_NUM) {
printk(KERN_INFO "NAND: Unable to find configuration "
"in GPMC\n ");
return;
}
if (nandcs < GPMC_CS_NUM) {
nand_data.cs = nandcs;
nand_data.parts = parts;
nand_data.nr_parts = nr_parts;
nand_data.devsize = options;
printk(KERN_INFO "Registering NAND on CS%d\n", nandcs);
if (gpmc_nand_init(&nand_data) < 0)
printk(KERN_ERR "Unable to register NAND device\n");
}
}
void __init omap_nand_flash_init(int options, struct mtd_partition *parts,
int nr_parts)
{
}
