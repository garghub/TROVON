static void __init bug_board_init(void)
{
imx31_soc_init();
mxc_iomux_setup_multiple_pins(bug_pins,
ARRAY_SIZE(bug_pins), "uart-4");
imx31_add_imx_uart4(&uart_pdata);
}
static void __init bug_timer_init(void)
{
mx31_clocks_init(26000000);
}
