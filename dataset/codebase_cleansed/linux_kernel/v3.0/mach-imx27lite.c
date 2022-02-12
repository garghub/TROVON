static void __init mx27lite_init(void)
{
mxc_gpio_setup_multiple_pins(mx27lite_pins, ARRAY_SIZE(mx27lite_pins),
"imx27lite");
imx27_add_imx_uart0(&uart_pdata);
imx27_add_fec(NULL);
}
static void __init mx27lite_timer_init(void)
{
mx27_clocks_init(26000000);
}
