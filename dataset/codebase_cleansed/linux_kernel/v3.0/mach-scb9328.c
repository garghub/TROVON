static int uart1_mxc_init(struct platform_device *pdev)
{
return mxc_gpio_setup_multiple_pins(mxc_uart1_pins,
ARRAY_SIZE(mxc_uart1_pins), "UART1");
}
static void uart1_mxc_exit(struct platform_device *pdev)
{
mxc_gpio_release_multiple_pins(mxc_uart1_pins,
ARRAY_SIZE(mxc_uart1_pins));
}
static void __init scb9328_init(void)
{
imx1_add_imx_uart0(&uart_pdata);
printk(KERN_INFO"Scb9328: Adding devices\n");
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init scb9328_timer_init(void)
{
mx1_clocks_init(32000);
}
