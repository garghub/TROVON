static void sg2_udc_command(int cmd)
{
switch (cmd) {
case PXA2XX_UDC_CMD_CONNECT:
UP2OCR |= UP2OCR_HXOE | UP2OCR_DPPUE | UP2OCR_DPPUBE;
break;
case PXA2XX_UDC_CMD_DISCONNECT:
UP2OCR &= ~(UP2OCR_HXOE | UP2OCR_DPPUE | UP2OCR_DPPUBE);
break;
}
}
static void __init imote2_stargate2_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(sg2_im2_unified_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa2xx_set_spi_info(1, &pxa_ssp_master_0_info);
pxa2xx_set_spi_info(2, &pxa_ssp_master_1_info);
pxa2xx_set_spi_info(3, &pxa_ssp_master_2_info);
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
pxa27x_set_i2c_power_info(&i2c_pwr_pdata);
pxa_set_i2c_info(&i2c_pdata);
}
static int imote2_mci_get_ro(struct device *dev)
{
return 0;
}
static void __init imote2_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(imote2_pin_config));
imote2_stargate2_init();
platform_add_devices(imote2_devices, ARRAY_SIZE(imote2_devices));
i2c_register_board_info(0, imote2_i2c_board_info,
ARRAY_SIZE(imote2_i2c_board_info));
i2c_register_board_info(1, imote2_pwr_i2c_board_info,
ARRAY_SIZE(imote2_pwr_i2c_board_info));
pxa_set_mci_info(&imote2_mci_platform_data);
pxa_set_udc_info(&imote2_udc_info);
}
static int stargate2_mci_init(struct device *dev,
irq_handler_t stargate2_detect_int,
void *data)
{
int err;
err = gpio_request(SG2_SD_POWER_ENABLE, "SG2_sd_power_enable");
if (err) {
printk(KERN_ERR "Can't get the gpio for SD power control");
goto return_err;
}
gpio_direction_output(SG2_SD_POWER_ENABLE, 0);
err = gpio_request(SG2_GPIO_nSD_DETECT, "SG2_sd_detect");
if (err) {
printk(KERN_ERR "Can't get the sd detect gpio");
goto free_power_en;
}
gpio_direction_input(SG2_GPIO_nSD_DETECT);
err = request_irq(PXA_GPIO_TO_IRQ(SG2_GPIO_nSD_DETECT),
stargate2_detect_int,
IRQ_TYPE_EDGE_BOTH,
"MMC card detect",
data);
if (err) {
printk(KERN_ERR "can't request MMC card detect IRQ\n");
goto free_nsd_detect;
}
return 0;
free_nsd_detect:
gpio_free(SG2_GPIO_nSD_DETECT);
free_power_en:
gpio_free(SG2_SD_POWER_ENABLE);
return_err:
return err;
}
static void stargate2_mci_setpower(struct device *dev, unsigned int vdd)
{
gpio_set_value(SG2_SD_POWER_ENABLE, !!vdd);
}
static void stargate2_mci_exit(struct device *dev, void *data)
{
free_irq(PXA_GPIO_TO_IRQ(SG2_GPIO_nSD_DETECT), data);
gpio_free(SG2_SD_POWER_ENABLE);
gpio_free(SG2_GPIO_nSD_DETECT);
}
static int stargate2_reset_bluetooth(void)
{
int err;
err = gpio_request(SG2_BT_RESET, "SG2_BT_RESET");
if (err) {
printk(KERN_ERR "Could not get gpio for bluetooth reset\n");
return err;
}
gpio_direction_output(SG2_BT_RESET, 1);
mdelay(5);
gpio_set_value(SG2_BT_RESET, 0);
mdelay(10);
gpio_set_value(SG2_BT_RESET, 1);
gpio_free(SG2_BT_RESET);
return 0;
}
static int sg2_udc_detect(void)
{
return 1;
}
static void __init stargate2_init(void)
{
__raw_writel(__raw_readl(MECR) & ~MECR_NOS, MECR);
pxa2xx_mfp_config(ARRAY_AND_SIZE(stargate2_pin_config));
imote2_stargate2_init();
platform_add_devices(ARRAY_AND_SIZE(stargate2_devices));
i2c_register_board_info(0, ARRAY_AND_SIZE(stargate2_i2c_board_info));
i2c_register_board_info(1, stargate2_pwr_i2c_board_info,
ARRAY_SIZE(stargate2_pwr_i2c_board_info));
pxa_set_mci_info(&stargate2_mci_platform_data);
pxa_set_udc_info(&stargate2_udc_info);
stargate2_reset_bluetooth();
}
