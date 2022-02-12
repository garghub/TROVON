static void __init mx1ads_init(void)
{
imx1_soc_init();
mxc_gpio_setup_multiple_pins(mx1ads_pins,
ARRAY_SIZE(mx1ads_pins), "mx1ads");
imx1_add_imx_uart0(&uart0_pdata);
imx1_add_imx_uart1(&uart1_pdata);
mxc_register_device(&flash_device, &mx1ads_flash_data);
i2c_register_board_info(0, mx1ads_i2c_devices,
ARRAY_SIZE(mx1ads_i2c_devices));
imx1_add_imx_i2c(&mx1ads_i2c_data);
}
static void __init mx1ads_timer_init(void)
{
mx1_clocks_init(32000);
}
