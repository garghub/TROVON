static int rx51_lcd_enable(struct omap_dss_device *dssdev)
{
gpio_set_value(dssdev->reset_gpio, 1);
return 0;
}
static void rx51_lcd_disable(struct omap_dss_device *dssdev)
{
gpio_set_value(dssdev->reset_gpio, 0);
}
static int __init rx51_video_init(void)
{
if (!machine_is_nokia_rx51())
return 0;
if (omap_mux_init_gpio(RX51_LCD_RESET_GPIO, OMAP_PIN_OUTPUT)) {
pr_err("%s cannot configure MUX for LCD RESET\n", __func__);
return 0;
}
if (gpio_request_one(RX51_LCD_RESET_GPIO, GPIOF_OUT_INIT_HIGH,
"LCD ACX565AKM reset")) {
pr_err("%s failed to get LCD Reset GPIO\n", __func__);
return 0;
}
omap_display_init(&rx51_dss_board_info);
return 0;
}
