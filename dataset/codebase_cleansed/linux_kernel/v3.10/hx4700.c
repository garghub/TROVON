static void sony_lcd_init(void)
{
gpio_set_value(GPIO84_HX4700_LCD_SQN, 1);
gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 0);
gpio_set_value(GPIO111_HX4700_LCD_AVDD_3V3_ON, 0);
gpio_set_value(GPIO70_HX4700_LCD_SLIN1, 0);
gpio_set_value(GPIO62_HX4700_LCD_nRESET, 0);
mdelay(10);
gpio_set_value(GPIO59_HX4700_LCD_PC1, 0);
gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 0);
mdelay(20);
gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 1);
mdelay(5);
gpio_set_value(GPIO111_HX4700_LCD_AVDD_3V3_ON, 1);
mdelay(5);
gpio_set_value(GPIO70_HX4700_LCD_SLIN1, 1);
mdelay(10);
gpio_set_value(GPIO62_HX4700_LCD_nRESET, 1);
mdelay(10);
gpio_set_value(GPIO59_HX4700_LCD_PC1, 1);
mdelay(10);
gpio_set_value(GPIO112_HX4700_LCD_N2V7_7V3_ON, 1);
}
static void sony_lcd_off(void)
{
gpio_set_value(GPIO59_HX4700_LCD_PC1, 0);
gpio_set_value(GPIO62_HX4700_LCD_nRESET, 0);
mdelay(10);
gpio_set_value(GPIO112_HX4700_LCD_N2V7_7V3_ON, 0);
mdelay(10);
gpio_set_value(GPIO111_HX4700_LCD_AVDD_3V3_ON, 0);
mdelay(10);
gpio_set_value(GPIO110_HX4700_LCD_LVDD_3V3_ON, 0);
}
static void w3220_lcd_suspend(struct w100fb_par *wfb)
{
sony_lcd_off();
}
static void w3220_lcd_resume(struct w100fb_par *wfb)
{
sony_lcd_init();
}
static void hx4700_lcd_set_power(struct plat_lcd_data *pd, unsigned int power)
{
if (power)
sony_lcd_init();
else
sony_lcd_off();
}
static int power_supply_init(struct device *dev)
{
return gpio_request(GPIOD9_nAC_IN, "AC charger detect");
}
static int hx4700_is_ac_online(void)
{
return !gpio_get_value(GPIOD9_nAC_IN);
}
static void power_supply_exit(struct device *dev)
{
gpio_free(GPIOD9_nAC_IN);
}
static void hx4700_set_vpp(struct platform_device *pdev, int vpp)
{
gpio_set_value(GPIO91_HX4700_FLASH_VPEN, vpp);
}
static void __init hx4700_init(void)
{
int ret;
PCFR = PCFR_GPR_EN | PCFR_OPDE;
pxa2xx_mfp_config(ARRAY_AND_SIZE(hx4700_pin_config));
gpio_set_wake(GPIO12_HX4700_ASIC3_IRQ, 1);
ret = gpio_request_array(ARRAY_AND_SIZE(global_gpios));
if (ret)
pr_err ("hx4700: Failed to request GPIOs.\n");
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
pwm_add_table(hx4700_pwm_lookup, ARRAY_SIZE(hx4700_pwm_lookup));
pxa_set_ficp_info(&ficp_info);
pxa27x_set_i2c_power_info(NULL);
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(i2c_board_info));
i2c_register_board_info(1, ARRAY_AND_SIZE(pi2c_board_info));
pxa2xx_set_spi_info(2, &pxa_ssp2_master_info);
spi_register_board_info(ARRAY_AND_SIZE(tsc2046_board_info));
gpio_set_value(GPIO71_HX4700_ASIC3_nRESET, 0);
mdelay(10);
gpio_set_value(GPIO71_HX4700_ASIC3_nRESET, 1);
mdelay(10);
}
