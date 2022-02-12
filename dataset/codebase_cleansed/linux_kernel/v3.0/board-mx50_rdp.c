static inline void mx50_rdp_fec_reset(void)
{
gpio_request(FEC_EN, "fec-en");
gpio_direction_output(FEC_EN, 0);
gpio_request(FEC_RESET_B, "fec-reset_b");
gpio_direction_output(FEC_RESET_B, 0);
msleep(1);
gpio_set_value(FEC_RESET_B, 1);
}
static void __init mx50_rdp_board_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mx50_rdp_pads,
ARRAY_SIZE(mx50_rdp_pads));
imx50_add_imx_uart(0, &uart_pdata);
imx50_add_imx_uart(1, &uart_pdata);
mx50_rdp_fec_reset();
imx50_add_fec(&fec_data);
imx50_add_imx_i2c(0, &i2c_data);
imx50_add_imx_i2c(1, &i2c_data);
imx50_add_imx_i2c(2, &i2c_data);
}
static void __init mx50_rdp_timer_init(void)
{
mx50_clocks_init(32768, 24000000, 22579200);
}
