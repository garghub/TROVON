static void __init vision_map_io(void)
{
ep93xx_map_io();
iotable_init(vision_io_desc, ARRAY_SIZE(vision_io_desc));
}
static int vision_lcd_setup(struct platform_device *pdev)
{
int err;
err = gpio_request_one(VISION_LCD_ENABLE, GPIOF_INIT_HIGH,
dev_name(&pdev->dev));
if (err)
return err;
ep93xx_devcfg_clear_bits(EP93XX_SYSCON_DEVCFG_RAS |
EP93XX_SYSCON_DEVCFG_RASONP3 |
EP93XX_SYSCON_DEVCFG_EXVC);
return 0;
}
static void vision_lcd_teardown(struct platform_device *pdev)
{
gpio_free(VISION_LCD_ENABLE);
}
static void vision_lcd_blank(int blank_mode, struct fb_info *info)
{
if (blank_mode)
gpio_set_value(VISION_LCD_ENABLE, 0);
else
gpio_set_value(VISION_LCD_ENABLE, 1);
}
static int vision_spi_flash_hw_setup(struct spi_device *spi)
{
return gpio_request_one(VISION_SPI_FLASH_CS, GPIOF_INIT_HIGH,
spi->modalias);
}
static void vision_spi_flash_hw_cleanup(struct spi_device *spi)
{
gpio_free(VISION_SPI_FLASH_CS);
}
static void vision_spi_flash_hw_cs_control(struct spi_device *spi, int value)
{
gpio_set_value(VISION_SPI_FLASH_CS, value);
}
static int vision_spi_mmc_init(struct device *pdev,
irqreturn_t (*func)(int, void *), void *pdata)
{
int err;
err = gpio_request_array(vision_spi_mmc_gpios,
ARRAY_SIZE(vision_spi_mmc_gpios));
if (err)
return err;
err = gpio_set_debounce(VISION_SPI_MMC_CD, 1);
if (err)
goto exit_err;
err = request_irq(gpio_to_irq(VISION_SPI_MMC_CD), func,
IRQ_TYPE_EDGE_BOTH, "mmc_spi:cd", pdata);
if (err)
goto exit_err;
return 0;
exit_err:
gpio_free_array(vision_spi_mmc_gpios, ARRAY_SIZE(vision_spi_mmc_gpios));
return err;
}
static void vision_spi_mmc_exit(struct device *pdev, void *pdata)
{
free_irq(gpio_to_irq(VISION_SPI_MMC_CD), pdata);
gpio_free_array(vision_spi_mmc_gpios, ARRAY_SIZE(vision_spi_mmc_gpios));
}
static int vision_spi_mmc_get_ro(struct device *pdev)
{
return !!gpio_get_value(VISION_SPI_MMC_WP);
}
static int vision_spi_mmc_get_cd(struct device *pdev)
{
return !gpio_get_value(VISION_SPI_MMC_CD);
}
static int vision_spi_mmc_hw_setup(struct spi_device *spi)
{
return gpio_request_one(VISION_SPI_MMC_CS, GPIOF_INIT_HIGH,
spi->modalias);
}
static void vision_spi_mmc_hw_cleanup(struct spi_device *spi)
{
gpio_free(VISION_SPI_MMC_CS);
}
static void vision_spi_mmc_hw_cs_control(struct spi_device *spi, int value)
{
gpio_set_value(VISION_SPI_MMC_CS, value);
}
static void __init vision_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_flash(2, EP93XX_CS6_PHYS_BASE, SZ_64M);
ep93xx_register_eth(&vision_eth_data, 1);
ep93xx_register_fb(&ep93xxfb_info);
ep93xx_register_pwm(1, 0);
if (gpio_request_one(EP93XX_GPIO_LINE_F(7), GPIOF_DIR_IN,
"pca9539:74"))
pr_warn("cannot request interrupt gpio for pca9539:74\n");
ep93xx_register_i2c(&vision_i2c_gpio_data, vision_i2c_info,
ARRAY_SIZE(vision_i2c_info));
ep93xx_register_spi(&vision_spi_master, vision_spi_board_info,
ARRAY_SIZE(vision_spi_board_info));
}
