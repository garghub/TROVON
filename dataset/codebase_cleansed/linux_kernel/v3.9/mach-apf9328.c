static void __init apf9328_init(void)
{
imx1_soc_init();
mxc_gpio_setup_multiple_pins(apf9328_pins,
ARRAY_SIZE(apf9328_pins),
"APF9328");
imx1_add_imx_uart0(NULL);
imx1_add_imx_uart1(&uart1_pdata);
imx1_add_imx_i2c(&apf9328_i2c_data);
dm9000_resources[2].start = gpio_to_irq(IMX_GPIO_NR(2, 14));
dm9000_resources[2].end = gpio_to_irq(IMX_GPIO_NR(2, 14));
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init apf9328_timer_init(void)
{
mx1_clocks_init(32768);
}
