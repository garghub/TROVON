static void __init mx23evk_init(void)
{
int ret;
mxs_iomux_setup_multiple_pads(mx23evk_pads, ARRAY_SIZE(mx23evk_pads));
mx23_add_duart();
mx23_add_auart0();
ret = gpio_request_one(MX23EVK_MMC0_SLOT_POWER, GPIOF_OUT_INIT_LOW,
"mmc0-slot-power");
if (ret)
pr_warn("failed to request gpio mmc0-slot-power: %d\n", ret);
mx23_add_mxs_mmc(0, &mx23evk_mmc_pdata);
ret = gpio_request_one(MX23EVK_LCD_ENABLE, GPIOF_DIR_OUT, "lcd-enable");
if (ret)
pr_warn("failed to request gpio lcd-enable: %d\n", ret);
else
gpio_set_value(MX23EVK_LCD_ENABLE, 1);
ret = gpio_request_one(MX23EVK_BL_ENABLE, GPIOF_DIR_OUT, "bl-enable");
if (ret)
pr_warn("failed to request gpio bl-enable: %d\n", ret);
else
gpio_set_value(MX23EVK_BL_ENABLE, 1);
mx23_add_mxsfb(&mx23evk_mxsfb_pdata);
mx23_add_rtc_stmp3xxx();
}
static void __init mx23evk_timer_init(void)
{
mx23_clocks_init();
}
