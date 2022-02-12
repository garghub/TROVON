static void __init apf9328_init(void)
{
mxc_gpio_setup_multiple_pins(apf9328_pins,
ARRAY_SIZE(apf9328_pins),
"APF9328");
imx1_add_imx_uart0(&uart0_pdata);
imx1_add_imx_uart1(&uart1_pdata);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init apf9328_timer_init(void)
{
mx1_clocks_init(32768);
}
