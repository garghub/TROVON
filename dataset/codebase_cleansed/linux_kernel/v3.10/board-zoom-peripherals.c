static int zoom_twl_gpio_setup(struct device *dev,
unsigned gpio, unsigned ngpio)
{
mmc[0].gpio_cd = gpio + 0;
omap_hsmmc_late_init(mmc);
omap_twl4030_audio_data.jack_detect = gpio + 2;
omap_twl4030_audio_init("Zoom2", &omap_twl4030_audio_data);
return 0;
}
static int __init omap_i2c_init(void)
{
omap3_pmic_get_config(&zoom_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_BCI |
TWL_COMMON_PDATA_MADC | TWL_COMMON_PDATA_AUDIO,
TWL_COMMON_REGULATOR_VDAC | TWL_COMMON_REGULATOR_VPLL2);
if (machine_is_omap_zoom2())
zoom_twldata.audio->codec->ramp_delay_value = 3;
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
pwm_add_table(zoom_pwm_lookup, ARRAY_SIZE(zoom_pwm_lookup));
platform_add_devices(zoom_devices, ARRAY_SIZE(zoom_devices));
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
enable_board_wakeup_source();
omap_serial_init();
}
