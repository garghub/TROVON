static int qi_lb60_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
if (section)
return -ERANGE;
oobregion->length = 36;
oobregion->offset = 6;
if (mtd->oobsize == 128) {
oobregion->length *= 2;
oobregion->offset *= 2;
}
return 0;
}
static int qi_lb60_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
int eccbytes = 36, eccoff = 6;
if (section > 1)
return -ERANGE;
if (mtd->oobsize == 128) {
eccbytes *= 2;
eccoff *= 2;
}
if (!section) {
oobregion->offset = 2;
oobregion->length = eccoff - 2;
} else {
oobregion->offset = eccoff + eccbytes;
oobregion->length = mtd->oobsize - oobregion->offset;
}
return 0;
}
static void qi_lb60_nand_ident(struct platform_device *pdev,
struct mtd_info *mtd, struct mtd_partition **partitions,
int *num_partitions)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (chip->page_shift == 12) {
*partitions = qi_lb60_partitions_2gb;
*num_partitions = ARRAY_SIZE(qi_lb60_partitions_2gb);
} else {
*partitions = qi_lb60_partitions_1gb;
*num_partitions = ARRAY_SIZE(qi_lb60_partitions_1gb);
}
mtd_set_ooblayout(mtd, &qi_lb60_ooblayout_ops);
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
gpiod_add_lookup_table(&qi_lb60_audio_gpio_table);
gpiod_add_lookup_table(&qi_lb60_nand_gpio_table);
spi_register_board_info(qi_lb60_spi_board_info,
ARRAY_SIZE(qi_lb60_spi_board_info));
pwm_add_table(qi_lb60_pwm_lookup, ARRAY_SIZE(qi_lb60_pwm_lookup));
return platform_add_devices(jz_platform_devices,
ARRAY_SIZE(jz_platform_devices));
}
static int __init qi_lb60_board_setup(void)
{
printk(KERN_INFO "Qi Hardware JZ4740 QI LB60 setup\n");
board_gpio_setup();
if (qi_lb60_init_platform_devices())
panic("Failed to initialize platform devices");
return 0;
}
