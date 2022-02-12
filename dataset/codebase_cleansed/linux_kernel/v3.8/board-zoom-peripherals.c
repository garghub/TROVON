static int zoom_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
int ret;
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
ret = gpio_request_one(LCD_PANEL_ENABLE_GPIO, GPIOF_OUT_INIT_LOW,
"lcd enable");
if (ret)
pr_err("Failed to get LCD_PANEL_ENABLE_GPIO (gpio%d).\n",
LCD_PANEL_ENABLE_GPIO);
return ret;
}
static int __init omap_i2c_init(void)
{
omap3_pmic_get_config(&zoom_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_BCI |
TWL_COMMON_PDATA_MADC | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
if (machine_is_omap_zoom2()) {
struct twl4030_codec_data *codec_data;
codec_data = zoom_twldata.audio->codec;
codec_data->ramp_delay_value = 3;
codec_data->hs_extmute = 1;
codec_data->hs_extmute_gpio = ZOOM2_HEADSET_EXTMUTE_GPIO;
}
omap_pmic_init(1, 2400, "twl5030", 7 + OMAP_INTC_START, &zoom_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void enable_board_wakeup_source(void)
{
omap_mux_init_signal("sys_nirq",
OMAP_WAKEUP_EN | OMAP_PIN_INPUT_PULLUP);
}
void __init zoom_peripherals_init(void)
{
int ret;
omap_zoom_wlan_data.irq = gpio_to_irq(OMAP_ZOOM_WLAN_IRQ_GPIO);
ret = wl12xx_set_platform_data(&omap_zoom_wlan_data);
if (ret)
pr_err("error setting wl12xx data: %d\n", ret);
omap_hsmmc_init(mmc);
omap_i2c_init();
platform_device_register(&omap_vwlan_device);
usb_musb_init(NULL);
enable_board_wakeup_source();
omap_serial_init();
}
