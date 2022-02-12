static int nhk8815_nand_init(void)
{
writel(0x0000000E, FSMC_PCR(0));
writel(0x000D0A00, FSMC_PMEM(0));
writel(0x00100A00, FSMC_PATT(0));
writel(readl(FSMC_PCR(0)) | 0x04, FSMC_PCR(0));
return 0;
}
static void __init nhk8815_onenand_init(void)
{
#ifdef CONFIG_MTD_ONENAND
writel(0x000030db, FSMC_BCR(0));
writel(0x02100551, FSMC_BTR(0));
#endif
}
static int __init nhk8815_mmcsd_init(void)
{
int ret;
ret = gpio_request(112, "card detect bias");
if (ret)
return ret;
gpio_direction_output(112, 0);
amba_apb_device_add(NULL, "mmci", NOMADIK_SDI_BASE, SZ_4K, IRQ_SDMMC, 0, &mmcsd_plat_data, 0x10180180);
return 0;
}
static int __init nhk8815_eth_init(void)
{
int gpio_nr = 115;
int err;
err = gpio_request(gpio_nr, "eth_irq");
if (!err) err = nmk_gpio_set_mode(gpio_nr, NMK_GPIO_ALT_GPIO);
if (!err) err = gpio_direction_input(gpio_nr);
if (err)
pr_err("Error %i in %s\n", err, __func__);
return err;
}
static void __init nomadik_timer_init(void)
{
u32 src_cr;
src_cr = readl(io_p2v(NOMADIK_SRC_BASE));
src_cr &= SRC_CR_INIT_MASK;
src_cr |= SRC_CR_INIT_VAL;
writel(src_cr, io_p2v(NOMADIK_SRC_BASE));
nmdk_timer_init(io_p2v(NOMADIK_MTU0_BASE));
}
static void __init nhk8815_platform_init(void)
{
cpu8815_platform_init();
nhk8815_onenand_init();
platform_add_devices(nhk8815_platform_devices,
ARRAY_SIZE(nhk8815_platform_devices));
amba_apb_device_add(NULL, "uart0", NOMADIK_UART0_BASE, SZ_4K, IRQ_UART0, 0, NULL, 0);
amba_apb_device_add(NULL, "uart1", NOMADIK_UART1_BASE, SZ_4K, IRQ_UART1, 0, NULL, 0);
i2c_register_board_info(0, nhk8815_i2c0_devices,
ARRAY_SIZE(nhk8815_i2c0_devices));
i2c_register_board_info(1, nhk8815_i2c1_devices,
ARRAY_SIZE(nhk8815_i2c1_devices));
i2c_register_board_info(2, nhk8815_i2c2_devices,
ARRAY_SIZE(nhk8815_i2c2_devices));
}
