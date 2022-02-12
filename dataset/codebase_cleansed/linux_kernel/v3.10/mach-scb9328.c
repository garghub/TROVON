static void __init scb9328_init(void)
{
imx1_soc_init();
mxc_gpio_setup_multiple_pins(mxc_uart1_pins,
ARRAY_SIZE(mxc_uart1_pins), "UART1");
imx1_add_imx_uart0(&uart_pdata);
printk(KERN_INFO"Scb9328: Adding devices\n");
dm9000x_resources[2].start = gpio_to_irq(IMX_GPIO_NR(3, 3));
dm9000x_resources[2].end = gpio_to_irq(IMX_GPIO_NR(3, 3));
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init scb9328_timer_init(void)
{
mx1_clocks_init(32000);
}
