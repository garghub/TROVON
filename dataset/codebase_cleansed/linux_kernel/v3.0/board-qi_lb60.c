static void qi_lb60_nand_ident(struct platform_device *pdev,
struct nand_chip *chip, struct mtd_partition **partitions,
int *num_partitions)
{
if (chip->page_shift == 12) {
chip->ecc.layout = &qi_lb60_ecclayout_2gb;
*partitions = qi_lb60_partitions_2gb;
*num_partitions = ARRAY_SIZE(qi_lb60_partitions_2gb);
} else {
chip->ecc.layout = &qi_lb60_ecclayout_1gb;
*partitions = qi_lb60_partitions_1gb;
*num_partitions = ARRAY_SIZE(qi_lb60_partitions_1gb);
}
}
static void __init board_gpio_setup(void)
{
jz_gpio_disable_pullup(QI_LB60_GPIO_SD_VCC_EN_N);
jz_gpio_disable_pullup(QI_LB60_GPIO_SD_CD);
}
static int __init qi_lb60_init_platform_devices(void)
{
jz4740_framebuffer_device.dev.platform_data = &qi_lb60_fb_pdata;
jz4740_nand_device.dev.platform_data = &qi_lb60_nand_pdata;
jz4740_adc_device.dev.platform_data = &qi_lb60_battery_pdata;
jz4740_mmc_device.dev.platform_data = &qi_lb60_mmc_pdata;
jz4740_serial_device_register();
spi_register_board_info(qi_lb60_spi_board_info,
ARRAY_SIZE(qi_lb60_spi_board_info));
if (is_avt2) {
platform_device_register(&avt2_usb_regulator_device);
platform_device_register(&jz4740_usb_ohci_device);
}
return platform_add_devices(jz_platform_devices,
ARRAY_SIZE(jz_platform_devices));
}
static __init int board_avt2(char *str)
{
qi_lb60_mmc_pdata.card_detect_active_low = 1;
is_avt2 = true;
return 1;
}
static int __init qi_lb60_board_setup(void)
{
printk(KERN_INFO "Qi Hardware JZ4740 QI %s setup\n",
is_avt2 ? "AVT2" : "LB60");
board_gpio_setup();
if (qi_lb60_init_platform_devices())
panic("Failed to initialize platform devices\n");
return 0;
}
