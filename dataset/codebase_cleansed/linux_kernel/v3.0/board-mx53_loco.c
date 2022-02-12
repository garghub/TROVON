static inline void mx53_loco_fec_reset(void)
{
int ret;
ret = gpio_request(LOCO_FEC_PHY_RST, "fec-phy-reset");
if (ret) {
printk(KERN_ERR"failed to get GPIO_FEC_PHY_RESET: %d\n", ret);
return;
}
gpio_direction_output(LOCO_FEC_PHY_RST, 0);
msleep(1);
gpio_set_value(LOCO_FEC_PHY_RST, 1);
}
static void __init mx53_loco_board_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mx53_loco_pads,
ARRAY_SIZE(mx53_loco_pads));
imx53_add_imx_uart(0, NULL);
mx53_loco_fec_reset();
imx53_add_fec(&mx53_loco_fec_data);
imx53_add_imx2_wdt(0, NULL);
imx53_add_imx_i2c(0, &mx53_loco_i2c_data);
imx53_add_imx_i2c(1, &mx53_loco_i2c_data);
imx53_add_sdhci_esdhc_imx(0, NULL);
imx53_add_sdhci_esdhc_imx(2, NULL);
imx_add_gpio_keys(&loco_button_data);
}
static void __init mx53_loco_timer_init(void)
{
mx53_clocks_init(32768, 24000000, 0, 0);
}
