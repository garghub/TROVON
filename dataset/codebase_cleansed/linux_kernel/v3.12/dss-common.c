void __init omap4_panda_display_init_of(void)
{
omap_display_init(&omap4_panda_dss_data);
platform_device_register(&omap4_panda_tfp410_device);
platform_device_register(&omap4_panda_dvi_connector_device);
platform_device_register(&omap4_panda_tpd_device);
platform_device_register(&omap4_panda_hdmi_connector_device);
}
void __init omap_4430sdp_display_init_of(void)
{
int r;
r = gpio_request_one(DISPLAY_SEL_GPIO, GPIOF_OUT_INIT_HIGH,
"display_sel");
if (r)
pr_err("%s: Could not get display_sel GPIO\n", __func__);
r = gpio_request_one(DLP_POWER_ON_GPIO, GPIOF_OUT_INIT_LOW,
"DLP POWER ON");
if (r)
pr_err("%s: Could not get DLP POWER ON GPIO\n", __func__);
omap_display_init(&sdp4430_dss_data);
platform_device_register(&sdp4430_lcd_device);
platform_device_register(&sdp4430_lcd2_device);
platform_device_register(&sdp4430_tpd_device);
platform_device_register(&sdp4430_hdmi_connector_device);
}
