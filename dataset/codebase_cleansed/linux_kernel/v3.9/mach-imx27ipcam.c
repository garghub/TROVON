static void __init mx27ipcam_init(void)
{
imx27_soc_init();
mxc_gpio_setup_multiple_pins(mx27ipcam_pins, ARRAY_SIZE(mx27ipcam_pins),
"mx27ipcam");
imx27_add_imx_uart0(NULL);
imx27_add_fec(NULL);
imx27_add_imx2_wdt();
}
static void __init mx27ipcam_timer_init(void)
{
mx27_clocks_init(25000000);
}
