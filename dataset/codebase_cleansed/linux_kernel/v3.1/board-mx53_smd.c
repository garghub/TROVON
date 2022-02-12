static inline void mx53_smd_init_uart(void)
{
imx53_add_imx_uart(0, NULL);
imx53_add_imx_uart(1, NULL);
imx53_add_imx_uart(2, &mx53_smd_uart_data);
}
static inline void mx53_smd_fec_reset(void)
{
int ret;
ret = gpio_request(SMD_FEC_PHY_RST, "fec-phy-reset");
if (ret) {
printk(KERN_ERR"failed to get GPIO_FEC_PHY_RESET: %d\n", ret);
return;
}
gpio_direction_output(SMD_FEC_PHY_RST, 0);
msleep(1);
gpio_set_value(SMD_FEC_PHY_RST, 1);
}
static void __init mx53_smd_board_init(void)
{
imx53_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx53_smd_pads,
ARRAY_SIZE(mx53_smd_pads));
mx53_smd_init_uart();
mx53_smd_fec_reset();
imx53_add_fec(&mx53_smd_fec_data);
imx53_add_imx2_wdt(0, NULL);
imx53_add_imx_i2c(0, &mx53_smd_i2c_data);
imx53_add_sdhci_esdhc_imx(0, NULL);
imx53_add_sdhci_esdhc_imx(1, NULL);
imx53_add_sdhci_esdhc_imx(2, NULL);
}
static void __init mx53_smd_timer_init(void)
{
mx53_clocks_init(32768, 24000000, 22579200, 0);
}
