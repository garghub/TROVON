static int palmte2_backlight_init(struct device *dev)
{
return gpio_request_array(ARRAY_AND_SIZE(palmte_bl_gpios));
}
static int palmte2_backlight_notify(struct device *dev, int brightness)
{
gpio_set_value(GPIO_NR_PALMTE2_BL_POWER, brightness);
gpio_set_value(GPIO_NR_PALMTE2_LCD_POWER, brightness);
return brightness;
}
static void palmte2_backlight_exit(struct device *dev)
{
gpio_free_array(ARRAY_AND_SIZE(palmte_bl_gpios));
}
static int power_supply_init(struct device *dev)
{
int ret;
ret = gpio_request(GPIO_NR_PALMTE2_POWER_DETECT, "CABLE_STATE_AC");
if (ret)
goto err1;
ret = gpio_direction_input(GPIO_NR_PALMTE2_POWER_DETECT);
if (ret)
goto err2;
return 0;
err2:
gpio_free(GPIO_NR_PALMTE2_POWER_DETECT);
err1:
return ret;
}
static int palmte2_is_ac_online(void)
{
return gpio_get_value(GPIO_NR_PALMTE2_POWER_DETECT);
}
static void power_supply_exit(struct device *dev)
{
gpio_free(GPIO_NR_PALMTE2_POWER_DETECT);
}
static void __init palmte2_udc_init(void)
{
if (!gpio_request(GPIO_NR_PALMTE2_USB_PULLUP, "UDC Vbus")) {
gpio_direction_output(GPIO_NR_PALMTE2_USB_PULLUP, 1);
gpio_free(GPIO_NR_PALMTE2_USB_PULLUP);
}
}
static void __init palmte2_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(palmte2_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_fb_info(NULL, &palmte2_lcd_screen);
pxa_set_mci_info(&palmte2_mci_platform_data);
palmte2_udc_init();
pxa_set_ac97_info(&palmte2_ac97_pdata);
pxa_set_ficp_info(&palmte2_ficp_platform_data);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
