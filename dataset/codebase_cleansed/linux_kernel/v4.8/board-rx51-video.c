static int __init rx51_video_init(void)
{
if (!machine_is_nokia_rx51())
return 0;
if (omap_mux_init_gpio(RX51_LCD_RESET_GPIO, OMAP_PIN_OUTPUT)) {
pr_err("%s cannot configure MUX for LCD RESET\n", __func__);
return 0;
}
omap_display_init(&rx51_dss_board_info);
platform_device_register(&rx51_tv_connector_device);
return 0;
}
