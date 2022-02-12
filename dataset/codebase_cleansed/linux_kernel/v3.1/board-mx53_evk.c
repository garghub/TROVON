static inline void mx53_evk_init_uart(void)
{
imx53_add_imx_uart(0, NULL);
imx53_add_imx_uart(1, &mx53_evk_uart_pdata);
imx53_add_imx_uart(2, NULL);
}
static inline void mx53_evk_fec_reset(void)
{
int ret;
ret = gpio_request_one(MX53_EVK_FEC_PHY_RST, GPIOF_OUT_INIT_LOW,
"fec-phy-reset");
if (ret) {
printk(KERN_ERR"failed to get GPIO_FEC_PHY_RESET: %d\n", ret);
return;
}
msleep(1);
gpio_set_value(MX53_EVK_FEC_PHY_RST, 1);
}
static void __init mx53_evk_board_init(void)
{
imx53_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx53_evk_pads,
ARRAY_SIZE(mx53_evk_pads));
mx53_evk_init_uart();
mx53_evk_fec_reset();
imx53_add_fec(&mx53_evk_fec_pdata);
imx53_add_imx_i2c(0, &mx53_evk_i2c_data);
imx53_add_imx_i2c(1, &mx53_evk_i2c_data);
imx53_add_sdhci_esdhc_imx(0, NULL);
imx53_add_sdhci_esdhc_imx(1, NULL);
spi_register_board_info(mx53_evk_spi_board_info,
ARRAY_SIZE(mx53_evk_spi_board_info));
imx53_add_ecspi(0, &mx53_evk_spi_data);
imx53_add_imx2_wdt(0, NULL);
gpio_led_register_device(-1, &mx53evk_leds_data);
}
static void __init mx53_evk_timer_init(void)
{
mx53_clocks_init(32768, 24000000, 22579200, 0);
}
